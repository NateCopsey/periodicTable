#include <Adafruit_NeoPixel.h>

#define PIN    6
#define N_LEDS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);




void setup() {
    strip.begin();
    strip.fill(strip.ColorHSV(1, 255, 0)); //sets lights to off
    strip.show();
    delayhours(10);
    delayminutes(26);
}

void loop() {
   ombrewake();
   for (uint16_t i = 0; i < 6357; i += 1) {
      ombre1();
   }
   ombresleep();
   delayhours(10);
}

static void ombre1() {
  for (uint32_t hue = 0; hue < 65536; hue += 100) {
    strip.fill(strip.ColorHSV(hue, 255, 25));
    strip.show();
    delay(10);
  }
}

static void ombrewake() {
  for (int value = 0; value < 25; value +=1) {
    strip.fill(strip.ColorHSV(1, 255, value));
    strip.show();
    delay(20);
  }
}

static void ombresleep() {
  for (int value = 25; value > -1; value -=1) {
    strip.fill(strip.ColorHSV(65535, 255, value));
    strip.show();
    delay(20);
  }
}

static void alarm() {
  for (int i = 10; i > 0; i -=1) {
    strip.fill(strip.ColorHSV(65535, 255, 25));
    strip.show();
    delay(1000);
    strip.fill(strip.ColorHSV(65535, 0, 25));
    strip.show();
    delay(1000);
  }
}

static void delayseconds(uint32_t seconds) {
  for  (uint32_t i = 0; i < seconds; i += 1) {
    delay(1000); 
  }
}

static void delayminutes(uint32_t minutes) {
  for  (uint32_t i = 0; i < minutes; i += 1) {
    delayseconds(60); 
  }
}

static void delayhours(uint32_t hours) {
  for  (uint32_t i = 0; i < hours; i += 1) {
    delayminutes(60); 
  }
}
