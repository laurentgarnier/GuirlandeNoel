void christmas()
{
    setAll(32, 0, 0);
    blink();
    blink();
    blink();
    blink(); 
}

void blink()
{
    int Pixel = random(NUM_LEDS);
    setPixel(Pixel, 0xff, 0xff, 0xff);
    showStrip();
    delay(50);
    setPixel(Pixel, 32, 0, 0);
}
