#ifndef GPIO_H
#define GPIO_H

#include "S32K144.h"
#include <stdint.h>

void GPIO_SetPinOutput(GPIO_Type *base, uint8_t pin);
void GPIO_SetPinInput(GPIO_Type *base, uint8_t pin);
void GPIO_TogglePin(GPIO_Type *base, uint8_t pin);
uint8_t GPIO_ReadPin(GPIO_Type *base, uint8_t pin);
void GPIO_SetPin(GPIO_Type *base, uint8_t pin);
void GPIO_ClearPin(GPIO_Type *base, uint8_t pin);
#endif
