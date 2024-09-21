#ifndef LEDS_H
#define LEDS_H

#include "stdbool.h"
#include "stdint.h"

/**
 * @file leds.h
 * @author Federico Alderisi
 * @date 10/09/2024
 *
 * @brief Archivo de cabecera de puerto de LEDs
 */

/**
 * @brief Consulta si el LED esta encendido y retorna si fue exitoso
 *
 * @param led
 * @return true
 * @return false
 */
bool LedsIsOn(int led);

/**
 * @brief Inicializa puerto y apaga todos los LEDs, retorna si fue exitoso
 *
 * @param puerto
 * @return true
 * @return false
 */
bool LedsCreate(uint16_t *puerto);

/**
 * @brief Enciende el LED y retorna si fue exitoso
 *
 * @param led
 * @return true
 * @return false
 */
bool LedsSetOn(int led);

/**
 * @brief Apaga el LED y retorna si fue exitoso
 *
 * @param led
 * @return true
 * @return false
 */
bool LedsSetOff(int led);

/**
 * @brief Apaga todos los LEDs del puerto
 *
 */
void LedsSetAllOff(void);

/**
 * @brief Enciende todos los LEDs del puerto
 *
 */
void LedsSetAllOn(void);

#endif // LEDS_H