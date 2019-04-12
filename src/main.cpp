#include <Arduino.h>




int sensorA = 2;
int sensorB = 3;

int laserA = 4;
int laserB = 5;

int ledA = 6;
int ledB = 7;


int stateA = 0;
int stateB= 0;

int stateMode = 0;
int stateModeA= 0;
int stateModeB= 0;
int stateModeC= 0;

int buttonAraw = 0;
int buttonBraw = 0;
int buttonCraw = 0;

int buttonAstate = 0;
int buttonBstate = 0;
int buttonCstate = 0;

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
//----------------------------------------------------------TEST ---------------
void testNumbers(int numberChoice)
{

  if (numberChoice == 1)
  {
    t_one_i=  14691408 ;
    t_one_f = 14886376;
    t_two_i = 15303204 ;
    t_two_f = 15525700;
    t_three_i=  16018232;
    t_three_f = 16311960;
    t_four_i = 17046352 ;
    t_four_f = 17550116;

    time_A = 0.00;
    time_B = ((float)t_one_f - (float)t_one_i) / 1000000.00;
    time_C = ((float)t_two_i - (float)t_one_i) / 1000000.00;
    time_D = ((float)t_two_f - (float)t_one_i) / 1000000.00;
    time_E = ((float)t_three_i - (float)t_one_i) / 1000000.00;
    time_F = ((float)t_three_f - (float)t_one_i) / 1000000.00;
    time_G = ((float)t_four_i - (float)t_one_i) / 1000000.00;
    time_H = ((float)t_four_f -(float)t_one_i) / 1000000.00;


    digitalWrite(laserA, LOW);
    Serial.print(">> |time_A\t| ");
    Serial.print(t_one_i);
    Serial.print("\t[");
    Serial.print(time_A,3);
    Serial.println(" s]\t| <<");

    delay(200);

    digitalWrite(laserA, HIGH);
    delay(400);
    Serial.print(">> |time_B\t| ");
    Serial.print(t_one_f);
    Serial.print("\t[");
    Serial.print(time_B,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, LOW);
    delay(200);
    Serial.print(">> |time_C\t| ");
    Serial.print(t_two_i);
    Serial.print("\t[");
    Serial.print(time_C,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, HIGH);
    delay(300);
    Serial.print(">> |time_D\t| ");
    Serial.print(t_two_f);
    Serial.print("\t[");
    Serial.print(time_D,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, LOW);
    delay(200);
    Serial.print(">> |time_E\t| ");
    Serial.print(t_three_i);
    Serial.print("\t[");
    Serial.print(time_E,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, HIGH);
    delay(400);
    Serial.print(">> |time_F\t| ");
    Serial.print(t_three_f);
    Serial.print("\t[");
    Serial.print(time_F,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserA, LOW);
    delay(200);
    Serial.print(">> |time_G\t| ");
    Serial.print(t_four_i);
    Serial.print("\t[");
    Serial.print(time_G,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserA, HIGH);
    delay(300);
    Serial.print(">> |time_H\t| ");
    Serial.print(t_four_f);
    Serial.print("\t[");
    Serial.print(time_H,3);
    Serial.print(" s]");
    Serial.println("\t| <<");

    stateMode = 0;
  }
  if (numberChoice == 2)
  {
    t_one_i=287529300 ;
    t_one_f = 287708304;
    t_two_i = 288094444 ;
    t_two_f = 288306408;
    t_three_i=  288793896;
    t_three_f = 289079100;
    t_four_i = 289800732 ;
    t_four_f = 290318644;

    time_A = 0.00;
    time_B = ((float)t_one_f - (float)t_one_i) / 1000000.00;
    time_C = ((float)t_two_i - (float)t_one_i) / 1000000.00;
    time_D = ((float)t_two_f - (float)t_one_i) / 1000000.00;
    time_E = ((float)t_three_i - (float)t_one_i) / 1000000.00;
    time_F = ((float)t_three_f - (float)t_one_i) / 1000000.00;
    time_G = ((float)t_four_i - (float)t_one_i) / 1000000.00;
    time_H = ((float)t_four_f -(float)t_one_i) / 1000000.00;


    digitalWrite(laserA, LOW);
    Serial.print(">> |time_A\t| ");
    Serial.print(t_one_i);
    Serial.print("\t[");
    Serial.print(time_A,3);
    Serial.println(" s]\t| <<");

    delay(200);

    digitalWrite(laserA, HIGH);
    delay(400);
    Serial.print(">> |time_B\t| ");
    Serial.print(t_one_f);
    Serial.print("\t[");
    Serial.print(time_B,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, LOW);
    delay(200);
    Serial.print(">> |time_C\t| ");
    Serial.print(t_two_i);
    Serial.print("\t[");
    Serial.print(time_C,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, HIGH);
    delay(300);
    Serial.print(">> |time_D\t| ");
    Serial.print(t_two_f);
    Serial.print("\t[");
    Serial.print(time_D,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, LOW);
    delay(200);
    Serial.print(">> |time_E\t| ");
    Serial.print(t_three_i);
    Serial.print("\t[");
    Serial.print(time_E,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, HIGH);
    delay(400);
    Serial.print(">> |time_F\t| ");
    Serial.print(t_three_f);
    Serial.print("\t[");
    Serial.print(time_F,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserA, LOW);
    delay(200);
    Serial.print(">> |time_G\t| ");
    Serial.print(t_four_i);
    Serial.print("\t[");
    Serial.print(time_G,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserA, HIGH);
    delay(300);
    Serial.print(">> |time_H\t| ");
    Serial.print(t_four_f);
    Serial.print("\t[");
    Serial.print(time_H,3);
    Serial.print(" s]");
    Serial.println("\t| <<");

    stateMode = 0;
  }
  if (numberChoice == 3)
  {
    t_one_i=305722336 ;
    t_one_f = 305902264;
    t_two_i = 306278808 ;
    t_two_f = 306474228;
    t_three_i=  306912948;
    t_three_f = 307140584;
    t_four_i = 307622508 ;
    t_four_f = 307874984;

    time_A = 0.00;
    time_B = ((float)t_one_f - (float)t_one_i) / 1000000.00;
    time_C = ((float)t_two_i - (float)t_one_i) / 1000000.00;
    time_D = ((float)t_two_f - (float)t_one_i) / 1000000.00;
    time_E = ((float)t_three_i - (float)t_one_i) / 1000000.00;
    time_F = ((float)t_three_f - (float)t_one_i) / 1000000.00;
    time_G = ((float)t_four_i - (float)t_one_i) / 1000000.00;
    time_H = ((float)t_four_f -(float)t_one_i) / 1000000.00;


    digitalWrite(laserA, LOW);
    Serial.print(">> |time_A\t| ");
    Serial.print(t_one_i);
    Serial.print("\t[");
    Serial.print(time_A,3);
    Serial.println(" s]\t| <<");

    delay(200);

    digitalWrite(laserA, HIGH);
    delay(400);
    Serial.print(">> |time_B\t| ");
    Serial.print(t_one_f);
    Serial.print("\t[");
    Serial.print(time_B,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, LOW);
    delay(200);
    Serial.print(">> |time_C\t| ");
    Serial.print(t_two_i);
    Serial.print("\t[");
    Serial.print(time_C,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, HIGH);
    delay(300);
    Serial.print(">> |time_D\t| ");
    Serial.print(t_two_f);
    Serial.print("\t[");
    Serial.print(time_D,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, LOW);
    delay(200);
    Serial.print(">> |time_E\t| ");
    Serial.print(t_three_i);
    Serial.print("\t[");
    Serial.print(time_E,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserB, HIGH);
    delay(400);
    Serial.print(">> |time_F\t| ");
    Serial.print(t_three_f);
    Serial.print("\t[");
    Serial.print(time_F,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserA, LOW);
    delay(200);
    Serial.print(">> |time_G\t| ");
    Serial.print(t_four_i);
    Serial.print("\t[");
    Serial.print(time_G,3);
    Serial.println(" s]\t| <<");

    digitalWrite(laserA, HIGH);
    delay(300);
    Serial.print(">> |time_H\t| ");
    Serial.print(t_four_f);
    Serial.print("\t[");
    Serial.print(time_H,3);
    Serial.print(" s]");
    Serial.println("\t| <<");

    stateMode = 0;
  }
}
//----------------------------------------------------------TIMER READY---------
void timerReadyPrintForwards(int flash_period_on, int flash_period_off)
{
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledA, HIGH);
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
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledA, HIGH);
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
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  delay(flash_period_on);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(flash_period_off);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledA, HIGH);
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

  // testNumbers(countTest);

  // if(countTest == 3)
  // {
  // countTest = 0;
  // }
}
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
void buttonMenu()
{

  buttonAraw = analogRead(0);
  buttonBraw = analogRead(1);
  buttonCraw = analogRead(2);

  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);

  if(buttonAraw > buttonThreshold)
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
  if(buttonBraw > buttonThreshold)
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
  if(buttonCraw > buttonThreshold)
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
}p]
//------------------------------------------------------------------------------


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||SETUP||||||||
void setup()
{

  Serial.begin(9600);


  Serial.println("");
  Serial.println("#######################################################");
  Serial.println("    LASER TIMER, VELOCITY, ACCELERATION AND ENERGY");
  Serial.println("#######################################################");
  Serial.println("");
  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
  pinMode(laserA, OUTPUT);
  pinMode(laserB, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  delay(100);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(100);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  delay(100);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(250);
  digitalWrite(laserA, HIGH);
  digitalWrite(laserB, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  delay(100);
  digitalWrite(laserA, LOW);
  digitalWrite(laserB, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  delay(250);





}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||LOOP||||||||||
void loop()
{
  if(stateMode == 0)
  {
    buttonMenu();
  }

  //--------------------------------------------start four laser test-----
  if(stateMode == 1)
  {

    if (stateModeA == 1)
    {
      stateA = digitalRead(sensorA);
      while (stateA == 0)
      {
        if (counterA == 0)
        {
          t_one_i = micros();
          Serial.print(">> |time_A\t| ");
          Serial.print(t_one_i);
          Serial.print("\t[");
          time_A = 0.00;
          Serial.print(time_A,3);
          Serial.println(" s]\t| <<");

          counterA = 1;
        }
        stateA = digitalRead(sensorA);
        if(stateA == 1)
        {
          t_one_f = micros();

          Serial.print(">> |time_B\t| ");
          Serial.print(t_one_f);
          Serial.print("\t[");
          time_B = ((float)t_one_f - (float)t_one_i) / 1000000.00;
          Serial.print(time_B,3);
          Serial.println(" s]\t| <<");


          counterA =0;
          stateModeA = 2;

          break;
        }
      }
    }
    //---------------------------------------------------------------------TWO-----
    if (stateModeA == 2)
    {
      stateB = digitalRead(sensorB);
      while (stateB == 0)
      {

        if (counterB == 0)
        {
          t_two_i = micros();

          Serial.print(">> |time_C\t| ");
          Serial.print(t_two_i);
          Serial.print("\t[");
          time_C = ((float)t_two_i - (float)t_one_i) / 1000000.00;
          Serial.print(time_C,3);
          Serial.println(" s]\t| <<");

          counterB = 1;
        }

        stateB = digitalRead(sensorB);
        if(stateB == 1)
        {

          t_two_f = micros();

          Serial.print(">> |time_D\t| ");
          Serial.print(t_two_f);
          Serial.print("\t[");
          time_D = ((float)t_two_f - (float)t_one_i) / 1000000.00;
          Serial.print(time_D,3);
          Serial.println(" s]\t| <<");



          counterB =0;
          stateModeA = 3;

          break;
        }
      }
    }
    //---------------------------------------------------------------------THREE----
    if (stateModeA == 3)
    {
      stateB = digitalRead(sensorB);
      while (stateB == 0)
      {
        if (counterB == 0)
        {

          t_three_i = micros();

          Serial.print(">> |time_E\t| ");
          Serial.print(t_three_i);
          Serial.print("\t[");
          time_E = ((float)t_three_i - (float)t_one_i) / 1000000.00;
          Serial.print(time_E,3);
          Serial.println(" s]\t| <<");
          counterB = 1;

        }

        stateB = digitalRead(sensorB);

        if(stateB == 1)
        {

          t_three_f = micros();
          Serial.print(">> |time_F\t| ");
          Serial.print(t_three_f);
          Serial.print("\t[");
          time_F = ((float)t_three_f - (float)t_one_i) / 1000000.00;
          Serial.print(time_F,3);
          Serial.println(" s]\t| <<");


          counterB =0;
          stateModeA = 4;
          break;
        }
      }
    }
    //---------------------------------------------------------------------FOUR----
    if (stateModeA == 4)
    {
      stateA = digitalRead(sensorA);
      while (stateA == 0)
      {
        if (counterA == 0)
        {
          t_four_i = micros();

          Serial.print(">> |time_G\t| ");
          Serial.print(t_four_i);
          Serial.print("\t[");
          time_G = ((float)t_four_i - (float)t_one_i) / 1000000.00;
          Serial.print(time_G,3);
          Serial.println(" s]\t| <<");

          counterA = 1;
        }

        stateA = digitalRead(sensorA);
        if(stateA == 1)
        {

          t_four_f = micros();
          Serial.print(">> |time_H\t| ");
          Serial.print(t_four_f);
          Serial.print("\t[");
          time_H = ((float)t_four_f -(float)t_one_i) / 1000000.00;
          Serial.print(time_H,3);
          Serial.println(" s]\t| <<");

          counterA =0;
          stateModeA = 5;
          digitalWrite(ledA, LOW);
          digitalWrite(ledB, HIGH);
          for(int y = 0; y < 3;y++)
          {
            digitalWrite(laserA, LOW);
            digitalWrite(laserB, LOW);
            delay(100);
            digitalWrite(laserA, HIGH);
            digitalWrite(laserB, HIGH);
            delay(100);
            digitalWrite(laserA, LOW);
            digitalWrite(laserB, LOW);
          }
          break;
        }
      }
    }
    if(stateModeA == 5)
    {
      calculateVelocityForward();
      delay(500);
      calculateVelocityReverse();
      delay(500);
      calculateAccelerationForward();
      delay(500);
      calculateAccelerationReverse();
      stateMode = 0;
      stateModeA = 0;
    }
  }
  // end of four later test
  //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
  if(stateMode == 2)
  {

    if (stateModeB == 1)
    {
      stateA = digitalRead(sensorA);
      while (stateA == 0)
      {
        if (counterA == 0)
        {
          t_one_i = micros();
          Serial.print(">> |time_A\t| ");
          Serial.print(t_one_i);
          Serial.print("\t[");
          time_A = 0.00;
          Serial.print(time_A,3);
          Serial.println(" s]\t| <<");

          counterA = 1;
        }
        stateA = digitalRead(sensorA);
        if(stateA == 1)
        {
          t_one_f = micros();

          Serial.print(">> |time_B\t| ");
          Serial.print(t_one_f);
          Serial.print("\t[");
          time_B = ((float)t_one_f - (float)t_one_i) / 1000000.00;
          Serial.print(time_B,3);
          Serial.println(" s]\t| <<");


          counterA =0;
          stateModeB = 2;

          break;
        }
      }
    }
    //---------------------------------------------------------------------TWO-----
    if (stateModeB == 2)
    {
      stateB = digitalRead(sensorB);
      while (stateB == 0)
      {
        if (counterB == 0)
        {
          t_two_i = micros();
          Serial.print(">> |time_C\t| ");
          Serial.print(t_two_i);
          Serial.print("\t[");
          time_C = ((float)t_two_i - (float)t_one_i) / 1000000.00;
          Serial.print(time_C,3);
          Serial.println(" s]\t| <<");
          counterB = 1;
        }
        stateB = digitalRead(sensorB);
        if(stateB == 1)
        {
          t_two_f = micros();
          Serial.print(">> |time_D\t| ");
          Serial.print(t_two_f);
          Serial.print("\t[");
          time_D = ((float)t_two_f - (float)t_one_i) / 1000000.00;
          Serial.print(time_D,3);
          Serial.println(" s]\t| <<");
          for(int y = 0; y < 3;y++)
          {
            digitalWrite(laserA, LOW);
            digitalWrite(laserB, LOW);
            delay(100);
            digitalWrite(laserA, HIGH);
            digitalWrite(laserB, HIGH);
            delay(100);
            digitalWrite(laserA, LOW);
            digitalWrite(laserB, LOW);
          }
          counterB =0;
          stateModeB = 3;
          break;
        }
      }
    }
    if(stateModeB == 3)
    {
      delay(500);
      calculateVelocityForward();
      delay(500);
      calculateAccelerationForward();
      delay(500);
      stateMode = 0;
      stateModeA = 0;
    }
  }

  //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

  if(stateMode == 3)
  {

    if (stateModeC == 1)
    {
      stateB = digitalRead(sensorB);
      while (stateB == 0)
      {
        if (counterB == 0)
        {

          t_three_i = micros();

          Serial.print(">> |time_E\t| ");
          Serial.print(t_three_i);
          Serial.print("\t[");
          time_E = ((float)t_three_i - (float)t_one_i) / 1000000.00;
          Serial.print(time_E,3);
          Serial.println(" s]\t| <<");
          counterB = 1;

        }

        stateB = digitalRead(sensorB);

        if(stateB == 1)
        {

          t_three_f = micros();
          Serial.print(">> |time_F\t| ");
          Serial.print(t_three_f);
          Serial.print("\t[");
          time_F = ((float)t_three_f - (float)t_one_i) / 1000000.00;
          Serial.print(time_F,3);
          Serial.println(" s]\t| <<");


          counterB =0;
          stateModeC = 2;
          break;
        }
      }
    }
    //---------------------------------------------------------------------FOUR----
    if (stateModeC == 2)
    {
      stateA = digitalRead(sensorA);
      while (stateA == 0)
      {
        if (counterA == 0)
        {
          t_four_i = micros();

          Serial.print(">> |time_G\t| ");
          Serial.print(t_four_i);
          Serial.print("\t[");
          time_G = ((float)t_four_i - (float)t_one_i) / 1000000.00;
          Serial.print(time_G,3);
          Serial.println(" s]\t| <<");

          counterA = 1;
        }

        stateA = digitalRead(sensorA);
        if(stateA == 1)
        {

          t_four_f = micros();
          Serial.print(">> |time_H\t| ");
          Serial.print(t_four_f);
          Serial.print("\t[");
          time_H = ((float)t_four_f -(float)t_one_i) / 1000000.00;
          Serial.print(time_H,3);
          Serial.println(" s]\t| <<");

          counterA =0;
          stateModeC = 3;
          digitalWrite(ledA, LOW);
          digitalWrite(ledB, HIGH);
          for(int y = 0; y < 3;y++)
          {
            digitalWrite(laserA, LOW);
            digitalWrite(laserB, LOW);
            delay(100);
            digitalWrite(laserA, HIGH);
            digitalWrite(laserB, HIGH);
            delay(100);
            digitalWrite(laserA, LOW);
            digitalWrite(laserB, LOW);
          }
          break;
        }
      }
    }
    if(stateModeC == 3)
    {
      delay(500);
      calculateVelocityReverse();
      delay(500);
      calculateAccelerationReverse();
      delay(500);
      stateMode = 0;
      stateModeA = 0;
    }
  }

}
