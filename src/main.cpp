#include <Arduino.h>


// pins

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

unsigned long t_delta_one_two_i;
unsigned long t_delta_one_two_ii;
unsigned long t_delta_three_four_i;
unsigned long t_delta_three_four_ii;

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

float VLCTY_A_i;
float VLCTY_A_f;
float VLCTY_B_i;
float VLCTY_B_f;

float VLCTY_STRT_AB_i;
float VLCTY_STRT_AB_f;
float VLCTY_FNSH_AB_i;
float VLCTY_FNSH_AB_f;

float acc_a_i;
float acc_a_ii;
float acc_a_iii;
float acc_a_iv;



float distanceTRLY = 0.163;
float distanceCNTR = 0.5;

void calculateVelocity(int print_period)
{
  Serial.println("\n## ---- ---- ---- ---- ----   VELOCITY   ---- ---- ---- ---- ---- ##");
  delay(print_period);
//------------------------------------------------------------------------
Serial.print(">> |A_TRLLY_i");
  delay(print_period);

  t_delta_one = t_one_f - t_one_i;
      Serial.print("\t|delta: ");
      Serial.print(t_delta_one);
        delay(print_period);

  timerSECS_A_i = (float)t_delta_one / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_A_i);
        delay(print_period);

  VLCTY_A_i = distanceTRLY / timerSECS_A_i;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_A_i);
      Serial.println("\t| <<");
        delay(print_period);
//------------------------------------------------------------------------
Serial.print(">> |AB_STRT_i");
    delay(print_period);

  t_delta_one_two_i = t_two_i - t_one_i;
    Serial.print("\t|delta: ");
    Serial.print(t_delta_one_two_i);
      delay(print_period);

  timerSECS_STRT_AB_i = (float)t_delta_one_two_i / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_STRT_AB_i);
      delay(print_period);

  VLCTY_STRT_AB_i = distanceCNTR / timerSECS_STRT_AB_i;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_STRT_AB_i);
    Serial.println("\t| <<");
      delay(print_period);
//------------------------------------------------------------------------
Serial.print(">> |AB_FNSH_i");
    delay(print_period);

  t_delta_one_two_ii = t_two_f - t_one_f;
    Serial.print("\t|delta: ");
    Serial.print(t_delta_one_two_ii);
      delay(print_period);

  timerSECS_FNSH_AB_i = (float)t_delta_one_two_ii / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_FNSH_AB_i);
      delay(print_period);

  VLCTY_FNSH_AB_i = distanceCNTR / timerSECS_FNSH_AB_i;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_FNSH_AB_i);
    Serial.println("\t| <<");
      delay(print_period);

//------------------------------------------------------------------------
Serial.print(">> |B_TRLLY_i");
  delay(print_period);

  t_delta_two = t_two_f - t_two_i;
    Serial.print("\t|delta: ");
    Serial.print(t_delta_two);
      delay(print_period);

  timerSECS_B_i = (float)t_delta_two / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_B_i);
      delay(print_period);

  VLCTY_B_i = distanceTRLY / timerSECS_B_i;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_B_i);
    Serial.println("\t| <<");
      delay(print_period);
//------------------------------------------------------------------------
Serial.print(">> |B_TRLLY_f");
    delay(print_period);
  t_delta_three = t_three_f - t_three_i;
    Serial.print("\t|delta: ");
    Serial.print(t_delta_three);
      delay(print_period);

  timerSECS_B_f = (float)t_delta_three / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_B_f);
      delay(print_period);

  VLCTY_B_f = distanceTRLY / timerSECS_B_f;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_B_f);
    Serial.println("\t| <<");
      delay(print_period);

//------------------------------------------------------------------------
Serial.print(">> |AB_CNTR_f");
    delay(print_period);

  t_delta_three_four_i = t_four_i - t_three_i;
    Serial.print("\t|delta: ");
    Serial.print(t_delta_three_four_i);
      delay(print_period);

  timerSECS_STRT_AB_f = (float)t_delta_three_four_i / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_STRT_AB_f);
      delay(print_period);

  VLCTY_STRT_AB_f = distanceCNTR / timerSECS_STRT_AB_f;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_STRT_AB_f);
    Serial.println("\t| <<");
      delay(print_period);

//------------------------------------------------------------------------
Serial.print(">> |AB_FNSH_f");
    delay(print_period);

  t_delta_three_four_ii = t_four_f - t_three_f;
    Serial.print("\t|delta: ");
    Serial.print(t_delta_three_four_ii);
      delay(print_period);

  timerSECS_FNSH_AB_f = (float)t_delta_three_four_ii / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_FNSH_AB_f);
      delay(print_period);

  VLCTY_FNSH_AB_f = distanceCNTR / timerSECS_FNSH_AB_f;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_FNSH_AB_f);
    Serial.println("\t| <<");
      delay(print_period);

//------------------------------------------------------------------------

Serial.print(">> |A_TRLLY_f");
    delay(print_period);

  t_delta_four = t_four_f - t_four_i;
    Serial.print("\t|delta: ");
    Serial.print(t_delta_four);
      delay(print_period);

  timerSECS_A_f = (float)t_delta_four / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_A_f);
      delay(print_period);

  VLCTY_A_f = distanceTRLY / timerSECS_A_f;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_A_f);
    Serial.println("\t| <<");
      delay(print_period);
}
void timerReadyPrint(int flash_period_on, int flash_period_off)
{
Serial.println("## ---- ---- ----   TIMER  READY   ---- ---- ---- ##");
for(int x = 0; 0>3 ;x++)
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
}
digitalWrite(laserA, HIGH);
digitalWrite(laserB, HIGH);
digitalWrite(ledB, HIGH);
}
//------------------------------------------------------------------------------
void calculateAcceleration(int acc_delay)
{
Serial.println("\n## ---- ---- ---- ----    ACCELERATION    ---- ---- ---- ---- ##");
delay(acc_delay);

Serial.print(">> |a_i");
    delay(acc_delay);

    // initial
  float velocity_i = VLCTY_A_i;
  Serial.print("\t|v_i: ");
  Serial.print(velocity_i);
  delay(acc_delay);
  // final
  float velocity_f= VLCTY_B_i;
  Serial.print("\t\t|v_f: ");
  Serial.println(velocity_f);
  delay(acc_delay);

  float velocity_i_sq = velocity_i*velocity_i;
  Serial.print("\t|v_i_sq: ");
  Serial.print(velocity_i_sq);
  delay(acc_delay);
  // final
  float velocity_f_sq =velocity_f*velocity_f;
  Serial.print("\t\t|v_f_sq: ");
  Serial.println(velocity_f_sq);
  delay(acc_delay);

  float velocity_delta= velocity_f_sq - velocity_i_sq;

  Serial.print("\t|v_delta: ");
  Serial.println(velocity_delta,6);
  delay(acc_delay);

  float two_distance = distanceCNTR * 2.00;
  Serial.print("\t|2x: ");
  Serial.println(two_distance,2);
  delay(acc_delay);

  float acc_a_i = velocity_delta / two_distance;

  Serial.print("|acc_a_i: ");
  Serial.println(acc_a_i,5);
  delay(acc_delay);
}
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

calculateVelocity(100);
calculateAcceleration(200);
// ##################################################ACCELERATION

//
//   timerSECS_A_f = (float)t_delta_four / 1000000.00;
//     Serial.print("\t|secs: ");
//     Serial.print(timerSECS_A_f);
//       delay(250);
//
//   VLCTY_A_f = distanceTRLY / timerSECS_A_f;
//     Serial.print("\t|velo: ");
//     Serial.print(VLCTY_A_f);
//     Serial.println("\t| <<");
//       delay(250);
  }
  else
  {
    buttonAstate = 0;
  }
  if(buttonBraw > buttonThreshold)
  {
    buttonBstate = 1;

    stateMode = 1;
    timerReadyPrint(100,50);


  }
  else
  {
    buttonBstate = 0;
  }
  if(buttonCraw > buttonThreshold)
  {
    buttonCstate = 1;


  }
  else
  {
    buttonCstate = 0;
  }
}
//------------------------------------------------------------------------------
void printButtonState()
{
  Serial.print(">> | SAT - A | ");
  Serial.print(buttonAstate);
  Serial.print("\t| SAT - B | ");
  Serial.print(buttonBstate);
  Serial.print("\t| SAT - C |");
  Serial.print(buttonCstate);
  Serial.print("\t| <<");
}
//------------------------------------------------------------------------------
void checkSensors()
{

  stateA = digitalRead(sensorA);
  stateB = digitalRead(sensorB);

}
//------------------------------------------------------------------------------
void printCheckSensors()
{
  Serial.print(">> | SNS - A | ");
  Serial.print(stateA);
  Serial.print("\t| SNS - B |");
  Serial.print(stateB);
  Serial.print("\t| <<");
}

void laserLedFlash()
{

}


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||SETUP||||||||
void setup()
{

  Serial.begin(9600);


  Serial.println("#######################################################");
  Serial.println("    LASER TIMER, VELOCITY, ACCELERATION AND ENERGY");
  Serial.println("#######################################################");
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

//---------------------------------------------------------------------ONE-----
if (stateMode == 1)
{
  stateA = digitalRead(sensorA);
    while (stateA == 0)
    {
        if (counterA == 0)
        {
          t_one_i = micros();
          Serial.print(">> |TIMER_A_i");
          Serial.print("\t|STRT: ");
          Serial.print(t_one_i);
          counterA = 1;
        }
      stateA = digitalRead(sensorA);
      if(stateA == 1)
      {
        t_one_f = micros();

        Serial.print("\t|FNSH: ");
        Serial.print(t_one_f);
        Serial.println("\t| <<");


        counterA =0;
        stateMode = 2;

        break;
      }
    }
}
//---------------------------------------------------------------------TWO-----
if (stateMode == 2)
{
  stateB = digitalRead(sensorB);
    while (stateB == 0)
    {

        if (counterB == 0)
        {
          t_two_i = micros();

          Serial.print(">> |TIMER_B_i");
          Serial.print("\t|STRT: ");
          Serial.print(t_two_i);
          counterB = 1;
        }

      stateB = digitalRead(sensorB);
      if(stateB == 1)
      {

        t_two_f = micros();

        Serial.print("\t|FNSH: ");
        Serial.print(t_two_f);
        Serial.println("\t| <<");



        counterB =0;
        stateMode = 3;

        break;
      }
    }
}
//---------------------------------------------------------------------THREE----
if (stateMode == 3)
{
  stateB = digitalRead(sensorB);
    while (stateB == 0)
    {
      if (counterB == 0)
        {

          t_three_i = micros();

          Serial.print(">> |TIMER_B_f");
          Serial.print("\t|STRT: ");
          Serial.print(t_three_i);
          counterB = 1;

        }

      stateB = digitalRead(sensorB);

      if(stateB == 1)
      {

        t_three_f = micros();
        Serial.print("\t|FNSH: ");
        Serial.print(t_three_f);
          Serial.println("\t| <<");


        counterB =0;
        stateMode = 4;
        break;
      }
    }
}
//---------------------------------------------------------------------FOUR----
if (stateMode == 4)
{
  stateA = digitalRead(sensorA);
  while (stateA == 0)
  {
    if (counterA == 0)
    {
      t_four_i = micros();

      Serial.print(">> |TIMER_A_f");
      Serial.print("\t|STRT: ");
      Serial.print(t_four_i);
      counterA = 1;
    }

    stateA = digitalRead(sensorA);
    if(stateA == 1)
    {

      t_four_f = micros();
      Serial.print("\t|FNSH: ");
      Serial.print(t_four_f);
        Serial.println("\t| <<");

      counterA =0;
      stateMode = 0;
          digitalWrite(ledA, LOW);
          digitalWrite(ledB, HIGH);
      break;
    }
  }
}



}
