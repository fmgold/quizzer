
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "M4LW4RE";
const char* password = "p@s$w0&/=.";

//Your Domain name with URL path or IP address with path
const char* serverName = "http://13.245.101.82/api/v1/responses";

#define optionA D1
#define optionB D2
#define optionC D5
#define optionD D6


void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  pinMode(optionA, INPUT_PULLUP);
  pinMode(optionB, INPUT_PULLUP);
  pinMode(optionC, INPUT_PULLUP);
  pinMode(optionD, INPUT_PULLUP);
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  delay(2000);
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    //http.begin(client, serverName);
    // Specify content-type header
    //http.addHeader("Content-Type", "application/json");
    //http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    // Data to send with HTTP POST
    //String httpRequestData = "api_key=tPmAT5Ab3j7F9&sensor=BME280&value1=24.25&value2=49.54&value3=1005.14";
    // Send HTTP POST request
    //int httpResponseCode = http.POST(httpRequestData);

    // If you need an HTTP request with a content type: application/json, use the following:
    //http.addHeader("Content-Type", "application/json");
    //int httpResponseCode = http.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");

    // If you need an HTTP request with a content type: text/plain
    //http.addHeader("Content-Type", "text/plain");
    //int httpResponseCode = http.POST("Hello, World!");

    if (digitalRead(optionA) == 0) {
      Serial.println("Option A");
      HTTPClient http;
      http.begin(client, serverName);
      // Specify content-type header
      //http.addHeader("Content-Type", "application/json");
      //int httpResponseCode = http.POST("{\"contestant\":\"A\",\"option\":\"A\"}");
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST("{\"device\":\"1\",\"option\":\"A\"}");
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      // Free resources
      http.end();
    }

    if (digitalRead(optionB) == 0) {
      Serial.println("Option B");
      HTTPClient http;
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST("{\"device\":\"1\",\"option\":\"B\"}");
    }
    if (digitalRead(optionC) == 0) {
      HTTPClient http;
      http.begin(client, serverName);
      Serial.println("Option C");
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST("{\"device\":\"1\",\"option\":\"C\"}");
    }
    if (digitalRead(optionD) == 0) {
      HTTPClient http;
      http.begin(client, serverName);
      Serial.println("Option D");
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST("{\"device\":\"1\",\"option\":\"D\"}");
    }
  }



}
