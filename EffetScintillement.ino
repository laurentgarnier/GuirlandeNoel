void Scintillement(byte rouge, byte vert, byte bleu, int vitesse) {
  
  int pixel = random(NUM_LEDS);
  setPixel(pixel,rouge,vert,bleu);
  showStrip();
  delay(vitesse);
  setPixel(pixel,0,0,0);
}
