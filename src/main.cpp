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

int buttonAraw = 0;
int buttonBraw = 0;
int buttonCraw = 0;

int buttonAstate = 0;
int buttonBstate = 0;
int buttonCstate = 0;

int buttonThreshold = 768;

int counterA = 0;
int counterB = 0;

unsigned long timerStartA;
unsigned long timerEndA;
unsigned long timerDeltaA;

int testsA = 0;
int testsB = 0;

unsigned long timerStartB;
unsigned long timerEndB;
unsigned long timerDeltaB;

float distance = 0.163;

float timerSecondA;
float velocityA;
float timerSecondB;
float velocityB;


//------------------------------------------------------------------------------
void checkButtons()
{
  buttonAraw = analogRead(0);
  buttonBraw = analogRead(1);
  buttonCraw = analogRead(2);
}
//------------------------------------------------------------------------------
void printButtonAnalog()
{
  Serial.print(">> | BTN - A | ");
  Serial.print(buttonAraw);
  Serial.print("\t| BTN - B | ");
  Serial.print(buttonBraw);
  Serial.print("\t| BTN - C |");
  Serial.print(buttonCraw);
  Serial.print("\t| <<");
}
//------------------------------------------------------------------------------
void stateButton()
{
  checkButtons();
  if(buttonAraw > buttonThreshold)
  {
    buttonAstate = 1;
  }
  else
  {
    buttonAstate = 0;
  }
  if(buttonBraw > buttonThreshold)
  {
    buttonBstate = 1;
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
void PrintCheckSensors()
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

  Serial.print("Laser Tester");

  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
  pinMode(laserA, OUTPUT);
  pinMode(laserB, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  digitalWrite(laserA, HIGH);
  digitalWrite(ledA, HIGH);
  delay(500);
  digitalWrite(laserA, LOW);
  digitalWrite(ledA, LOW);
  delay(250);
  digitalWrite(laserA, HIGH);



  digitalWrite(laserB, HIGH);
  digitalWrite(ledB, HIGH);
  delay(500);
  digitalWrite(laserB, LOW);
  digitalWrite(ledB, LOW);
  delay(250);
  digitalWrite(laserB, HIGH);

}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void loop() {

checkSensors();


  while(digitalRead(sensorA) == LOW)
  {
    counterA++;

    if(counterA == 1)
    {
      timerStartA = micros();
      Serial.println("###############");
      Serial.print(">>>\t");
      Serial.print(testsA);
      Serial.println("\t<<<");
      Serial.println("-------------");
    }
      Serial.print(counterA);
      Serial.print(" - ");

      if ((counterA % 5) == 0)
      {
        Serial.println(" | ");
      }

    if(digitalRead(sensorA) == HIGH)
    {
      Serial.println(" | ");
      timerEndA = micros();
      testsA++;
      timerDeltaA = timerEndA - timerStartA;
      timerSecondA = (float)timerDeltaA / 1000000.00;
      velocityA = distance / timerSecondA;

      Serial.println("-------------");
      Serial.print("mcrs: ");
      Serial.println(timerDeltaA);
      Serial.println("-------------");
      Serial.print("secs: ");
      Serial.println(timerSecondA);
      Serial.println("-------------");
      Serial.print("| vlct:\t ");
      Serial.print(velocityA);
      Serial.println("\t|");
      //      Serial.println(counter);
      counterA = 0;

      break;
    }
  }
//------------------------------------------------------------------------------
  while(digitalRead(sensorB) == LOW)
  {
    counterB++;

    if(counterB == 1)
    {
      timerStartB = micros();
      Serial.println("###############");
      Serial.print(">>>\t");
      Serial.print(testsB);
      Serial.println("\t<<<");
      Serial.println("-------------");
    }
      Serial.print(counterB);
      Serial.print(" - ");

      if ((counterB % 5) == 0)
      {
        Serial.println(" | ");
      }

    if(digitalRead(sensorB) == HIGH)
    {
      Serial.println(" | ");
      timerEndB = micros();
      testsB++;
      timerDeltaB = timerEndB - timerStartB;
      timerSecondB = (float)timerDeltaB / 1000000.00;
      velocityB = distance / timerSecondB;

      Serial.println("-------------");
      Serial.print("mcrs: ");
      Serial.println(timerDeltaB);
      Serial.println("-------------");
      Serial.print("secs: ");
      Serial.println(timerSecondB);
      Serial.println("-------------");
      Serial.print("| vlct:\t ");
      Serial.print(velocityB);
      Serial.println("\t|");
      //      Serial.println(counter);
      counterB = 0;

      float velocityAhundred = velocityA*100.00;
      float velocityBhundred = velocityB*100.00;
      int acc = ((int)velocityBhundred^2) - ((int)velocityAhundred^2);
      float accPrint = (float)acc / 100.00;
      Serial.println("Acceleration * 100");
      Serial.println(acc);
      Serial.println("Acceleration");
      Serial.println(accPrint);
      break;
    }
  }

}
