#include "Arduino.h"
#include <U8g2lib.h>
#include "global.hpp"
#include "math.h"

// letter format:
// 1st byte is polygon type:
// 0 - end of figure marker
// 2 - box (filled rectangle); x1 should be bigger than x0, the same for y1 and y0
// 3 - triangle
// 4 - quadrangle
// next bytes are x and y coordinates of polygon nodes (y goes after x)
// number of nodes is equal to numeric polygon type; number of bytes is doubled number of nodes
const byte fnt_32[] PROGMEM = {2, 0,224, 16,240, 2, 32,224, 48,240, 2, 64,224, 80,240, 0}; //ellipsis

const byte fnt_49[] PROGMEM = {4, 0,64, 64,0, 96,0, 16,80, 2, 64,0, 96,240, 0}; //1
const byte fnt_50[] PROGMEM = {4, 0,32, 32,0, 128,0, 160,32, 4, 128,32, 160,32, 160,112, 128,144, 2, 32,112, 128,144, 4, 0,144, 32,112, 32,208, 0,208, 2, 0, 208, 160,240, 0}; //2
const byte fnt_51[] PROGMEM = {4, 0,32, 32,0, 128,0, 160,32, 4, 128,32, 160,32, 160,104, 128,120, 2, 32,104, 128,136, 4, 128,120, 160,136, 160,208, 128,208, 4, 0,208, 160,208, 124,240, 32,240, 0}; //3
const byte fnt_52[] PROGMEM = {4, 0,160, 128,0, 128,48, 44,160, 2, 128,0, 160,240, 2, 0,160, 128,192, 0}; //4
const byte fnt_53[] PROGMEM = {2, 0,0, 160,32, 4, 0,32, 32,32, 32,128, 0,96, 2, 32,96, 128,128, 4, 128,96, 160,128, 160,208, 128,208, 4, 0,208, 160,208, 128,240, 32,240, 0}; //5
const byte fnt_54[] PROGMEM = {4, 32,0, 128,0, 160,32, 0,32, 2, 0,32, 32,208, 2, 32,96, 128,128, 4, 128,96, 160,128, 160,208, 128,208, 4, 0,208, 160,208, 128,240, 32,240, 0}; //6
const byte fnt_55[] PROGMEM = {2, 0,0, 160,32, 4, 0,240, 128,32, 160,40, 40,240, 3, 128,32, 160,32, 160,48, 0}; //7
const byte fnt_56[] PROGMEM = {2, 32,0, 128,32, 4, 0,32, 32,0, 32,112, 0,96, 4, 128,0, 160,32, 160,96, 128,112, 2, 32,96, 128,128, 4, 0,128, 32,112, 32,240, 0,208, 4, 128,108, 160,128, 160,208, 128,240, 2, 32,208, 128,240, 0}; //8
const byte fnt_57[] PROGMEM = {4, 0,32, 32,0, 128,0, 160,32, 4, 0,32, 32,32, 32,144, 0,112, 2, 32,112, 128,144, 4, 128,32, 160,32, 160,208, 128,240, 4, 0,208, 128,208, 128,240, 32,240, 0}; //9


const byte fnt_192[] PROGMEM = {4, 0,240, 80,0, 112,0, 32,240, 4, 96,48, 112,0, 192,240, 160,240, 2, 32,160, 160,192, 0}; //??
const byte fnt_193[] PROGMEM = {2, 0,0, 32,240, 2 ,32,0, 160,32, 2, 32,80, 128,112, 3, 128,80, 160,112, 128,112, 2, 128,112, 160,206, 3, 128,206, 160,206, 128,240, 2, 32,206, 128,240, 0}; //??
const byte fnt_194[] PROGMEM = {2, 0,0, 32,240, 2, 32,0, 128,32, 3, 128,0, 160,32, 128, 32, 2, 128,32, 160,104, 3, 128,104, 160,104, 128,120, 2, 32,104, 128,136, 3, 128,120, 160,136, 128,136, 2, 128,136, 160,208, 3, 128,208, 160,208, 128,240, 2, 32,208, 128,240, 0}; //??
const byte fnt_195[] PROGMEM = {2, 0,0, 32,240, 2, 32,0, 160,32, 0}; //??
const byte fnt_196[] PROGMEM = {2, 0,240, 32,255, 2, 0,206, 192,240, 4, 16,206, 64,0, 96,0, 48,206, 2, 80,0, 112,32, 4, 96,0, 128,0, 176, 206, 144,206, 2, 160,240, 192,255, 0}; //??
const byte fnt_197[] PROGMEM = {2, 0,0, 32,240, 2, 32,0, 160,32, 2, 32,104, 128,136, 2, 32,208, 160,240, 0}; //??
const byte fnt_198[] PROGMEM = {4, 0,0, 32,0, 80,120, 48,120, 2, 80,0, 112,240, 4, 160,0, 192,0, 144,120, 112,120, 4, 48,120, 80,120, 32,240, 0,240, 4, 112,120, 144,120, 192,240, 160,240, 0}; //??
const byte fnt_199[] PROGMEM = {2, 0,0, 128,32, 4, 128,0, 160,32, 160,102, 128,120, 2, 32,102, 128,136, 4, 128,120, 160,136, 160,208, 128,240, 2, 0,208, 128,240, 0}; //??
const byte fnt_200[] PROGMEM = {2, 0,0, 32,240, 4, 32,176, 128,0, 128,64, 32,240, 2, 128,0, 160,240, 0}; //??
const byte fnt_201[] PROGMEM = {2, 0,0, 32,240, 4, 32,176, 128,0, 128,64, 32,240, 2, 128,0, 160,240, 2, 48,0, 112,16, 0}; //??
const byte fnt_202[] PROGMEM = {2, 0,0, 32,240, 4, 32,118, 112,0, 144,0, 32,164, 4, 63,120, 144, 240, 112,240, 47, 143, 0}; //??
const byte fnt_203[] PROGMEM = {4, 64,0, 96,0, 32,240, 0,240, 4, 64,0, 96,0, 160,240, 128,240, 0}; //??
const byte fnt_204[] PROGMEM = {2, 0,0, 32,240, 4, 32,0, 96,128, 96,192, 32,64, 4, 96,128, 160,0, 160,64, 96,192, 2, 160,0, 192,240, 0}; //??
const byte fnt_205[] PROGMEM = {2, 0,0, 32,240, 2, 32,96, 128,128, 2, 128,0, 160,240, 0}; //??
const byte fnt_206[] PROGMEM = {4, 0,32, 32,0, 144,0, 176,32, 2, 0,32, 32,208, 2, 144,32, 176,208, 4, 0,208, 176,208, 144,240, 32,240, 0}; //??
const byte fnt_207[] PROGMEM = {2, 0,0, 32,240, 2, 32,0, 128,32, 2, 128,0, 160,240, 0}; //??
const byte fnt_208[] PROGMEM = {2, 0,0, 32,240, 4, 32,0, 128,0, 160,32, 32,32, 2, 128,32, 160,128, 4, 32,128, 160,128, 128,160, 32,160, 0}; //??
const byte fnt_209[] PROGMEM = {4, 0,32, 32,0, 160,0, 160,32, 2, 0,32, 32,208, 4, 0,208, 160,208, 160,240, 32,240, 0}; //??
const byte fnt_210[] PROGMEM = {2, 0,0, 160,32, 2, 64,32, 96,240, 0}; //T
const byte fnt_211[] PROGMEM = {4, 0,0, 32,0, 81,92, 64, 120, 4, 128,0, 160,0, 32,240, 0,240, 0}; //??
const byte fnt_212[] PROGMEM = {4, 0,32, 32,0, 160,0, 192,32, 2, 0,32, 32,160, 2, 80,32, 114,240, 2, 160,32, 192,160, 4, 0,160, 192,160, 160,192, 32,192, 0}; //??
const byte fnt_213[] PROGMEM = {4, 0,0, 32,0, 160,240, 128,240, 4, 128,0, 160,0, 32,240, 0,240, 0}; //??
const byte fnt_214[] PROGMEM = {2, 0,0, 32,240, 2, 128,0, 160,240, 2, 32,208, 128, 240, 2, 160,208, 176,255, 0}; //??
const byte fnt_215[] PROGMEM = {4, 0,0, 32,0, 32,144, 0, 112, 2, 32,112, 128,144, 2, 128,0, 160,240, 0}; //??
const byte fnt_216[] PROGMEM = {2, 0,0, 32,208, 2, 80,0, 112,208, 2, 160,0, 192,208, 2, 0,208, 192,240, 0}; //??
const byte fnt_217[] PROGMEM = {2, 0,0, 32,208, 2, 80,0, 112,208, 2, 160,0, 192,208, 2, 0,208, 192,240, 2, 192,208, 208, 255, 0}; //??
const byte fnt_218[] PROGMEM = {}; //??
const byte fnt_219[] PROGMEM = {2, 0,0, 32,240, 4, 32,80, 112, 80, 144,112, 32,112, 2, 112,112, 144,208, 4, 32,208, 144,208, 112,240, 32,240, 2, 160,0, 192,240, 0}; //??
const byte fnt_220[] PROGMEM = {}; //??
const byte fnt_221[] PROGMEM = {4, 0,0, 128,0, 160,32, 0,32, 2, 128,32, 160,208, 2, 32,102, 128,134, 4, 0,208, 160,208, 128,240, 0,240, 0}; //??
const byte fnt_222[] PROGMEM = {2, 0,0, 32,240, 2, 32,104, 64,136, 4, 64,32, 96,0, 160,0, 192,32, 2, 64,32, 96,208, 2, 160,32, 192,208, 4, 64,208, 192,208, 160,240, 96,240, 0}; //??
const byte fnt_223[] PROGMEM = {4, 0,32, 32,0, 32,160, 0, 128, 2, 32, 0, 128,32, 2, 128,0, 160,240, 2, 32,128, 128,160, 4, 48,160, 80,160, 32,240, 0,240, 0 }; //??

const byte *const font_tbl[] PROGMEM = {
NULL,//0-end of line marker
NULL,//1-SOH
NULL,//2-STX
NULL,//3-ETX
NULL,//4-EOT
NULL,//5-ENQ
NULL,//6-ACK
NULL,//7-BEL
NULL,//8-BS
NULL,//9-TAB
NULL,//10-LF
NULL,//11-VT
NULL,//12-FF
NULL,//13-CR
NULL,//14-SO
NULL,//15-SI
NULL,//16-DLE
NULL,//17-DC1
NULL,//18-DC2
NULL,//19-DC3
NULL,//20-DC4
NULL,//21-NAK
NULL,//22-SYN
NULL,//23-ETB
NULL,//24-CAN
NULL,//25-EM
NULL,//26-SUB
NULL,//27-ESC
NULL,//28-FS
NULL,//29-GS
NULL,//30-RS
NULL,//31-US
fnt_32,//32-SP (ellipsis)
NULL,//33-!
NULL,//34-"
NULL,//35-#
NULL,//36-$
NULL,//37-%
NULL,//38-&
NULL,//39-'
NULL,//40-(
NULL,//41-)
NULL,//42-*
NULL,//43-+
NULL,//44-,
NULL,//45--
NULL,//46-.
NULL,//47-/
fnt_206,//48-0 (O)
fnt_49,//49-1
fnt_50,//50-2
fnt_51,//51-3
fnt_52,//52-4
fnt_53,//53-5
fnt_54,//54-6
fnt_55,//55-7
fnt_56,//56-8
fnt_57,//57-9
NULL,//58-:
NULL,//59-;
NULL,//60-<
NULL,//61-=
NULL,//62->
NULL,//63-?
NULL,//64-@
fnt_192,//65-A
NULL,//66-B
NULL,//67-C
NULL,//68-D
NULL,//69-E
NULL,//70-F
NULL,//71-G
NULL,//72-H
NULL,//73-I
NULL,//74-J
NULL,//75-K
NULL,//76-L
NULL,//77-M
NULL,//78-N
NULL,//79-O
NULL,//80-P
NULL,//81-Q
NULL,//82-R
NULL,//83-S
NULL,//84-T
NULL,//85-U
NULL,//86-V
NULL,//87-W
NULL,//88-X
NULL,//89-Y
NULL,//90-Z
NULL,//91-[
NULL,//92-backslash
NULL,//93-]
NULL,//94-^
NULL,//95-_
NULL,//96-`
NULL,//97-a
NULL,//98-b
NULL,//99-c
NULL,//100-d
NULL,//101-e
NULL,//102-f
NULL,//103-g
NULL,//104-h
NULL,//105-i
NULL,//106-j
NULL,//107-k
NULL,//108-l
NULL,//109-m
NULL,//110-n
NULL,//111-o
NULL,//112-p
NULL,//113-q
NULL,//114-r
NULL,//115-s
NULL,//116-t
NULL,//117-u
NULL,//118-v
NULL,//119-w
NULL,//120-x
NULL,//121-y
NULL,//122-z
NULL,//123-{
NULL,//124-|
NULL,//125-}
NULL,//126-~
NULL,//127-DEL
NULL,//128-??
NULL,//129-??
NULL,//130-???
NULL,//131-??
NULL,//132-???
NULL,//133-???
NULL,//134-???
NULL,//135-???
NULL,//136-???
NULL,//137-???
NULL,//138-??
NULL,//139-???
NULL,//140-??
NULL,//141-??
NULL,//142-??
NULL,//143-??
NULL,//144-??
NULL,//145-???
NULL,//146-???
NULL,//147-???
NULL,//148-???
NULL,//149-???
NULL,//150-???
NULL,//151-???
NULL,//152-
NULL,//153-???
NULL,//154-??
NULL,//155-???
NULL,//156-??
NULL,//157-??
NULL,//158-??
NULL,//159-??
NULL,//160-
NULL,//161-??
NULL,//162-??
NULL,//163-??
NULL,//164-??
NULL,//165-??
NULL,//166-??
NULL,//167-??
NULL,//168-??
NULL,//169-??
NULL,//170-??
NULL,//171-??
NULL,//172-??
NULL,//173-??
NULL,//174-??
NULL,//175-??
NULL,//176-??
NULL,//177-??
NULL,//178-??
NULL,//179-??
NULL,//180-??
NULL,//181-??
NULL,//182-??
NULL,//183-??
NULL,//184-??
NULL,//185-???
NULL,//186-??
NULL,//187-??
NULL,//188-??
NULL,//189-??
NULL,//190-??
NULL,//191-??
fnt_192,//192-??
fnt_193,//193-??
fnt_194,//194-??
fnt_195,//195-??
fnt_196,//196-??
fnt_197,//197-??
fnt_198,//198-??
fnt_199,//199-??
fnt_200,//200-??
fnt_201,//201-??
fnt_202,//202-??
fnt_203,//203-??
fnt_204,//204-??
fnt_205,//205-??
fnt_206,//206-??
fnt_207,//207-??
fnt_208,//208-??
fnt_209,//209-??
fnt_210,//210-??
fnt_211,//211-??
fnt_212,//212-??
fnt_213,//213-??
fnt_214,//214-??
fnt_215,//215-??
fnt_216,//216-??
fnt_217,//217-??
fnt_218,//218-??
fnt_219,//219-??
fnt_220,//220-??
fnt_221,//221-??
fnt_222,//222-??
fnt_223,//223-??
NULL,//224-??
NULL,//225-??
NULL,//226-??
NULL,//227-??
NULL,//228-??
NULL,//229-??
NULL,//230-??
NULL,//231-??
NULL,//232-??
NULL,//233-??
NULL,//234-??
NULL,//235-??
NULL,//236-??
NULL,//237-??
NULL,//238-??
NULL,//239-??
NULL,//240-??
NULL,//241-??
NULL,//242-??
NULL,//243-??
NULL,//244-??
NULL,//245-??
NULL,//246-??
NULL,//247-??
NULL,//248-??
NULL,//249-??
NULL,//250-??
NULL,//251-??
NULL,//252-??
NULL,//253-??
NULL,//254-??
NULL //255-??
};

#define LSPACE 5 //space between letters, in pixels

void drawQuadrangle(int16_t x0,int16_t y0,int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t x3,int16_t y3) {
    u8g2.drawTriangle(x0,y0,x1,y1,x3,y3);
    u8g2.drawTriangle(x3,y3,x1,y1,x2,y2);
}


void drawLetter(char letter, int xb, float coef) {
        uint16_t dataaddr = pgm_read_word(&(font_tbl[(byte)letter]));
        bool loopPolygons = true;
        int x0,y0,x1,y1,x2,y2,x3,y3;
        do {
            byte ptype = pgm_read_byte(dataaddr++);
            //Serial.print("ptype=");Serial.println(ptype);
            switch (ptype) {
                case 0:
                    loopPolygons = false;
                    break;
                case 2:
                    x0 = xb + pgm_read_byte(dataaddr++)*coef; y0 = pgm_read_byte(dataaddr++)/4;
                    x1 = xb + pgm_read_byte(dataaddr++)*coef; y1 = pgm_read_byte(dataaddr++)/4;
                    u8g2.drawBox( min(x0,x1),min(y0,y1), abs(x1-x0), abs(y1-y0));
                    break;
                case 3:
                    x0 = xb + pgm_read_byte(dataaddr++)*coef; y0 = pgm_read_byte(dataaddr++)/4;
                    x1 = xb + pgm_read_byte(dataaddr++)*coef; y1 = pgm_read_byte(dataaddr++)/4;
                    x2 = xb + pgm_read_byte(dataaddr++)*coef; y2 = pgm_read_byte(dataaddr++)/4;

                    u8g2.drawTriangle( x0,y0, x1,y1, x2,y2);
                    break;
                case 4:
                    x0 = xb + pgm_read_byte(dataaddr++)*coef; y0 = pgm_read_byte(dataaddr++)/4;
                    x1 = xb + pgm_read_byte(dataaddr++)*coef; y1 = pgm_read_byte(dataaddr++)/4;
                    x2 = xb + pgm_read_byte(dataaddr++)*coef; y2 = pgm_read_byte(dataaddr++)/4;
                    x3 = xb + pgm_read_byte(dataaddr++)*coef; y3 = pgm_read_byte(dataaddr++)/4;

                    /*Serial.print(x0);Serial.print('-');Serial.println(y0);
                    Serial.print(x1);Serial.print('-');Serial.println(y1);
                    Serial.print(x2);Serial.print('-');Serial.println(y2);
                    Serial.print(x3);Serial.print('-');Serial.println(y3);*/
                    drawQuadrangle( x0,y0, x1,y1, x2,y2, x3,y3);
                    break;
            }
        } while (loopPolygons);

}

int getLetterWidth(char letter) {
    uint16_t dataaddr = pgm_read_word(&(font_tbl[(byte)letter]));
    int width=0, x;
    while (true) {
        byte ptype = pgm_read_byte(dataaddr++);
        if (ptype == 0) {
            break;
        }
        for (int p=0;p<ptype;p++) {
            x = pgm_read_byte(dataaddr++); if (x > width) width = x;
            pgm_read_byte(dataaddr++);
        }
    };
    return width;
}


void drawSyllable(char *syllable) {
    char *s = syllable;
    int width = -LSPACE*4;
    do {
        width += getLetterWidth(*s) + LSPACE*4;
    } while (*(++s));
    
    float coef = (width > 512) ? (128.0 / width) : 0.25;
    int xbase = (width < 512) ? (64-width / 8) : 0;
    u8g2.firstPage();
    do 
    {
        s = syllable;
        int x = xbase;
        do {
            drawLetter(*s,x,coef);
            x += (getLetterWidth(*s) + LSPACE*4) * coef;
        } while (*(++s));
    } while (u8g2.nextPage());  
}
