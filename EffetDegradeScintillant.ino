void DegradeScintillant(){
      for(int bleu = 0; bleu < 255; bleu ++){
        setAll(255-bleu, 0, bleu);      

       if(bleu%3 == 0)
        Flasher(100);       
      }
       for(int rouge = 0; rouge < 255; rouge ++){
        setAll(0, rouge, 255-rouge);      

        if(rouge%3 == 0)
        Flasher(100);       
      }
       for(int vert = 0; vert < 255; vert ++){
        setAll(vert, 255-vert, 0);      

         if(vert%3 == 0)
        Flasher(100); 
      }
}

void Flasher(int dureeDuFlash){
  int pixel = random(NUM_LEDS);

  int ancienneValeurRouge = leds[pixel].red;
  int ancienneValeurVert = leds[pixel].green;
  int ancienneValeurBleu = leds[pixel].blue;
  
  setPixel(pixel,0xff,0xff,0xff);
  showStrip();
  delay(dureeDuFlash);

   // On repositionne le pixel à son ancienne valeur
  setPixel(pixel,ancienneValeurRouge, ancienneValeurVert, ancienneValeurBleu);
  showStrip();
}
