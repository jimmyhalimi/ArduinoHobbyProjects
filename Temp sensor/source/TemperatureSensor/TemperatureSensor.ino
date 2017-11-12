#include <Thermistor.h>
#include <LiquidCrystal.h>

Thermistor temp(0);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int temperature = temp.getTemp();
  lcd.setCursor(0, 0);
  lcd.print("M.H. TIT    Temp");
  lcd.setCursor(1, 1);
  lcd.print(temperature);
  lcd.setCursor(4, 1);
  lcd.print("*C");
  delay(5000);
  }
