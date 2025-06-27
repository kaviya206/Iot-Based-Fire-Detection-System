//source code along with blynk integration

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>


char ssid[] = "Wokwi-GUEST";
char pass[] = "";


#define DHTPIN 4
#define DHTTYPE DHT22
#define BUZZER 26
#define TEMP_HIGH 30  

#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_LINES 2

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
BlynkTimer timer;

void sendToBlynk(float temp, String alert) {
  Blynk.virtualWrite(V0, temp);   // Temperature
  Blynk.virtualWrite(V2, alert);  // Alert/status
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Fire Detector");
  lcd.setCursor(1, 1);
  lcd.print("Initializing");
  delay(1500);
  lcd.clear();

  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  float temp = dht.readTemperature();
  String alertMsg = "✅ Normal";

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println(" °C");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C   ");  

  if (temp > TEMP_HIGH) {
    tone(BUZZER, 1000); 
    lcd.setCursor(0, 1);
    lcd.print("High Temp!");
    alertMsg = "High Temp Alert!";
    Blynk.logEvent("fire_alert", alertMsg);  // Push notification
  } else {
    noTone(BUZZER); 
    lcd.setCursor(0, 1);
    lcd.print(" Status: Normal  ");
  }

  sendToBlynk(temp, alertMsg);
  delay(2000);
}
