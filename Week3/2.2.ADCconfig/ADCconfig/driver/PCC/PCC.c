#include "S32K144.h"
#include "PCC.h"

void PCC_EnableClock(uint8_t periphIndex)
{
    // Bật clock cho ngoại vi tương ứng (PORT hoặc ADC)
    IP_PCC->PCCn[periphIndex] |= PCC_PCCn_CGC_MASK;
}
