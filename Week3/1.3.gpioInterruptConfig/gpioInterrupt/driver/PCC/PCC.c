#include "S32K144.h"
#include "PCC.h"

void PCC_EnableClock_PORT(char port)
{
    uint8_t portIndex;

    // Xác định chỉ số PORT tương ứng với tham số nhập vào
    switch (port) {
        case 'A':
            portIndex = PCC_PORTA_INDEX;
            break;
        case 'B':
            portIndex = PCC_PORTB_INDEX;
            break;
        case 'C':
            portIndex = PCC_PORTC_INDEX;
            break;
        case 'D':
            portIndex = PCC_PORTD_INDEX;
            break;
        case 'E':
            portIndex = PCC_PORTE_INDEX;
            break;
        default:
            return; // Nếu tham số không hợp lệ, thoát hàm
    }

    // Bật clock cho PORT tương ứng
    IP_PCC->PCCn[portIndex] |= PCC_PCCn_CGC_MASK;
}
