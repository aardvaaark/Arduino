#include <LiquidCrystal.h>

int LED_PIN = 8;
int ONE_UNIT_DURATION = 600;
int DAH_DURATION = 3;
int LETTER_SPACING = 7;
int WORD_SPACING = 15;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
}

void dit() {
  digitalWrite(LED_PIN, HIGH);
  delay(ONE_UNIT_DURATION);
  digitalWrite(LED_PIN, LOW);
  delay(ONE_UNIT_DURATION);
}

void dah() {
  digitalWrite(LED_PIN, HIGH);
  delay(DAH_DURATION * ONE_UNIT_DURATION);
  digitalWrite(LED_PIN, LOW);
  delay(ONE_UNIT_DURATION);
}

void loop() {

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);

  
  dah();
  dah();
  
  delay(LETTER_SPACING * ONE_UNIT_DURATION);

  dah();
  dah();
  dah();

  delay(LETTER_SPACING * ONE_UNIT_DURATION);

  dit();
  dit();
  dit();
  dit();

  delay(LETTER_SPACING * ONE_UNIT_DURATION);

  dit();
  dit();
  dit();
  dit();
  dit();

  delay(LETTER_SPACING * ONE_UNIT_DURATION);

  dah();
  dah();

  delay(LETTER_SPACING * ONE_UNIT_DURATION);

  dit();
  dah();

  delay(LETTER_SPACING * ONE_UNIT_DURATION);

  dit();
  dit();
  dit();

  delay(LETTER_SPACING * ONE_UNIT_DURATION);

  dit();
  dit();
  dit();
  dit();

  delay(WORD_SPACING * ONE_UNIT_DURATION);
}
