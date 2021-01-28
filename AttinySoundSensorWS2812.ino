#include <FastLED.h>

#define NUM_LEDS 32     //Number of LEDs
#define LED_PIN 1       //Digital Pin 1 = P1 Attiny Board
#define SOUND_PIN 1     //Analog Pin 1 = P2 Attiny Board

long tot;   //Total
long val;   //Value

CRGB leds[NUM_LEDS];

void setup() {
  pinMode(SOUND_PIN, INPUT);
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < 100; i++) {
    val = analogRead(SOUND_PIN);
    tot = tot + val;
    delayMicroseconds(60);
  }

  val = tot / 100;
  tot = 0;
  val = map(val, 30, 500, 0, 32);

  for (int i = 0; i < NUM_LEDS; i++) {
    if (i < val) {
      leds[i] = CRGB::Blue;
    }
    if (i > val) {
      leds[i] = CRGB::Red;
    }
  }
  FastLED.show();
  delayMicroseconds(60);
}
