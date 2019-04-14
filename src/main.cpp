#include <Arduino.h>
#include <Nokia_LCD.h>
#include <graphics.h>
#include <variables.h>

// #include<testing.h> //used when unconnected from system
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||LCD||||||||

const int lcdPinCLK = 8;
const int lcdPinDIN = 9;
const int lcdPinDC = 10;
const int lcdPinCE = 11;
const int lcdPinRST = 12;
// Nokia_LCD lcd(CLK, DIN, DC, CE, RST );
Nokia_LCD lcd(lcdPinCLK, lcdPinDIN, lcdPinDC, lcdPinCE, lcdPinRST);

#include<calculations.h>
#include<interface.h>


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||SETUP||||||||
void setup()
{
  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
  pinMode(laserA, OUTPUT);
  pinMode(laserB, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);


  // Initialize Serial Comms
  Serial.begin(9600);
  serialStartUp();

  // Initialize LCD screen
  lcd.begin();
  lcd.setContrast(47);
  lcdStartUp();







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
