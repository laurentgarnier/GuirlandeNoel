void HeliceRGB() 
{
  teinte = 0;
  indexLed++;

  int ghue = (teinte + 80) % 255;
  int bhue = (teinte + 160) % 255;
 
  int N3  = int(NUM_LEDS/10);
  int N12 = int(NUM_LEDS/40);  

  for(int i = 0; i < N3; i++ ) {
    int j0 = (indexLed + i + NUM_LEDS - N12) % NUM_LEDS;
    int j1 = (j0+N3) % NUM_LEDS;
    int j2 = (j1+N3) % NUM_LEDS;    
    leds[j0] = CHSV(teinte, saturation, brillance);
    leds[j1] = CHSV(ghue, saturation, brillance);
    leds[j2] = CHSV(bhue, saturation, brillance);    
  }
   FastLED.show();
   delay(100);
}