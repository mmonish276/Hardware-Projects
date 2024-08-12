# Traffic Light System Project

## Description
#### The Traffic Light System is a hardware design that simulates modern traffic control lights for intersections. This system features red, yellow, and green LEDs that operate on a timer to regulate vehicle flow. Additionally, a white LED is included to represent emergency vehicle warning lights and is activated when a pushbutton is pressed. An LCD display provides textual information corresponding to each light's status (e.g., "Red light is ON" will display "Stop" when the red LED is lit).

## Components Used
#### 1. Red, Yellow, Green, and White LEDs
#### 2. Potentiometer
#### 3. Pushbutton
#### 4. 100 Ohm & 1 kOhm Resistors
#### 5. 16x2 LCD Screen
#### 6. Arduino Uno R3
#### 7. Breadboard

## Code Information

#### The C++ code for this project implements the following:

#### 1. Emergency Mode: Features a pushbutton to activate a white LED for emergency vehicles. When the button is pressed, the system overrides the traffic lights and displays an emergency message on the LCD.

#### 2. Debouncing Logic: Includes a debounce mechanism to ensure reliable button presses by filtering out noise and accidental triggers.

#### 3. LED Control: Manages the state of multiple LEDs to represent traffic lights and emergency signals. The LEDs are controlled through digital I/O pins, with their state changes reflected through textual commands on the LCD.

#### For further details on the design and code implementation, feel free to refer to the Hardware.md file and the .cpp code file(s) in this folder.
