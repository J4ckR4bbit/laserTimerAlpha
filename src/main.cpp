#include <Arduino.h>
#include <Nokia_LCD.h>
#include <graphics.h>
#include <variables.h>

// #include<testing.h> //used when unconnected from system
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||LCD||||||||||||||||||||||||||||||||||||||||||||||||||||

const byte lcdPinCLK = 8;
const byte lcdPinDIN = 9;
const byte lcdPinDC = 10;
const byte lcdPinCE = 11;
const byte lcdPinRST = 12;
const byte lcdPinLED = 13;
// Nokia_LCD lcd(CLK, DIN, DC, CE, RST );
Nokia_LCD lcd(lcdPinCLK, lcdPinDIN, lcdPinDC, lcdPinCE, lcdPinRST);

#include<calculations.h>
#include<interface.h>


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||ARDUINO PINS |||||||||||||||||||||||||||||||||||||||||
int sensorPinA = 2;
int sensorPinB = 3;
int sensorC = 7;

int laserA = 4;
int laserB = 5;
int laserC = 6;

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||FUNTIONS |||||||||||||||||||||||||||||||||||||||||||||
//---------------------------------------------------------------------------------------------------------------------
void switchLCD_LED(bool stateLCD_LED)
{
  if(stateLCD_LED == false) {
    digitalWrite(lcdPinLED, LOW);
    Serial.println("##  \tLCD_LED |OFF| \t ##");
  }
  if(stateLCD_LED == true) {
    digitalWrite(lcdPinLED, HIGH);
    Serial.println("##  \tLCD_LED |ON | \t ##");
  }
}
//---------------------------------------------------------------------------------------------------------------------
void checkSig(byte chkPinA,byte chkPinB,byte chkPinC){

  Serial.print("??  \t"); // starts line with relavant symbol
  //checks the state of laser A
  if(chkPinA == true) {
    stateSigA = digitalRead(sensorPinA);
    if(stateSigA == false){
      Serial.print(F("lsrA | LOW|\t");
    }
    if(stateSigA == true){
      Serial.print(F("lsrA |HIGH|\t");
    }
  }
  else{
    Serial.print(F("lsrA |null|\t");
  }

  //checks the state of laser B
  if(chkPinB == true) {
    stateSigB = digitalRead(sensorPinB);
    if(stateSigB == false){
      Serial.print(F("lsrA | LOW|\t");
    }
    if(stateSigB == true){
      Serial.print(F("lsrA |HIGH|\t");
    }
  }
  else{
    Serial.print(F("lsrA |null|\t");
  }

//---------------------------------------------------------------------------------------------------------------------
//switches a laser on or off.
void switchLaserOn (bool lsrA,bool lsrB,bool lsrC){
  if(lsrA == true)
  {
    digitalWrite(laserA, HIGH);
    Serial.print(F(">>  \tlsrA| ON|\t<<");
  }
  else{
    digitalWrite(laserA, LOW);
    Serial.print(F(">>  \tlsrA| OFF|\t<<");
  }
  if(lsrA == true)
  {
    digitalWrite(laserB, HIGH);
    Serial.print(F(">>  \tlsrB| ON|\t<<");
  }
  else{
    digitalWrite(laserA, LOW);
    Serial.print(F(">>  \tlsrA| OFF|\t<<");
  }
  if(lsrA == true)
  {
    digitalWrite(laserA, HIGH);
    Serial.print(F(">>  \tlsrA| ON|\t<<");
  }
  else{
    digitalWrite(laserA, LOW);
    Serial.print(F(">>  \tlsrA| OFF|\t<<");
  }
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||SETUP|||||||||||||||||||||||||||||||||||||||||||||||||||
void setup()
{
  pinMode(sensorPinA, INPUT);
  pinMode(sensorPinB, INPUT);
  pinMode(laserA, OUTPUT);
  pinMode(laserB, OUTPUT);
  pinMode(sensorC, INPUT);
  pinMode(laserC, OUTPUT);
  pinMode(lcdPinLED, OUTPUT);

  // Initialize Serial Comms
  Serial.begin(9600);
  serialStartUp();


  // Initialize LCD screen
  lcd.begin();
  lcd.setContrast(47);
  switchLCD_LED(true):
  lcdStartUp();







}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||LOOP|||||||||||||||||||||||||||||||||||||||||||||||||||||
void loop()
{


}
