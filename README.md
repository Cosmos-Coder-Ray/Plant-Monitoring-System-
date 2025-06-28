# 🌿 Smart Environmental Monitoring System

A compact and cost-effective Arduino-based project to monitor environmental parameters like temperature, humidity, soil moisture, and rain detection. The system displays real-time data on an OLED screen and provides audible alerts using a buzzer. Ideal for home gardening, school labs, smart irrigation, and weather monitoring.

---

## 📸 Project Overview

This project uses an Arduino UNO along with a DHT11, soil moisture sensor, rain sensor, and an OLED display to monitor environmental conditions. A buzzer gives sound alerts for dry soil, rain detection, or high temperature.

---

## 🛠️ Components Required

| Component                 | Quantity |
|---------------------------|----------|
| Arduino UNO               | 1        |
| V5 Sensor Shield (optional, but recommended) | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| Soil Moisture Sensor (AO + DO) | 1 |
| Rain Drop Sensor Module (AO + DO) | 1 |
| OLED Display (0.96", I2C) | 1 |
| Buzzer (Passive or Active) | 1 |
| Jumper Wires              | As needed |
| Breadboard                | Optional |
| 4Ω or 8Ω speaker (if using PAM8403) | Optional |

---

## 🧠 Features

- Monitors:
  - 🌡️ Temperature
  - 💧 Humidity
  - 🌱 Soil Moisture
  - 🌧️ Rain Detection
- Displays live data on OLED screen
- Buzzer alerts when:
  - Soil is too dry
  - It is raining
  - Temperature > 35°C
- Also prints data in Serial Monitor

---

## 🧪 Circuit Connections

### 🟢 Sensor Wiring

| Component               | Arduino Pin |
|-------------------------|-------------|
| DHT11                   | D2          |
| Rain Sensor (D0 Output) | D3          |
| Soil Moisture Sensor (AO) | A0        |
| OLED Display (I2C)      | SDA → A4, SCL → A5 |
| Buzzer                  | D9          |

> Connect all sensor **VCCs to 5V**, **GNDs to GND**.  
> Adjust soil & rain sensor sensitivity via onboard potentiometer.

---

## ⚙️ How to Build

### 1. Wiring
- Connect the sensors as per the table above.
- Place the OLED and buzzer accordingly.
- Use a breadboard or V5 sensor shield for easier setup.

### 2. Upload the Code
- Open the `Arduino IDE`.
- Install required libraries:
  - `Adafruit SSD1306`
  - `Adafruit GFX`
  - `DHT sensor library`
- Copy the code from `main.ino` or this repository.
- Select **Arduino UNO** board and upload.

### 3. Test the System
- Open **Serial Monitor** (9600 baud).
- Check OLED screen for data.
- Test buzzer alerts by:
  - Touching rain sensor with water
  - Inserting soil sensor into dry/wet soil
  - Heating DHT11 slightly

---

## 🖥️ Screenshot Preview

> Add OLED image here (optional)

---

## 🚀 Applications

- 🪴 **Smart Gardening** – know when to water plants
- 🧪 **School Lab Projects** – beginner-friendly electronics + IoT base
- 🌾 **Smart Farming** – soil/rain sensing on small scale
- 🏡 **Home Automation** – environmental monitoring station
- 🌦️ **Weather Stations** – basic local environment tracking

---

## 🔮 Future Scope

- IoT Integration with ESP8266 for cloud monitoring
- Add SD card module for logging data
- Use DFPlayer for voice alerts instead of beeps
- Auto-irrigation using a relay + water pump

---

## 📚 Libraries Used

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)

---

## 📝 License

This project is open-source under the MIT License. Feel free to fork and modify!

---

## ✍️ Author

Created by **[Your Name]**  
Student at **[Your School Name]** | Class **[Your Class & Section]**

