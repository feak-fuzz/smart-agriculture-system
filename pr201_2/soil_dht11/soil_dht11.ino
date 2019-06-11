#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
int sensor_pin = A0;

int output_value ;

void setup() {
  // start working...
  Serial.begin(9600);
  Serial.println("temp and humidity");
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop() {
 delay(250);
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
  output_value= analogRead(sensor_pin);

   output_value = map(output_value,550,0,0,100);

   Serial.print("soil Mositure : ");

   Serial.print(output_value);

   Serial.println("%");

   delay(1000);

}
