
/*
This bit of code is run when testing it provides
predetermined values for the laser timing.
*/

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
