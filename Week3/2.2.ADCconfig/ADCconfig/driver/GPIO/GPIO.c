#include "GPIO.h"

#include "S32K144.h"

/* =========================
   Cấu hình hướng dữ liệu
   ========================= */
void GPIO_SetPinOutput(GPIO_Type *base, uint8_t pin)
{
    base->PDDR |= (1 << pin);   // Cấu hình pin là OUTPUT
}

void GPIO_SetPinInput(GPIO_Type *base, uint8_t pin)
{
    base->PDDR &= ~(1 << pin);  // Cấu hình pin là INPUT
}

/* =========================
   Ghi / Xóa / Đảo trạng thái pin
   ========================= */
void GPIO_SetPin(GPIO_Type *base, uint8_t pin)
{
    base->PSOR = (1 << pin);    // Ghi mức logic 1 (SET)
}

void GPIO_ClearPin(GPIO_Type *base, uint8_t pin)
{
    base->PCOR = (1 << pin);    // Ghi mức logic 0 (CLEAR)
}

void GPIO_TogglePin(GPIO_Type *base, uint8_t pin)
{
    base->PTOR = (1 << pin);    // Đảo trạng thái chân (TOGGLE)
}

/* =========================
   Đọc trạng thái pin
   ========================= */
uint8_t GPIO_ReadPin(GPIO_Type *base, uint8_t pin)
{
    return (base->PDIR >> pin) & 1;  // Đọc giá trị pin (0 hoặc 1)
}
