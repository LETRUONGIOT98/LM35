#include <LiquidCrystal_I2C.h> // thuw vieejn i2c
#define ADC_VREF_mV    5000.0 // ddo milivol
#define ADC_RESOLUTION 1023.0
#define PIN_LM35 A0 // pin connected to LM35 temperature sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
  Serial.begin(9600);
  lcd.init();      // initialize the lcd
  lcd.backlight(); // open the backlight
 
}

void loop() {
  int adcVal = analogRead(PIN_LM35);
  int milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  int temp = milliVolt / 10;

  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("  DO NHIET DO   ");
  lcd.setCursor(0, 1); 
  lcd.print("NHIET DO:     *C");
  lcd.setCursor(10, 1); 
  lcd.print(temp);
  delay(1000);
}
