#include "unity.h"
#include "leds.h"

/** @todo
Con la inicialización todos los LEDs quedan
apagados.
Prender un LED individual.
Apagar un LED individual.
Prender y apagar múltiples LED’s.
Prender todos los LEDs de una vez.
Apagar todos los LEDs de una vez.
Consultar el estado de un LED que está encendido
Consultar el estado de un LED que est apagado
Revisar limites de los parametros.
Revisar parámetros fuera de los limites.
*/

// Se ejecuta antes de cada prueba.Si no existe, ceedling lo crea, si existe lo usa
void setUp(void){

}

// Se ejecuta despues de cada prueba. Si no existe, ceedling lo crea, si existe lo usa
void tearDown(void){

}

// Con la inicialización todos los LEDs quedan apagados
void test_todos_los_leds_inician_apagados(void){
    uint16_t puerto_virtual = 0xFFFF; // Arrancan iniciados entonces verificamos luego del test que queda en cero

    LedsCreate(&puerto_virtual); // Le pasamos la direccion del puerto
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual); // Verificamos si los bits quedan en cero
}