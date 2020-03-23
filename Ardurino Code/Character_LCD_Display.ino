// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(2,0);
  lcd.print("Einar  Darri");
  lcd.setCursor(3, 1);
  lcd.print("23/03/2020");
}

void loop() {

}
