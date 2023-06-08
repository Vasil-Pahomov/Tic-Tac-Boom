#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <U8g2lib.h>
#include <EEPROM.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

#include "font.hpp"
#include "syllable.hpp"
#include "images.hpp"

#define BUTTON_PIN 3
#define SOUND_PIN 7
#define VIBRO_PIN 5
#define PWR_PIN 2
#define LED_PIN 4
#define BATT_PIN A3

#define BOMB_INIT_MAX_FREQ 10000 //maximum tone frequency when button is held initting the bomb

#define SETTINGS_IDLE_TIMEOUT 30000 // idle time in settings - after that settings will exit
#define SETTINGS_LONG_PRESS 1000 //button long press time to change current setting; short press advances to the next setting


U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9);

bool locked = false;
unsigned long startMs;

extern byte usedSylsCount; //bad way to share data between files...

void initAwake() {
  ADCSRA |= (1 << ADEN); // Turn ADC back on

  pinMode(PWR_PIN, OUTPUT);
  digitalWrite(PWR_PIN,HIGH);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(SOUND_PIN, OUTPUT);
  pinMode(VIBRO_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  pinMode(BATT_PIN, INPUT);
  analogReference(INTERNAL);
  randomSeed(analogRead(BATT_PIN));

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);

  u8g2.begin();  
  u8g2.setPowerSave(LOW);
  u8g2.setBusClock(1500000);
}

void setup(void)
{
  Serial.begin(38400);
}

void boomSound() {
  digitalWrite(VIBRO_PIN,HIGH);
  for (int i=10000;i>0;i--) {
    byte bt = ((i & 255) > 127) && (i > random(20000));
    digitalWrite(SOUND_PIN,bt);
    digitalWrite(LED_PIN,bt);
   }
  digitalWrite(VIBRO_PIN,LOW);
}

//returns true if a lock has been set or an attempt to set a lock was tried
bool checkEnterLockMode() {
  //if the button is hold (after being released) and less than 1 seconds left since start, we may try entering lock mode
  if ( (millis() - startMs < 1000) && !digitalRead(BUTTON_PIN)) {
    drawUnlock(u8g2);
    while (!digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button released
    delay(50);
    while (digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button pressed
    if (millis() - startMs > 2000) return true; // too much between presses - no lock
    delay(50);
    while (!digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button released
    delay(50);
    while (digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button pressed
    if (millis() - startMs > 3000) return true; // too much between presses - no lock
    tone(SOUND_PIN, 200, 100);
    drawLock(u8g2);
    delay(500);
    locked = true;
    usedSylsCount = 0;
    return true;
  } else {
    return false;
  }
}

byte normalizeSetting(byte item, byte value) {
  switch (item) {
    case 0: // language
      return value > 1 ? 0 : value;
    case 1: // team size
      return value > 1 ? 0 : value;
    case 2: // timer value
      return value > 3 ? 0 : value;
    case 3: // use syllable limitations
      return value > 1 ? 0 : value;
    default:
      return 0;
    }
}

void displaySetting(byte item, byte value) {
  switch (item) {
    case 0: // language
      switch (value) {
        case 0: // english
          drawSyllable("ENG");
          break;
        case 1: // russian
          drawSyllable("–”—");
          break;
        default:
          drawSyllable("0 ");
          break;
      }
      break;
    case 1: // team size
      switch (value) {
        case 0: //small team
          drawSyllable("Ã¿ÀŒ");
          break;
        case 1: //big team
          drawSyllable("ÃÕŒ√Œ");
          break;
        default:
          drawSyllable("1 ");
          break;
      }
      break;
    case 2: // timer value
      switch (value) {
        case 0: //30 sec
          drawSyllable("0:30");
          break;
        case 1: //60 sec
          drawSyllable("1:00");
          break;
        case 2: //120 sec
          drawSyllable("2:00");
          break;
        case 3: //300 sec
          drawSyllable("5:00");
          break;
        default:
          drawSyllable("2 ");
          break;
      }
      break;
    case 3: // use syllable limitations
      switch (value) {
        case 0: //do not use
          drawSyllable("—ÀŒ√");
          break;
        case 1: //use
          drawSyllable(" —ÀŒ√ ");
          break;
        default:
          drawSyllable("3 ");
          break;
      }
      break;
    default:
      drawSyllable("  ");
      break;
    }
}

void editSettings() {
  // 0 - language (0 - eng, 1 - rus)
  // 1 - team size (0 - <10, 1 - >10)
  // 2 - timer value (0 - 30sec, 1 - 60sec, 2-120sec, 3-130sec)
  // 3 - use syllable limitations (0 - do not use, 1 - use)
  byte item = 0; 
  unsigned long lastms;
  lastms = millis();
  drawSyllable("Õ¿—“–");
  while (!digitalRead(BUTTON_PIN)) { //wait until button is released
    if ((millis() - lastms) > SETTINGS_IDLE_TIMEOUT) return;
  }

  bool currentSettingBeingChanged = false;

  do {
    digitalWrite(LED_PIN, HIGH);
    lastms = millis();
    EEPROM.update(item, normalizeSetting(item,EEPROM.read(item)));
    displaySetting(item, EEPROM.read(item));
    digitalWrite(LED_PIN, LOW);

    while (digitalRead(BUTTON_PIN)) { //wait until button is pressed
      if ((millis() - lastms) > SETTINGS_IDLE_TIMEOUT) return;
    }

    digitalWrite(LED_PIN, HIGH);
    lastms = millis();
    while (!digitalRead(BUTTON_PIN)) { //wait until button is released
      if ( (millis() - lastms) > SETTINGS_LONG_PRESS ) break;
    }
    if ( (millis() - lastms) > SETTINGS_LONG_PRESS ) { // long press - change setting value and do NOT advance to the next
      EEPROM.update(item, normalizeSetting(item, EEPROM.read(item)+1));
      currentSettingBeingChanged = true;
      if (item == 0) { //a hack to reset used syllables when changing the language
            usedSylsCount = 0;
      }
    } else {
      //short press here - advance to the next setting if current setting is not being changed
      if (!currentSettingBeingChanged) {
        item++;
      }
      currentSettingBeingChanged = false;
    }
  } while (item<=3);
  digitalWrite(LED_PIN, LOW);
  u8g2.clear();
}

void processTimer() {
  int maxsecs = 60;
  switch (EEPROM.read(2)) {
    case 0: maxsecs = 30; break;
    case 2: maxsecs = 120; break;
    case 3: maxsecs = 300; break;
    default: maxsecs = 60; break;
  }
  int secs = maxsecs;
  char buf[5];
  while (secs>0) {
    long startMs = millis();
    long elapsedMs;
    if (secs <=3) {
      tone(SOUND_PIN, 1000, 500);
    } else {
      digitalWrite(SOUND_PIN, HIGH);
      delay(1);
      digitalWrite(SOUND_PIN, LOW); 
    }
    digitalWrite(LED_PIN,HIGH);
    buf[0] = (byte) (secs / 60) + '0';
    buf[1] = ':';
    buf[2] = (byte)((secs % 60) / 10) + '0';
    buf[3] = (byte)((secs % 60) % 10) + '0';
    buf[4] = 0;
    //itoa(secs % 60, buf, 10);
    drawSyllable(buf);
    do {
      elapsedMs = millis()-startMs;
      digitalWrite(LED_PIN, elapsedMs < (maxsecs-secs)*1000/maxsecs);
      delay(1);
      if (!digitalRead(BUTTON_PIN)) {
        break;
      }
    } while (elapsedMs < 1000);
    if (elapsedMs < 999) break;    
    secs--;
  }
  if (secs == 0) {
    tone(SOUND_PIN, 2000, 1000);
    drawSyllable("0:00"); 
    delay(1000);
  } else {
    if (checkEnterLockMode()) return;
  }  
  digitalWrite(LED_PIN, LOW);
}

void processBomb() {
  int startFreq = 440;
  digitalWrite(LED_PIN, HIGH);
  drawBomb(u8g2);
  while (!digitalRead(BUTTON_PIN) && (startFreq < BOMB_INIT_MAX_FREQ)) {
      tone(SOUND_PIN,startFreq,50);
      for (int i=0;i<100;i++) {
        random();
        if (digitalRead(BUTTON_PIN)) break;
        delay(1);
      }
      startFreq*=1.1;
  }
  if (startFreq < BOMB_INIT_MAX_FREQ) {
    drawRandomSyllable();
    digitalWrite(LED_PIN, LOW);
    int c;
    switch (EEPROM.read(1)) {
      case 1: c = 120 + random(600);break;
      default: c = 40 + random(200);break;
    }
    while (c>0 && digitalRead(BUTTON_PIN)) {
      digitalWrite(LED_PIN,HIGH);
      tone(SOUND_PIN, 10000, 10);
      delay(10);
      digitalWrite(LED_PIN,LOW);
      delay(230);
      c--;
    }
    drawOutblast(u8g2);
    boomSound();
    digitalWrite(LED_PIN, LOW);
  } else { // button is kept too long - go settings
    editSettings();
  }
}

void buttonISR() {
}

void sleepUntilButtonPress() {
  u8g2.setPowerSave(HIGH);

  SPCR = 0;
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(PWR_PIN,LOW);
  digitalWrite(LED_PIN,LOW);

  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(SOUND_PIN,INPUT);

  pinMode(BUTTON_PIN,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISR, FALLING);

  ADCSRA &= ~(1 << ADEN); // turn ADC off
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Set powerdown mode
  sleep_enable();
  // Turn brown-out detector off
  MCUCR != ((1 << BODS) | (1 << BODSE));
  MCUCR &= ~(1 << BODSE);
  sleep_cpu(); // set MCU to power-down mode

  detachInterrupt(digitalPinToInterrupt(BUTTON_PIN));  
}

void displayBatt() {
  char buf[5];
  while (1) {
    unsigned int adc = 0;
    for (byte i=0;i<64;i++) {
        adc+=analogRead(BATT_PIN);
    }
    adc/=64;
    itoa(adc,buf,10);
    drawSyllable(buf);
    delay(500);
  }
}

void checkLeaveLockMode() {
  drawLock(u8g2);
  while (!digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button released
  delay(50);
  while (digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button pressed
  if (millis() - startMs > 1000) return; // too much between presses - no unlock
  delay(50);
  while (!digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button released
  delay(50);
  while (digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button pressed
  if (millis() - startMs > 2000) return; // too much between presses - no unlock
  delay(50);
  while (!digitalRead(BUTTON_PIN) && (millis() - startMs < 3500));//wait until button released
  if (millis() - startMs > 3000) return; // too much between presses - no unlock
  tone(SOUND_PIN, 400, 100);
  drawUnlock(u8g2);
  locked = false;
  delay(500);
}

void loop(void)
{
  sleepUntilButtonPress();
  startMs = millis();
  initAwake();

  if (locked) {
    checkLeaveLockMode();
    return;
  }
  //wait 500ms until button released
  while (!digitalRead(BUTTON_PIN) && (millis() - startMs < 500));

  if (digitalRead(BUTTON_PIN)) {
    processTimer();
  } else {
    processBomb();
  }

  unsigned int adc = 0;
  for (byte i=0;i<64;i++) {
      adc+=analogRead(BATT_PIN);
  }
  //950 ADC value corresponds to 4V battery voltage, so values below 750 consider battery low
  adc/=64;
  if (adc < 750) {
    drawSyllable("«¿–ﬂƒ");
    tone(SOUND_PIN, 1000, 300);
    delay(600);
    tone(SOUND_PIN, 1000, 300);
    delay(600);
    tone(SOUND_PIN, 1000, 300);
    delay(2000);
  }
}
