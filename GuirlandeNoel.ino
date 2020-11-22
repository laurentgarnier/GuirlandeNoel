// Guirlande Noël
// Utilisation avec Arduino Wemos D1
// Pin 4 pour piloter le ruban de led

#include "FastLED.h"

#define NUM_LEDS 100 // assemblage de 2 guirlandes de 50 leds
#define PIN_LEDS 4

CRGB leds[NUM_LEDS];


int indexLed = 0;
byte brillance = 255;
byte saturation = 255;
int delais = 20;          
byte pas = 10;           
byte teinte = 0;

int nombreBoucle = 0;

unsigned long dernierTemps = 0;

const int nombreEffet = 15;
String listeDesEffets[nombreEffet];
int selectedEffect = 11;
int lastEffect = 11;


void setup()
{
  FastLED.addLeds<WS2811, PIN_LEDS, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Iniitialisation de random
  randomSeed(analogRead(0));

  // On éteint le ruban
  setAll(0, 0, 0);

  // Association du numéro et du libellé de l'effet
  listeDesEffets[0] = "Multicolor clignotant";
  listeDesEffets[1] = "D&#233;grad&#233; scintillant";
  listeDesEffets[2] = "Flash";
  listeDesEffets[3] = "Flash sur fond rouge";
  listeDesEffets[4] = "Arc en ciel mobile";
  listeDesEffets[5] = "M&#233;t&#233;orite";
  listeDesEffets[6] = "Multicolor clignotant avec curseur";
  listeDesEffets[7] = "Eclatement aleatoire";
  listeDesEffets[8] = "Sucre d orge";
  listeDesEffets[9] = "Helice RGB";
  listeDesEffets[10] = "Arc en ciel qui monte";
  listeDesEffets[11] = "Arc en ciel par zone";
  listeDesEffets[12] = "Noel avec fondu";
  listeDesEffets[13] = "OL";
  listeDesEffets[14] = "Reperes";

  initialiserBluetooth();

  // Liaison série USB de debug
  Serial.begin(9600);
  Serial.println("Pret");
  Serial.setDebugOutput(true);
}

void loop()
{
  // Si des données sont reçues sur la liaison série
  if (Serial.available() > 0)
  {
    String valeur = Serial.readString();
    Serial.println("Recu : " + valeur);
    selectedEffect = valeur.toInt();
  }

  if (selectedEffect > nombreEffet - 1)
    selectedEffect = 0;

   if(selectedEffect != lastEffect)
  {
    setAll(0,0,0);
    lastEffect = selectedEffect;
  }

  // Serial.println("Effet #" + String(selectedEffect));
  switch (selectedEffect)
  {
    case 0:
    {
      //Serial.println("MultiCouleursClignotant");
      MultiCouleursClignotant(500);
      break;
    }
    case 1:
    {
      //Serial.println("DegradeScintillant");
      DegradeScintillant();
      break;
    }
    case 2:
    {
      //Serial.println("Scintillement");
      Scintillement(0xff, 0xff, 0xff, 125);
      break;
    }
    case 3:
    {
      // Serial.println("ScintillementSurFondRouge");
      christmas();
      break;
    }
    case 4:
    {
      // Serial.println("ArcEnCiel");
      // ArcEnCiel - vitesse
      ArcEnCiel(10);
      break;
    }
    case 5:
    {
      // Serial.println("Meteorite");
      // meteorRain - (rouge, vert, bleu), taille meteorite, taille de la trainee, trainee aleatoire (true/false), vitesse
      Meteorite(0xff, 0xff, 0xff, 5, 25, true, 15);
      break;
    }
    case 6:
    {
      //Serial.println("MultiCouleursClignotantEtNoirQuiBouge");
      // MultiCouleursClignotantEtNoirQuiBouge - vitesse
      MultiCouleursClignotantEtNoirQuiBouge(100);
      break;
    }
    case 7 :
    {
      EclatementAleatoire();
      break;
    }
    case 8 : 
    {
      SucreDOrge();
      break;
    }
    case 9 :
    {
      HeliceRGB();
      break;
    }
    case 10 :
    {
      ArcEnCielQuiMonte();
      break;
    }
    case 11 :
    {
      ArcEnCielParZone();
      break;
    }
    case 12 :
    {
      NoelAvecFondu();
      break;
    }
    case 13 :
    {
      OLFadeInOut();
      break;
    }
    case 14 :
    {
      AfficherLedsRepere();
      break;
    }
    default :
    {
      ArcEnCielParZone();
      break;
    }
  }
nombreBoucle++;

}


String construireMainPage()
{
  String mainPage = F("<!DOCTYPE html><html><head>");
  mainPage.concat(F("<style>.button {background-color: #121212; border: none; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer;}</style></head>"));
  mainPage.concat(F("<body><center><h1>Guirlande - "));
  mainPage.concat(listeDesEffets[selectedEffect]);
  mainPage.concat(F("</h1><br>"));
  mainPage.concat(F("1 - <a href=\"effet?num=0\" class=\"button\">Multicolor clignotant</a><br>"));
  mainPage.concat(F("2 - <a href=\"effet?num=6\" class=\"button\">Multicolor clignotant avec curseur</a><br>"));
  mainPage.concat(F("3 - <a href=\"effet?num=1\" class=\"button\">D&#233;grad&#233; scintillant</a><br>"));
  mainPage.concat(F("4 - <a href=\"effet?num=2\" class=\"button\">Flash</a><br>"));
  mainPage.concat(F("5 - <a href=\"effet?num=3\" class=\"button\">Flash sur fond rouge</a><br>"));
  mainPage.concat(F("6 - <a href=\"effet?num=4\" class=\"button\">Arc en ciel mobile</a><br>"));
  mainPage.concat(F("7 - <a href=\"effet?num=5\" class=\"button\">M&#233;t&#233;orite</a><br>"));
  mainPage.concat(F("<hr></center></body></html>"));
  return mainPage;
}
