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
