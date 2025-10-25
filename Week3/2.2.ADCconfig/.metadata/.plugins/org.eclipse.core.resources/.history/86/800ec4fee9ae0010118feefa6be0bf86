#include "GPIO.h"

void GPIO_SetPinOutput(GPIO_Type *base, uint8_t pin)
{
    base->PDDR |= (1 << pin);   // Output
}

void GPIO_SetPinInput(GPIO_Type *base, uint8_t pin)
{
    base->PDDR &= ~(1 << pin);  // Input
}

void GPIO_TogglePin(GPIO_Type *base, uint8_t pin)
{
    base->PTOR = (1 << pin);
}

uint8_t GPIO_ReadPin(GPIO_Type *base, uint8_t pin)
{
    return (base->PDIR >> pin) & 1;
}
