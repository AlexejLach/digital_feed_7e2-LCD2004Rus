                                      // ***** ПАРАМЕТРЫ ЖЕЛЕЗА ***** //
                                  
#define ENC_LINE_PER_REV     1800     // Кол-во линий энкодера на 1 оборот шпинделя 
#define MOTOR_Z_STEP_PER_REV 1200     // Кол-во шагов двигателя на оборот винта Z, продольная
#define SCREW_Z              200      // Шаг продольного винта Z в сотках, 2мм    
#define McSTEP_Z             1        // Микрошаг, ось Z, продольная
#define MOTOR_X_STEP_PER_REV 1000     // Кол-во шагов двигателя на оборот винта X, поперечная
#define SCREW_X              100      // Шаг поперечного винта X в сотках, 1мм
#define REBOUND_X            200      // Отскок резца в микрошагах, для авторезанья, должен быть больше люфта поперечки
#define REBOUND_Z            400      // Отскок резца в микрошагах, для авторезанья, должен быть больше люфта продольки
#define McSTEP_X             1        // Микрошаг, ось X, поперечная
#define THRD_ACCEL           25       // К.деления с которого будем ускоряться на Резьбах, THRD_ACCEL + Ks должен быть < 255
#define FEED_ACCEL           3        // Жесткость разгона на подачах, бОльше значение - короче разгон
#define MIN_FEED             1        // Желаемая минимальная подача  в сотках/оборот, 0.01мм/об
#define MAX_FEED             20       // Желаемая максимальная подача в сотках/оборот, 0.25мм/об
#define MIN_aFEED            10       // Желаемая минимальная подача  в mm/минуту, 10мм/мин
#define MAX_aFEED            400      // Желаемая максимальная подача в mm/минуту, 400мм/мин
#define Excess_Lag           2        // Сколько лишних микрошагов набегает на отскоке оси Х в режиме "ШАР"
#define PASS_FINISH          2        // Количество чистовых проходов, по умолчанию, после автоцикла в режиме "Резьба"                


// Ускоренные перемещения                               
#define MAX_RAPID_MOTION     50                      // Меньше - бОльшая конечная скорость           //6000000/32/((85+1)*2)/400*60=163rpm
#define MIN_RAPID_MOTION    (MAX_RAPID_MOTION + 190) // Больше - мЕньшая начальная скорость, max 255 //6000000/32/((165+85+1)*2)/400*60=56rpm
#define REPEAt              (McSTEP_Z * 1)           // Кол-во повторов для постоянной скорости в пределах полного шага    
                                                     // Длительность разгона = 100/2*REPEAT(2)/Microstep(2) = 50 полных шагов цикл ускорения
// Ручной энкодер (100 линий)
#define HC_SCALE_1           1        // 1-e положение, масштаб = 1сотка/тик = 1мм/оборот
#define HC_SCALE_10          10       // 2-e положение, масштаб = 10соток/тик = 10мм/оборот
#define HC_START_SPEED_1     250      // старт РГИ, 250000/(250+1)/800*60/2 = 37rpm
#define HC_MAX_SPEED_1       150      // максимум скорости РГИ, 250000/(150+1)/800*60/2 = 62rpm
#define HC_START_SPEED_10    150      // старт РГИ, 250000/(150+1)/800*60/2 = 62rpm
#define HC_MAX_SPEED_10      50       // максимум скорости РГИ, 250000/(23+1)/800*60/2 = 391rpm
#define HC_X_DIR             0        // 1-поперечка по часовой, 0-против
#define HC_Z_DIR             1        // 1-продолная по часовой, 0-против

// Настройка линейки
 
#define LIN_X               200       // корректировка изменений масштаба оси X на диаметр
#define BT_X                20        // масштаб 10 = 0.10mm 20 = 0.20mm и т. д., в режиме линейка кнопками влево-вправо

/////////////////////////////////////////////////////////////////////////////////////////////////
// ***** Cone *****
struct cone_info_type
{
  byte Cs_Div;
  int  Cm_Div;
  char Cone_Print[6];
};
const cone_info_type Cone_Info[] =
{
     { 1,  2000, " 45\5" },
     { 46, 1088, " KM0" },
     { 48, 1128, " KM1" },
     { 48,  480, " KM2" },
     { 47, 8128, " KM3" },
     { 46, 2096, " KM4" },
     { 45, 6048, " KM5" },
     { 46,  320, " KM6" },
     { 46, 1088, " B7 "  },  // 1:19,212 ( B - Конус Морзе)
     { 48, 1128, " B10" },  // 1:20,047
     { 48, 1128, " B12" },  // 1:20,047
     { 48,  480, " B16" },  // 1:20,020
     { 48,  480, " B18" },  // 1:20,020
     { 47, 8128, " B22" },  // 1:19,922
     { 47, 8128, " B24" },  // 1:19,922
     { 46, 2096, " B32" },  // 1:19,254
     { 45, 6048, " B45" },  // 1:19,002
     
     {  9,  6000,  " 1:4" },
     {  12,    0,  " 1:5" },
     {  16, 8000,  " 1:7" },
     {  24,    0,  "1:10" },
     {  38, 4000,  "1:16" },
     {  48,    0,  "1:20" },
     {  57, 6000,  "1:24" },
     {  72,    0,  "1:30" },
     { 120,    0,  "1:50" },
     {  21, 9429,  "7:64" },
    
//     { 0, 1050, "85\5" },
//     { 0, 2116, "80\5" },
//     { 0, 3215, "75\5" },
//     { 0, 4368, "70\5" },
//     { 0, 5596, "65\5" },
//     { 0, 6928, "60\5" },
//     { 0, 7210, "59\5" },
//     { 0, 7498, "58\5" },
//     { 0, 7793, "57\5" },
//     { 0, 8094, "56\5" },
//     { 0, 8402, "55\5" },
//     { 0, 8719, "54\5" },
//     { 0, 9043, "53\5" },
//     { 0, 9375, "52\5" },
//     { 0, 9717, "51\5" },
     { 1,   69, " 50\5" }, // \5 - Знак градуса.
     { 1,  431, " 49\5" },
     { 1,  805, " 48\5" },
     { 1, 1190, " 47\5" },
     { 1, 1588, " 46\5" },
     { 1, 2000, " 45\5" },
     { 1, 2426, " 44\5" },
     { 1, 2868, " 43\5" },
     { 1, 3327, " 42\5" },
     { 1, 3804, " 41\5" },
     { 1, 4301, " 40\5" },
     { 1, 4819, " 39\5" },
     { 1, 5359, " 38\5" },
     { 1, 5925, " 37\5" },
     { 1, 6517, " 36\5" },
     { 1, 7138, " 35\5" },
     { 1, 7791, " 34\5" },
     { 1, 8478, " 33\5" },
     { 1, 9204, " 32\5" },
     { 1, 9971, " 31\5" },
     { 2,  785, " 30\5" },
     { 2, 1649, " 29\5" },
     { 2, 2569, " 28\5" },
     { 2, 3551, " 27\5" },
     { 2, 4604, " 26\5" },
     { 2, 5734, " 25\5" },
     { 2, 6952, " 24\5" },
     { 2, 8270, " 23\5" },
     { 2, 9701, " 22\5" },
     { 3, 1261, " 21\5" },
     { 3, 2970, " 20\5" },
     { 3, 4851, " 19\5" },
     { 3, 6932, " 18\5" },
     { 3, 9250, " 17\5" },
     { 4, 1849, " 16\5" },
     { 4, 4785, " 15\5" },
     { 4, 8129, " 14\5" },
     { 5, 1978, " 13\5" },
     { 5, 6456, " 12\5" },
     { 6, 1735, " 11\5" },
     { 6, 8055, " 10\5" },
     { 7, 5765, "  9\5" },
     { 8, 5384, "  8\5" },
     { 9, 7732, "  7\5" },
     { 11, 4172, "  6\5" },
     { 13, 7161, "  5\5" },
     { 17, 1608, "  4\5" },
     { 22, 8974, "  3\5" },
     { 34, 3635, "  2\5" },
     { 68, 7480, "  1\5" },


};
#define TOTAL_CONE (sizeof(Cone_Info) / sizeof(Cone_Info[0]))


// ***** Threads *****
struct thread_info_type
{
  byte Ks_Div_Z;
  int  Km_Div_Z;
  byte Ks_Div_X;
  int  Km_Div_X;
  char Thread_Print[7];
  float Step;
  byte Pass;
  int Limit_Print;     
};
const thread_info_type Thread_Info[] = 
{  
   { 60,    0,  36,    0, "0.10mm", 0.10, 5,  990 },
   { 30,    0,  18,    0, "0.20mm",  0.2, 4,  980 },
   { 24,    0,  14, 4000, "0.25mm", 0.25, 4,  840 },
   { 20,    0,  12,    0, "0.30mm",  0.3, 4,  740 },
   { 17, 1429,  10, 2857, "0.35mm", 0.35, 5,  680 },
   { 15,    0,   9,    0, "0.40mm",  0.4, 5,  640 },
   { 13, 3333,   8,    0, "0.45mm", 0.45, 6,  600 },
   { 12,    0,   7, 2000, "0.50mm",  0.5, 6,  560 },
   { 10,    0,   6,    0, "0.60mm",  0.6, 7,  520 },
   { 8,  5714,   5, 1429, "0.70mm",  0.7, 8,  480 },
   { 8,     0,   4, 8000, "0.75mm", 0.75, 8,  460 },
   { 7,  5000,   4, 5000, "0.80mm",  0.8, 8,  460 },
   { 6,     0,   3, 6000, "1.00mm",    1, 10, 420 },
   { 4,  8000,   2, 8800, "1.25mm", 1.25, 12, 400 },
   { 4,  0,      2, 4000, "1.50mm",  1.5, 14, 380 },
   { 3,  4286,   2,  571, "1.75mm", 1.75, 16, 360 },
   { 3,     0,   1, 8000, "2.00mm",    2, 18,  80 },
   { 2,  4000,   1, 4400, "2.50mm",  2.5, 22,  80 },
   { 2,     0,   1, 2000, "3.00mm",    3, 26,  80 },
   { 1,  5000,   0, 9000, "4.00mm",    4, 34,  80 },
   { 1,  2000,   0, 7200, "5.00mm",    4, 34,  80 },
   { 1,     0,   0, 6000, "6.00mm",    4, 34,  80 },
// дюймовая
   { 18, 8976, 11, 3386, "80tpi ", 0.318, 5,  720 },
   { 17,   79, 10, 2047, "72tpi ", 0.353, 5,  680 },
   { 15, 1181,  9,  709, "64tpi ", 0.397, 5,  640 },
   { 14, 1732,  8, 5039, "60tpi ", 0.423, 5,  620 },
   { 13, 2283,  7, 9370, "56tpi ", 0.454, 6,  580 },
   { 11, 3386,  6, 8031, "48tpi ", 0.529, 6,  540 },
   { 10, 3937,  6, 2362, "44tpi ", 0.577, 7,  520 },
   { 9,  4488,  5, 6693, "40tpi ", 0.635, 7,  500 },
   { 8,  5039,  5, 1024, "36tpi ", 0.706, 8,  480 },
   { 7,  5591,  4, 5354, "32tpi ", 0.794, 8,  460 },
   { 6,  6142,  3, 9685, "28tpi ", 0.907, 9,  440 },
   { 6,  3780,  3, 8268, "27tpi ", 0.941, 10, 420 },
   { 6,  1417,  3, 6850, "26tpi ", 0.977, 10, 420 },
   { 5,  6693,  3, 4016, "24tpi ", 1.058, 10, 420 },
   { 5,  1969,  3, 1181, "22tpi ", 1.155, 11, 400 },
   { 4,  7244,  2, 8346, "20tpi ",  1.27, 12, 400 },
   { 4,  4882,  2, 6929, "19tpi ", 1.337, 13, 380 },
   { 4,  2520,  2, 5512, "18tpi ", 1.411, 13, 380 },
   { 3,  7795,  2, 2677, "16tpi ", 1.588, 15, 360 },
   { 3,  3071,  1, 9843, "14tpi ", 1.814, 17, 220 },
   { 3,   709,  1, 8425, "13tpi ", 1.954, 18, 200 },
   { 2,  8346,  1, 7008, "12tpi ", 2.117, 19, 180 },
   { 2,  5984,  1, 5591, "11tpi ", 2.309, 20, 160 },
   { 2,  3622,  1, 4173, "10tpi ",  2.54, 22, 120 },
   { 2,  1260,  1, 2756, " 9tpi ", 2.822, 25, 100 },
   { 1,  8898,  1, 1339, " 8tpi ", 3.175, 27,  80 },
   { 1,  6535,  0, 9921, " 7tpi ", 3.629, 31,  80 }, 
   { 1,  4173,  0, 8504, " 6tpi ", 4.233, 36,  80 }, 

 
    
  // Трубная
   {  6, 3780,    3, 8268,   "T 1/16", 0.941,  20,  420 },  // 27   tpi // резьба на трубах
   {  6, 3780,    3, 8268,   "T 1/8 ", 0.941,  20,  420 },  // 27   tpi             
   {  4, 2520,    2, 5512,   "T 1/4 ", 1.411,  29,  750 },  // 18   tpi             
   {  4, 2520,    2, 5512,   "T 3/8 ", 1.411,  29,  750 },  // 18   tpi              
   {  3, 3071,    1, 9843,   "T 1/2 ", 1.814,  36,  230 },  // 14   tpi             
   {  3, 3071,    1, 9843,   "T 3/4 ", 1.814,  36,  230 },  // 14   tpi                 
   {  2, 7165,    1, 6299,   "T 1   ", 2.209,  44,  160 },  // 11,5 tpi                  
   {  2, 7165,    1, 6299,   "T1 1/4", 2.209,  44,  160 },  // 11,5 tpi              
   {  2, 7165,    1, 6299,   "T1 1/2", 2.209,  44,  160 },  // 11,5 tpi           
   {  2, 7165,    1, 6299,   "T 2   ", 2.209,  44,  160 },  // 11,5 tpi               
   
             
   
};
#define TOTAL_THREADS (sizeof(Thread_Info) / sizeof(Thread_Info[0]))


#define Thrd_Accel_Err Thread_Info[0].Ks_Div_Z                 // неверно задано ускорение
//static_assert(Thrd_Accel_Err + THRD_ACCEL <= 255, "Неверно задано значение THRD_ACCEL");
//////////////////////////////////////////////////////////////////////////////////////////////////

#define a  (uint32_t)(ENC_LINE_PER_REV / ((float)MOTOR_Z_STEP_PER_REV * McSTEP_Z * MIN_FEED / SCREW_Z) /2)
static_assert(a <= 255, "Неверно задано значение MIN_FEED");
#define b  (uint32_t)(ENC_LINE_PER_REV / ((float)MOTOR_Z_STEP_PER_REV * McSTEP_Z * MAX_FEED / SCREW_Z) /2)
static_assert(b > 1, "Неверно задано значение MAX_FEED");
#define c  250000 / ((uint32_t)MIN_aFEED * MOTOR_Z_STEP_PER_REV * McSTEP_Z / ((uint32_t)60 * SCREW_Z / 100) * 2) -1
static_assert(c <= 65535, "Неверно задано значение MIN_aFEED");
#define d  250000 / ((uint32_t)MAX_aFEED * MOTOR_Z_STEP_PER_REV * McSTEP_Z / ((uint32_t)60 * SCREW_Z / 100) * 2) -1
static_assert(d > 1, "Неверно задано значение MAX_aFEED");

#define e  (uint32_t)(ENC_LINE_PER_REV / ((float)MOTOR_X_STEP_PER_REV * McSTEP_X * MIN_FEED / SCREW_X) /2)
static_assert(e <= 255, "Неверно задано значение MIN_FEED");
#define f  (uint32_t)(ENC_LINE_PER_REV / ((float)MOTOR_X_STEP_PER_REV * McSTEP_X * MAX_FEED / SCREW_X) /2)
static_assert(f > 1, "Неверно задано значение MAX_FEED");
#define g  250000 / ((uint32_t)MIN_aFEED * MOTOR_X_STEP_PER_REV * McSTEP_X / ((uint32_t)60 * SCREW_X / 100) * 2) -1
static_assert(g <= 65535, "Неверно задано значение MIN_aFEED");
#define h  250000 / ((uint32_t)MAX_aFEED * MOTOR_X_STEP_PER_REV * McSTEP_X / ((uint32_t)60 * SCREW_X / 100) * 2) -1
static_assert(h > 1, "Неверно задано значение MAX_aFEED");
//////////////////////////////////////////////////////////


// ***** MY CONSTANT *****
#define CW               0
#define CCW              1
#define ON               1
#define OFF              0

#include <avr/pgmspace.h>
#include <util/delay.h>
#include "LiquidCrystalRus.h"
LiquidCrystalRus lcd(8, 9, 10, 11, 12, 13);
char LCD_Row_1[21];
char LCD_Row_2[21];
char LCD_Row_3[21];
char LCD_Row_4[21];
char LCD_Row_5[21];
char LCD_Row_6[21];
char LCD_Row_7[21];
byte strelka_vlevo[8] = 
{
  B00000,
  B00100,
  B01000,
  B11111,
  B01000,
  B00100,
  B00000,
  B00000,
};
byte strelka_vpravo[8] = 
{
  0b00000,
  0b00100,
  0b00010,
  0b11111,
  0b00010,
  0b00100,
  0b00000,
  0b00000
};
byte strelka_vverh[8] = 
{
  B00000,
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00000,
  B00000,
};
byte strelka_vniz[8] = 
{
  B00000,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100,
  B00000,
  B00000,
};
byte znak_diametr[8] = 
{
  0b00001,
  0b01110,
  0b10011,
  0b10101,
  0b11001,
  0b01110,
  0b10000,
  0b00000
};
byte znak_gradus[8] = 
{
  0b01100,
  0b10010,
  0b10010,
  0b01100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte znak_radius[8] = 
{
  B00000,
  B11110,
  B10010,
  B11110,
  B11000,
  B10100,
  B10010,
  B00000
};


#define Beeper_Init()          DDRH = B01100010;\
                               PORTH = B10011101    // LCD-H5,H6 Buzzer-PH1_Pin16
#define Beeper_On()            PORTH &= ~(1<<1)     // Pin16 0
#define Beeper_Off()           PORTH |= (1<<1)      // Pin16 1



// ***** Stepper Motor *****
#define Motor_Init()           DDRL = B11111011;\
                               PORTL = B0000100

#define Motor_Z_SetPulse()     PORTL &= ~(1<<0)     // Pin49 0
#define Motor_Z_RemovePulse()  PORTL |= (1<<0)      // Pin49 1
#define Motor_Z_InvertPulse()  PORTL ^= (1<<0)      // Pin49
#define Read_Z_State           (PINL & (1<<0))

#define Motor_X_SetPulse()     PORTL &= ~(1<<1)     // Pin48 0
#define Motor_X_RemovePulse()  PORTL |= (1<<1)      // Pin48 1
#define Motor_X_InvertPulse()  PORTL ^= (1<<1)      // Pin48
#define Read_X_State           (PINL & (1<<1))

#define Motor_Z_CW()           PORTL &= ~(1<<6)    // Pin43 0
#define Motor_Z_CCW()          PORTL |= (1<<6)     // Pin43 1

#define Motor_X_CW()           PORTL &= ~(1<<5)    // Pin44 0
#define Motor_X_CCW()          PORTL |= (1<<5)     // Pin44 1

#define Motor_Z_Enable()   do {PORTL |= (1<<4); _delay_ms(100);} while(0)   // Pin45 1
#define Motor_Z_Disable()     {PORTL &= ~(1<<4); _delay_ms(100);}                            // Pin45 0
#define Read_Z_Ena_State      (PINL & (1<<4))

#define Motor_X_Enable()   do {PORTL |= (1<<3); _delay_ms(100);} while(0)   // Pin46 1
#define Motor_X_Disable()     {PORTL &= ~(1<<3); _delay_ms(100);}                           // Pin46 0
#define Read_X_Ena_State       (PINL & (1<<3))


// ***** Tacho *****
#define TachoSetPulse()        PORTL |= (1<<7)      // Pin42 1
#define TachoRemovePulse()     PORTL &= ~(1<<7)     // Pin42 0


// ***** Encoder *****
#define ENC_TICK              (ENC_LINE_PER_REV * 2)    // Рабочее кол-во импульсов
#define Encoder_Init()         DDRD = B00000000;\
                               PORTD = B11111111        // подтяжка PIN_21, 20, 19, 18
#define Enc_Read              (PIND & (1<<1))
#define Enc_Ch_A              (PIND & (1<<0))
#define Enc_Ch_B              (PIND & (1<<1))
 


// ***** Hand_Coder *****            // Z/X: Input-E4,E5, подтяжка-E4,E5, X1/X10: Input-J0,J1, подтяжка-J0,J1.
#define Hand_Init()            DDRE = B00000000;\
                               PORTE = B11111111;\
                               DDRJ = B00000000;\
                               PORTJ = B11111111
                                     
#define Hand_Ch_A             (PIND & (1<<2))
#define Hand_Ch_B             (PIND & (1<<3))

#define Hand_Axis_Read        (PINE & B00110000)       // E4,E5
byte Hand_Axis_Old = 0;

#define Hand_Scale_Read        (PINJ & B00000011)      // J0,J1
byte Hand_Scale_Old = 0;

//***** Limit Buttons & LEDs *****
#define Limit_Init()           DDRA = B10101010;\
                               PORTA = B01010101    // IN-A0,A2,A4,A6, OUT-A1,A3,A5,A7, подтяжка

#define Limit_Buttons_Read    (PINA & B01010101)    // PA0 Pin22, PA2 Pin24, PA4 Pin26, PA6 Pin28.
byte Limit_Button_Old = 0;

#define Limit_Rear_LED_On()    PORTA &= ~(1<<1)     // PA1, Pin23 0
#define Limit_Rear_LED_Off()   PORTA |= (1<<1)      // PA1, Pin23 1
#define Limit_Front_LED_On()   PORTA &= ~(1<<3)     // PA3, Pin25 0
#define Limit_Front_LED_Off()  PORTA |= (1<<3)      // PA3, Pin25 1
#define Limit_Right_LED_On()   PORTA &= ~(1<<5)     // PA5, Pin27 0
#define Limit_Right_LED_Off()  PORTA |= (1<<5)      // PA5, Pin27 1
#define Limit_Left_LED_On()    PORTA &= ~(1<<7)     // PA7, Pin29 0
#define Limit_Left_LED_Off()   PORTA |= (1<<7)      // PA7, Pin29 1

#define Limit_Pos_Max          2147483648
#define Limit_Pos_Min         -2147483648


//////////////////
#define Menu_Buttons_Init()    DDRF = B00000000;\
                               PORTF = B11111111;     

#define Buttons_Read           (PINF & B00001111)    // Pin_A0 PF0, Pin_A1 PF1, Pin_A2 PF2, Pin_A3 PF3, Pin_A4 PF4.
byte Button_Old = 0;

#define Button_Sel_Read        (PINF & B00010000)    // Pin_A4 PF4
byte Button_Sel_Old = 0;
bool key_sel_flag = false;

//////////////////
#define Joy_Init()             DDRK = B00000000;\
                               PORTK = B11111111;    // подтяжка PIN_A8, A9, A10, A11, A12 // Submode Sw: A13, A14, A15

#define Joy_Read              (PINK & B00001111)     // PK0 PK1 PK2 PK3
#define Button_Rapid          (PINK & B00010000)     // PK4
byte Joy_Old = 0;

////////////////////
#define Submode_Read          (PINK & B11100000)     // PK5 PK6 PK7
byte Submode_Old = 0;


// ***** Mode *****
#define Mode_Switch_Init()     DDRC = B00000000;\
                               PORTC = B11111111;        // подтяжка PORT_A, ОБЯЗАТЕЛЬНА! внешняя подтяжка к +5 через 1К резисторы
#define Mode_Read             (PINC & B11111111)
byte Mode_Old = 0;

#define DELAY_ENTER_KEYCYCLE 2        // Задержка для входа в режим автонажатия кнопок меню. Значения от 1 до разумного максимума
#define DELAY_INTO_KEYCYCLE  0        // Интервал срабатывания автонажатия кнопок меню.      Значения от 1 до DELAY_ENTER_KEYCYCLE
#define LINEIKA (MOTOR_X_STEP_PER_REV * McSTEP_X / LIN_X )  ///    / (SCREW_X / 100)) 

enum Mode
{
  Mode_Feed = 1,
  Mode_aFeed,
  Mode_Thread,
  Mode_Cone_L,
  Mode_Cone_R,
  Mode_Sphere,
  Mode_Divider,
  Mode_Reserve
};

enum Sub_Mode_Thread
{
  Sub_Mode_Thread_Int = 1,
  Sub_Mode_Thread_Man,
  Sub_Mode_Thread_Ext,
};

enum Sub_Mode_Feed
{
  Sub_Mode_Feed_Int = 1,
  Sub_Mode_Feed_Man,
  Sub_Mode_Feed_Ext,
};

enum Sub_Mode_aFeed
{
  Sub_Mode_aFeed_Int = 1,
  Sub_Mode_aFeed_Man,
  Sub_Mode_aFeed_Ext,
};

enum Sub_Mode_Cone
{
  Sub_Mode_Cone_Int = 1,
  Sub_Mode_Cone_Man,
  Sub_Mode_Cone_Ext,
};

enum Sub_Mode_Sphere
{
  Sub_Mode_Sphere_Int = 1,
  Sub_Mode_Sphere_Man,
  Sub_Mode_Sphere_Ext,
};


//***** Ускоренное перемещение *****
#define Timer2_Init()          TCCR2A = (1<<WGM21);\
                               TCCR2B = (1<<CS20)|(1<<CS21); // 16MHz/32 = 500kHz

//***** РГИ перемещение *****
#define Timer3_Init()          TCCR3A = 0;\
                               TCCR3B = (1<<WGM32)|(1<<CS30)|(1<<CS31); // 16MHz/32 = 250kHz

// ***** aFeed *****
#define Timer4_Init()          TCCR4A = 0;\
                               TCCR4B = (1<<WGM42)|(1<<CS40)|(1<<CS41); // 16MHz/32 = 250kHz

// ***** Feed *****
#define Timer5_Init()          TCCR5A = 0;\
                               TCCR5B = (1<<WGM52) | (1<<CS52) | (1<<CS51) | (1<<CS50)

// ***** Interrupts *****
#define INT0_Init()               EICRA |= (1<<ISC00)
#define INT2_Init()               EICRA |= (1<<ISC20)

#define Enable_INT0()             EIMSK |= (1<<INT0)
#define Disable_INT0()            EIMSK &= ~(1<<INT0)

#define Ena_INT_Hcoder()      do {EIFR = (1<<INTF2); EIMSK |= (1<<INT2);} while(0)
#define Disa_INT_Hcoder()         EIMSK &= ~(1<<INT2)

#define Enable_INT_OCR2A()    do {TCNT2 = 0; TIFR2 = (1<<OCF2A); TIMSK2 = (1<<OCIE2A);} while(0)
#define Disable_INT_OCR2A()       TIMSK2 &= ~(1<<OCIE2A)

#define Enable_INT_OCR2B()    do {TCNT2 = 0; TIFR2 = (1<<OCF2B); TIMSK2 = (1<<OCIE2B);} while(0)
#define Disable_INT_OCR2B()       TIMSK2 &= ~(1<<OCIE2B)

#define Enable_INT_OCR3A()    do {TCNT3 = 0; TIFR3 = (1<<OCF3A); TIMSK3 = (1<<OCIE3A);} while(0)
#define Disable_INT_OCR3A()       TIMSK3 &= ~(1<<OCIE3A)

#define Enable_INT_OCR3B()    do {TCNT3 = 0; TIFR3 = (1<<OCF3B); TIMSK3 = (1<<OCIE3B);} while(0)
#define Disable_INT_OCR3B()       TIMSK3 &= ~(1<<OCIE3B)

#define Enable_INT_OCR4A()    do {TCNT4 = 0; TIFR4 = (1<<OCF4A); TIMSK4 = (1<<OCIE4A);} while(0)
#define Disable_INT_OCR4A()       TIMSK4 &= ~(1<<OCIE4A)

#define Enable_INT_OCR4B()    do {TCNT4 = 0; TIFR4 = (1<<OCF4B); TIMSK4 = (1<<OCIE4B);} while(0)
#define Disable_INT_OCR4B()       TIMSK4 &= ~(1<<OCIE4B)

#define Enable_INT_OCR5A()    do {TCNT5 = 0; TIFR5 = (1<<OCF5A); TIMSK5 = (1<<OCIE5A);} while(0)
#define Disable_INT_OCR5A()       TIMSK5 &= ~(1<<OCIE5A)

#define Enable_INT_OCR5B()    do {TCNT5 = 0; TIFR5 = (1<<OCF5B); TIMSK5 = (1<<OCIE5B);} while(0)
#define Disable_INT_OCR5B()       TIMSK5 &= ~(1<<OCIE5B)

////////////////////////////////////////////////////////////
#define Ena_INT_Thrd()        do {Disable_INT_OCR2A();\
                                  Disable_INT_OCR2B();\
                                  Disable_INT_OCR4A();\
                                  Disable_INT_OCR4B();\
                                  Disable_INT_OCR5A();\
                                  Disable_INT_OCR5B();\
                                  Enable_INT0();} while(0)

#define Ena_INT_Z_Feed()      do {Disable_INT0();\
                                  Disable_INT_OCR2A();\
                                  Disable_INT_OCR2B();\
                                  Disable_INT_OCR4A();\
                                  Disable_INT_OCR4B();\
                                  Disable_INT_OCR5B();\
                                  Enable_INT_OCR5A();} while(0)
                                  
#define Ena_INT_X_Feed()      do {Disable_INT0();\
                                  Disable_INT_OCR2A();\
                                  Disable_INT_OCR2B();\
                                  Disable_INT_OCR4A();\
                                  Disable_INT_OCR4B();\
                                  Disable_INT_OCR5A();\
                                  Enable_INT_OCR5B();} while(0)

#define Ena_INT_Z_aFeed()     do {Disable_INT0();\
                                  Disable_INT_OCR2A();\
                                  Disable_INT_OCR2B();\
                                  Disable_INT_OCR4B();\
                                  Disable_INT_OCR5A();\
                                  Disable_INT_OCR5B();\
                                  Enable_INT_OCR4A();} while(0)

#define Ena_INT_X_aFeed()     do {Disable_INT0();\
                                  Disable_INT_OCR2A();\
                                  Disable_INT_OCR2B();\
                                  Disable_INT_OCR4A();\
                                  Disable_INT_OCR5A();\
                                  Disable_INT_OCR5B();\
                                  Enable_INT_OCR4B();} while(0)
                                     
#define Ena_INT_Z_Rapid()     do {Disable_INT0();\
                                  Disable_INT_OCR2B();\
                                  Disable_INT_OCR4A();\
                                  Disable_INT_OCR4B();\
                                  Disable_INT_OCR5A();\
                                  Disable_INT_OCR5B();\
                                  Enable_INT_OCR2A();} while(0)
                                     
#define Ena_INT_X_Rapid()     do {Disable_INT0();\
                                  Disable_INT_OCR2A();\
                                  Disable_INT_OCR4A();\
                                  Disable_INT_OCR4B();\
                                  Disable_INT_OCR5A();\
                                  Disable_INT_OCR5B();\
                                  Enable_INT_OCR2B();} while(0)
                                                                       

// ***** My Flags *****
typedef struct
{ 
   uint8_t bit0 : 1;
   uint8_t bit1 : 1;
   uint8_t bit2 : 1;
   uint8_t bit3 : 1;
   uint8_t bit4 : 1;
   uint8_t bit5 : 1;
   uint8_t bit6 : 1;
   uint8_t bit7 : 1;
}FLAG;
#define Spindle_Dir        ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit0    // CW-0, CCW-1
#define Motor_Z_Dir        ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit1    // CW-0, CCW-1
#define Joy_Z_flag         ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit2    // On-1, Off-0
#define Step_Z_flag        ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit3    // On-1, Off-0
#define Motor_X_Dir        ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit4    // CW-0, CCW-1
#define Joy_X_flag         ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit5    // On-1, Off-0
#define Step_X_flag        ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit6    // On-1, Off-0
#define Cone_flag          ((volatile FLAG*)_SFR_MEM_ADDR(GPIOR0))->bit7    // On-1, Off-0

bool spindle_flag = OFF;
bool feed_Z_flag = OFF;
bool feed_X_flag = OFF;

bool rapid_step_Z_flag = OFF;
bool rapid_step_X_flag = OFF;
bool rapid_Z_flag = OFF;
bool rapid_X_flag = OFF;

bool limit_Left_flag = OFF;
bool limit_Right_flag = OFF;
bool limit_Front_flag = OFF;
bool limit_Rear_flag = OFF;

bool limit_button_flag = OFF;
bool button_up_flag = OFF;
bool button_down_flag = OFF;
bool button_left_flag = OFF;
bool button_right_flag = OFF;

bool a_flag = false;
bool b_flag = false;
bool c_flag = false;
bool d_flag = false;
bool cycle_flag = false;

bool err_1_flag = false;
bool err_2_flag = false;
bool Complete_flag = false;
bool Ruler_flag = false;

bool hand_X = OFF;
bool hand_Z = OFF;
bool flag_hand_X = OFF;
bool flag_hand_Z = OFF;
bool X_flag = OFF;                    // временный
bool Z_flag = OFF;                    // временный
bool flag_Scale_x1 = OFF;             // возможно только для отладки
bool flag_Scale_x10 = OFF;            // возможно только для отладки
bool control_flag = OFF;
bool flag_j = OFF;

// ***** MY VARIABLES *****
int Tacho_Count = 0;
int Tacho_Count_Old =0;
int Spindle_Count = 0;
long Motor_Z_Pos = 0;
long Motor_X_Pos = 0;

int pin = 20;
unsigned long Timeout = 72000;
unsigned long timer;
byte KeyCycle = 0;
int Otskok_Z = REBOUND_Z;
int Step = 0;
int McStep_Lag = 0; 
int Pass_Fin = 0;
int Thr_Pass_Summ = 0;
int SelectMenu = 1;
unsigned long Infeed_ValueX = 0;
unsigned long Infeed_ValueZ = 0;
long Size_X_mm = 0;
long MSize_X_mm = 0;
long Size_Z_mm = 0;
long Otkat_Z_mm = 0;
long X_pos = 0;
long MX_pos = 0;
long Z_pos = 0; 
unsigned long RPM = 0;
unsigned long Freq = 0;
unsigned long Spindle_Angle = 0;
unsigned long Required_Angle = 0;
int Speed_Limit = 0;
unsigned long Infeed_Value = 0;

int Enc_Pos = 0;
volatile long Hand_Count = 0;
long Hand_Count_Old = 0;
long Hand_Count_New = 0;
long Hand_Z_Pos = 0;
long Hand_X_Pos = 0;

byte Scale = HC_SCALE_1;

int Ks_Count = 0;
int Km_Count = 0;
int Ks_Divisor = 0;
int tmp_Ks_Divisor = THRD_ACCEL;
int Km_Divisor = 0;
uint16_t Feed_Divisor = 0;
uint16_t aFeed_Divisor = 0;

int Cs_Count = 0;
int Cm_Count = 0;
int Cs_Divisor = 0;
int Cm_Divisor = 0;

byte tmp_Accel = THRD_ACCEL;
byte Repeat_Count = 0;

int Brake_Compens = 0;

byte Mode = Mode_Feed;
byte Sub_Mode_Thread = Sub_Mode_Thread_Man;
byte Sub_Mode_Feed = Sub_Mode_Feed_Man;
byte Sub_Mode_aFeed = Sub_Mode_aFeed_Man;
byte Sub_Mode_Cone = Sub_Mode_Cone_Man;
byte Sub_Mode_Sphere = Sub_Mode_Sphere_Man;
byte Thread_Step = 0;
byte Cone_Step = 0;

long Limit_Pos_Left = Limit_Pos_Max;
long Limit_Pos_Right = Limit_Pos_Min;
long Limit_Pos_Front = Limit_Pos_Max;
long Limit_Pos_Rear = Limit_Pos_Min;
volatile long Limit_Pos = 0;
volatile long Limit_Pos_HC = 0;

uint16_t Feed_mm = 0;
uint16_t aFeed_mm = 0;

uint16_t Start_Speed = ENC_LINE_PER_REV / ((uint32_t)MOTOR_Z_STEP_PER_REV * McSTEP_Z * MIN_FEED / SCREW_Z) /FEED_ACCEL;
uint16_t max_OCR5A = ENC_LINE_PER_REV / ((uint32_t)MOTOR_Z_STEP_PER_REV * McSTEP_Z * MIN_FEED / SCREW_Z) /FEED_ACCEL;                                                                                     // Начальная скорость подачи при разгоне/торможении
uint16_t max_OCR4A = (250000 / ((uint32_t)MIN_aFEED * MOTOR_Z_STEP_PER_REV * McSTEP_Z / ((uint32_t)60 * SCREW_Z / 100) * 2) - 1) /FEED_ACCEL;

byte Total_Tooth = 1;
byte Current_Tooth = 1;

long Pass_Total = 1;
long Pass_Nr = 1;
long Null_X_Pos = 0;
long Null_Z_Pos = 0;
int Ap = 0;
long Pass_Total_Sphr = 1;

int ADC_Feed = 0;
long Sum_ADC = 0;
int ADC_Array[16];
byte x = 0;

long Control_Count = 0;


// Sphere

const int Cutter_Width_array[] = {100, 125, 150, 175, 200, 225, 250, 275, 300};
#define TOTAL_CUTTER_WIDTH (sizeof(Cutter_Width_array) / sizeof(Cutter_Width_array[0]))
byte Cutter_Step = 4;
int Cutter_Width = Cutter_Width_array[Cutter_Step];

const int Cutting_Width_array[] = {10, 25, 50, 75, 100, 125, 150, 175, 200};
#define TOTAL_CUTTING_STEP (sizeof(Cutting_Width_array) / sizeof(Cutting_Width_array[0]))
byte Cutting_Step = 2;
int Cutting_Width = Cutting_Width_array[Cutting_Step];

long Sph_R_mm = 1000;
long Sph_R = 0;
long Bar_R_mm = 0;
long Bar_R = 0;
long SphBar = 0;

#define KEYB_TIMER_FLAG       (TIFR1 & (1<<OCF1A))
#define CLEAR_KEYB_TIMER   do {TCNT1 = 0; (TIFR1 |= (1<<OCF1A));} while(0)

uint16_t max_OCR3A = HC_START_SPEED_1;
uint16_t min_OCR3A = HC_MAX_SPEED_1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{ 
  _delay_ms(500);
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print("      А.Л   stiz    ");
  lcd.setCursor(0, 1);
  lcd.print(" Система управления ");
  lcd.setCursor(0, 2);
  lcd.print("  Токарным Станком  ");
  lcd.setCursor(0, 3);
  lcd.print("            7e2 v2.2");
  
  
  DDRG = B11111111;

  
  lcd.createChar(1, strelka_vlevo);
  lcd.createChar(2, strelka_vpravo);
  lcd.createChar(3, strelka_vverh);
  lcd.createChar(4, strelka_vniz);
  lcd.createChar(5, znak_gradus);
  lcd.createChar(6, znak_diametr);
  lcd.createChar(7, znak_radius);
            
  
  TIMSK0 = 0;
     
  // ***** Timer0 ***** // ***** Тахометр *****
//  TCCR0A = (1<<COM0B0)|(1<<WGM01); // Toggle OC0B on Compare Match // CTC Mode2
//  TCCR0B = (1<<CS00);     // No Prescaler
//  OCR0A = 89; // 1800/10(выходных пульсов)/2-1 = 89
//  TIMSK0 = (1<<OCIE0B);
    
  Encoder_Init();
  Hand_Init();
  Motor_Init();
  
  INT0_Init();
  INT2_Init();

  Timer2_Init();
  OCR2A = MIN_RAPID_MOTION;

  Timer3_Init();
  OCR3A = max_OCR3A;

  Timer4_Init();
  OCR4A = max_OCR4A;
  
  Timer5_Init();
  OCR5A = max_OCR5A;
  
  Ena_INT_Z_Feed();
  
  Limit_Init();

  Limit_Rear_LED_Off();
  Limit_Right_LED_Off();
  Limit_Front_LED_Off();
  Limit_Left_LED_Off();  
  
  Limit_Left_LED_On();
  Limit_Rear_LED_Off();
  _delay_ms(100);
  Limit_Front_LED_On();
  Limit_Left_LED_Off();
  _delay_ms(100);
  Limit_Right_LED_On();
  Limit_Front_LED_Off();
  _delay_ms(100);  
  Limit_Rear_LED_On();
  Limit_Right_LED_Off();
  _delay_ms(100);
  Limit_Left_LED_On();
  Limit_Rear_LED_Off();
  _delay_ms(100);
  Limit_Front_LED_On();
  Limit_Left_LED_Off();
  _delay_ms(100);
  Limit_Right_LED_On();
  Limit_Front_LED_Off();
  _delay_ms(100);  
  Limit_Rear_LED_On();
  Limit_Right_LED_Off();
  _delay_ms(100);
  Limit_Left_LED_On();
  Limit_Rear_LED_Off();
  _delay_ms(100);
  Limit_Front_LED_On();
  Limit_Left_LED_Off();
  _delay_ms(100);
  Limit_Right_LED_On();
  Limit_Front_LED_Off();
  _delay_ms(100);  
  Limit_Rear_LED_On();
  Limit_Right_LED_Off();
  _delay_ms(100);
   Limit_Left_LED_On();
  Limit_Rear_LED_Off();
  _delay_ms(100);
  Limit_Front_LED_On();
  Limit_Left_LED_Off();
  _delay_ms(100);
  Limit_Right_LED_On();
  Limit_Front_LED_Off();
  _delay_ms(100);  
  Limit_Rear_LED_On();
  Limit_Right_LED_Off();
  _delay_ms(100);
  Limit_Left_LED_On();
  Limit_Rear_LED_Off();
  _delay_ms(100);
  Limit_Front_LED_On();
  Limit_Left_LED_Off();
  _delay_ms(100);
  Limit_Right_LED_On();
  Limit_Front_LED_Off();
  _delay_ms(100);  
  Limit_Rear_LED_On();
  Limit_Right_LED_Off();
  _delay_ms(100);
  Limit_Left_LED_On();
  Limit_Rear_LED_Off();
  _delay_ms(100);
  Limit_Front_LED_On();
  Limit_Left_LED_Off();
  _delay_ms(100);
  Limit_Right_LED_On();
  Limit_Front_LED_Off();
  _delay_ms(100);  
  Limit_Rear_LED_On();
  Limit_Right_LED_Off();
  _delay_ms(100);
  
  Limit_Rear_LED_Off();
  Limit_Right_LED_Off();
  Limit_Front_LED_Off();
  Limit_Left_LED_Off();
  
  Menu_Buttons_Init();
  Joy_Init();
  Mode_Switch_Init();

  Beeper_Init();
  Beeper_Off();
  
  Spindle_Dir = CW;
  Motor_Z_Dir = CW;
  Joy_Z_flag = OFF;
  Step_Z_flag = OFF;
  Motor_X_Dir = CW;
  Joy_X_flag = OFF;
  Step_X_flag = OFF;

  TCCR1A = 0;
  TCCR1B = 0
         |(0<<ICNC1)|(0<<ICES1)
         |(0<<WGM13)|(1<<WGM12)
         |(1<<CS12)|(0<<CS11)|(1<<CS10);
  OCR1A = 625;

  Motor_Z_RemovePulse();
  Motor_X_RemovePulse();
  pinMode(53, OUTPUT);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  Spindle();
  
  MSize_X_mm = MX_pos / ((float)MOTOR_X_STEP_PER_REV / SCREW_X / 2 * McSTEP_X);
  Size_X_mm = X_pos / ((float)MOTOR_X_STEP_PER_REV / SCREW_X * McSTEP_X);
  Size_Z_mm = Z_pos / ((float)MOTOR_Z_STEP_PER_REV / SCREW_Z * McSTEP_Z);
  Otkat_Z_mm = Otskok_Z / ((float)MOTOR_Z_STEP_PER_REV / SCREW_Z * McSTEP_Z);
  Spindle_Angle = Enc_Pos * 360000 / ENC_TICK;
  Required_Angle = 360000 * (Current_Tooth - 1) / Total_Tooth; 

   
  if (SelectMenu == 1) Read_ADC_Feed();
  if (KEYB_TIMER_FLAG != 0) Menu();
  if (Mode == Mode_Divider) Print();
  if (Mode == Mode_aFeed && SelectMenu == 2 || Mode == Mode_Divider)
      { 
        Print();
        digitalWrite(53, LOW); // Если выключена делилика, то на 53 выводе +5в // HIGH - +5в, LOW - 0/
      }
  else digitalWrite(53, HIGH);

   if ((Mode == Mode_Feed      && SelectMenu == 2) || 
       (Mode == Mode_Cone_L    && SelectMenu == 3) ||
       (Mode == Mode_Cone_R    && SelectMenu == 3) || 
       (Mode == Mode_aFeed     && SelectMenu == 3) || 
       (Mode == Mode_Sphere    && SelectMenu == 3) ||
       (Mode == Mode_Thread    && SelectMenu == 3)) 
        Ruler_flag = true;
   else Ruler_flag = false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// *****  Thread ***** ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ISR(INT0_vect)
{
   TachoRemovePulse();

   if (!Enc_Ch_A)
   {
      if (!Enc_Ch_B)
      {
         Spindle_Dir = CW;
         if (++Enc_Pos == ENC_TICK)
         {                                           
            Enc_Pos = 0;
            TachoSetPulse();
            if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
            else if (Joy_X_flag == ON) {Step_X_flag = ON;}
         }
      }
      else
      {
        Spindle_Dir = CCW;
        if (--Enc_Pos < 0)
        { 
           Enc_Pos = ENC_TICK - 1;
           TachoSetPulse();
           if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
           else if (Joy_X_flag == ON) {Step_X_flag = ON;}
        }
      }
   }
   
   else
   {
      if (!Enc_Ch_B) 
      {
         Spindle_Dir = CCW;
         if (--Enc_Pos < 0)
         { 
            Enc_Pos = ENC_TICK - 1;
            TachoSetPulse();
            if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
            else if (Joy_X_flag == ON) {Step_X_flag = ON;}
         }
      }
      else 
      {
         Spindle_Dir = CW;
         if (++Enc_Pos == ENC_TICK)
         {                                           
            Enc_Pos = 0;
            TachoSetPulse();
            if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
            else if (Joy_X_flag == ON) {Step_X_flag = ON;}
         }
      }
   }  
   
   if (Step_Z_flag == ON)
   {   Motor_Z_RemovePulse();
      if ( (Motor_Z_Dir == CW && Motor_Z_Pos > Limit_Pos) || (Motor_Z_Dir == CCW && Motor_Z_Pos < Limit_Pos) || (!Joy_Z_flag) )
      {
         if (tmp_Ks_Divisor < tmp_Accel)
         {
            Ks_Count++;
            if (Ks_Count > tmp_Ks_Divisor)
            {
               Motor_Z_SetPulse();
               if (Motor_Z_Dir == CW) {Motor_Z_Pos ++; Z_pos ++;}
               else {Motor_Z_Pos --; Z_pos --;}
               Ks_Count = 0;
               if (++Repeat_Count == REPEAt)
               {
                  Repeat_Count = 0;
                  tmp_Ks_Divisor ++;
               }
            }
         }  
         else {Step_Z_flag = OFF;}
      }

      else
      {
         Ks_Count++;
         if (Ks_Count > tmp_Ks_Divisor)
         {
            Motor_Z_SetPulse();
            if (Motor_Z_Dir == CW) {Motor_Z_Pos ++; Z_pos ++;}
            else {Motor_Z_Pos --; Z_pos --;}
         
            if (tmp_Ks_Divisor > Ks_Divisor)
            {
               Ks_Count = 0;
               if (++Repeat_Count == REPEAt)
               {
                  Repeat_Count = 0;
                  tmp_Ks_Divisor --;
               }
            }
            else
            {  
               Km_Count = Km_Count + Km_Divisor;
               if (Km_Count > Km_Divisor)
               {
                  Km_Count = Km_Count - 10000;
                  Ks_Count = 0;
               }
               else {Ks_Count = 1;}
            }
         }
      }
   }
   
   if (Step_X_flag == ON)
   {  Motor_X_RemovePulse();
      if ( (Motor_X_Dir == CW && Motor_X_Pos > Limit_Pos) || (Motor_X_Dir == CCW && Motor_X_Pos < Limit_Pos) || (!Joy_X_flag) )
      {
         if (tmp_Ks_Divisor < tmp_Accel)
         {
            Ks_Count++;
            if (Ks_Count > tmp_Ks_Divisor)
            {
               Motor_X_SetPulse();
               if (Motor_X_Dir == CW) {Motor_X_Pos ++; X_pos ++; MX_pos ++;}
               else {Motor_X_Pos --; X_pos --; MX_pos --;}
               Ks_Count = 0;
               if (++Repeat_Count == REPEAt)
               {
                  Repeat_Count = 0;
                  tmp_Ks_Divisor ++;
               }
            }
         }  
         else {Step_X_flag = OFF;}
      }

      else
      {
         Ks_Count++;
         if (Ks_Count > tmp_Ks_Divisor)
         {
            Motor_X_SetPulse();
            if (Motor_X_Dir == CW) {Motor_X_Pos ++; X_pos ++; MX_pos ++;}
            else {Motor_X_Pos --; X_pos --; MX_pos --;}
         
            if (tmp_Ks_Divisor > Ks_Divisor)
            {
               Ks_Count = 0;
               if (++Repeat_Count == REPEAt)
               {
                  Repeat_Count = 0;
                  tmp_Ks_Divisor --;
               }
            }
            else
            {  
               Km_Count = Km_Count + Km_Divisor;
               if (Km_Count > Km_Divisor)
               {
                  Km_Count = Km_Count - 10000;
                  Ks_Count = 0;
               }
               else {Ks_Count = 1;}
            }
         }
      }
   }
}


ISR(INT1_vect)
{
//
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// *****  Tacho ***** ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ISR (TIMER0_COMPB_vect)                                 // Тахометр
{
   //   
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// *****  Feed & Cone ***** //////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ISR (TIMER5_COMPA_vect)
{
     if (!Enc_Ch_A)
   {
      if (!Enc_Ch_B)
      {
         Spindle_Dir = CW;
         if (++Enc_Pos == ENC_TICK)
         {                                           
            Enc_Pos = 0;
            TachoSetPulse();
            if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
            else if (Joy_X_flag == ON) {Step_X_flag = ON;}
         }
      }
      else
      {
        Spindle_Dir = CCW;
        if (--Enc_Pos < 0)
        { 
           Enc_Pos = ENC_TICK - 1;
           TachoSetPulse();
           if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
           else if (Joy_X_flag == ON) {Step_X_flag = ON;}
        }
      }
   }
   
   else
   {
      if (!Enc_Ch_B) 
      {
         Spindle_Dir = CCW;
         if (--Enc_Pos < 0)
         { 
            Enc_Pos = ENC_TICK - 1;
            TachoSetPulse();
            if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
            else if (Joy_X_flag == ON) {Step_X_flag = ON;}
         }
      }
      else 
      {
         Spindle_Dir = CW;
         if (++Enc_Pos == ENC_TICK)
         {                                           
            Enc_Pos = 0;
            TachoSetPulse();
            if (Joy_Z_flag == ON) {Step_Z_flag = ON;}
            else if (Joy_X_flag == ON) {Step_X_flag = ON;}
         }
      }
   }
   if (Joy_Z_flag == ON) {Motor_X_RemovePulse();}
   TachoRemovePulse();
   Tacho_Count = Tacho_Count + (OCR5A+1);
   if (Tacho_Count > ENC_LINE_PER_REV)
   {
      TachoSetPulse();
      Tacho_Count = Tacho_Count - ENC_LINE_PER_REV;
   }
   
   if ( (Motor_Z_Dir == CW && Motor_Z_Pos > Limit_Pos) || (Motor_Z_Dir == CCW && Motor_Z_Pos < Limit_Pos) || (!feed_Z_flag) )   
   {
      if (OCR5A < max_OCR5A)
      {
         Motor_Z_InvertPulse();
         if (!Read_Z_State)
         {
            OCR5A++;
            if (Motor_Z_Dir == CW) {Motor_Z_Pos ++; Z_pos ++;}
            else {Motor_Z_Pos --; Z_pos --;}
         }
      }
      else
      {             
         Step_Z_flag = OFF;
         Step_X_flag = OFF;
      }
   }
   
   else
   {
      Step_Z_flag = ON;
      Motor_Z_InvertPulse();
      if (!Read_Z_State)
      {
         if (Motor_Z_Dir == CW) {Motor_Z_Pos ++; Z_pos ++;}
         else {Motor_Z_Pos --; Z_pos --;}
      
         if (OCR5A > Feed_Divisor) {OCR5A--;}
         else if (OCR5A < Feed_Divisor) {OCR5A ++;}
      }
   }
   
   if (Step_X_flag == ON)
   {
      if (++Cs_Count > Cs_Divisor)
      {
         Motor_X_SetPulse();

         if (Motor_X_Dir == CW) {Motor_X_Pos ++; X_pos ++; MX_pos ++;}
         else {Motor_X_Pos --; X_pos --; MX_pos --;}

         Cm_Count = Cm_Count + Cm_Divisor;
         if (Cm_Count > Cm_Divisor)
         {
            Cm_Count = Cm_Count - 10000;
            Cs_Count = 0;
         }
         else {Cs_Count = 1;}
      }
   }
}

////////////////////////////////////////////////////////////
ISR (TIMER5_COMPB_vect)
{
   TachoRemovePulse();   
   Tacho_Count = Tacho_Count + (OCR5A+1);
   if (Tacho_Count > ENC_LINE_PER_REV)
   {
      TachoSetPulse();
      Tacho_Count = Tacho_Count - ENC_LINE_PER_REV;
   }
  
   if ( (Motor_X_Dir == CW && Motor_X_Pos > Limit_Pos) || (Motor_X_Dir == CCW && Motor_X_Pos < Limit_Pos) || (!feed_X_flag) )
   {
      if (OCR5A < max_OCR5A)
      {
         Motor_X_InvertPulse();
         if (!Read_X_State)
         {
            OCR5A++;
            if (Motor_X_Dir == CW) {Motor_X_Pos ++; X_pos ++; MX_pos ++;}
            else {Motor_X_Pos --; X_pos --; MX_pos --;}
         }
      }
      else {Step_X_flag = OFF;}
   }
   
   else 
   {
      Step_X_flag = ON;
      Motor_X_InvertPulse();
      {
         if (!Read_X_State)
         {
            if (Motor_X_Dir == CW) {Motor_X_Pos ++; X_pos ++; MX_pos ++;}
            else {Motor_X_Pos --; X_pos --; MX_pos --;}
      
            if (OCR5A > Feed_Divisor) {OCR5A--;}
            else if (OCR5A < Feed_Divisor) {OCR5A ++;}
         }
      }
   }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ***** Rapid Feed & Rapid Cone ***** ///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ISR (TIMER2_COMPA_vect)
{
   Motor_X_RemovePulse();
   if ( (Motor_Z_Dir == CW && Motor_Z_Pos > Limit_Pos) || (Motor_Z_Dir == CCW && Motor_Z_Pos < Limit_Pos) || (!rapid_Z_flag) )  
   {
      if (OCR2A < MIN_RAPID_MOTION)
      {
         Motor_Z_InvertPulse();
         if (!Read_Z_State)
         {
            if (Motor_Z_Dir == CW) { Motor_Z_Pos ++; Z_pos ++;}
            else { Motor_Z_Pos --; Z_pos --;}

            if (++Repeat_Count == REPEAt)
            {
               Repeat_Count = 0;
               OCR2A ++;
            }
         }
      }
      else
      {
         rapid_step_Z_flag = OFF;
         Step_X_flag = OFF;
      }
   }
  
   else
   {
      rapid_step_Z_flag = ON;
      Motor_Z_InvertPulse();
      if (!Read_Z_State)
      {
         if (Motor_Z_Dir == CW) { Motor_Z_Pos ++; Z_pos ++;}
         else { Motor_Z_Pos --; Z_pos --;}

         if (OCR2A > MAX_RAPID_MOTION)
         {
            if (++Repeat_Count == REPEAt)
            {
               Repeat_Count = 0;
               OCR2A --;
            }
         }
      }
   }
   
   ///////////////////////////////////////////////////////
   if (Step_X_flag == ON)
   {
      if (++Cs_Count > Cs_Divisor)
      {
         Motor_X_SetPulse();
         if (Motor_X_Dir == CW) { Motor_X_Pos ++; X_pos ++; MX_pos ++;}
         else { Motor_X_Pos --; X_pos --; MX_pos --;}
         
         Cm_Count = Cm_Count + Cm_Divisor;
         if (Cm_Count > Cm_Divisor)
         {
            Cm_Count = Cm_Count - 10000;
            Cs_Count = 0;
         }
         else {Cs_Count = 1;}
      }
   }
}

//////////////////////////////////////////////////////////
ISR (TIMER2_COMPB_vect)
{
   if ( (Motor_X_Dir == CW && Motor_X_Pos > Limit_Pos) || (Motor_X_Dir == CCW && Motor_X_Pos < Limit_Pos) || (!rapid_X_flag) )
   {
      if (OCR2A < MIN_RAPID_MOTION)
      {
         Motor_X_InvertPulse();
         if (!Read_X_State)
         {
            if (Motor_X_Dir == CW) { Motor_X_Pos ++; X_pos ++; MX_pos ++;}
            else { Motor_X_Pos --; X_pos --; MX_pos --;}

            if (++Repeat_Count == REPEAt)
            {
               Repeat_Count = 0;
               OCR2A ++;
            }
         }
      }
      else  {rapid_step_X_flag = OFF;}
   }
  
   else
   {
      rapid_step_X_flag = ON;
      Motor_X_InvertPulse();
      if (!Read_X_State)
      {
         if (Motor_X_Dir == CW) { Motor_X_Pos ++; X_pos ++; MX_pos ++;}
         else { Motor_X_Pos --; X_pos --; MX_pos --;}

         if (OCR2A > MAX_RAPID_MOTION)
         {
            if (++Repeat_Count == REPEAt)
            {
               Repeat_Count = 0;
               OCR2A --;
            }
         }
      }
   }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ***** Asynchron Feed ***** ////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ISR (TIMER4_COMPA_vect)
{

   if (Joy_Z_flag == ON) {Motor_X_RemovePulse();}
   TachoRemovePulse();
   Tacho_Count = Tacho_Count + (OCR5A+1);
   if (Tacho_Count > ENC_LINE_PER_REV)
   {
      TachoSetPulse();
      Tacho_Count = Tacho_Count - ENC_LINE_PER_REV;
   }
  
   if ( (Motor_Z_Dir == CW && Motor_Z_Pos > Limit_Pos) || (Motor_Z_Dir == CCW && Motor_Z_Pos < Limit_Pos) || (!feed_Z_flag) )
   {
      if (OCR4A < max_OCR4A)
      {
         Motor_Z_InvertPulse();
         if (!Read_Z_State)
         {
            OCR4A ++;
            if (Motor_Z_Dir == CW) {Motor_Z_Pos ++; Z_pos ++;}
            else                   {Motor_Z_Pos --; Z_pos --;}
         }
      }
      else
      {             
         Step_Z_flag = OFF;
         Step_X_flag = OFF;
      }
   }
   
   else
   {
      Step_Z_flag = ON;
      Motor_Z_InvertPulse();
      if (!Read_Z_State)
      {
         if (Motor_Z_Dir == CW) {Motor_Z_Pos ++; Z_pos ++;}
         else                   {Motor_Z_Pos --; Z_pos --;}

         if      (OCR4A > aFeed_Divisor) {OCR4A --;}
         else if (OCR4A < aFeed_Divisor) {OCR4A ++;}
      }
   }
}

//////////////////////////////////////////////////////////
ISR (TIMER4_COMPB_vect)
{
   if ( (Motor_X_Dir == CW && Motor_X_Pos > Limit_Pos) || (Motor_X_Dir == CCW && Motor_X_Pos < Limit_Pos) || (!feed_X_flag) )
   {
      if (OCR4A < max_OCR4A)
      {
         Motor_X_InvertPulse();
         if (!Read_X_State)
         {
            OCR4A ++;
            if (Motor_X_Dir == CW) {Motor_X_Pos ++; X_pos ++; MX_pos ++;}
            else                   {Motor_X_Pos --; X_pos --; MX_pos --;}
         }
      }
      else
      {             
         Step_Z_flag = OFF;
         Step_X_flag = OFF;
      }
   }
   
   else 
   {
      Step_X_flag = ON;
      Motor_X_InvertPulse();
      if (!Read_X_State)
      {
         if (Motor_X_Dir == CW) {Motor_X_Pos ++; X_pos ++; MX_pos ++;}
         else                   {Motor_X_Pos --; X_pos --; MX_pos --;}

         if      (OCR4A > aFeed_Divisor) {OCR4A --;}
         else if (OCR4A < aFeed_Divisor) {OCR4A ++;}
      }
   }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ***** HandCoder ***** /////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ISR(INT2_vect)
{
   if (!Hand_Ch_A)
   {
      if (!Hand_Ch_B) {Hand_Count --;}
   }
   
   else
   {
      if (!Hand_Ch_B) {Hand_Count ++;}
   }

}

/////////////////////////////////////////////
ISR (TIMER3_COMPA_vect)
{   
   if (Motor_Z_Dir == CW)
   {
      if (Motor_Z_Pos < Null_Z_Pos + Hand_Z_Pos)
      {
         Motor_Z_InvertPulse();
         if (!Read_Z_State) 
         {
            Motor_Z_Pos ++; Z_pos ++;
            if ((Motor_Z_Pos > Limit_Pos_HC) || (hand_Z == OFF))
            {
               if (OCR3A < max_OCR3A) OCR3A ++;
            }
            else if (Motor_Z_Pos < Limit_Pos_HC)
            {
               if (OCR3A > min_OCR3A) OCR3A --;
            }
         }
      }
      else if (Motor_Z_Pos == Hand_Z_Pos)
      {
      //
      }
   }

   else if (Motor_Z_Dir == CCW)
   {
      if (Motor_Z_Pos > Null_Z_Pos + Hand_Z_Pos)
      {
         Motor_Z_InvertPulse();
         if (!Read_Z_State) 
         {
            Motor_Z_Pos --; Z_pos --;
            if (Motor_Z_Pos < Limit_Pos_HC  || hand_Z == OFF)
            {
               if (OCR3A < max_OCR3A) OCR3A ++;
            }
            else if (Motor_Z_Pos > Limit_Pos_HC)
            {
               if (OCR3A > min_OCR3A) OCR3A --;
            }
         }
      }
      else if (Motor_Z_Pos == Hand_Z_Pos)
      {
      //
      }
   }
}

//////////////////////////////////////////////////////////
ISR (TIMER3_COMPB_vect)
{   
   if (Motor_X_Dir == CW)
   {
      if (Motor_X_Pos < Null_X_Pos + Hand_X_Pos)
      {
         Motor_X_InvertPulse();
         if (!Read_X_State) 
         {
            Motor_X_Pos ++; 
            X_pos ++;
            MX_pos ++;
            if ((Motor_X_Pos > Limit_Pos_HC) || (hand_X == OFF))
            {
               if (OCR3A < max_OCR3A) OCR3A ++;
            }
            else if (Motor_X_Pos < Limit_Pos_HC)
            {
               if (OCR3A > min_OCR3A) OCR3A --;
            }
         }
      }
      else if (Motor_X_Pos == Hand_X_Pos)
      {             
      //
      }
   }

   else if (Motor_X_Dir == CCW)
   {
      if (Motor_X_Pos > Null_X_Pos + Hand_X_Pos)
      {
         Motor_X_InvertPulse();
         if (!Read_X_State) 
         {
            Motor_X_Pos --; 
            X_pos --;
            MX_pos --;
            if ((Motor_X_Pos < Limit_Pos_HC) || (hand_X == OFF))
            {
               if (OCR3A < max_OCR3A) OCR3A ++;
            }
            else if (Motor_X_Pos > Limit_Pos_HC)
            {
               if (OCR3A > min_OCR3A) OCR3A --;
            }
         }
      }
      else if (Motor_X_Pos == Hand_X_Pos)
      {             
      //
      }
   }
}


// ***** End ***** ///////////////////////////////////////////////////
