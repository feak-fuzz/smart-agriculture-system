/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
   More info: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
   Dev: Michalis Vasilakis // Date: 1/7/2015 // www.ardumotive.com 
*/

//Libraries
#include <DHT.h>
#include <Wire.h> 
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//ALWAYS USE THIS WITH LCD I2C and Addres 0x3F
#define I2C_ADDR 0x3F
#define BACKLIGHT_PIN 3
#define En_pin 11
//#define Rw_pin 
#define Rs_pin 12
#define D4_pin 5
#define D5_pin 4
#define D6_pin 3
#define D7_pin 2
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,/*Rw_pin*/,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
 // lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  //lcd.setBacklight(HIGH);
}

void loop()
{
  
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  //Print temp and humidity values to serial monitor
  /*Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
*/
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Hum:  ");
  lcd.print(hum);
  lcd.print(" %");

  delay(2000); //Delay 2 sec.

}
