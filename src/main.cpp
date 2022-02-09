#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

#include "font.hpp"
#include "syllable.hpp"
#include "images.hpp"

#define BUTTON_PIN 3
#define SOUND_PIN 7
#define PWR_PIN 2
#define LED_PIN 4
#define BATT_PIN A3

//U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);//                                                                                                        !!!0.96" I2C
//U8X8_SH1106_128X64_NONAME_4W_HW_SPI u8x8(/* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);//                                                                                           !!!1.3" SPI
U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 8, /* reset=*/ 9);

void initAwake() {
  ADCSRA |= (1 << ADEN); // Turn ADC back on

  pinMode(PWR_PIN, OUTPUT);
  digitalWrite(PWR_PIN,HIGH);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(SOUND_PIN, OUTPUT);
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
}

void boomSound() {
  for (int i=10000;i>0;i--) {
    byte bt = ((i & 255) > 127) && (i > random(20000));
    digitalWrite(SOUND_PIN,bt);
    digitalWrite(LED_PIN,bt);
   }
}


void processTimer() {
  int secs = 60;
  char buf[3];
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
    itoa(secs, buf, 10);
    drawSyllable(buf);
    do {
      elapsedMs = millis()-startMs;
      digitalWrite(LED_PIN, elapsedMs < (60-secs)*16);
      delay(1);
      if (!digitalRead(BUTTON_PIN)) break;
    } while (elapsedMs < 1000);
    if (elapsedMs < 999) break;    
    secs--;
  }
  if (secs == 0) { 
    tone(SOUND_PIN, 2000, 1000);
  }
  drawWhistle(u8g2);
  digitalWrite(LED_PIN, LOW);
}

void processBomb() {
  int startFreq = 440;
  digitalWrite(LED_PIN, HIGH);
  drawBomb(u8g2);
  while (!digitalRead(BUTTON_PIN) && (startFreq < 10000)) {
      tone(SOUND_PIN,startFreq,50);
      for (int i=0;i<100;i++) {
        random();
        if (digitalRead(BUTTON_PIN)) break;
        delay(1);
      }
      startFreq*=1.1;
  }
  if (startFreq < 10000) {
    drawRandomSyllable();
    digitalWrite(LED_PIN, LOW);
    int c = 80 + random(80);
    while (c>0 && digitalRead(BUTTON_PIN)) {
      digitalWrite(LED_PIN,HIGH);
      tone(SOUND_PIN, 10000, 10);
      delay(10);
      digitalWrite(LED_PIN,LOW);
      delay(230);
      c--;
    }
  }
  drawOutblast(u8g2);
  boomSound();
  digitalWrite(LED_PIN, LOW);
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

  ADCSRA &= ~(1 << ADEN); // Отключаем АЦП
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Устанавливаем интересующий нас режим
  sleep_enable();
  // Отключаем детектор пониженного напряжения питания
  MCUCR != ((1 << BODS) | (1 << BODSE));
  MCUCR &= ~(1 << BODSE);
  sleep_cpu(); // Переводим МК в спящий режим

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
    //950 ADC value corresponds to 4V battery voltage, so values below 750 consider battery low
    itoa(adc,buf,10);
    drawSyllable(buf);
    delay(500);
  }
}

void loop(void)
{
  sleepUntilButtonPress();
  initAwake();

  if (digitalRead(BUTTON_PIN)) {
    processTimer();
  } else {
    processBomb();
  }

  unsigned int adc = 0;
  for (byte i=0;i<64;i++) {
      adc+=analogRead(A3);
  }
  //950 ADC value corresponds to 4V battery voltage, so values below 750 consider battery low
  adc/=64;
  if (adc < 750) {
    drawSyllable("ЗАРЯД");
    tone(SOUND_PIN, 1000, 300);
    delay(600);
    tone(SOUND_PIN, 1000, 300);
    delay(600);
    tone(SOUND_PIN, 1000, 300);
    delay(2000);
  }

  unsigned long ms = millis();
  while (millis() < ms + 5000 && digitalRead(BUTTON_PIN));
  
  while (!digitalRead(BUTTON_PIN));
}
