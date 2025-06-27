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


This project is **fully simulated using Wokwi**, a virtual platform that enables real-time testing and visualization of embedded systems. It is also compatible with physical ESP32 boards and components.



## Features

- Real-time temperature monitoring using a DHT22 sensor
- Audible fire alert via active buzzer
- Visual display of temperature and fire status using an I2C LCD
- Manual mute button to disable the buzzer during an alert
- Real-time fire alerts and temperature logging on the Blynk IoT app
- Fully testable in Wokwi (online simulator) and deployable on real hardware



## Components Used

| Component         | Quantity | Description                               |
|------------------|----------|-------------------------------------------|
| ESP32 Dev Board  | 1        | Main microcontroller with WiFi capability |
| DHT22 Sensor     | 1        | Digital sensor for temperature readings   |
| Buzzer           | 1        | Audio output to indicate fire alert       |
| I2C LCD 20x4     | 1        | Displays temperature and system status    |
| Jumper Wires     | As needed| For making all necessary connections      |
| Breadboard       | Optional | For prototyping (if using real hardware)  |



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
3. If the temperature rises between **70°C and 80°C**, the system identifies it as a fire:
   - A **buzzer** is activated as a local alarm.
   - The **LCD** displays “FIRE DETECTED”.
   - The **Blynk app** receives:
     - An alert message via **Virtual Pin V0**

## Circuit Diagram

 Below is a screenshot of the Wokwi setup:
![Screenshot (87)](https://github.com/user-attachments/assets/097bfef8-2841-44e8-a89c-83b74a42faca)



## Pin Configuration

| ESP32 Pin | Connected Component | Description               |
|-----------|---------------------|---------------------------|
| GPIO 2    | DHT22 Data Pin      | Temperature input         |
| GPIO 12   | Buzzer              | Alert sound output        |
| GPIO 21   | LCD SDA             | I2C Data Line             |
| GPIO 22   | LCD SCL             | I2C Clock Line            |
| GND       | All component grounds | Common ground            |
| 3.3V / 5V | DHT22, LCD Power    | Depending on module specs |


## IoT Integration with Blynk

This project uses the **Blynk IoT platform** to provide cloud connectivity and real-time notifications to the user.


### Recommended Widgets on Blynk Mobile App:

| Widget Type | Virtual Pin | Description             |
|-------------|-------------|-------------------------|
| Label       | V0          | Displays fire alert     |


## Author
Kaviya
ECE Student
