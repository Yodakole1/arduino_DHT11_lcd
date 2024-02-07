#include <LiquidCrystal.h>
#include <DHT.h>

//Declaration
const int senzor_pin = 8;
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

DHT dht11 (senzor_pin, DHT11);

float temp  = 0;
float vlaznost = 0;

//Setup
void setup() {
  lcd.begin(16, 2);
  lcd.print("Started ");
  delay(1200);
  lcd.clear();
  lcd.setCursor(0,0);
  dht11.begin();

}

//Main parts
void loop() {

  lcd.print("Ready");
  temp = dht11.readTemperature();
  vlaznost = dht11.readHumidity();
  delay(1500);
  lcd.clear();

  lcd.print("Temperature ");
  delay(4000);
  lcd.clear();
  lcd.print(temp);
  lcd.print(" C");
  delay(3000);
  lcd.clear();
  delay(300);

  lcd.print("Humidity ");
  delay(4000);
  lcd.clear();
  lcd.print(vlaznost);
  lcd.print("%");
  delay(5000);
  lcd.clear();

  delay(4000);
}
