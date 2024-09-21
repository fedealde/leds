#include "leds.h"
#include <stddef.h>

//#define DEBUG

#ifdef DEBUG
#define ASSERT(arg)                                                            \
  if (arg) {                                                                   \
    while (1)                                                                  \
      ;                                                                        \
  }
#else
#define ASSERT(arg)
#endif

#define LSB 0x0001
#define LAST_LED 16
#define FIRST_LED 1
#define LED_OFFSET 1
#define ALL_LED_OFF 0x0000
#define ALL_LED_ON 0xFFFF

static uint16_t *puerto;
static bool LedsLimitCheck(int led);

uint16_t LedToMask(int led) { return LSB << (led - LED_OFFSET); }

static bool LedsLimitCheck(int led) {

  return ((LAST_LED >= led) && (FIRST_LED <= led));
}

bool LedsCreate(uint16_t *direccion) {

  ASSERT(NULL != direccion); // Podría directamente utilizar esto, elimino el if
                             // y retorno void

  if (NULL != direccion) {
    puerto = direccion;
    LedsSetAllOff();
    return true;
  } else {
    return false;
  }
}

bool LedsSetOn(int led) {

  ASSERT(NULL != puerto);

  if (false != LedsLimitCheck(led)) {
    *puerto |= LedToMask(led);
    return true;
  } else {
    return false;
  }
}

bool LedsSetOff(int led) {

  ASSERT(NULL != puerto);

  if (false != LedsLimitCheck(led)) {
    *puerto &= ~LedToMask(led);
    return true;
  } else {
    return false;
  }
}

void LedsSetAllOff(void) {
  ASSERT(NULL != puerto);
  *puerto = ALL_LED_OFF;
}

void LedsSetAllOn(void) {
  ASSERT(NULL != puerto);
  *puerto = ALL_LED_ON;
}

bool LedsIsOn(int led) {

  ASSERT(NULL != puerto);
  return (LedToMask(led) == (*puerto & LedToMask(led)));
}
