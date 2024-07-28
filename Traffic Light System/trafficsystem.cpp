// C++ code to direct traffic, including emergency veh. light to stop all traffic

#include "LiquidCrystal.h"

LiquidCrystal lcd(12,11,5,4,3,2);

//white LED for emergency vehicle
#define LED_PIN 8 

#define BUTTON_PIN 7

byte lastButtonState = LOW;
byte ledState = LOW;
unsigned long debounceDuration = 50; // ms of delay
unsigned long lastTimeButtonStateChanged = 0;

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lcd.begin(16, 2);
  
}

void loop()
{
  if (millis() - lastTimeButtonStateChanged > debounceDuration) 
  {
    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) 
    {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) 
      {
        ledState = (ledState == HIGH) ? LOW: HIGH;
        digitalWrite(LED_PIN, ledState);
      }
    }
  }
  
  //if white light is on, print emergency vehicle, else dont print
  if (digitalRead(8) == HIGH)
  {
    digitalWrite(9, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Emergency");

    lcd.setCursor(0, 1);
    lcd.print("Vehicle");
  }
  
  else 
  {
    if (digitalRead(8) == LOW)
  	{
    	lcd.clear();
  	}
  }
  
  //Red light
  digitalWrite(9, HIGH);
  lcd.print("Remain stopped");
  delay(5000); // Wait for 5s
  digitalWrite(9, LOW);
  lcd.clear();
  delay(500); // Wait for 0.5s

  //Green light
  digitalWrite(6, HIGH);
  lcd.print("Proceed on");
  delay(10000); // Wait for 10s
  digitalWrite(6, LOW);
  lcd.clear();
  delay(500); // Wait for 0.5s
  
  //Yellow light
  digitalWrite(10, HIGH);
  lcd.print("Slow down");
  delay(5000); // Wait for 5s
  digitalWrite(10, LOW);  
  lcd.clear();
  delay(500); // Wait for 0.5s
  
  
  //Red light
  digitalWrite(9, HIGH);
  lcd.print("Stop");
  delay(5000); // Wait for 5s
  lcd.clear();
  
}
