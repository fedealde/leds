#include "leds.h"
#include <stddef.h>

#define LSB 0x0001
#define LAST_LED 16
#define FIRST_LED 1
#define LED_OFFSET 1
#define ALL_LED_OFF 0x0000
#define ALL_LED_ON 0xFFFF

static uint16_t *puerto;

uint16_t LedToMask(int led) { return LSB << (led - LED_OFFSET); }

bool LedsLimitCheck(int led) {

  return ((LAST_LED >= led) && (FIRST_LED <= led));
}

bool LedsCreate(uint16_t *direccion) {

  if (NULL != direccion) {
    puerto = direccion;
    *puerto = ALL_LED_OFF;
    return true;
  } else {
    return false;
  }
}

bool LedsSetOn(int led) {

  if (false != LedsLimitCheck(led)) {
    *puerto |= LedToMask(led);
    return true;
  } else {
    return false;
  }
}

bool LedsSetOff(int led) {

  if (false != LedsLimitCheck(led)) {
    *puerto &= ~LedToMask(led);
    return true;
  } else {
    return false;
  }
}

void LedsSetAllOff(void) { *puerto = ALL_LED_OFF; }

void LedsSetAllOn(void) { *puerto = ALL_LED_ON; }

bool LedsIsOn(int led) {
  return (LedToMask(led) == (*puerto & LedToMask(led)));
}
