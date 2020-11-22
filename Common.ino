// ***************************************
// ** FastLed/NeoPixel Common Functions **
// ***************************************

// Apply LED color changes
void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

// Set a LED color (not yet visible)
void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

// Set all LEDs to a given color and apply it (visible)
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}




// utilise par ArcEnCiel and theaterChaseRainbow
byte * RoueDeCouleur(byte positionSurLaRoue) {
  static byte c[3];
  
  if(positionSurLaRoue < 85) {
   c[0]=positionSurLaRoue * 3;
   c[1]=255 - positionSurLaRoue * 3;
   c[2]=0;
  } else if(positionSurLaRoue < 170) {
   positionSurLaRoue -= 85;
   c[0]=255 - positionSurLaRoue * 3;
   c[1]=0;
   c[2]=positionSurLaRoue * 3;
  } else {
   positionSurLaRoue -= 170;
   c[0]=0;
   c[1]=positionSurLaRoue * 3;
   c[2]=255 - positionSurLaRoue * 3;
  }

  return c;
}

void FonduRougeVersBlanc()
{
  for (int colorStep = 0; colorStep < 33; colorStep++)
  {

    int r = 32;
    int b = colorStep;
    int g = colorStep;

    for (int x = 0; x < NUM_LEDS; x++)
    {
      leds[x] = CRGB(r, g, b);
    }

    showStrip();
    delay(50);
  }
}


void FonduBlancVersRouge()
{
  for (int colorStep = 0; colorStep < 33; colorStep++)
  {

    int r = 32;
    int b = 32-colorStep;
    int g = 32-colorStep;

    for (int x = 0; x < NUM_LEDS; x++)
    {
      leds[x] = CRGB(r, g, b);
    }

    showStrip();
    delay(50);
  }
}