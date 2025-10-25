#ifndef ADC_H
#define ADC_H

#include "S32K144.h"

/* Cấu trúc cấu hình cho ADC */
typedef struct {
    uint8_t smplts;    // Thời gian lấy mẫu (0 đến 255 tương ứng với 2 đến 256 chu kỳ ADCK)
    uint8_t refsel;    // Nguồn điện áp tham chiếu (0: Vref, 1: VrefH)
    uint8_t mode;      // Độ phân giải (0: 8-bit, 1: 12-bit)
    uint8_t adiclk;    // Clock nguồn cho ADC (0: Bus clock, 1: hệ thống clock, v.v.)
    uint8_t adiv;      // Chia clock ADC (0: không chia, 1: chia 2, ...)
} ADC_Config;

/* Các hàm chức năng */
void ADC_Init(ADC_Type *adc, ADC_Config *config);
uint16_t ADC_Read(ADC_Type *adc, uint8_t channel);

#endif // ADC_DRIVER_H
