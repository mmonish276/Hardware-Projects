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

## Code Information
#### The C++ code performs the following functions:

#### 1. LiquidCrystal Library: Controls the 16x2 LCD to display distance information.
#### 2. Servo Library: Moves the ultrasonic sensor across a 180-degree range.
#### 3. Ultrasonic Sensor: Measures the distance to objects.
#### 4. LED and Buzzer: Provide visual and auditory alerts when an object is detected.
#### 5. Servo Motor: Sweeps the ultrasonic sensor from 0 to 180 degrees to detect objects.
#### 6. Distance Measurement: Uses the ultrasonic sensor to calculate and display the distance of detected objects.
##
#### For more detailed information about the design and code, refer to the Hardware.md file and the .cpp code file(s) in this folder.
