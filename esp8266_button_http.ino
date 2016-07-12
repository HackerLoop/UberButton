/*
 *  Press a button and send a post request
 *
 */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;

const int buttonPin = D2;
int buttonState = 0;
String url = "https://ewiqmhfpwe.execute-api.eu-central-1.amazonaws.com/prod/126lafayette/";
String gateway_token ="";
void Request();

void setup() {
    Serial.begin(115200);
    pinMode(buttonPin, INPUT);
    delay(10);

    // We start by connecting to a WiFi network
    WiFiMulti.addAP("bla", "blablabla");

    Serial.println();
    Serial.println();
    Serial.print("Wait for WiFi... ");

    while(WiFiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    delay(500);
}


void loop() {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      Serial.println("pressed");
      Request();
    } else {
      Serial.println("waiting for a press");
    }
    delay(250);
}

void Request() {
   HTTPClient http;
   http.begin(url, "70 05 FF 6C 40 C1 E8 26 22 BD 69 7C 2B 01 5B 7C 9F C3 63 47");
   http.addHeader("x-api-key", gateway_token);
   String payload = "{\"clickType\":\"SINGLE\"}"; 
   Serial.print("POST payload: "); Serial.println(payload);
   int httpCode = http.POST(payload);
   Serial.print("HTTP POST Response: "); Serial.println(httpCode); // HTTP code 200 means ok 
   http.end();
   delay (5000);
}

