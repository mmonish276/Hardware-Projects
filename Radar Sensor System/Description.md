# Radar Sensor System

## Description
#### The Radar Sensor System is designed to detect objects within a specified range using an ultrasonic distance sensor. The sensor is mounted on a servo motor, allowing it to rotate 180 degrees and expand its field of view. When an object is detected, the system triggers an alarm sound through a piezo buzzer and illuminates a red LED as a visual alert. Additionally, the distance to the detected object is displayed on a 16x2 LCD screen.

## Components Used
#### 1. Red LED
#### 2. Potentiometer
#### 3. Ultrasonic Distance Sensor
#### 4. 100 Ohm and 1 kOhm Resistors
#### 5. 16x2 LCD Screen
#### 6. Arduino Uno R3
#### 7. Breadboard
#### 8. Positional Microservo
#### 9. Piezo Buzzer

## Purposes of Key Components

1. **Ultrasonic Distance Sensor**
   - Measures the distance to an object using sound waves.
   - Triggered by sending a pulse and measuring the duration of the returned echo.

2. **Servo Motor**
   - Rotates the sensor across a 180-degree range to scan for objects.
   - Controlled to sweep from 0 to 180 degrees and back.

3. **LCD Display**
   - Shows the distance to the detected object.
   - Provides visual feedback if an object is detected within the specified range.

4. **LED and Piezo Buzzer**
   - Provides a visual and auditory alert when an object is detected.
   - The LED lights up, and the buzzer emits a sound if the object is within the detectable range.

## Code Description

1. **Libraries and Initialization**
   - Includes `LiquidCrystal` for LCD control and `Servo` for servo motor control.
   - Initializes the servo motor and LCD display.

2. **Setup Function**
   - Configures the pin modes for the LED, buzzer, and servo motor.
   - Attaches the servo motor to a specified pin and sets its range.

3. **Loop Function**
   - Rotates the servo from 0 to 180 degrees and back, scanning for objects.
   - Calls `measureDistance()` to get distance measurements after each servo movement.

4. **Measure Distance Function**
   - Triggers the ultrasonic sensor to emit a pulse and measures the time taken for it to return.
   - Calculates the distance and converts it to centimeters.
   - Updates the LCD with the distance if an object is detected within 200 cm.
   - Activates the LED and Piezo if the distance is less than 200 cm, and provides alerts.
   - Clears the LCD and deactivates the LED and buzzer if no object is detected within range.

## Usage

1. **Connect the Hardware**
   - Connect the ultrasonic sensor, servo motor, LCD display, LED, and buzzer to the specified pins on your microcontroller.

2. **Upload the Code**
   - Use the Arduino IDE to upload the provided code to your microcontroller.

3. **Observe the Output**
   - Watch the LCD for distance readings and the LED and buzzer for alerts when an object is detected.

## Requirements

- **Hardware**: Ultrasonic distance sensor, servo motor, LCD display, LED, buzzer.
- **Software**: Arduino IDE, required libraries (`LiquidCrystal`, `Servo`).
