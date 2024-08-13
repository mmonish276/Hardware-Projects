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

## Purposes of Key Components

1. **White LED**
   - Represents the emergency vehicle.
   - Controlled by a button press to activate or deactivate.

2. **LCD Display**
   - Shows status messages and instructions to drivers.
   - Updates based on the state of the emergency vehicle and traffic light phases.

3. **Traffic Lights**
   - Red, green, and yellow LEDs simulate traffic light signals.

4. **Button**
   - Triggers emergency vehicle mode when pressed.

## Code Description

1. **Libraries and Initialization**
   - Includes the `LiquidCrystal` library for LCD control.
   - Defines pins for the emergency LED, traffic light LEDs, and button.
   - Initializes the LCD and sets pin modes.

2. **Setup Function**
   - Configures pins for output (LEDs) and input (button).

3. **Loop Function**
   - Implements debouncing for the button to detect state changes in push button.
   - Toggles the emergency LED state based on button presses.
   - Displays a message on the LCD when the emergency LED is on and for each other traffic light.

4. **Traffic Light Control**
   - **Red Light**: Turns on for 5 seconds with a message to "Remain stopped".
   - **Green Light**: Turns on for 10 seconds with a message to "Proceed on".
   - **Yellow Light**: Turns on for 5 seconds with a message to "Slow down".
   - **Red Light**: Cycles back to red for 5 seconds with a message to "Stop".

5. **Emergency Mode**
   - When the emergency LED is on, the system stops all traffic and displays an emergency message.
   - The traffic light cycle is paused during this mode.

#### For further details on the design and code implementation, feel free to refer to the Hardware.md file and the .cpp code file(s) in this folder.

## Sources Used:
#### 1. [How to Turn LED On/Off w/ Debounced Switch](https://roboticsbackend.com/arduino-turn-led-on-and-off-with-button/)
#### 2. Arduino's Forum
#### 3. [LED and Switch in Arduino](https://binaryupdates.com/led-and-switch-with-arduino-uno/)
