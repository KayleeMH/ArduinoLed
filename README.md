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
   
    #include <Adafruit_NeoPixel.h>
    
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
  <li> Define the pin as output, in the setup
  
  `
  pinMode(LEDpin, OUTPUT);
  `
  </li>
  <li> In the setup, start up the strip.
  
  ```
  //setup the strip
  strip.begin();
  strip.show();
```
</li>
  
  </ol>
  
  <b> Now we will write an if/else statement, using the values of the sensor to turn on the ledstrip. I use the first three leds on my strip to display the temperature. </b>
  <ol>
  <li> I decided to go with 19 degrees = 1 led on, 20 degrees = 2 leds, 20 and above = 3 leds. If the temperature is below 19 it'd also be one led, but in a different colour. </li>
  <li> From the earlier code, we have the temperature (t), so we just have to use it in our if, else statement. With setPixelColor, we turn on the colour of a led. The first number (0, 1, 2) is the number of the led we chose to colour. The following numbers stand for RGB. (fully red would be: 255, 0, 0)
    
    if (t == 19.00){
    strip.setPixelColor(0, 252, 236, 10);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.show();
    Serial.println("1 yellow");}
  
  </li>
  <li> Don't forget the 
  
  ` 
  strip.show();
  ` ! 
  Otherwise it won't work. </li>
  <li> Write the rest of the statement (else if & else). You can make it as long and as complicated as you like. </li>
  <li> <b> Once you have completed your code, it's time to test ! Upload your sketch and open the serial monitor. You should be able to see the value and depending on what value, the ledstrip should light up in the colours you decided to go with ! </b></li>
  </ol>
  
  
  #### Now add the light sensor
  If it becomes dark (low values of the light sensor) the remaining leds on the led strip will turn on
  
<ol>
  <li> Define the light sensor (above the setup, with the other define's)
    
     `
    #define LIGHTsns A0
    `
  </li>
  <li> In the void loop, we want to read the value the sensor gives. We create a variable (int) to store the value our light sensor gives
  
  ```
  //read the light sensor value
  int sensorValue = analogRead(LIGHTsns);
  Serial.print("Light value: ");
  Serial.println(sensorValue);
  ```
  </li>
  <li> <b> TEST THIS STEP </b> Upload the code to your node, and see if you have to light value displayed and it changes if you cover the light sensor (with your hand for example).
  <li> Now that we have our value stored, we can use it in an if/else statement, like we did earlier! The light values range from 0 to 1024. I decided to split it into 5 parts </li>
  <li> For every 200 (0 - 200, 200 - 400, and so on) we set a different brightness on the led strip. The lower the value, the higher we turn on the led. </li>
  <li> However, we could use ` strip.setBrightness `, but normally this is only used once, in the setup. If repeatedly used, it's better to use something else. I use the colour white and black, and all values in between. 255, 255, 255 is white. 0, 0, 0 is black (off).
  <li> Time to write another if, else ! I used the leds ranging from 4 - 9, as I earlier used 0 - 2. I don't use Led #3 to show it's about two different things with a little gap between it. </li>
  <li> Code, code, code 
  
  ```
  if (sensorValue >= 0 && sensorValue <= 200) {
    strip.setPixelColor(4, 255, 255, 255);
    strip.setPixelColor(5, 255, 255, 255);
    strip.setPixelColor(6, 255, 255, 255);
    strip.setPixelColor(7, 255, 255, 255);
    strip.setPixelColor(8, 255, 255, 255);
    strip.setPixelColor(9, 255, 255, 255);
    strip.show(); 
  }
  ```
  </li>
  <li> repeat this for all values.
  
  ```
  else if (sensorValue >= 200 && sensorValue <= 400) {
    strip.setPixelColor(4, 200, 200, 200);
    strip.setPixelColor(5, 200, 200, 200);
    strip.setPixelColor(6, 200, 200, 200);
    strip.setPixelColor(7, 200, 200, 200);
    strip.setPixelColor(8, 200, 200, 200);
    strip.setPixelColor(9, 200, 200, 200);
    strip.show();

  }
  ```
  </li>
  <li> Once finished with all values and the complete if, else statement.. <b> you're done ! </b> </li>
  <li> Test ! The light value should show up the serial monitor (as well as your temperature from earlier), put your hand over the light sensor and see the lights turn off. </li>
 </ol>
 
The code is now done. If you have done everything correctly you should have the first three leds being yellow/orange depending on the temperature, one led turned off (fourth) and the remaining 6 turned on in white, the brightness depending on the amount of light the sensor picks up.
  
  <i>General tips: </i>
  <ul>
  <li> Check if you have selected the right board (Node MCU 1.0 ESP-12E Module in my case) </li>
  <li> Check the port </li>
  <li> The baud rate of your monitor should match what you have mentioned in the code (9600) </li>
  <li> Don't understimate the power of Serial Monitor, send data to it to check if your sensors work ! </li>
  <li> Use comments to remember which part does what in your code </li>
  
</ul>
    
### Conclusion

The if else statements with setPixelColor's have become quite long due to calling on each single pixel, rather than writing a for loop. If you want to make your code shorter (and neater), it's better to write this in a loop, rather than repeating it over and over. 
I'm quite happy with how it turned out, but the code is quite extensive and could be shorter!

For more information on for loops: http://www.toptechboy.com/arduino/arduino-lesson-3-simple-led-circuit/ <br>
Advanced coding for Arduino Neopixel: https://learn.adafruit.com/adafruit-neopixel-uberguide/advanced-coding/ <br>
Information about the DHT11 sensor: http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/ <br>
How the LDR light sensor works: https://www.kitronik.co.uk/blog/how-an-ldr-light-dependent-resistor-works/ <br>
Cheap sensors you can purchase and play around with: https://randomnerdtutorials.com/21-arduino-modules-you-can-buy-for-less-than-2/ <br>
More easy projects for inspiration: https://www.makeuseof.com/tag/10-great-arduino-projects-for-beginners/


<b> Happy coding ! </b>
