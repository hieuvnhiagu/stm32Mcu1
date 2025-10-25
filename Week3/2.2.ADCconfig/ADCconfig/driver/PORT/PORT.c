#include "PORT.h"

void PORTC_PinConfig(uint8_t pin, uint8_t mux)
{
    IP_PORTC->PCR[pin] = PORT_PCR_MUX(mux);   // Chọn chức năng ALT = mux
}

void PORT_PinConfig(PORT_Type *port, uint8_t pin, uint8_t mux)
{
    // Cấu hình pin tương ứng với mux
    port->PCR[pin] = PORT_PCR_MUX(mux);
}

void PORT_Interrupt(PORT_Type *port, uint8_t pin, uint8_t mux, uint8_t irqType)
{
    // Cấu hình chức năng pin (mux)
    port->PCR[pin] = PORT_PCR_MUX(mux);

    // Cấu hình ngắt cạnh (IRQC)
    port->PCR[pin] |= PORT_PCR_IRQC(irqType); // IRQ type: 0b1001 cho falling edge hoặc 0b1010 cho rising edge
}
