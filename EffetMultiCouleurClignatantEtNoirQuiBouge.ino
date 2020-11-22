void MultiCouleursClignotantEtNoirQuiBouge(int vitesse){
   
  for(int pixel = 0; pixel < NUM_LEDS; pixel++){
     setPixel(pixel, 0,0,0);
     showStrip();
     delay(10);
    setPixel(pixel, random(255),random(255),random(255));
    showStrip();
  }

  delay(vitesse);
   
}
