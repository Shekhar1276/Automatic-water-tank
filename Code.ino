#include <LiquidCrystal.h>

#include <Wire.h>

#include <SoftwareSerial.h>

#define lenght 16.0

 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


 const char maxRange = 300;
 int triggerPIN=6; 
 int echoPIN=7;
 int relay=10;
 int LED = 8;
 int Buzzer=9;
 long duration, cm;
 int distance;
void setup()
{
   lcd.begin(16, 2);

   pinMode(triggerPIN ,OUTPUT);
   pinMode(echoPIN ,INPUT);
   pinMode(relay ,OUTPUT);
   pinMode(Buzzer ,OUTPUT);
   pinMode(LED, OUTPUT);
   Serial.begin(9600);
}


void loop()
{
   digitalWrite(triggerPIN, LOW);
   delay(10);
   digitalWrite(triggerPIN, HIGH);
   delay(10);
   digitalWrite(triggerPIN, LOW);
   duration = pulseIn(echoPIN, HIGH);
   distance = duration/58;
   lcd.clear();
  

  if (distance == 250 || distance == 70)
  
  {digitalWrite(Buzzer, HIGH);
   delay(200);
  }


  if ( distance >= 250)
  {
    digitalWrite(relay, HIGH);
    digitalWrite(LED, HIGH);
    delay(15000);
    lcd.setCursor(0, 0);
    lcd.print("Water level is");
      lcd.print("-");
    lcd.print(300-distance);
        lcd.print("cm");
    lcd.print("  Water level is low");
    for (int positionCounter = 0; positionCounter < 5; positionCounter++) {

 lcd.scrollDisplayLeft();
 delay(150);
 }
 for (int positionCounter = 0; positionCounter < 21; positionCounter++) {

 lcd.scrollDisplayRight();
 delay(150);
 }
    delay(100);
    lcd.clear(); 
}
 
  if (  distance  <= 70)
  {
    digitalWrite(relay, LOW);
    lcd.setCursor(0, 0);
        lcd.print("Water level is");
      lcd.print("-");
    lcd.print(300-distance);
    lcd.print("cm");
    lcd.print("  The tank is full");   
    for (int positionCounter = 0; positionCounter < 5; positionCounter++) {

 lcd.scrollDisplayLeft(); 
 delay(150);
    }
 for (int positionCounter = 0; positionCounter < 21; positionCounter++) {

 lcd.scrollDisplayRight(); 
 delay(150);
 }
    delay(100);
    lcd.clear();
  }
  if (distance <=175 && distance >=70)
  {
    lcd.setCursor(0,0);
        lcd.print("Water level is");
      lcd.print("-");
    lcd.print(300-distance);
        lcd.print("cm");
    lcd.print("  Water level is ok");
    for (int positionCounter = 0; positionCounter < 5; positionCounter++) {

 lcd.scrollDisplayLeft(); 
 delay(150);
 }
 for (int positionCounter = 0; positionCounter < 21; positionCounter++) {

 lcd.scrollDisplayRight(); 
 delay(150);
 }
    delay(100);
    lcd.clear();
  }
   if (distance <=250 && distance >=175)
  {
    digitalWrite(relay, HIGH);
     digitalWrite(LED, HIGH);
    lcd.setCursor(0,0);
         lcd.print("Water level is");
     lcd.print("-");
    lcd.print(300-distance);
         lcd.print("cm");
    lcd.print("  Water level is ok");
    for (int positionCounter = 0; positionCounter < 5; positionCounter++) {

 lcd.scrollDisplayLeft(); 
 delay(150);
 }
 for (int positionCounter = 0; positionCounter < 21; positionCounter++) {

 lcd.scrollDisplayRight(); 
 delay(150);
 }
    delay(100);
    lcd.clear();
  }
  }
