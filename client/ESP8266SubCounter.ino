#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include "JsonStreamingParser.h"
#include "Fetch.h"
#include <ArduinoJson.h>

#include "theSwedishMaker.h"


const uint16_t WAIT_TIME = 80000; //Time between fecthing data.


// Define the typ of hardware and the pins used. 

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   12
#define DATA_PIN  15
#define CS_PIN    13

// Hardware SPI connection
//MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

const char* serverName = "http://localhost:3000";

unsigned long lastTime = 0;
unsigned long timerDelay = 15000; //600000


// =======================================================================
// Configuration of router settings
// =======================================================================

const char* ssid     = "your_ssd";      // SSID of local network
const char* password = "your_password";       // Password of network

String currentMessage = "";
char charBuf[50];

void setup() 
{
  P.begin();
  P.setFont(fontSubs);
  
  // Connecting to wifi
  Serial.begin(115200);
  Serial.print("Connecting WiFi ");
  WiFi.begin(ssid, password);
  P.print("GALGANDO");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); delay(500);
  }
  Serial.println("");
  Serial.print("Connected: "); Serial.println(WiFi.localIP());
  
  P.displayScroll("Hello", PA_CENTER, PA_SCAN_HORIZX, 100);
}


void loop(void)
{
if (P.displayAnimate()) {
    P.displayReset();
  }

  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      timerDelay = 600000;

      WiFiClientSecure client;  // or WiFiClientSecure for HTTPS
      HTTPClient http;
      client.setInsecure();
      // Send request
      http.begin(client, serverName);
      int httpResponseCode = http.GET();

      // Print the response
      String payload = http.getString();

      P.displayReset();
      P.displayClear();

      if(currentMessage != payload) {

        //animation of new notification
        P.print("OMG!!!");
        delay(500);
        P.print("");
        delay(500);
        P.print("OMG!!!");
        delay(500);
        P.print("");
        delay(500);
        P.print("OMG!!!");
        delay(500);
        P.print("");
        delay(500);
        P.print("OMG!!!");
        delay(1000);
        currentMessage = payload;
        Serial.println("RESPONSE ");
        Serial.println(payload);

        //P.print(payload);
        payload.toCharArray(charBuf, 50);
        Serial.println("converted message: ");
        //Serial.println(charBuf[1]);
        P.displayReset();
        P.displayClear();
        P.displayScroll(charBuf, PA_CENTER, PA_SCROLL_LEFT, 100);


      } else {
        P.displayReset();
        P.displayScroll(charBuf, PA_CENTER, PA_SCROLL_LEFT, 100);
      }


      
      // FORMAT
      //String instaFollowers = num_format(followers);
      
      // PRINT
      //Serial.println(subsCount);
      //P.print("*" + subsCount); 
      //delay(3500);
      // P.print("*" + viewCount); //Uncomment if your want to show viewcount.
      // delay(3500); //Uncomment if you want to show viewcount.

    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}



