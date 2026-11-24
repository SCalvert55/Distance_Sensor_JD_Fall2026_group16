include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X sensor;

void setup() {
  Serial.begin(115200);

  if (!sensor.begin()) {
    Serial.println("Sensor not found");
    while (true);
  }
}

void loop() {
  VL53L0X_RangingMeasurementData_t result;
  sensor.rangingTest(&result);

  if (result.RangeStatus == 4) {
    Serial.println("Out of range");
  } else {
    Serial.print(result.RangeMilliMeter);
    Serial.println(" mm");
  }

  delay(500);
}
