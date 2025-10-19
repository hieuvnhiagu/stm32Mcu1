#ifndef PORT_H
#define PORT_H

#include "S32K144.h"

// Enum for PORT IDs
typedef enum {
    ARM_PORT_ID_A = 0,
    ARM_PORT_ID_B,
    ARM_PORT_ID_C,
    ARM_PORT_ID_D,
    ARM_PORT_ID_E,
} ARM_PORT_ID;

// Enum for Pin Numbers
typedef enum {
    ARM_PORT_PIN_0 = 0,
    ARM_PORT_PIN_1,
    ARM_PORT_PIN_2,
    ARM_PORT_PIN_3,
    ARM_PORT_PIN_4,
    ARM_PORT_PIN_5,
    ARM_PORT_PIN_6,
    ARM_PORT_PIN_7,
    ARM_PORT_PIN_8,
    ARM_PORT_PIN_9,
    ARM_PORT_PIN_10,
    ARM_PORT_PIN_11,
    ARM_PORT_PIN_12,
    ARM_PORT_PIN_13,
    ARM_PORT_PIN_14,
    ARM_PORT_PIN_15,
} ARM_PORT_Pin_t;

// Enum for MUX configurations
typedef enum {
    ARM_PORT_MUX_GPIO = 1,
    ARM_PORT_MUX_ALT1,
    ARM_PORT_MUX_ALT2,
    ARM_PORT_MUX_ALT3,
    // Add more as required
} ARM_PORT_CONFIG;

// Enum for GPIO direction
typedef enum {
    ARM_GPIO_DIRECTION_INPUT = 0,
    ARM_GPIO_DIRECTION_OUTPUT,
} ARM_GPIO_DIRECTION;

// Enum for GPIO pull-up/down resistors
typedef enum {
    ARM_GPIO_PULL_NONE = 0,
    ARM_GPIO_PULL_UP,
    ARM_GPIO_PULL_DOWN,
} ARM_GPIO_PULL_RESISTOR;

// Function prototypes for PORT configuration
void PORT_Setup(ARM_PORT_ID port, ARM_PORT_Pin_t pin, ARM_PORT_CONFIG config);
void PORT_SetDirection(ARM_PORT_ID port, ARM_PORT_Pin_t pin, ARM_GPIO_DIRECTION direction);
void PORT_SetPullResistor(ARM_PORT_ID port, ARM_PORT_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor);

#endif // PORT_H
