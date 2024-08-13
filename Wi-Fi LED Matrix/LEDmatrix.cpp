#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>
#include <FS.h>

const char* ssid = "<Wifi Name>"; 
const char* password = "<Wifi Password>"; 

#define NEOPIXEL_PIN 2  // GPIO pin connected to NeoPixels
#define NUM_PIXELS 256  // Number of NeoPixels
#define POTENTIO_PIN A0 //analong input pin for potentiometer
#define RGB_CHARS_PER_PIXEL 6   //rgb hex values needed to fix color of each pixel

Adafruit_NeoPixel pixels(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
ESP8266WebServer server(80);    //port 80 for data input

//function declr.
void process_request();

int brightness= 255;  //default brightness

void setup()
{
    Serial.begin(115200); //baud rate initialization to serial monitor
    
    pixels.begin();
    pixels.show();  //starting w/ all 'off'

    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.print(".");
        delay(500);
    }
    
    if (!SPIFFS.begin()) 
    {
        Serial.println("Failed to mount file system");
        return;
    }

    Serial.print("Wi-Fi Connected: HTTP POST Requests Acceptable!\n");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); //IP of ESP8266 module

    server.on("/update", HTTP_POST, process_request); //listen for HTTP requests after /update endpt.
    server.begin(); //server start
}

void loop()
{
    server.handleClient();

}

void process_request()
{
    int potentiometer_value = analogRead(POTENTIO_PIN);
    brightness = map(potentiometer_value, 0, 1023, 0, 255);   //map 0-1023 potentio. values to 0-255 brightness range of neopix

    // Read the raw POST data
    String rgb_HEX = server.arg("plain"); // Read the body of the POST request as plain text

    if (rgb_HEX.length() == 0) 
    {
        server.send(400, "text/plain", "No data received");
        return;
    }

    Serial.print("Received data length: ");
    Serial.println(rgb_HEX.length());

    int i;
    for (i = 0; i< rgb_HEX.length(); i++)
        ;
    
    //error-checking pre-processing

    if((i) % RGB_CHARS_PER_PIXEL != 0)    //length checking for hex data (each RGB hex code is 6 chars. long)
    {
        Serial.println("Invalid hex data length");
        server.send(400, "text/plain", "Invalid hex data length");
        return;
    }

    int numPixels = (rgb_HEX.length()) / 6;
    
    if (numPixels > NUM_PIXELS) 
    {
        Serial.println("Colors exceed available pixels");
        server.send(400, "text/plain", "Colors exceed available pixels");
        return;
    }
    //neopixel updating
    int hex_index = 0;  //index for HEX string (every 6th)
    int j= 0;   //pixel number

    while (j < numPixels)
    {
        String colorHex = rgb_HEX.substring(hex_index, hex_index + RGB_CHARS_PER_PIXEL); // Extract each 6-character color hex

        //color conversion HEX --> Numeric
        long color = strtol(colorHex.c_str(), NULL, 16);

        //extraction (bitwise ops)
        byte r = (color >> 16) & 0xFF;     //shifts red component to least significant pos. & extracts only last 8 bits
        byte g = (color >> 8) & 0xFF;       //same procedure as RED, but green= middle 8 bits
        byte b = color & 0xFF;

        r= (r* brightness) / 255;
        g= (g* brightness) / 255;
        b= (b* brightness) / 255;

        pixels.setPixelColor(j, pixels.Color(r, g, b));    

        hex_index+= RGB_CHARS_PER_PIXEL;
        j++;
    }
    pixels.show();
    server.send(200, "text/plain", "Data Processing Successful!");

}
