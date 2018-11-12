## Temperature and Light, displayed (as colours) on a neopixel ledstrip

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
  <li>DHT library (download: https://github.com/adafruit/DHT-sensor-library)
  Install by dragging the extracted map into your Arduino Libraries (Documents > Arduino > Libaries) </li>
  <li>Adafruit_Sensor library by Adafruit, you can find it under manage libraries (Sketch > Include Libraries > Manage Libraries) </li>
  <li>Adaruit Neopixels by Adafruit, found under manage libraries as well</li>
</ul>

### Setting up the hardware
<img src="https://i.imgur.com/p8vR2Pu.jpg" alt="Circuit Setup">

Light Sensor -  Connect to A0 and 3V <br>
DHT -   
<ul>
  <li>Left pin to 3V</li>
  <li> Second pin (second from left) to D1</li>
  <li>Third pin isn't used</li>
  <li>Fourth pin (right pin) to Ground (G)</li>
</ul>
Led strip -     
<ul>
  <li>GND to ground (G)</li>
  <li>Din to D5</li>
  <li>+5V to 3V</li>
</ul>

Images from:<br>
https://www.maxphi.com/wp-content/uploads/2017/08/dht11-pinout-173x300.png
https://circuits4you.com/wp-content/uploads/2018/01/esp8266-lcd-display-16x2.png

### And now.. the code
There is quite a lot to do, so we keep it simple and easy. Step by step.

#### First temperature/humidity sensor (DHT11)
<ol>
  <li> Open the <b>DHTtester example</b>. File > Examples > DHT sensor library. If you don't have this library, go back to installing the software, see above. </li>
  <li> Change the defined pin to <b>D1</b> </li>
  <li> Uncomment the sensor you are using, we are using DHT11. See image <img src="https://i.imgur.com/dupYad5.png"></li>
  <li> Delete all the commented lines to clean your file (not necessary) </li>
  <li> Remove Fahrenheit and Heat Index lines (Yellow Lines in screenshot) (Unless you want to display Celcius and Fahrenheit)
    <img src="https://i.imgur.com/3vYmcEo.png"></li>
  <li> The last line of all the Serial.print's should be Serial.println. This prints the value on a new line. Every new value will be on a new line instead of onelong line </li>
  <li> Upload the sketch and open the Serial Monitor to see if this part works ! It should look something like this: <img src="https://i.imgur.com/yYXoNss.png"></li>
</ol>

#### Now connect the ledstrip to it (Neopixels)
<ol>
  <li> In your current sketch (with the DHT sensor), include the Adafruit Neopixel library
    
    `
    #include <Adafruit_NeoPixel.h>
    `
    
  </li>
  <li> Define the led strip. The number is the amount of leds, my strip has 10, but change this to the amount you have
  
  ` 
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, LEDpin, NEO_GRB + NEO_KHZ800);
  `
  </li>
  <li> Define the pin we use for the ledstrip
  
  `
  #define LEDpin D5
  `
  </li>
    
