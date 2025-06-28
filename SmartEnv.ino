#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED parameters
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET -1    
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT11 Sensor parameters
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 and OLED Test!"));

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.display(); // Show initial Adafruit logo
  delay(2000);
  display.clearDisplay(); // Clear the buffer

  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000); // Read sensor every 2 seconds

  // Read humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (is Fahrenheit is true)
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Failed to read from"));
    display.println(F("DHT sensor!"));
    display.display();
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius
  float hic = dht.computeHeatIndex(t, h);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  // Display values on OLED
  display.clearDisplay();
  display.setTextSize(2); 
  display.setTextColor(SSD1306_WHITE); 

  // Display Humidity
  display.setCursor(0, 0);
  display.print(F("Hum: "));
  display.print(h);
  display.println(F("%"));

  // Display Temperature in Celsius
  display.setCursor(0, 25);
  display.print(F("Temp: "));
  display.print(t);
  display.print((char)247); // Degree symbol
  display.println(F("C"));

  display.display(); // Update the display
}
