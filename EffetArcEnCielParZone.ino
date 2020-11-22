void fill_rainbow_ctrl( struct CRGB * pFirstLED, int numToFill,
                  uint8_t teinteInitiale,
                  uint8_t deltaTeinte,
      uint8_t saturation,
      uint8_t brillanceSouhaitee)
{
    CHSV hsv;
    hsv.hue = teinteInitiale;
    hsv.sat = saturation;
    hsv.val = brillanceSouhaitee;
    for( int i = 0; i < numToFill; i++) {
        hsv2rgb_rainbow( hsv, pFirstLED[i]);
        hsv.hue += deltaTeinte;
    }
}

void ArcEnCielParZone()
{
  fill_rainbow_ctrl( leds, NUM_LEDS, teinte, pas, saturation, brillance);
  teinte++;
  FastLED.show();
  delay(5);
   
}