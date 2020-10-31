#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

TM1637Display display(CLK, DIO);

void setup()
{
}
int times=1234;
void loop()
{
  
  //uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  //uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  display.setBrightness(0x0f);
  //display.clear();
  //delay(TEST_DELAY);
  display.showNumberDecEx(times, 0b11100000, false, 4, 0);
  delay(TEST_DELAY);
  times=times+1;
//  display.setSegments(SEG_DONE);
  //delay(TEST_DELAY);
  //while(1);
}
