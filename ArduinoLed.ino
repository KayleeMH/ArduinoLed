//neopixel library
#include <Adafruit_NeoPixel.h>

//library for hum/temperature sensor
#include <Adafruit_Sensor.h>
#include "DHT.h"

//define the pin your humidity sensor is connected to
#define DHTPIN D1

// define what humidity sensor you are using
#define DHTTYPE DHT11  
 
//define the pin of the ledstrip
#define LEDpin D5

//define the strip, the number '10' is the amount of leds on your strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, LEDpin, NEO_GRB + NEO_KHZ800);

//define the analog light sensor
#define LIGHTsns A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //setup connection to the serial monitor
  Serial.begin(9600);
  Serial.println("Test for serial connection");

  //define ledpin as an output
  pinMode(LEDpin, OUTPUT);

  dht.begin();

  //setup the strip
  strip.begin();
  strip.show();

}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)){
    //if the sensor can't read anything, print this
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  //print the values of humidity (h) and temperature (t) in Celcius
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  //the last value printed is println (printline) so the new values will appear on a second line, rather than on the same line as the old values

  //read the light sensor value
  int sensorValue = analogRead(LIGHTsns);
  Serial.print("Light value: ");
  Serial.println(sensorValue);
  
  //if else for temperature
  if (t == 19.00){
    strip.setPixelColor(0, 252, 236, 10);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.show();
    Serial.println("1 yellow");
  }
  else if (t == 20.00) {
    strip.setPixelColor(0, 252, 203, 10);
    strip.setPixelColor(1, 252, 203, 10);
    strip.setPixelColor(2, 0, 0, 0);
    strip.show();
    Serial.println("2 yellow/orange");
  }
  else if (t >= 20){
    strip.setPixelColor(0, 252, 147, 10);
    strip.setPixelColor(1, 252, 147, 10);
    strip.setPixelColor(2, 252, 147, 10);
    strip.show();
    Serial.println("3 orange");
  }
  else {
    Serial.println("Temperature below 19");
    strip.setPixelColor(0, 255, 255, 50);
    strip.show();
  }

  //if else for turning on the light
  if (sensorValue >= 0 && sensorValue <= 200) {
    strip.setPixelColor(4, 255, 255, 255);
    strip.setPixelColor(5, 255, 255, 255);
    strip.setPixelColor(6, 255, 255, 255);
    strip.setPixelColor(7, 255, 255, 255);
    strip.setPixelColor(8, 255, 255, 255);
    strip.setPixelColor(9, 255, 255, 255);
    strip.show();
    
  }
  else if (sensorValue >= 200 && sensorValue <= 400) {
    strip.setPixelColor(4, 200, 200, 200);
    strip.setPixelColor(5, 200, 200, 200);
    strip.setPixelColor(6, 200, 200, 200);
    strip.setPixelColor(7, 200, 200, 200);
    strip.setPixelColor(8, 200, 200, 200);
    strip.setPixelColor(9, 200, 200, 200);
    strip.show();

  }
  else if (sensorValue >= 400 && sensorValue <= 600) {
    strip.setPixelColor(4, 150, 150, 150);
    strip.setPixelColor(5, 150, 150, 150);
    strip.setPixelColor(6, 150, 150, 150);
    strip.setPixelColor(7, 150, 150, 150);
    strip.setPixelColor(8, 150, 150, 150);
    strip.setPixelColor(9, 150, 150, 150);
    strip.show();
  }
  else if (sensorValue >= 600 && sensorValue <= 700) {
    strip.setPixelColor(4, 100, 100, 100);
    strip.setPixelColor(5, 100, 100, 100);
    strip.setPixelColor(6, 100, 100, 100);
    strip.setPixelColor(7, 100, 100, 100);
    strip.setPixelColor(8, 100, 100, 100);
    strip.setPixelColor(9, 100, 100, 100);
    strip.show();
  }
  else if (sensorValue >= 700 && sensorValue <= 850){
    strip.setPixelColor(4, 50, 50, 50);
    strip.setPixelColor(5, 50, 50, 50);
    strip.setPixelColor(6, 50, 50, 50);
    strip.setPixelColor(7, 50, 50, 50);
    strip.setPixelColor(8, 50, 50, 50);
    strip.setPixelColor(9, 50, 50, 50);
    strip.show();
  }
  else {
    strip.setPixelColor(4, 0, 0, 0);
    strip.setPixelColor(5, 0, 0, 0);
    strip.setPixelColor(6, 0, 0, 0);
    strip.setPixelColor(7, 0, 0, 0);
    strip.setPixelColor(8, 0, 0, 0);
    strip.setPixelColor(9, 0, 0, 0);
    
  }
  
}
