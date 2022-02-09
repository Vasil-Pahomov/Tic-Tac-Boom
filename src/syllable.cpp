#include "Arduino.h"
#include "font.hpp"

const char syl_0[] PROGMEM = "рю";
const char syl_1[] PROGMEM = "пн";
const char syl_2[] PROGMEM = "юл";
const char syl_3[] PROGMEM = "бед";
const char syl_4[] PROGMEM = "нр";
const char syl_5[] PROGMEM = "мхй";
const char syl_6[] PROGMEM = "люр";
const char syl_7[] PROGMEM = "кнб";
const char syl_8[] PROGMEM = "пс";
const char syl_9[] PROGMEM = "нй";
const char syl_10[] PROGMEM = "ясдю";
const char syl_11[] PROGMEM = "кн";
const char syl_12[] PROGMEM = "юд";
const char syl_13[] PROGMEM = "юмр";
const char syl_14[] PROGMEM = "унд";
const char syl_15[] PROGMEM = "сй";
const char syl_16[] PROGMEM = "гю";
const char syl_17[] PROGMEM = "пег";
const char syl_18[] PROGMEM = "нд";
const char syl_19[] PROGMEM = "рнп";
const char syl_20[] PROGMEM = "хй";
const char syl_21[] PROGMEM = "он";
const char syl_22[] PROGMEM = "цю";
const char syl_23[] PROGMEM = "днй";
const char syl_24[] PROGMEM = "юр";
const char syl_25[] PROGMEM = "бхй";
const char syl_26[] PROGMEM = "яю";
const char syl_27[] PROGMEM = "кю";
const char syl_28[] PROGMEM = "ке";
const char syl_29[] PROGMEM = "юяр";
const char syl_30[] PROGMEM = "юк";
const char syl_31[] PROGMEM = "юй";
const char syl_32[] PROGMEM = "кнл";
const char syl_33[] PROGMEM = "пнц";
const char syl_34[] PROGMEM = "дек";
const char syl_35[] PROGMEM = "рхй";
const char syl_36[] PROGMEM = "янм";
const char syl_37[] PROGMEM = "рек";
const char syl_38[] PROGMEM = "хр";
const char syl_39[] PROGMEM = "юг";
const char syl_40[] PROGMEM = "бей";
const char syl_41[] PROGMEM = "кх";
const char syl_42[] PROGMEM = "йн";
const char syl_43[] PROGMEM = "пю";
const char syl_44[] PROGMEM = "йе";
const char syl_45[] PROGMEM = "вю";
const char syl_46[] PROGMEM = "оюм";
const char syl_47[] PROGMEM = "анк";
const char syl_48[] PROGMEM = "лерп";
const char syl_49[] PROGMEM = "йхм";
const char syl_50[] PROGMEM = "юя";
const char syl_51[] PROGMEM = "сг";
const char syl_52[] PROGMEM = "юп";
const char syl_53[] PROGMEM = "бн";
const char syl_54[] PROGMEM = "йю";
const char syl_55[] PROGMEM = "еб";
const char syl_56[] PROGMEM = "лер";
const char syl_57[] PROGMEM = "нм";
const char syl_58[] PROGMEM = "бнд";
const char syl_59[] PROGMEM = "аю";
const char syl_60[] PROGMEM = "юйр";
const char syl_61[] PROGMEM = "см";
const char syl_62[] PROGMEM = "хк";
const char syl_63[] PROGMEM = "бюп";
const char syl_64[] PROGMEM = "хгл";
const char syl_65[] PROGMEM = "са";
const char syl_66[] PROGMEM = "лю";
const char syl_67[] PROGMEM = "лн";
const char syl_68[] PROGMEM = "кюяр";
const char syl_69[] PROGMEM = "кнц";
const char syl_70[] PROGMEM = "пнл";
const char syl_71[] PROGMEM = "дх";
const char syl_72[] PROGMEM = "бю";
const char syl_73[] PROGMEM = "йно";
const char syl_74[] PROGMEM = "пнд";
const char syl_75[] PROGMEM = "бнг";
const char syl_76[] PROGMEM = "ою";
const char syl_77[] PROGMEM = "пюм";
const char syl_78[] PROGMEM = "ме";
const char syl_79[] PROGMEM = "нп";
const char syl_80[] PROGMEM = "хм";
const char syl_81[] PROGMEM = "ун";
const char syl_82[] PROGMEM = "хмр";
const char syl_83[] PROGMEM = "унг";
const char syl_84[] PROGMEM = "мю";
const char syl_85[] PROGMEM = "леп";
const char syl_86[] PROGMEM = "люя";
const char syl_87[] PROGMEM = "ся";
const char syl_88[] PROGMEM = "фс";
const char syl_89[] PROGMEM = "охр";
const char syl_90[] PROGMEM = "йнк";
const char syl_91[] PROGMEM = "хяр";
const char syl_92[] PROGMEM = "йх";
const char syl_93[] PROGMEM = "ян";
const char syl_94[] PROGMEM = "мх";
const char syl_95[] PROGMEM = "нл";
const char syl_96[] PROGMEM = "тнм";
const char syl_97[] PROGMEM = "рх";
const char syl_98[] PROGMEM = "дхй";
const char syl_99[] PROGMEM = "ре";
const char syl_100[] PROGMEM = "кч";
const char syl_101[] PROGMEM = "бю";
const char syl_102[] PROGMEM = "нб";
const char syl_103[] PROGMEM = "юм";
const char syl_104[] PROGMEM = "рн";
const char syl_105[] PROGMEM = "мн";
const char syl_106[] PROGMEM = "кня";
const char syl_107[] PROGMEM = "лс";
const char syl_108[] PROGMEM = "няр";
const char *const syl_table[] PROGMEM = {syl_0, syl_1, syl_2, syl_3, syl_4, syl_5, syl_6, syl_7, syl_8, syl_9, syl_10, syl_11, syl_12, syl_13, syl_14, syl_15, syl_16, syl_17, syl_18, syl_19, syl_20, syl_21, syl_22, syl_23, syl_24, syl_25, syl_26, syl_27, syl_28, syl_29, syl_30, syl_31, syl_32, syl_33, syl_34, syl_35, syl_36, syl_37, syl_38, syl_39, syl_40, syl_41, syl_42, syl_43, syl_44, syl_45, syl_46, syl_47, syl_48, syl_49, syl_50, syl_51, syl_52, syl_53, syl_54, syl_55, syl_56, syl_57, syl_58, syl_59, syl_60, syl_61, syl_62, syl_63, syl_64, syl_65, syl_66, syl_67, syl_68, syl_69, syl_70, syl_71, syl_72, syl_73, syl_74, syl_75, syl_76, syl_77, syl_78, syl_79, syl_80, syl_81, syl_82, syl_83, syl_84, syl_85, syl_86, syl_87, syl_88, syl_89, syl_90, syl_91, syl_92, syl_93, syl_94, syl_95, syl_96, syl_97, syl_98, syl_99, syl_100, syl_101, syl_102, syl_103, syl_104, syl_105, syl_106, syl_107, syl_108};


void drawRandomSyllable() {
    char buf[10];
    char *cp;
    int sylind = random(sizeof(syl_table)/sizeof(char*));
    switch (random(3)) {
        case 0:
            //ellipsis at the end
            strcpy_P(buf, (char *)pgm_read_word(&(syl_table[sylind])));
            cp = buf + strlen(buf);
            *(cp++) = 32;
            *(cp++) = 0;
            break;
        case 1:
            //ellipsis at the beginning
            buf[0] = 32;
            strcpy_P(buf+1, (char *)pgm_read_word(&(syl_table[sylind])));
            break;
        case 2:
            //ellipsis at the beginning and at the end
            buf[0] = 32;
            strcpy_P(buf+1, (char *)pgm_read_word(&(syl_table[sylind])));
            cp = buf + strlen(buf);
            *(cp++) = 32;
            *(cp++) = 0;
            break;
    }
    drawSyllable(buf);
}