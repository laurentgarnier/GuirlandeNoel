void MultiCouleursClignotant(int vitesse){
   
  for(int pixel = 0; pixel < NUM_LEDS; pixel++){
    setPixel(pixel, random(255),random(255),random(255));
    
  }
 showStrip();
  delay(vitesse);
   
}
