// C++ code to detect objects via ultrasonic dist. sensor

#include "LiquidCrystal.h"
#include <Servo.h>

Servo servo_6;

//LCD pins
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  pinMode(9, OUTPUT); //LED pin
  pinMode(10, OUTPUT); //piezo/buzz pin
  pinMode(6, OUTPUT); //servo pin
  lcd.begin(16, 2);
  servo_6.attach(6, 500, 2500); 
}

void loop() 
{
  for (int pos = 0; pos <= 180; pos += 1) 
  {
    servo_6.write(pos);
    delay(80);
    measureDistance(); // Measure distance after servo moves
  }
  
  for (int pos = 180; pos >= 0; pos -= 1) 
  {
    servo_6.write(pos);
    delay(80);
   measureDistance(); // Measure distance after servo moves
  }
}

void measureDistance() 
{
  pinMode(7, OUTPUT); //dist sensor

  // Trigger the ultrasonic sensor
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(5); // 5 ms pulse for distance sensor
  digitalWrite(7, LOW);
  
  pinMode(7, INPUT); // Switch to input to read signal
  
  long time = pulseIn(7, HIGH);
  int cm_dist = time * 0.034 / 2; // Calculate distance in centimeters
  
  // Print distance to LCD if object detected within range
  if (cm_dist < 200)
  {
    lcd.clear(); // Clear LCD screen
    lcd.setCursor(0, 0);
    lcd.print("Object Detected");
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(cm_dist);
    lcd.print(" cm");
    delay(1000);
  }
  
  if (cm_dist < 200) 
  {
   	digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    tone(10, 500);
    delay(1000);
    noTone(10);
    delay(500);
  }
  
  else 
  {
    digitalWrite(9, LOW);
   	digitalWrite(10, LOW);
    noTone(10);
    lcd.clear();
  }
}
