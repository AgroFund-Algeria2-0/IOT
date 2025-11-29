#define BLYNK_TEMPLATE_ID "TMPL3bD3AW9sI"
#define BLYNK_TEMPLATE_NAME "Smart Irrigation"
#define BLYNK_AUTH_TOKEN "DJQVS8MpwISaJ7v8iZkDcmDUGEpJI0c-"
#include <DHT.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal.h>
#include <ESP32Servo.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTTYPE DHT22
#define LOOP_DELAY 2000
#define NUM_AREAS 3 

const int DHT_PINS[NUM_AREAS] = {13, 15, 17};
const int SERVO_PINS[NUM_AREAS] = {34, 40, 26};
const int LED_PINS[NUM_AREAS] = {14, 12, 33};

int humidityThresholds[NUM_AREAS] = {40, 45, 50};
float temperatureThresholds[NUM_AREAS] = {30.0, 28.0, 32.0};

DHT sensors[NUM_AREAS] = {DHT(DHT_PINS[0], DHTTYPE), DHT(DHT_PINS[1], DHTTYPE), DHT(DHT_PINS[2], DHTTYPE)};
Servo waterPumps[NUM_AREAS];
bool isIrrigationActive[NUM_AREAS] = {false, false, false};

LiquidCrystal lcd(19, 4, 18, 21, 5, 15);

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("System Starting...");
  delay(2000);
  lcd.clear();
  lcd.print("Connecting WiFi...");
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
  lcd.print("System Ready");
  Serial.println("Setup complete. System is ready.");

  for (int i = 0; i < NUM_AREAS; i++) {
    sensors[i].begin();
    waterPumps[i].attach(SERVO_PINS[i]);
    waterPumps[i].write(0); 
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
}

void loop() {
  Blynk.run();
  for (int i = 0; i < NUM_AREAS; i++) {
    float temperature = sensors[i].readTemperature();
    float humidity = sensors[i].readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.print("Error: Area ");
      Serial.print(i + 1);
      Serial.println(" Sensor Error!");
      continue;
    }

    Serial.print("Area ");
    Serial.print(i + 1);
    Serial.print(" - Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Blynk.virtualWrite(V6 + i * 2, temperature); 
    Blynk.virtualWrite(V7 + i * 2, humidity);  

    if (shouldIrrigate(humidity, temperature, humidityThresholds[i], temperatureThresholds[i])) {
      activateIrrigation(i);
    } else {
      deactivateIrrigation(i);
    }
  }

  delay(LOOP_DELAY);
}

bool shouldIrrigate(float humidity, float temperature, int humidityThreshold, float temperatureThreshold) {
  if (humidity < humidityThreshold && temperature > temperatureThreshold) {
    return true;
  }
  return false;
}

void activateIrrigation(int area) {
  if (!isIrrigationActive[area]) {
    Serial.print("Area ");
    Serial.print(area + 1);
    Serial.println(" - Irrigation ON");
    digitalWrite(LED_PINS[area], HIGH);
    Blynk.virtualWrite(V1 + area, 1); 
    isIrrigationActive[area] = true;
    waterPumps[area].write(180); 
  }
}

void deactivateIrrigation(int area) {
  if (isIrrigationActive[area]) {
    Serial.print("Area ");
    Serial.print(area + 1);
    Serial.println(" - Irrigation OFF");
    digitalWrite(LED_PINS[area], LOW);
    Blynk.virtualWrite(V1 + area, 0); 
    isIrrigationActive[area] = false;
    waterPumps[area].write(0); 
  }
}

