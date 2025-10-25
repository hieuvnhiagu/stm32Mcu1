#include "port.h"

// Function to configure the PORT pin for a specific MUX configuration
void PORT_Setup(ARM_PORT_ID port, ARM_PORT_Pin_t pin, ARM_PORT_CONFIG config) {
    PORT_Type *base;

    // Select the base address based on the port ID
    switch (port) {
        case ARM_PORT_ID_A: base = IP_PORTA; break;
        case ARM_PORT_ID_B: base = IP_PORTB; break;
        case ARM_PORT_ID_C: base = IP_PORTC; break;
        case ARM_PORT_ID_D: base = IP_PORTD; break;
        case ARM_PORT_ID_E: base = IP_PORTE; break;
        default: return;
    }

    base->PCR[pin] = PORT_PCR_MUX(config);  // Set MUX configuration for the pin
}

// Function to set the direction (input/output) for a specific pin
void PORT_SetDirection(ARM_PORT_ID port, ARM_PORT_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    GPIO_Type *gpio_base;
    PORT_Type *port_base;

    // Select the base addresses for PORT and GPIO
    switch (port) {
        case ARM_PORT_ID_A: port_base = IP_PORTA; gpio_base = IP_PTA; break;
        case ARM_PORT_ID_B: port_base = IP_PORTB; gpio_base = IP_PTB; break;
        case ARM_PORT_ID_C: port_base = IP_PORTC; gpio_base = IP_PTC; break;
        case ARM_PORT_ID_D: port_base = IP_PORTD; gpio_base = IP_PTD; break;
        case ARM_PORT_ID_E: port_base = IP_PORTE; gpio_base = IP_PTE; break;
        default: return;
    }

    if (direction == ARM_GPIO_DIRECTION_OUTPUT) {
        gpio_base->PDDR |= (1 << pin);  // Set as output
    } else {
        gpio_base->PDDR &= ~(1 << pin); // Set as input
    }
}

// Function to configure pull-up or pull-down resistors for a pin
void PORT_SetPullResistor(ARM_PORT_ID port, ARM_PORT_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    PORT_Type *port_base;

    // Select base address for PORT
    switch (port) {
        case ARM_PORT_ID_A: port_base = IP_PORTA; break;
        case ARM_PORT_ID_B: port_base = IP_PORTB; break;
        case ARM_PORT_ID_C: port_base = IP_PORTC; break;
        case ARM_PORT_ID_D: port_base = IP_PORTD; break;
        case ARM_PORT_ID_E: port_base = IP_PORTE; break;
        default: return;
    }

    if (resistor == ARM_GPIO_PULL_UP) {
        port_base->PCR[pin] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK; // Enable pull-up resistor
    } else if (resistor == ARM_GPIO_PULL_DOWN) {
        port_base->PCR[pin] |= PORT_PCR_PE_MASK; // Enable pull-down resistor
        port_base->PCR[pin] &= ~PORT_PCR_PS_MASK; // Select pull-down
    } else {
        port_base->PCR[pin] &= ~PORT_PCR_PE_MASK; // Disable pull resistors
    }
}
