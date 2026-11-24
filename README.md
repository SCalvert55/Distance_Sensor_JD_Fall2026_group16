You'll need to get the adafruit VL53L0X sensor library for code to work. just go into arduino IDE, go to tools->manage libraries or click the library button on the left, and just look up the sensor. Make sure it's the adafruit one though


Kicad was also done on Kicad 10.0, I've had trouble opening files on the wrong version, so make sure you've got the right one


For the ESP32, it is important that the 5V and 3.3V pins of the ESP32 are connected properly. The ESP32 can take 5V, so we'll use the regulator to make sure that it's supplied with that, connected to the 5V/Vin pin. The distance sensor only works at 2.6V-3.5V, so we need to connect the 3.3V pin of the ESP32 to that.
