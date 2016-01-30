#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "qr.h"

Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);


static const unsigned char logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

void setup() {
  display.begin();
  display.setContrast(50);
  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer

  // text display tests
  /*
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0, 0);
    display.println("Hello, world!");
    display.display();
    delay(2000);
  */

 // display.clearDisplay();
 // display.drawBitmap(30, 16,  logo16_glcd_bmp, 16, 16, 1);
  display.clearDisplay();
  delay(1000);

  display.drawXBitmap(0, 0, qr1_bits,  42, 42, 1);

  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
