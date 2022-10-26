#include "mylib.h"

static const int PIN_LED[] = {5, 6, 10, 11};
bool isLedOn[] = {false, false, false, false};

void led_init() {
  int led;
  for (led = LED0; led <= LED3; ++led) {
    pinMode(PIN_LED[led], OUTPUT);
  }
}

void led_off(led_t led) {
  if (!isPinNumberWithinRange(led)) {
    return;
  }
  digitalWrite(PIN_LED[led], LOW);
  isLedOn[led] = false;
}

void led_on(led_t led) {
  if (!isPinNumberWithinRange(led)) {
    return;
  }
  digitalWrite(PIN_LED[led], HIGH);
  isLedOn[led] = true;
}

bool isPinNumberWithinRange(led_t led) {
  if (led < LED0 || led > LED3) {
    return false;
  }
  return true;
}

void led_toggle(led_t led) {
  if (!isPinNumberWithinRange(led)) {
    return;
  }
  if (isLedOn[led]) {
    digitalWrite(PIN_LED[led], LOW);
    isLedOn[led] = false;
  } else {
    digitalWrite(PIN_LED[led], HIGH);
    isLedOn[led] = true;
  }
}

void all_led_on() {
  led_on(LED0);
  led_on(LED1);
  led_on(LED2);
  led_on(LED3);
}
