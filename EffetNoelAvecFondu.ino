bool fonduRougeVersBlanc = true;

void NoelAvecFondu()
{
    int couleurClignotement;
    int couleurDuFond;
    int couleurRougeClignotant;

    if (fonduRougeVersBlanc)
    {
        couleurClignotement = 128;
        couleurDuFond = 0;
        couleurRougeClignotant = 128;
    }
    else
    {
        couleurClignotement = 0;
        couleurDuFond = 32;
        couleurRougeClignotant = 255;
    }

    // on débute avec tout à rouge
    setAll(32, couleurDuFond, couleurDuFond);

    // 2 clignotements par cycle (blanc quand fond rouge et rouge quand fond blanc)
    int Pixel = random(NUM_LEDS);
    setPixel(Pixel, couleurRougeClignotant, couleurClignotement, couleurClignotement);
    showStrip();
    delay(75);
    setPixel(Pixel, 32, couleurDuFond, couleurDuFond);

    Pixel = random(NUM_LEDS);
    setPixel(Pixel, couleurRougeClignotant, couleurClignotement, couleurClignotement);
    showStrip();
    delay(75);
    setPixel(Pixel, 32, couleurDuFond, couleurDuFond);

    if (millis() - dernierTemps > 30000)
    {
        if (fonduRougeVersBlanc)
        {
            FonduRougeVersBlanc();
            fonduRougeVersBlanc = false;
        }
        else
        {
            FonduBlancVersRouge();
            fonduRougeVersBlanc = true;
        }
        dernierTemps = millis();
    }
}
