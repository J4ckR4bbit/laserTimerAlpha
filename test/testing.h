
/*
This bit of code is run when testing it provides
predetermined values for the laser timing.
*/
/*
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

*/
