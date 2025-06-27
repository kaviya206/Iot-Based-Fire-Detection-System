# IoT-Based Fire Detection System 

## Project Description

This project demonstrates a smart **fire detection and alert system** using the **ESP32 microcontroller**, a **DHT22 digital temperature sensor**, a **20x4 I2C LCD**, and a **buzzer** for local alerts. The primary objective is to detect abnormal temperature rises that may indicate a fire and to respond immediately with both **local warnings** and **remote IoT-based alerts**.

The ESP32 constantly reads temperature values from the DHT22 sensor. If the temperature crosses a defined threshold (between 70°C and 80°C), the system recognizes this as a fire event. Upon detection:

- A **buzzer is activated** to alert nearby individuals.
- The **LCD** displays a warning message indicating the fire.
- The system sends a real-time alert and temperature value to the **Blynk IoT platform**, which notifies the user via the **Blynk mobile app or web dashboard**.

This project is especially useful in applications such as:
- Homes and offices
- Server or electrical rooms
- Laboratories
- Smart buildings or factories

In addition to detection, a **manual push button** is integrated to **mute the buzzer**, allowing users to acknowledge the alert without disabling the system.

This project is **fully simulated using Wokwi**, a virtual platform that enables real-time testing and visualization of embedded systems. It is also compatible with physical ESP32 boards and components.



## Features

- Real-time temperature monitoring using a DHT22 sensor
- Audible fire alert via active buzzer
- Visual display of temperature and fire status using an I2C LCD
- Manual mute button to disable the buzzer during an alert
- Real-time fire alerts and temperature logging on the Blynk IoT app
- Fully testable in Wokwi (online simulator) and deployable on real hardware



## Hardware Used

| Component         | Quantity | Description                               |
|------------------|----------|-------------------------------------------|
| ESP32 Dev Board  | 1        | Main microcontroller with WiFi capability |
| DHT22 Sensor     | 1        | Digital sensor for temperature readings   |
| Buzzer           | 1        | Audio output to indicate fire alert       |
| I2C LCD 20x4     | 1        | Displays temperature and system status    |
| Jumper Wires     | As needed| For making all necessary connections      |
| Breadboard       | Optional | For prototyping (if using real hardware)  |

---

## Software
- Wokwi Simulator
### Required Arduino Libraries:
- `DHT.h` — for reading data from the DHT22 sensor
- `Wire.h` — for I2C communication with the LCD
- `LiquidCrystal_I2C.h` — for driving the LCD
- `WiFi.h` — for ESP32 WiFi connectivity
- `BlynkSimpleEsp32.h` — for connecting to the Blynk IoT platform


## Working Principle

1. The **DHT22** sensor continuously reads temperature from the environment.
2. The temperature is displayed on the **LCD** in real time.
3. If the temperature rises, the system identifies it as a fire:
   - A **buzzer** is activated as a local alarm.
   - The **LCD** displays “FIRE DETECTED”.
   - The **Blynk app** receives:
     - An alert message via **Virtual Pin V0**
     - The current temperature via **Virtual Pin V1**
4. The user can press a **push button** to mute the buzzer while the alert continues to display and send data.


## Circuit Diagram

![Screenshot (87)](https://github.com/user-attachments/assets/12f80dba-5e54-4803-9ec2-c64722ce85fc)


## Pin Configuration

| ESP32 Pin | Connected Component | Description               |
|-----------|---------------------|---------------------------|
| GPIO 4   | DHT22 Data Pin      | Temperature input         |
| GPIO 12   | Buzzer              | Alert sound output        |
| GPIO 21   | LCD SDA             | I2C Data Line             |
| GPIO 22   | LCD SCL             | I2C Clock Line            |
| GND       | All component grounds | Common ground            |
| 3.3V / 5V | DHT22, LCD Power    | Depending on module specs |


## IoT Integration with Blynk

This project uses the **Blynk IoT platform** to provide cloud connectivity and real-time notifications to the user.

###  Widgets on Blynk Mobile App:

| Widget Type | Virtual Pin | Description             |
|-------------|-------------|-------------------------|
| Label       | V0          | Displays fire alert     |
| Gauge/Display | V1        | Displays temperature    |

## Author
Kaviya
ECE Student
