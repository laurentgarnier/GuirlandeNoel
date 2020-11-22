void ArcEnCielQuiMonte() 
{
  indexLed++;
  teinte = teinte + pas;
  if (indexLed >= NUM_LEDS) {indexLed = 0;}
  if (teinte > 255) {teinte = 0;}
  leds[indexLed] = CHSV(teinte, saturation, brillance);
  FastLED.show();
  delay(5);
}