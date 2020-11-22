int boucle = 0;

void OLFadeInOut(){

    
    if(boucle > NUM_LEDS)
      boucle = 0;

    boucle++;
    // Tous les NUM_LEDS boucle affichage d'une météorite blanche sur toute la longueur
    if(boucle == (NUM_LEDS/2)){
      int ancienneValeurRouge;
      int ancienneValeurBleu;

      for (int i = 0; i <= NUM_LEDS; i++)
      {
        if(i > 0)
          setPixel(i-1, ancienneValeurRouge, 0, ancienneValeurBleu);
        
        if(i != NUM_LEDS) {

        ancienneValeurRouge = leds[i].red;
        ancienneValeurBleu = leds[i].blue;

        setPixel(i, 255,255,255);
        }
        showStrip();
        delay(2);
        
      }
      return;
      
    }

    int pixel = random(0, NUM_LEDS);
    int ancienneValeur;
    int nouvelleValeur = random(5, 255);

    Serial.println("valeur : " + nouvelleValeur);

    // Le pixel était rouge, il devient bleu
    // fondu de sa couleur à éteint puis de éteint à la couleur cible
    if(leds[pixel].red > 0){
      
      ancienneValeur = leds[pixel].red;
      // fondu extinction
      for(int i=0; i < ancienneValeur; i+=2){
        setPixel(pixel, ancienneValeur-i, 0 , 0);
        showStrip();
      }
      // fondu vers sa nouvelle couleur
      for(int i=0; i < nouvelleValeur; i+=2){
        setPixel(pixel, 0, 0 , i);
        showStrip();
      }
      return;
    }

    // Le pixel était bleu, il devient rouge
    // fondu de sa couleur à éteint puis de éteint à la couleur cible
    if(leds[pixel].blue > 0){

      ancienneValeur = leds[pixel].blue;
      // fondu extinction
      for(int i=0; i < ancienneValeur; i+=2){
        setPixel(pixel, 0 , 0, ancienneValeur-i);
        showStrip();
      }
       // fondu vers sa nouvelle couleur
      for(int i=0; i < nouvelleValeur; i+=2){
        setPixel(pixel, i, 0 , 0);
        showStrip();
      }
      return;
    }

    // première fois, fondu pour atteindre la couleur cible
    // les coups paires on met la couleur rouge et impair en bleu
    if(leds[pixel].red == 0 && leds[pixel].blue == 0){
      
        for(int i=0; i < nouvelleValeur; i++){
          if(boucle % 2 != 0)
            setPixel(pixel, 0 , 0, i);
          else
            setPixel(pixel, i, 0 , 0);
          showStrip();
        }
    }
}

// void fadeToColor(byte origine, byte longueur){
//   int stepDeCouleur = (128/longueur);
//   int cptPixel = 0;
//   for(int start = origine - longueur; start < origine; start++  ){
//     if(start > 0){
//       setPixel(start, (128 - (cptPixel * stepDeCouleur)), 0, 0 );
//     }
//     cptPixel++;

//   }
// }