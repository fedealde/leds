#include "leds.h"
#include "unity.h"

/**
 * @file test_leds.c
 * @author Federico Alderisi
 * @date 10/09/2024
 *
 * @brief Archivo de tests de puerto de LEDs leds.c
 */

// Command: ceedling clobber gcov:all utils:gcov

/** Tests a desarrollar
1- Inicializacion de puerto
2- Prender un LED individual
3- Apagar un LED individual
4- Prender y apagar varios LEDs
5- Apagar TODOS los LEDs
6- Encender TODOS los LEDs
7- Consultar por un LED encendido
8- Consultar por un LED apagado
9- Verificar creacion de puerto nulo
10- Prueba intermedia de encendido (2 y 5) y apagado (3 y 5), dentro de limites
(1 y 16), fuera de los limites (0, -6 y 17) chequeo final de leds encendidos (2)
*/

/*-----------Definiciones globales de test-----------*/

static int16_t puerto_virtual;

// Se ejecuta antes de cada prueba. Si no existe, ceedling lo crea y si existe
// lo usa
void setUp(void) { LedsCreate(&puerto_virtual); }

// Se ejecuta despues de cada prueba. Si no existe, ceedling lo crea y si existe
// lo usa
void tearDown(void) {}

/*---------------------------------------------------*/

/*-----------Test desarrollados-----------*/

// Inicializamos los LEDs, quedan apagados
void test_todos_los_leds_inician_apagados(void) {

  uint16_t puerto_virtual = 0xFFFF;

  TEST_ASSERT_TRUE(LedsCreate(&puerto_virtual));
  TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prendemos un LED individual
void test_prender_un_led_individual(void) {

  TEST_ASSERT_TRUE(LedsSetOn(3));
  TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// Prendemos un LED individual
void test_apagar_un_led_individual(void) {

  TEST_ASSERT_TRUE(LedsSetOn(3));
  TEST_ASSERT_TRUE(LedsSetOff(3));
  TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prendemos y apagamos varios LEDs
void test_prender_y_apagar_varios_leds(void) {

  TEST_ASSERT_TRUE(LedsSetOn(7));
  TEST_ASSERT_TRUE(LedsSetOn(5));
  TEST_ASSERT_TRUE(LedsSetOff(2));
  TEST_ASSERT_TRUE(LedsSetOff(7));

  TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

// Apagamos todos los LEDs de una vez
void test_apagar_todos_los_leds(void) {

  LedsSetAllOff();
  TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prendemos todos los LEDs de una vez
void test_prender_todos_los_leds(void) {

  LedsSetAllOn();
  TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

// Consultar el estado de un LED que esta encendido
void test_consultar_por_led_encendido(void) {

  TEST_ASSERT_TRUE(LedsSetOn(12));
  TEST_ASSERT_TRUE(LedsIsOn(12));
}

// Consultar el estado de un LED que esta apagado
void test_consultar_por_led_apagado(void) { TEST_ASSERT_FALSE(LedsIsOn(12)); }

// Prueba de puerto nulo
void test_consulta_creacion_puerto_nulo(void) {

  uint16_t *puerto_virtual_local = NULL;
  TEST_ASSERT_FALSE(LedsCreate(puerto_virtual_local));
}

// Prueba intermedia de encendido (2 y 5) y apagado (3 y 5), dentro de limites
// (1 y 16), fuera de los limites (0, -6 y 17) chequeo final de leds encendidos
// (2)
void test_consulta_encendido_y_apagado_dentro_y_fuera_de_limite_y_chequeo(
    void) {

  TEST_ASSERT_TRUE(LedsSetOn(1));
  TEST_ASSERT_TRUE(LedsSetOn(2));
  TEST_ASSERT_TRUE(LedsSetOn(5));
  TEST_ASSERT_TRUE(LedsSetOn(16));
  TEST_ASSERT_FALSE(LedsSetOn(-6));
  TEST_ASSERT_FALSE(LedsSetOn(0));
  TEST_ASSERT_FALSE(LedsSetOn(17));

  TEST_ASSERT_TRUE(LedsSetOff(1));
  TEST_ASSERT_TRUE(LedsSetOff(3));
  TEST_ASSERT_TRUE(LedsSetOff(5));
  TEST_ASSERT_TRUE(LedsSetOff(16));
  TEST_ASSERT_FALSE(LedsSetOff(-6));
  TEST_ASSERT_FALSE(LedsSetOff(0));
  TEST_ASSERT_FALSE(LedsSetOff(17));

  TEST_ASSERT_EQUAL_HEX16(1 << 1, puerto_virtual);
}

/*----------------------------------------*/