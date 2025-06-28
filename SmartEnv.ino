#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <Wire.h>

// === OLED configuration ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === DHT11 configuration ===
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// === Sensor Pins ===
#define SOIL_PIN A0
#define RAIN_PIN 3
#define BUZZER_PIN 9

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RAIN_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED display not found!");
    while (true); // stop here if OLED not found
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 25);
  display.println("Smart Env Monitor");
  display.display();
  delay(2000); // Startup message
}

void loop() {
  // === Read Sensor Values ===
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilValue = analogRead(SOIL_PIN);
  bool isRaining = digitalRead(RAIN_PIN) == LOW;

  String soilStatus = (soilValue < 400) ? "Dry" : "Wet";
  String rainStatus = isRaining ? "Yes" : "No";

  // === Display Data on OLED ===
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temp: "); display.print(temperature); display.println(" C");
  display.print("Humidity: "); display.print(humidity); display.println(" %");
  display.print("Soil: "); display.print(soilStatus); display.print(" ("); display.print(soilValue); display.println(")");
  display.print("Rain: "); display.println(rainStatus);
  display.display();

  // === Print to Serial Monitor ===
  Serial.println("===== Environmental Data =====");
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity   : "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Soil       : "); Serial.print(soilValue); Serial.print(" -> "); Serial.println(soilStatus);
  Serial.print("Rain       : "); Serial.println(rainStatus);
  Serial.println("================================");
  Serial.println();

  // === Audio Alerts ===
  if (soilValue < 400) {
    tone(BUZZER_PIN, 1000, 400); // Dry soil alert
    delay(600);
  }

  if (isRaining) {
    tone(BUZZER_PIN, 1500, 300); // Rain alert
    delay(500);
  }

  if (temperature > 35.0) {
    tone(BUZZER_PIN, 1200, 600); // High temperature alert
    delay(800);
  }

  delay(3000); // Wait before next loop cycle
}
