#include "LedControl.h"

LedControl lc=LedControl(12,10,11,2);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames

// Put values in arrays
byte invader1[] =
{
   B00000000,  // First frame of invader #1
   B01111110 ,
   B01000000 ,
   B01111110,
   B01000000,
   B01000000,
   B01000000 ,
   B00000000
};

byte invader2[] =
{
  B00000000, // Second frame of invader #1
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000
};

byte invader3[] =
{
  B00000000, // First frame of invader #2
  B00001110,
  B00100000,
  B01000000,
  B01000000,
  B00100000,
  B00001110,
  B00000000
};

byte invader4[] =
{
  B00000000, // Second frame of invader #2
  B01000100,
  B01001000,
  B01010000,
  B01100000,
  B01010000,
  B01001000,
  B00000000
};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
}


//  Take values in Arrays and Display them
void sinvader1()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,invader1[i]);
  }
}

void sinvader2()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,invader2[i]);
  }
}

void sinvader3()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(2,i,invader3[i]);
  }
}

void sinvader4()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,invader4[i]);
  }
}

void loop()
{
// Put #1 frame on both Display
    sinvader1();
    delay(delayTime);
    sinvader2();
    delay(delayTime);


// Put #2 frame on both Display
    sinvader3();
    delay(delayTime);
    sinvader4();
    delay(delayTime);

}
