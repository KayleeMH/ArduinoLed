## Temperature and Light sensors, displayed as colours on a neopixel ledstrip

### Introduction
This small project is a part of a bigger project about 'intelligent' plants. The plant (sensors) will inform the user about its status, regarding humidity, temperature, light and moisture in the soil.

This repository is about the temperature and light, both displayed on the ledstrip. I have 'split' my ledstrip in two parts to show both the temperature and light. However you could also use multiple led strips, or RGB lights. 

### What you need

#### Hardware
<ul> 
  <li>ESP 8266 Node MCU
    <img src="https://www.fingerpointengg.com/wp-content/uploads/2017/11/Node_MCU_Gallery_image-1.jpg" alt="ESP8266" width="100"/></li>
  <li>DHT11 Humidity and Temperature sensor 
    <img src="https://potentiallabs.com/cart/image/cache/catalog/new%20components/DHT11-800x800.jpg" alt="DHT11" width="100"/></li>
  <li>Neopixels Ledstrip 
    <img src="https://cdn.solarbotics.com/products/photos/e97722a0b3fd8f278a50bae297807da9/60560-IMG_1328.jpg?w=800" alt="Ledstrip"   width="100"></li>
  <li>LDR Light sensor 
     <img src="https://www.aam.com.pk/wp-content/uploads/2017/10/ldr.jpg" alt="Light sensor" width="100"></li>
  </ul>
  
#### Software
<ul>
  <li>Arduino</li>
  <li>DHT library (download: https://github.com/adafruit/DHT-sensor-library)</li>
  <li>Adafruit_Sensor library by Adafruit, you can find it under manage libraries (Sketch > Include Libraries > Manage Libraries) </li>
  <li>Adaruit Neopixels by Adafruit, found under manage libraries as well</li>
</ul>
