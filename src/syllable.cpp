#include "Arduino.h"
#include "font.hpp"

const char syl_0[] PROGMEM = "��";
const char syl_1[] PROGMEM = "��";
const char syl_2[] PROGMEM = "��";
const char syl_3[] PROGMEM = "���";
const char syl_4[] PROGMEM = "��";
const char syl_5[] PROGMEM = "���";
const char syl_6[] PROGMEM = "���";
const char syl_7[] PROGMEM = "���";
const char syl_8[] PROGMEM = "��";
const char syl_9[] PROGMEM = "��";
const char syl_10[] PROGMEM = "����";
const char syl_11[] PROGMEM = "��";
const char syl_12[] PROGMEM = "��";
const char syl_13[] PROGMEM = "���";
const char syl_14[] PROGMEM = "���";
const char syl_15[] PROGMEM = "��";
const char syl_16[] PROGMEM = "��";
const char syl_17[] PROGMEM = "���";
const char syl_18[] PROGMEM = "��";
const char syl_19[] PROGMEM = "���";
const char syl_20[] PROGMEM = "��";
const char syl_21[] PROGMEM = "��";
const char syl_22[] PROGMEM = "��";
const char syl_23[] PROGMEM = "���";
const char syl_24[] PROGMEM = "��";
const char syl_25[] PROGMEM = "���";
const char syl_26[] PROGMEM = "��";
const char syl_27[] PROGMEM = "��";
const char syl_28[] PROGMEM = "��";
const char syl_29[] PROGMEM = "���";
const char syl_30[] PROGMEM = "��";
const char syl_31[] PROGMEM = "��";
const char syl_32[] PROGMEM = "���";
const char syl_33[] PROGMEM = "���";
const char syl_34[] PROGMEM = "���";
const char syl_35[] PROGMEM = "���";
const char syl_36[] PROGMEM = "���";
const char syl_37[] PROGMEM = "���";
const char syl_38[] PROGMEM = "��";
const char syl_39[] PROGMEM = "��";
const char syl_40[] PROGMEM = "���";
const char syl_41[] PROGMEM = "��";
const char syl_42[] PROGMEM = "��";
const char syl_43[] PROGMEM = "��";
const char syl_44[] PROGMEM = "��";
const char syl_45[] PROGMEM = "��";
const char syl_46[] PROGMEM = "���";
const char syl_47[] PROGMEM = "���";
const char syl_48[] PROGMEM = "����";
const char syl_49[] PROGMEM = "���";
const char syl_50[] PROGMEM = "��";
const char syl_51[] PROGMEM = "��";
const char syl_52[] PROGMEM = "��";
const char syl_53[] PROGMEM = "��";
const char syl_54[] PROGMEM = "��";
const char syl_55[] PROGMEM = "��";
const char syl_56[] PROGMEM = "���";
const char syl_57[] PROGMEM = "��";
const char syl_58[] PROGMEM = "���";
const char syl_59[] PROGMEM = "��";
const char syl_60[] PROGMEM = "���";
const char syl_61[] PROGMEM = "��";
const char syl_62[] PROGMEM = "��";
const char syl_63[] PROGMEM = "���";
const char syl_64[] PROGMEM = "���";
const char syl_65[] PROGMEM = "��";
const char syl_66[] PROGMEM = "��";
const char syl_67[] PROGMEM = "��";
const char syl_68[] PROGMEM = "����";
const char syl_69[] PROGMEM = "���";
const char syl_70[] PROGMEM = "���";
const char syl_71[] PROGMEM = "��";
const char syl_72[] PROGMEM = "��";
const char syl_73[] PROGMEM = "���";
const char syl_74[] PROGMEM = "���";
const char syl_75[] PROGMEM = "���";
const char syl_76[] PROGMEM = "��";
const char syl_77[] PROGMEM = "���";
const char syl_78[] PROGMEM = "��";
const char syl_79[] PROGMEM = "��";
const char syl_80[] PROGMEM = "��";
const char syl_81[] PROGMEM = "��";
const char syl_82[] PROGMEM = "���";
const char syl_83[] PROGMEM = "���";
const char syl_84[] PROGMEM = "��";
const char syl_85[] PROGMEM = "���";
const char syl_86[] PROGMEM = "���";
const char syl_87[] PROGMEM = "��";
const char syl_88[] PROGMEM = "��";
const char syl_89[] PROGMEM = "���";
const char syl_90[] PROGMEM = "���";
const char syl_91[] PROGMEM = "���";
const char syl_92[] PROGMEM = "��";
const char syl_93[] PROGMEM = "��";
const char syl_94[] PROGMEM = "��";
const char syl_95[] PROGMEM = "��";
const char syl_96[] PROGMEM = "���";
const char syl_97[] PROGMEM = "��";
const char syl_98[] PROGMEM = "���";
const char syl_99[] PROGMEM = "��";
const char syl_100[] PROGMEM = "��";
const char syl_101[] PROGMEM = "��";
const char syl_102[] PROGMEM = "��";
const char syl_103[] PROGMEM = "��";
const char syl_104[] PROGMEM = "��";
const char syl_105[] PROGMEM = "��";
const char syl_106[] PROGMEM = "���";
const char syl_107[] PROGMEM = "��";
const char syl_108[] PROGMEM = "���";
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