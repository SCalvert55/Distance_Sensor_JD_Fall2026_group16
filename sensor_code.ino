#include <Adafruit_VL53L0X.h>
#include <LiquidCrystal_I2C.h>


Adafruit_VL53L0X sensor;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();


  if (!sensor.begin()) {
    Serial.println("Sensor not found");
    while (true);
  }
  lcd.print("Distance");
}

void loop() {
  VL53L0X_RangingMeasurementData_t result;
  sensor.rangingTest(&result);

  if (result.RangeStatus == 4) {
    Serial.println("Out of range");
  } else {
    Serial.print(result.RangeMilliMeter);
    Serial.println(" mm");

    lcd.print(result.RangeMilliMeter);
    lcd.print(" mm            ");
  }

  delay(500);
}
