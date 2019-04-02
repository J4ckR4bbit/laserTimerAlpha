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
unsigned long t_four_i;
unsigned long t_three_i;

unsigned long t_one_f;
unsigned long t_two_f;
unsigned long t_four_f;
unsigned long t_three_f;

unsigned long timerDLTA_A_i;
unsigned long timerDLTA_B_i;
unsigned long timerDLTA_A_f;
unsigned long timerDLTA_B_f;

unsigned long timerDLTA_STRT_AB_i;
unsigned long timerDLTA_FNSH_AB_i;
unsigned long timerDLTA_STRT_AB_f;
unsigned long timerDLTA_FNSH_AB_f;

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



//------------------------------------------------------------------------------
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



    Serial.println("\n## ---- ---- ---- ---- ----   VELOCITY   ---- ---- ---- ---- ---- ##");
    delay(250);



  //------------------------------------------------------------------------
  Serial.print(">> |A_TRLLY_i");
    delay(250);

    timerDLTA_A_i = t_one_f - t_one_i;
        Serial.print("\t|delta: ");
        Serial.print(timerDLTA_A_i);
          delay(250);

    timerSECS_A_i = (float)timerDLTA_A_i / 1000000.00;
        Serial.print("\t|secs: ");
        Serial.print(timerSECS_A_i);
          delay(250);

    VLCTY_A_i = distanceTRLY / timerSECS_A_i;
        Serial.print("\t|velo: ");
        Serial.print(VLCTY_A_i);
        Serial.println("\t| <<");
          delay(250);
  //------------------------------------------------------------------------
  Serial.print(">> |AB_STRT_i");
      delay(250);

    timerDLTA_STRT_AB_i = t_two_i - t_one_i;
      Serial.print("\t|delta: ");
      Serial.print(timerDLTA_STRT_AB_i);
        delay(250);

    timerSECS_STRT_AB_i = (float)timerDLTA_STRT_AB_i / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_STRT_AB_i);
        delay(250);

    VLCTY_STRT_AB_i = distanceCNTR / timerSECS_STRT_AB_i;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_STRT_AB_i);
      Serial.println("\t| <<");
        delay(250);
  //------------------------------------------------------------------------
  Serial.print(">> |AB_FNSH_i");
      delay(250);

    timerDLTA_FNSH_AB_i = t_two_f - t_one_f;
      Serial.print("\t|delta: ");
      Serial.print(timerDLTA_FNSH_AB_i);
        delay(250);

    timerSECS_FNSH_AB_i = (float)timerDLTA_FNSH_AB_i / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_STRT_AB_i);
        delay(250);

    VLCTY_FNSH_AB_i = distanceCNTR / timerSECS_FNSH_AB_i;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_FNSH_AB_i);
      Serial.println("\t| <<");
        delay(250);

  //------------------------------------------------------------------------
  Serial.print(">> |B_TRLLY_i");
    delay(250);

    timerDLTA_B_i = t_two_f - t_two_i;
      Serial.print("\t|delta: ");
      Serial.print(timerDLTA_B_i);
        delay(250);

    timerSECS_B_i = (float)timerDLTA_B_i / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_B_i);
        delay(250);

    VLCTY_B_i = distanceTRLY / timerSECS_B_i;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_B_i);
      Serial.println("\t| <<");
        delay(250);
  //------------------------------------------------------------------------
  Serial.print(">> |B_TRLLY_f");
      delay(250);
    timerDLTA_B_f = t_three_f - t_three_i;
      Serial.print("\t|delta: ");
      Serial.print(timerDLTA_B_f);
        delay(250);

    timerSECS_B_f = (float)timerDLTA_B_f / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_B_f);
        delay(250);

    VLCTY_B_f = distanceTRLY / timerSECS_B_f;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_B_f);
      Serial.println("\t| <<");
        delay(250);

  //------------------------------------------------------------------------
  Serial.print(">> |AB_CNTR_f");
      delay(250);

    timerDLTA_STRT_AB_f = t_four_i - t_three_i;
      Serial.print("\t|delta: ");
      Serial.print(timerDLTA_STRT_AB_f);
        delay(250);

    timerSECS_STRT_AB_f = (float)timerDLTA_STRT_AB_f / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_STRT_AB_f);
        delay(250);

    VLCTY_STRT_AB_f = distanceCNTR / timerSECS_STRT_AB_f;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_STRT_AB_f);
      Serial.println("\t| <<");
        delay(250);

  //------------------------------------------------------------------------
  Serial.print(">> |AB_FNSH_f");
      delay(250);

    timerDLTA_FNSH_AB_f = t_four_f - t_three_f;
      Serial.print("\t|delta: ");
      Serial.print(timerDLTA_FNSH_AB_f);
        delay(250);

    timerSECS_FNSH_AB_f = (float)timerDLTA_FNSH_AB_f / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_STRT_AB_f);
        delay(250);

    VLCTY_FNSH_AB_f = distanceCNTR / timerSECS_FNSH_AB_f;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_FNSH_AB_f);
      Serial.println("\t| <<");
        delay(250);

  //------------------------------------------------------------------------

  Serial.print(">> |A_TRLLY_f");
      delay(250);

    timerDLTA_A_f = t_four_f - t_four_i;
      Serial.print("\t|delta: ");
      Serial.print(timerDLTA_A_f);
        delay(250);

    timerSECS_A_f = (float)timerDLTA_A_f / 1000000.00;
      Serial.print("\t|secs: ");
      Serial.print(timerSECS_A_f);
        delay(250);

    VLCTY_A_f = distanceTRLY / timerSECS_A_f;
      Serial.print("\t|velo: ");
      Serial.print(VLCTY_A_f);
      Serial.println("\t| <<");
        delay(250);

//##################################################ACCELERATION
Serial.println("\n## ---- ---- ---- ----    ACCELERATION    ---- ---- ---- ---- ##");
delay(250);

Serial.print(">> |a_i");
    delay(250);

    Serial.print("\t|v_i: ");
    Serial.print(VLCTY_A_i);
      delay(250);

      Serial.print("\t|v_f: ");
      Serial.print(VLCTY_B_i);
        delay(250);


  timerSECS_A_f = (float)timerDLTA_A_f / 1000000.00;
    Serial.print("\t|secs: ");
    Serial.print(timerSECS_A_f);
      delay(250);

  VLCTY_A_f = distanceTRLY / timerSECS_A_f;
    Serial.print("\t|velo: ");
    Serial.print(VLCTY_A_f);
    Serial.println("\t| <<");
      delay(250);
  }
  else
  {
    buttonAstate = 0;
  }
  if(buttonBraw > buttonThreshold)
  {
    buttonBstate = 1;

    stateMode = 1;

    Serial.println("## ---- ---- ----   TIMER  READY   ---- ---- ---- ##");
    digitalWrite(laserA, HIGH);
    digitalWrite(laserB, HIGH);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    delay(150);
    digitalWrite(laserA, LOW);
    digitalWrite(laserB, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    delay(150);
    digitalWrite(laserA, HIGH);
    digitalWrite(laserB, HIGH);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    delay(150);
    digitalWrite(laserA, LOW);
    digitalWrite(laserB, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    delay(250);
    digitalWrite(laserA, HIGH);
    digitalWrite(laserB, HIGH);
    digitalWrite(ledB, HIGH);
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


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void setup()
{

  Serial.begin(9600);


  Serial.println("#######################################################");
  Serial.println("     LASER TIMER, VELOCITY, ACCELERATION AND ENERGY");
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

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
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
