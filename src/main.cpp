#include <Arduino.h>
#include <Nokia_LCD.h>


// #include<testing.h> //used when unconnected from system
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||LCD||||||||||||||||||||||||||||||||||||||||||||||||||||

const byte lcdPinCLK = 8;
const byte lcdPinDIN = 9;
const byte lcdPinDC = 10;
const byte lcdPinCE = 11;
const byte lcdPinRST = 12;
const byte lcdPinLED = 13;
// Nokia_LCD lcd(CLK, DIN, DC, CE, RST );
Nokia_LCD lcd(lcdPinCLK, lcdPinDIN, lcdPinDC, lcdPinCE, lcdPinRST);



//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||ARDUINO PINS |||||||||||||||||||||||||||||||||||||||||
int sensorPinA = 2;
int sensorPinB = 3;
int sensorC = 7;

int laserA = 4;
int laserB = 5;
int laserC = 6;

/*
  VARIABLES
*/





  //||||||||||||||||||||||||||||||||||||||||||||||||||   TIME VARIABLES   ||||||||
  // time delays
  const int O_bit = 1;
  const int i_bit = 2;
  const int ii_bit = 4;
  const int iii_bit = 8;
  const int iv_bit = 16;
  const int v_bit = 32;
  const int vi_bit = 64;
  const int vii_bit = 128;
  const int viii_bit = 256;
  const int ix_bit = 512;
  const int x_bit = 1024;

  //||||||||||||||||||||||||||||||||||||||||||||||||||   ANALOG VARIABLES   ||||||||
  //recieved from the buttons in the analog Pins
  int inputA_anlg = 0;
  int inputB_anlg = 0;
  int inputC_anlg = 0;
  int inputD_anlg = 0;
  int inputE_anlg = 0;

  // returns a single digit form a "if algorithm"
  int stateA_anlg = 0;
  int stateB_anlg = 0;
  int stateC_anlg = 0;
  int stateD_anlg = 0;
  int stateE_anlg = 0;



  //||||||||||||||||||||||||||||||||||||||||||||||||||   STATE VARIABLES   ||||||||
  int stateSigA = 0;
  int stateSigB= 0;
  int stateSigC= 0;


  int stateMode = 0;
  int stateModeA= 0;
  int stateModeB= 0;
  int stateModeC= 0;

  int buttonAstate =0;
  int buttonBstate =0;
  int buttonCstate =0;

  int buttonThreshold = 768;

  int counterA = 0;
  int counterB = 0;

  unsigned long t_one_i;
  unsigned long t_two_i;
  unsigned long t_three_i;
  unsigned long t_four_i;

  unsigned long t_one_f;
  unsigned long t_two_f;
  unsigned long t_three_f;
  unsigned long t_four_f;

  unsigned long t_delta_one;
  unsigned long t_delta_two;
  unsigned long t_delta_three;
  unsigned long t_delta_four;

  unsigned long t_delta_oneTwo_i;
  unsigned long t_delta_oneTwo_ii;
  unsigned long t_delta_threeFour_i;
  unsigned long t_delta_threeFour_ii;

  float time_A;
  float time_B;
  float time_C;
  float time_D;
  float time_E;
  float time_F;
  float time_G;
  float time_H;


  int testsA = 0;
  int testsB = 0;

  float timerSECS_A_i;
  float timerSECS_A_f;
  float timerSECS_B_i;
  float timerSECS_B_f;

  float timerSECS_STRT_AB_i;
  float timerSECS_STRT_AB_f;
  float timerSECS_FNSH_AB_i;
  float timerSECS_FNSH_AB_f;

  float vel_A_i;
  float vel_A_ii;
  float vel_B_i;
  float vel_B_ii;

  float vel_C_i;
  float vel_C_ii;
  float vel_D_i;
  float vel_D_ii;

  float acc_a_i;
  float acc_a_ii;
  float acc_a_iii;
  float acc_a_iv;
  float acc_a_v;
  float acc_a_vi;

  float velocity_i;
  float velocity_f;
  float velocity_i_sq;
  float velocity_f_sq;
  float velocity_delta;
  float two_distance;

  float distanceTRLY = 0.165;
  float distanceCNTR = 0.5;

  int countTest = 0;


int lcd_X_pos = 0;
int lcd_Y_pos = 0;
//#########################################################################################################
//      GRAPHICS
//#########################################################################################################
const unsigned char hintEduLogo[504] PROGMEM = {
  0x00, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
  0x02, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2,
  0xE2, 0xE2, 0x22, 0xA2, 0xA2, 0xA2, 0xA2, 0x22, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2,
  0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2,
  0xE2, 0xE2, 0xE2, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
  0x02, 0x02, 0xFE, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x8F, 0x8F, 0x8F, 0x8F, 0x00, 0x00, 0xF0, 0xF0, 0xF0,
  0xF0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0xF0, 0xF0, 0xF0,
  0xFE, 0xFE, 0xFE, 0xFE, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
  0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0xCE, 0x4E, 0x4E, 0xCE, 0x0E, 0xCE, 0x4E, 0x46, 0xF6, 0x06,
  0xCE, 0x0E, 0x0E, 0xCE, 0x0E, 0xCE, 0x4E, 0x4E, 0x4E, 0x0E, 0xCE, 0x4E, 0x4E, 0xCE, 0x0E, 0x46,
  0xE6, 0x46, 0x06, 0xD6, 0x06, 0xCE, 0x4E, 0x4E, 0xCE, 0x0E, 0xCE, 0x4E, 0x4E, 0xCE, 0x0E, 0x0E,
  0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFF, 0x00, 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x47, 0x45, 0x45, 0x45, 0x40, 0x47,
  0x44, 0x44, 0x47, 0x40, 0x47, 0x44, 0x44, 0x47, 0x40, 0x47, 0x44, 0x44, 0x44, 0x40, 0x47, 0x42,
  0x42, 0x47, 0x40, 0x40, 0x47, 0x40, 0x40, 0x47, 0x40, 0x47, 0x44, 0x44, 0x47, 0x40, 0x47, 0x40,
  0x40, 0x47, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7F, 0x00,
};



const unsigned char menuLogo[504] PROGMEM = {
  0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7D, 0x05,
  0x7D, 0x05, 0x7D, 0x01, 0x01, 0x7D, 0x55, 0x55, 0x55, 0x01, 0x01, 0x7D, 0x09, 0x11, 0x21, 0x7D,
  0x01, 0x01, 0x7D, 0x41, 0x41, 0x7D, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF,
};

const unsigned char laserWarning[504] PROGMEM = {
0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7D, 0x41, 0x7D, 0x41, 0x7D, 0x01,
0x7D, 0x15, 0x15, 0x7D, 0x01, 0x7D, 0x15, 0x35, 0x5D, 0x01, 0x7D, 0x19, 0x31, 0x7D, 0x01, 0x7D,
0x01, 0x7D, 0x19, 0x31, 0x7D, 0x01, 0x7D, 0x45, 0x55, 0x75, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x81, 0x61, 0x11, 0x09, 0x11, 0x61, 0x81,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x41, 0xC1, 0x41, 0x01, 0xC1, 0x01, 0xC1, 0x01, 0xC1, 0x01,
0xC1, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x06, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x17, 0x10, 0xE0, 0x07, 0xF1,
0x57, 0x10, 0x07, 0xF0, 0x05, 0xF5, 0x07, 0xF0, 0x00, 0xF0, 0x10, 0x10, 0x00, 0xF0, 0x50, 0x10,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x20, 0x18, 0x06, 0x01, 0x10, 0x20,
0x40, 0x80, 0x00, 0x80, 0xFC, 0x80, 0x00, 0x80, 0x40, 0x20, 0x10, 0x01, 0x06, 0x18, 0x20, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7D, 0x41,
0x7D, 0x00, 0x5C, 0x55, 0x75, 0x01, 0x7C, 0x54, 0x45, 0x00, 0x5C, 0x55, 0x74, 0x01, 0x01, 0x01,
0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0x00, 0x00,
0x04, 0x04, 0x04, 0x84, 0x44, 0x2E, 0x1F, 0x3F, 0xFF, 0x3F, 0x1F, 0x2E, 0x44, 0x84, 0x04, 0x04,
0x04, 0x04, 0x04, 0x04, 0x07, 0x0C, 0x30, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x1F, 0x10, 0x10, 0x00, 0x1F, 0x05, 0x1F, 0x00, 0x17, 0x15, 0x1D, 0x00, 0x1F, 0x15,
0x11, 0x00, 0x1F, 0x0D, 0x17, 0x00, 0x17, 0x15, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0xB0, 0xAC, 0xA3, 0xA0, 0xA0, 0xA0,
0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA1, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA7, 0xA0, 0xA0, 0xA0,
0xA0, 0xA0, 0xA1, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA3, 0xAC, 0xB0, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF,
};


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||FUNTIONS |||||||||||||||||||||||||||||||||||||||||||||
//---------------------------------------------------------------------------------------------------------------------
void switchLCD_LED(bool stateLCD_LED)
{
  if(stateLCD_LED == false) {
    digitalWrite(lcdPinLED, LOW);
    Serial.println("##  \tLCD_LED |OFF| \t ##");
  }
  if(stateLCD_LED == true) {
    digitalWrite(lcdPinLED, HIGH);
    Serial.println("##  \tLCD_LED |ON | \t ##");
  }
}
//---------------------------------------------------------------------------------------------------------------------
void checkSig(byte chkPinA,byte chkPinB,byte chkPinC){

  Serial.print("??  \t"); // starts line with relavant symbol
  //checks the state of laser A
  if(chkPinA == true) {
    stateSigA = digitalRead(sensorPinA);
    if(stateSigA == false){
      Serial.print(F("lsrA | LOW|\t");
    }
    if(stateSigA == true){
      Serial.print(F("lsrA |HIGH|\t");
    }
  }
  else{
    Serial.print(F("lsrA |null|\t");
  }

  //checks the state of laser B
  if(chkPinB == true) {
    stateSigB = digitalRead(sensorPinB);
    if(stateSigB == false){
      Serial.print(F("lsrB | LOW|\t");
    }
    if(stateSigB == true){
      Serial.print(F("lsrB |HIGH|\t");
    }
  }
  else{
    Serial.print(F("lsrB |null|\t");
  }

  //checks the state of laser C
  if(chkPinC == true) {
    stateSigC = digitalRead(sensorPinC);
    if(stateSigC == false){
      Serial.print(F("lsrC | LOW|\t");
    }
    if(stateSigC == true){
      Serial.print(F("lsrC |HIGH|\t");
    }
  }
  else{
    Serial.print(F("lsrC |null|\t");
  }

//---------------------------------------------------------------------------------------------------------------------
//switches a laser on or off.
void switchLaserOn (bool lsrA,bool lsrB,bool lsrC){
  if(lsrA == true)
  {
    digitalWrite(laserA, HIGH);
    Serial.print(F(">>  \tlsrA| ON|\t <<");
  }
  else{
    digitalWrite(laserA, LOW);
    Serial.print(F(">>  \tlsrA| OFF|\t<<");
  }
  if(lsrA == true)
  {
    digitalWrite(laserB, HIGH);
    Serial.print(F(">>  \tlsrB| ON|\t<<");
  }
  else{
    digitalWrite(laserA, LOW);
    Serial.print(F(">>  \tlsrA| OFF|\t<<");
  }
  if(lsrA == true)
  {
    digitalWrite(laserA, HIGH);
    Serial.print(F(">>  \tlsrA| ON|\t<<");
  }
  else{
    digitalWrite(laserA, LOW);
    Serial.print(F(">>  \tlsrA| OFF|\t<<");
  }
}

//interface
void buttonMenu()
{
//new code
  inputA_anlg = analogRead(0);
  inputB_anlg = analogRead(1);
  inputC_anlg = analogRead(2);
  inputD_anlg = analogRead(4);
  inputE_anlg = analogRead(5);

  // inside button on shield
    if (inputA_anlg > 768)  {
      stateA_anlg = 1;
    }
    else {
      stateA_anlg = 0;
    }

    // outside button on shield
    if (inputB_anlg > 768) {
      stateB_anlg = 1;
    }
    else {
      stateB_anlg = 0;
    }

    // side button on shield
    if (inputC_anlg > 768) {
      stateC_anlg = 1;
    }
    else {
      stateC_anlg = 0;
    }

    // right button on LCD (if 1 then red button high && if 2 the little button high)
    if (inputD_anlg > 768) {
      stateD_anlg = 1;
    }
    else if (inputD_anlg < 768 && inputD_anlg > 256) {
      stateD_anlg = 2;
    }
    else
    {
      stateD_anlg = 0;
    }
    // left button on LCD (if 1 then red button high && if 2 the little button high)
    if (inputE_anlg > 768) {
      stateE_anlg = 1;
    }
    else if (inputE_anlg < 768 && inputE_anlg > 256) {
      stateE_anlg = 2;
    }
    else
    {
      stateE_anlg = 0;
    }



    if(stateD_anlg == 1)
    {
      buttonAstate = 1;
      stateMode = 2;
      stateModeB = 1;
      timerReadyPrintForwards(50,50);
    }
    else
    {
      buttonAstate = 0;
    }
  if(stateE_anlg == 2)
    {
      buttonBstate = 1;
      stateMode = 3;
      stateModeC = 1;
      timerReadyPrintReverse(50,50);
    }
    else
    {
      buttonBstate = 0;
    }
  if(stateE_anlg == 1)
    {
      buttonCstate = 1;
      stateMode = 1;
      stateModeA = 1;
      timerReadyPrintBothWay(50,50);
    }
    else
    {
      buttonCstate = 0;
    }


}
void timerReadyPrintForwards(int flash_period_on, int flash_period_off)
{
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledB, HIGH);

  countTest++;
  Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++");
  Serial.print("\t\tTEST NUMBER: ");
  Serial.println(countTest);
  Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++");
  Serial.println("\n## ---- ---- ----   FORWARDS READY   ---- ---- ---- ##");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FORWARD");
  lcd.setCursor(0,1);
  lcd.print("A1 -> B1");
  lcd.setCursor(15,2);
  lcd.print("TIMER WILL");
  lcd.setCursor(15,3);
  lcd.print("START WHEN");
  lcd.setCursor(15,4);
  lcd.print("LASER BEAM");
  lcd.setCursor(15,5);
  lcd.print("IS  BROKEN");

  // testNumbers(countTest)
  // testNumbers(countTest);

  // if(countTest == 3)
  // {
  // countTest = 0;
  // }
}
void timerReadyPrintReverse(int flash_period_on, int flash_period_off)
{
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledB, HIGH);

  countTest++;
  Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++");
  Serial.print("\t\tTEST NUMBER: ");
  Serial.println(countTest);
  Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++");
  Serial.println("\n## ---- ---- ----   REVERSE READY   ---- ---- ---- ##");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("REVERSE");
  lcd.setCursor(0,1);
  lcd.print(" B2 -> A2");
  lcd.setCursor(15,2);
  lcd.print("TIMER WILL");
  lcd.setCursor(15,3);
  lcd.print("START WHEN");
  lcd.setCursor(15,4);
  lcd.print("LASER BEAM");
  lcd.setCursor(15,5);
  lcd.print("IS  BROKEN");

  // testNumbers(countTest);

  // if(countTest == 3)
  // {
  // countTest = 0;
  // }
}
void timerReadyPrintBothWay(int flash_period_on, int flash_period_off)
{
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);

  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledB, HIGH);

  countTest++;
  Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++");
  Serial.print("\t\tTEST NUMBER: ");
  Serial.println(countTest);
  Serial.println("++++++++++++++++++++++++++++++++++++++++++++++++++++");
  Serial.println("\n## ---- ---- ----   BOTH WAYS READY   ---- ---- ---- ##");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BOTH WAYS");
  lcd.setCursor(0,1);
  lcd.print(" A1-B1-B2-A2");
  lcd.setCursor(15,2);
  lcd.print("TIMER WILL");
  lcd.setCursor(15,3);
  lcd.print("START WHEN");
  lcd.setCursor(15,4);
  lcd.print("LASER BEAM");
  lcd.setCursor(15,5);
  lcd.print("IS  BROKEN");

  // testNumbers(countTest);

  // if(countTest == 3)
  // {
  // countTest = 0;
  // }
}
//########################################################################################
//    CALCULATIONS
//################################################################################################
//------------------------------------------------------------------------------
void calculateVelocityForward()
{
  Serial.println("\n## ---- ---- ---- ----    VELOCITY  FORWARD  ---- ---- ---- ---- ##");
  //------------------------------------------------------------------------
  t_delta_one = t_one_f - t_one_i;
  timerSECS_A_i = (float)t_delta_one / 1000000.00;
  vel_A_i = distanceTRLY / timerSECS_A_i;
  //------------------------------------------------------------------------
  t_delta_oneTwo_i = t_two_i - t_one_i;
  timerSECS_STRT_AB_i = (float)t_delta_oneTwo_i / 1000000.00;
  vel_C_i = distanceCNTR / timerSECS_STRT_AB_i;
  //------------------------------------------------------------------------
  t_delta_oneTwo_ii = t_two_f - t_one_f;
  timerSECS_FNSH_AB_i = (float)t_delta_oneTwo_ii / 1000000.00;
  vel_C_ii = distanceCNTR / timerSECS_FNSH_AB_i;
  //------------------------------------------------------------------------
  t_delta_two = t_two_f - t_two_i;
  timerSECS_B_i = (float)t_delta_two / 1000000.00;
  vel_B_i = distanceTRLY / timerSECS_B_i;
  //------------------------------------------------------------------------
  Serial.print(">> |vel_A_i");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_one);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_A_i);
  Serial.print("\t|velo: ");
  Serial.print(vel_A_i);
  Serial.println("\t| <<");

  //------------------------------------------------------------------------
  Serial.print(">> |vel_C_i");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_oneTwo_i);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_STRT_AB_i);
  Serial.print("\t|velo: ");
  Serial.print(vel_C_i);
  Serial.println("\t| <<");

  //------------------------------------------------------------------------
  Serial.print(">> |vel_C_ii");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_oneTwo_ii);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_FNSH_AB_i);
  Serial.print("\t|velo: ");
  Serial.print(vel_C_ii);
  Serial.println("\t| <<");
  //------------------------------------------------------------------------
  Serial.print(">> |vel_B_i");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_two);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_B_i);
  Serial.print("\t|velo: ");
  Serial.print(vel_B_i);
  Serial.println("\t| <<");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Velocity - FWRD");
  delay(v_bit);
  lcd.setCursor(0,1);
  lcd.print("vAi:");
  lcd.print(int(vel_A_i)*10);
  delay(v_bit);
  lcd.setCursor(0,2);
  lcd.print("vCi:");
  lcd.print(int(vel_C_i)*10);
    delay(v_bit);
  lcd.setCursor(0,3);
  lcd.print("vCii:");
    lcd.print(int(vel_C_ii)*10);

    delay(v_bit);
  lcd.setCursor(0,4);
  lcd.print("vBi:");
    lcd.print(int(vel_B_i)*10);

  delay(x_bit);
  delay(x_bit);
  delay(x_bit);
}
void calculateVelocityReverse()
{
  //------------------------------------------------------------------------
  Serial.println("\n## ---- ---- ---- ----    VELOCITY  REVERSE  ---- ---- ---- ---- ##");
  //------------------------------------------------------------------------
  t_delta_three = t_three_f - t_three_i;
  timerSECS_B_f = (float)t_delta_three / 1000000.00;
  vel_B_ii = distanceTRLY / timerSECS_B_f;
  //------------------------------------------------------------------------
  t_delta_threeFour_i = t_four_i - t_three_i;
  timerSECS_STRT_AB_f = (float)t_delta_threeFour_i / 1000000.00;
  vel_D_i = distanceCNTR / timerSECS_STRT_AB_f;
  //------------------------------------------------------------------------
  t_delta_threeFour_ii = t_four_f - t_three_f;
  timerSECS_FNSH_AB_f = (float)t_delta_threeFour_ii / 1000000.00;
  vel_D_ii = distanceCNTR / timerSECS_FNSH_AB_f;
  //------------------------------------------------------------------------
  t_delta_four = t_four_f - t_four_i;
  timerSECS_A_f = (float)t_delta_four / 1000000.00;
  vel_A_ii = distanceTRLY / timerSECS_A_f;
  //------------------------------------------------------------------------
  Serial.print(">> |vel_B_ii");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_three);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_B_f);
  Serial.print("\t|velo: ");
  Serial.print(vel_B_ii);
  Serial.println("\t| <<");
  //------------------------------------------------------------------------
  Serial.print(">> |vel_D_i");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_threeFour_i);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_STRT_AB_f);
  Serial.print("\t|velo: ");
  Serial.print(vel_D_i);
  Serial.println("\t| <<");
  //------------------------------------------------------------------------
  Serial.print(">> |vel_D_ii");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_threeFour_ii);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_FNSH_AB_f);
  Serial.print("\t|velo: ");
  Serial.print(vel_D_ii);
  Serial.println("\t| <<");
  //------------------------------------------------------------------------
  Serial.print(">> |vel_A_ii");
  Serial.print("\t|delta: ");
  Serial.print(t_delta_four);
  Serial.print("\t|secs: ");
  Serial.print(timerSECS_A_f);
  Serial.print("\t|velo: ");
  Serial.print(vel_A_ii);
  Serial.println("\t| <<");
  //------------------------------------------------------------------------

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Velocity - REV");
  delay(v_bit);

  lcd.setCursor(0,1);
  lcd.print("vBii:");
  lcd.print(int(vel_B_ii)*10);
  delay(v_bit);

  lcd.setCursor(0,2);
  lcd.print("vDi:");
  lcd.print(int(vel_D_i)*10);
  delay(v_bit);

  lcd.setCursor(0,3);
  lcd.print("vDii:");
  lcd.print(int(vel_D_ii)*10);
  delay(v_bit);

  lcd.setCursor(0,4);
  lcd.print("vAii:");
  lcd.print(int(vel_A_ii)*10);
  delay(x_bit);
  delay(x_bit);
  delay(x_bit);
}
//------------------------------------------------------------------------------ACCCELERATION
void calculateAccelerationForward()
{
  Serial.println("\n## ---- ---- ---- ----     ACCELERATION FORWARD     ---- ---- ---- ---- ##");

  //------------------------------------------------------------------------------A1
  Serial.print(">>|i");

  velocity_i = 0;
  velocity_f= 0;
  velocity_i_sq= 0;
  velocity_f_sq= 0;
  velocity_delta= 0;
  two_distance= 0;

  velocity_i = vel_A_i;
  velocity_f= vel_B_i;
  velocity_i_sq = velocity_i*velocity_i;
  velocity_f_sq =velocity_f*velocity_f;
  velocity_delta= velocity_f_sq - velocity_i_sq;
  two_distance = distanceCNTR * 2.00;
  acc_a_i = velocity_delta / two_distance;

  Serial.print("\t|v_i: ");
  Serial.print(velocity_i);
  Serial.print("\t|v_f: ");
  Serial.print(velocity_f);
  Serial.print("\t|v_i_sq: ");
  Serial.print(velocity_i_sq);
  Serial.print("\t|v_f_sq: ");
  Serial.print(velocity_f_sq);
  Serial.println("\t| <<");

  Serial.print(">>|");
  Serial.print("\t|v_d: ");
  Serial.print(velocity_delta,3);
  Serial.print("\t|2x: ");
  Serial.print(two_distance,2);
  Serial.print("\t|\tacc: ");
  Serial.print(acc_a_i,5);
  Serial.println("\t\t| <<");
  // //-----------------------------------------------------------------------------A2
  Serial.println("");
  Serial.print(">>|ii");

  velocity_i = 0;
  velocity_f= 0;
  velocity_i_sq= 0;
  velocity_f_sq= 0;
  velocity_delta= 0;
  two_distance= 0;
  acc_a_i= 0;

  velocity_i = vel_A_i;
  float velocity_sum_A = vel_C_i + vel_C_ii;
  float velocity_avg_A = velocity_sum_A / 2.00;
  velocity_f= velocity_avg_A;
  velocity_i_sq = velocity_i*velocity_i;
  velocity_f_sq =velocity_f*velocity_f;
  velocity_delta= velocity_f_sq - velocity_i_sq;
  two_distance = 0.25 * 2.00;
  acc_a_ii = velocity_delta / two_distance;

  Serial.print("\t|v_i: ");
  Serial.print(velocity_i);
  Serial.print("\t|v_f: ");
  Serial.print(velocity_f);
  Serial.print("\t|v_i_sq: ");
  Serial.print(velocity_i_sq);
  Serial.print("\t|v_f_sq: ");
  Serial.print(velocity_f_sq);
  Serial.println("\t| <<");

  Serial.print(">>|");
  Serial.print("\t|v_d: ");
  Serial.print(velocity_delta,3);
  Serial.print("\t|2x: ");
  Serial.print(two_distance,2);
  Serial.print("\t|\tacc: ");
  Serial.print(acc_a_ii,5);
  Serial.println("\t\t| <<");

  // //-----------------------------------------------------------------------------A2
  Serial.println("");
  Serial.print(">>|iii");

  velocity_i = 0;
  velocity_f= 0;
  velocity_i_sq= 0;
  velocity_f_sq= 0;
  velocity_delta= 0;
  two_distance= 0;

  float velocity_sum_B = vel_C_i + vel_C_ii;
  float velocity_avg_B = velocity_sum_B / 2.00;
  velocity_i= velocity_avg_B;
  velocity_f = vel_B_i;
  velocity_i_sq = velocity_i*velocity_i;
  velocity_f_sq =velocity_f*velocity_f;
  velocity_delta= velocity_f_sq - velocity_i_sq;
  two_distance = 0.25 * 2.00;
  acc_a_iii = velocity_delta / two_distance;

  Serial.print("\t|v_i: ");
  Serial.print(velocity_i);
  Serial.print("\t|v_f: ");
  Serial.print(velocity_f);
  Serial.print("\t|v_i_sq: ");
  Serial.print(velocity_i_sq);
  Serial.print("\t|v_f_sq: ");
  Serial.print(velocity_f_sq);
  Serial.println("\t| <<");

  Serial.print(">>|");
  Serial.print("\t|v_d: ");
  Serial.print(velocity_delta,3);
  Serial.print("\t|2x: ");
  Serial.print(two_distance,2);
  Serial.print("\t|\tacc: ");
  Serial.print(acc_a_iii,5);
  Serial.println("\t\t| <<");

}
void calculateAccelerationReverse()
{
  Serial.println("\n## ---- ---- ---- ----     ACCELERATION REVERSE     ---- ---- ---- ---- ##");
  //------------------------------------------------------------------------------A1
  Serial.print(">>|iv");

  velocity_i = 0;
  velocity_f= 0;
  velocity_i_sq= 0;
  velocity_f_sq= 0;
  velocity_delta= 0;
  two_distance= 0;

  velocity_i = vel_B_ii;
  velocity_f= vel_A_ii;
  velocity_i_sq = velocity_i*velocity_i;
  velocity_f_sq =velocity_f*velocity_f;
  velocity_delta= velocity_f_sq - velocity_i_sq;
  two_distance = distanceCNTR * 2.00;
  acc_a_iv = velocity_delta / two_distance;

  Serial.print("\t|v_i: ");
  Serial.print(velocity_i);
  Serial.print("\t|v_f: ");
  Serial.print(velocity_f);
  Serial.print("\t|v_i_sq: ");
  Serial.print(velocity_i_sq);
  Serial.print("\t|v_f_sq: ");
  Serial.print(velocity_f_sq);
  Serial.println("\t| <<");

  Serial.print(">>|");
  Serial.print("\t|v_d: ");
  Serial.print(velocity_delta,3);
  Serial.print("\t|2x: ");
  Serial.print(two_distance,2);
  Serial.print("\t|\tacc: ");
  Serial.print(acc_a_iv,5);
  Serial.println("\t\t| <<");
  //-----------------------------------------------------------------------------A2
  Serial.println("");
  Serial.print(">>|v");

  velocity_i = 0;
  velocity_f= 0;
  velocity_i_sq= 0;
  velocity_f_sq= 0;
  velocity_delta= 0;
  two_distance= 0;

  velocity_i = vel_B_ii;
  float velocity_sum_C = vel_D_i + vel_D_ii;
  float velocity_avg_C = velocity_sum_C / 2.00;
  velocity_f= velocity_avg_C;
  velocity_i_sq = velocity_i*velocity_i;
  velocity_f_sq =velocity_f*velocity_f;
  velocity_delta= velocity_f_sq - velocity_i_sq;
  two_distance = 0.25 * 2.00;
  acc_a_v = velocity_delta / two_distance;

  Serial.print("\t|v_i: ");
  Serial.print(velocity_i);
  Serial.print("\t|v_f: ");
  Serial.print(velocity_f);
  Serial.print("\t|v_i_sq: ");
  Serial.print(velocity_i_sq);
  Serial.print("\t|v_f_sq: ");
  Serial.print(velocity_f_sq);
  Serial.println("\t| <<");

  Serial.print(">>|");
  Serial.print("\t|v_d: ");
  Serial.print(velocity_delta,3);
  Serial.print("\t|2x: ");
  Serial.print(two_distance,2);
  Serial.print("\t|\tacc: ");
  Serial.print(acc_a_v,5);
  Serial.println("\t\t| <<");
  // //-----------------------------------------------------------------------------A2

  Serial.println("");
  Serial.print(">>|vi");

  velocity_i = 0;
  velocity_f= 0;
  velocity_i_sq= 0;
  velocity_f_sq= 0;
  velocity_delta= 0;
  two_distance= 0;

  float velocity_sum_D = vel_D_i + vel_D_ii;
  float velocity_avg_D = velocity_sum_D / 2.00;
  velocity_i= velocity_avg_D;
  velocity_f = vel_A_ii;
  velocity_i_sq = velocity_i*velocity_i;
  velocity_f_sq =velocity_f*velocity_f;
  velocity_delta= velocity_f_sq - velocity_i_sq;
  two_distance = 0.25 * 2.00;
  acc_a_vi = velocity_delta / two_distance;

  Serial.print("\t|v_i: ");
  Serial.print(velocity_i);
  Serial.print("\t|v_f: ");
  Serial.print(velocity_f);
  Serial.print("\t|v_i_sq: ");
  Serial.print(velocity_i_sq);
  Serial.print("\t|v_f_sq: ");
  Serial.print(velocity_f_sq);
  Serial.println("\t| <<");

  Serial.print(">>|");
  Serial.print("\t|v_d: ");
  Serial.print(velocity_delta,3);
  Serial.print("\t|2x: ");
  Serial.print(two_distance,2);
  Serial.print("\t|\tacc: ");
  Serial.print(acc_a_vi,5);
  Serial.println("\t\t| <<");


}
//-----------------------------------------------------------------------------

void serialStartUp()
{
  Serial.println("");
  Serial.println("#######################################################");
  Serial.println("    LASER TIMER, VELOCITY, ACCELERATION AND ENERGY");
  Serial.println("#######################################################");
  Serial.println("");


  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);

  delay(100);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(100);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);

  delay(100);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(250);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(laserC, HIGH);

  delay(100);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(250);
}

void lcdStartUp()
{
  lcd.clear(true);
  delay(vii_bit);
  // Draw the platis.solutions logo on your screen

  delay(x_bit);
  // Clear the screen by filling it with white pixels

  lcd.draw(hintEduLogo, sizeof(hintEduLogo) / sizeof(hintEduLogo[0]), true);
  delay(x_bit);
  // Clear the screen by filling it with white pixels
  lcd.clear();

  lcd.draw(menuLogo, sizeof(menuLogo) / sizeof(menuLogo[0]), true);
  delay(x_bit);

  lcd.clear();

  lcd.draw(laserWarning, sizeof(laserWarning) / sizeof(laserWarning[0]), true);
  delay(x_bit);

  lcd.clear();


}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||SETUP|||||||||||||||||||||||||||||||||||||||||||||||||||
void setup()
{
  pinMode(sensorPinA, INPUT);
  pinMode(sensorPinB, INPUT);
  pinMode(laserA, OUTPUT);
  pinMode(laserB, OUTPUT);
  pinMode(sensorC, INPUT);
  pinMode(laserC, OUTPUT);
  pinMode(lcdPinLED, OUTPUT);

  // Initialize Serial Comms
  Serial.begin(9600);
  serialStartUp();


  // Initialize LCD screen
  lcd.begin();
  lcd.setContrast(47);
  switchLCD_LED(true):
  lcdStartUp();







}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||LOOP|||||||||||||||||||||||||||||||||||||||||||||||||||||
void loop()
{


}
