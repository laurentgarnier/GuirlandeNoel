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

//Permet l'affichage de leds qui servent de repère de positionnement sur le sapin
// 100 leds réparties en 5 anneaux sur le sapin
// Anneau 5 en haut 6 leds de 94 à 99
// Anneau 4, 12 leds de 82 à 93
// Anneau 3, 20 leds de 62 à 81
// Anneau 2, 27 leds de 35 à 61
// Anneau 1 en bas 35 leds de 0 à 34
// L'idee etant que toutes les leds de la même couleur soient alignées sur la même droite verticale
void AfficherLedsRepere()
{
  // Les leds blanches
  setPixel(0, 255,255,255);
  setPixel(35, 255,255,255);
  setPixel(62, 255,255,255);
  setPixel(82, 255,255,255);
  setPixel(94, 255,255,255);

  // Les leds rouges (1/4)
  setPixel(8,  255,0,0);
  setPixel(41, 255,0,0);
  setPixel(66, 255,0,0);
  setPixel(84, 255,0,0);
  setPixel(95, 255,0,0);

  // Les leds vertes (1/4)
  setPixel(17,  0,255,0);
  setPixel(48, 0,255,0);
  setPixel(71, 0,255,0);
  setPixel(87, 0,255,0);
  setPixel(97, 0,255,0);

  // Les leds bleues (1/4)
  setPixel(26, 0,0,255);
  setPixel(55, 0,0,255);
  setPixel(76, 0,0,255);
  setPixel(90, 0,0,255);
  setPixel(98, 0,0,255);

}