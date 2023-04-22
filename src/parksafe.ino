/*
 * Project car
 * Description:
 * Author:
 * Date:
 */
#include "neopixel.h"
#define PIXEL_COUNT 60
#define PIXEL_PIN D2
#define PIXEL_TYPE WS2812

int pw_pin = D1;
long inch;
int flag = 0;

Adafruit_NeoPixel ring(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
// setup() runs once, when the device is first turned on.
void setup() {
pinMode(pw_pin, INPUT);
// takes input into D1
Serial.begin(9600);
  // Put initialization like pinMode and begin functions here.
}
// loop() runs over and over again, as quickly as it can execute.
void loop() {


inch = pulseIn(pw_pin, HIGH);
Serial.print("The distance = ");
Serial.println(inch);
// raw value is printed
delay(100);
if (inch > 800 && inch < 2200) // checks to object in this range
{
  ring.begin();
  flag = 1;
for(int i=0; i<ring.numPixels(); i++)
{
  ring.setPixelColor(i, 0, 255, 0);
  ring.setBrightness(85);
  ring.show();
  delay(30);
}
// turns on the LED

inch = pulseIn(pw_pin, HIGH);
if (inch > 2200)
{
  flag = 2;
  delay(10000);
  for(int i=ring.numPixels(); i>-1; i--)
{
  inch = pulseIn(pw_pin, HIGH);
if (inch > 2200)
{
  ring.setPixelColor(i, 0, 0, 0);
  ring.setBrightness(85);
  ring.show();
  delay(30); } // turns off the LED while detecting object each second
  else
  {
    break;
  }

}
}
}

}  
