


void EclatementAleatoire() 
{
  int rndidx = random16(0, NUM_LEDS);
  int rndhue = random8(0, 255);  
  int rndbright = random8(10, brillance);
  leds[rndidx] = CHSV(rndhue, saturation, rndbright);
  showStrip();
  delay(random8(0, delais));
}