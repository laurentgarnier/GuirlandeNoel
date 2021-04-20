// Guirlande Noël
// Utilisation avec Arduino ESP32S
// Pin 4 pour piloter le ruban de led

#include "FastLED.h"
#include "BluetoothSerial.h"


#define NUM_LEDS 150 // assemblage de 3 guirlandes de 50 leds
#define PIN_LEDS 4

CRGB leds[NUM_LEDS];

BluetoothSerial SerialBT;

int indexLed = 0;
byte brillance = 255;
byte saturation = 255;
int delais = 20;          
byte pas = 10;           
byte teinte = 0;
byte red = 0;
byte green = 0;
byte blue = 0;

int nombreBoucle = 0;

unsigned long dernierTemps = 0;

const int nombreEffet = 15;

int selectedEffect = 11;
int lastEffect = 11;


void setup()
{
  pinMode(PIN_LEDS, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println("Starting");
  
  FastLED.addLeds<WS2811, PIN_LEDS, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Iniitialisation de random
  randomSeed(analogRead(0));

  initialiserBluetooth();

  // Fin init
  setAll(255, 0, 0);
  delay(1000);
  setAll(0, 255, 0);
  delay(1000);
  setAll(0, 0, 255);
  delay(1000);
  setAll(0, 0, 0);
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
  int nbCaractere = 1;
  int effet = 0;
  while(SerialBT.available()){
    // on reçoit le code ascii des entiers, 48 code ascii de 0
    int valeurRecue = SerialBT.read() - 48;
    // on recoit les dizaines
    if(nbCaractere == 2)
      effet = 10 * effet + valeurRecue;
    else // Cas des unites
      effet = valeurRecue;

   nbCaractere++;
  }
  
  if(nbCaractere > 1)
  {
    selectedEffect = effet;
    Serial.println("recu : " + String(effet));
  }

  if (selectedEffect > nombreEffet - 1)
    selectedEffect = 11;

   if(selectedEffect != lastEffect){
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
      Serial.println("Reperes");
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
