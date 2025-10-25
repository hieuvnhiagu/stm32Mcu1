#include "ADC.h"

/* =========================
   Cấu hình ADC0 với các tham số ADC_Config
   ========================= */
void ADC_Init(ADC_Type *adc, ADC_Config *config)
{
    // Cấu hình thời gian lấy mẫu (SMPLTS = desired sample time - 1)
    adc->CFG2 = ADC_CFG2_SMPLTS(config->smplts);

    // Chọn kênh ADC0_SE14 (PTC14)
    adc->SC1[0] = ADC_SC1_ADCH(14);

    // Cấu hình ADC: Độ phân giải, sử dụng Bus clock, chia clock
    adc->CFG1 = ADC_CFG1_MODE(config->mode)             // Độ phân giải (8-bit/12-bit)
               | ADC_CFG1_ADICLK(config->adiclk)           // Bus clock hoặc hệ thống clock
               | ADC_CFG1_ADIV(config->adiv);            // Chia clock ADC

    // Cấu hình nguồn điện áp tham chiếu (VrefH hoặc VrefL)
    adc->SC2 = ADC_SC2_REFSEL(config->refsel);  // Chọn nguồn tham chiếu ngoài (VD: VrefH)
}

/* =========================
   Hàm đọc giá trị ADC (12-bit)
   ========================= */
uint16_t ADC_Read(ADC_Type *adc, uint8_t channel)
{
    adc->SC1[0] = ADC_SC1_ADCH(channel);         // Chọn kênh ADC
    while (!(adc->SC1[0] & ADC_SC1_COCO_MASK));  // Chờ chuyển đổi xong
    return adc->R[0];                            // Trả về kết quả
}

/* =========================
   Điều khiển LED dựa trên giá trị ADC
   ========================= */

