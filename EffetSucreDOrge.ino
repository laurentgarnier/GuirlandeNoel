void SucreDOrge() 
{
  indexLed++;

  int N6  = int(NUM_LEDS/10);  
  int N12 = int(NUM_LEDS/20);  
  
  for(int i = 0; i < N6; i++ ) {
    int j0 = (indexLed + i + NUM_LEDS - N12) % NUM_LEDS;
    int j1 = (j0+N6) % NUM_LEDS;
    int j2 = (j1+N6) % NUM_LEDS;
    int j3 = (j2+N6) % NUM_LEDS;
    int j4 = (j3+N6) % NUM_LEDS;
    int j5 = (j4+N6) % NUM_LEDS;
 
    leds[j0] = CRGB(255, 255, 255).nscale8_video(brillance*.75);
    leds[j1] = CRGB(255, 0, 0).nscale8_video(brillance);
    leds[j2] = CRGB(255, 255, 255).nscale8_video(brillance*.75);
    leds[j3] = CRGB(255, 0, 0).nscale8_video(brillance);
    leds[j4] = CRGB(255, 255, 255).nscale8_video(brillance*.75);
    leds[j5] = CRGB(255, 0, 0).nscale8_video(brillance);
    
  }
  FastLED.show();
  delay(125);
   
}