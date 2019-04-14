

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

void serialStartUp()
{
  Serial.println("");
  Serial.println("#######################################################");
  Serial.println("    LASER TIMER, VELOCITY, ACCELERATION AND ENERGY");
  Serial.println("#######################################################");
  Serial.println("");


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

  lcd.draw(menuLogo, sizeof(menuLogo) / sizeof(menuLogo[0]), true);
  delay(x_bit);

  lcd.clear();
}
