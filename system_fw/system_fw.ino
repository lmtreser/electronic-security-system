/* 
    Panel de Alarma Didáctico
    Lucas Martín Treser
    Abril de 2025
*/

#include <LiquidCrystal_AIP31068_I2C.h>
#include <Keypad.h>

#define MSG_VERSION "v042025"

const byte LED_01 = 13;
const byte LED_02 = A0;
const byte LED_03 = A1;
const byte LED_04 = A2;
const byte LED_05 = A3;

const byte BUZZER = 9;

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte rowPins[ROWS] = { 2, 3, 4, 5 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 8, 7, 6 };     //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_AIP31068_I2C lcd(0x3E, 16, 2);

void setup() {

  pinMode(LED_01, OUTPUT);
  pinMode(LED_02, OUTPUT);
  pinMode(LED_03, OUTPUT);
  pinMode(LED_04, OUTPUT);
  pinMode(LED_05, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
  Serial.println("Hello Human!");

  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("Alarm Panel");
  lcd.setCursor(0, 1);
  lcd.print(MSG_VERSION);

  digitalWrite(LED_01, HIGH);
  digitalWrite(LED_02, HIGH);
  digitalWrite(LED_03, HIGH);
  digitalWrite(LED_04, HIGH);
  digitalWrite(LED_05, LOW);
  delay(1000);
  digitalWrite(LED_01, LOW);
  digitalWrite(LED_02, LOW);
  digitalWrite(LED_03, LOW);
  digitalWrite(LED_04, LOW);
  digitalWrite(LED_05, HIGH);

  digitalWrite(BUZZER, HIGH);
  delay(250);
  digitalWrite(BUZZER, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press a key");
}

void loop() {

  char key = keypad.getKey();

  if (key) {
    lcd.setCursor(0, 1);
    lcd.print(key);
  }
}
