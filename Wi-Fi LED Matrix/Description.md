# LED Matrix Project

## Description
#### The LED Matrix is a design that can display various images on a grid of Adafruit RGB Neopixels (256 in this project), extracting RGB values from hexadecimal image files uinder the control of a wireless ESP8266 ESP-01 Wireless Transceiver Module. The code is able to receive HTTP POST requests from the command prompt of a laptop and process it into a Neopixel LED display.

## Components Used
#### 1. Adafruit Neopixel Array (16x16)
#### 2. Potentiometer
#### 3. ESP8266 ESP-01 Wifi Module
#### 4. Male to Female and Male to Male jumper wires
#### 5. 3.3V Regulator (5V to 3.3V step-down)
#### 6. Arduino Uno R3
#### 7. Breadboard
#### 8. Optional: 100 uF capacitors for stable 3.3V to ESP8266's 8 pins

## Disclaimer
#### In order to convert images into valid hexadecimal data, [this link](https://notisrac.github.io/FileToCArray/) was used. From there, the data was pasted into a .txt file and all commas, spaces, and 0x hexadecimal identifiers were removed with [this tool:](https://onlinecaseconvert.com/remove-comma-online-tool/)
##

## Instructions 
#### Step 1: Compile the program onto Arduino IDE and the ESP8266
#### Step 2: Use the image to hexadecimal converters and processing links provided above to format the RGB data correctly in a .txt file
#### Step 3: Run the program and follow the instructions below after the ESP8266 is connected to Wi-Fi:

To send raw hex RGB data to the ESP8266, use the following `curl` command. Replace `<ESP8266 IP Address>` with the actual IP address of your ESP8266 device and `<Path to .txt file w/ raw hex RGB data>` with the path to your text file containing the RGB data.

```sh
curl -X POST http://<ESP8266 IP Address>/update \
-H "Content-Type: text/plain" \
--data-binary @"<Path to .txt file w/ raw hex RGB data>"
```

## Code Information

## Key Features

1. **Wi-Fi Connectivity**
   - The ESP8266 connects to a specified Wi-Fi network using the credentials provided in the code.
   - **Wi-Fi SSID**: `<Your Wi-Fi Name>`
   - **Password**: `<Your Wi-Fi Password>`

2. **NeoPixel LED Control**
   - The code controls a strip of NeoPixel LEDs connected to GPIO pin 2.
   - **Number of LEDs**: 256
   - The library `<Adafruit_NeoPixel.h>` manages the NeoPixels.

3. **HTTP Server Setup**
   - An HTTP server runs on port 80 and listens for POST requests at the `/update` endpoint.
   - The server processes incoming data to update the LED colors based on RGB values provided in the request.

4. **File System Access**
   - The ESP8266 uses the SPIFFS file system to read the RGB color data directly from the command line.

5. **Dynamic Brightness Adjustment**
   - The brightness of the NeoPixels is dynamically adjusted based on the value read from a potentiometer connected to analog pin A0.
   - The brightness is mapped from a range of 0-1023 (potentiometer) to 0-255 (LED brightness).

6. **Data Processing**
   - The server expects raw RGB color data in hexadecimal format sent in the body of the POST request.
   - Each color value is represented as a 6-character hexadecimal string.
   - Data validation ensures the correct length of the RGB data, and the number of colors does not exceed the number of LEDs.

7. **Error Handling**
   - The code includes error handling for common issues, such as missing data or invalid data length, and sends appropriate HTTP responses to the terminal & Arduino IDE Serial Monitor.

## Example Usage

1. **Upload the Code**
   - Upload the sketch to your ESP8266 board using the Arduino IDE.
   - Unplug the RESET pin of the ESP8266 from that of the Arduino.
   - Press the red RESET button on the Arduino and proceed after receiving Wifi connectivity confirmation.

2. **Send RGB Data**
   - Once the ESP8266 is connected to Wi-Fi, send RGB data to the ESP8266 using the following `curl` command:
     ```sh
     curl -X POST http://<ESP8266 IP Address>/update \
     -H "Content-Type: text/plain" \
     --data-binary @"<Path to .txt file with raw hex RGB data>"
     ```
   - Replace `<ESP8266 IP Address>` with your ESP8266’s IP address and `<Path to .txt file with raw hex RGB data>` with the path to your data file.

## Requirements

- **Hardware**: ESP8266 microcontroller, NeoPixel LED strip, potentiometer.
- **Software**: Arduino IDE, required libraries (`ESP8266WiFi`, `ESP8266WebServer`, `Adafruit_NeoPixel`, `FS`).

#### For further details on the design and code implementation, feel free to refer to the Hardware.md file and the .cpp code file(s) in this folder.

## Sources
#### The following sources were used both for research purposes in finding a suitable design and in providing guidance for hardware/code development.
##
#### 1. [Controlling addressable LEDs w/ ESP modules and WLED Software](https://www.youtube.com/watch?v=GYxctjukehY)
#### 2. [Introduction to Controlling Neopixels with Arduino](https://www.instructables.com/How-to-Get-Started-Controlling-Neopixels-With-an-A/)
#### 3. [Arduino Forum- Programming Neopixels](https://forum.arduino.cc/t/neopixel-arduino-uno-programing/986361/6)
#### 4. [Wiring and Testing ESP-01 Wifi Module](https://www.youtube.com/watch?v=FbHiz3O6JYk)
#### 5. [Arduino Forum- Processing HTTP requests in Arduino](https://forum.arduino.cc/t/is-this-the-best-way-to-get-data-from-a-http-request/678197/4)
#### 6. [Store and Retrieve Data from File](https://www.instructables.com/Arduino-IDE-How-to-Store-and-Retrieve-Data-From-a-/)
#### 7.[Arduino Form- Reading File Content](https://forum.arduino.cc/t/read-content-into-string/670475)
