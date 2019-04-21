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
  int stateBSig= 0;
  int stateBSig= 0;


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
