#include "S32K144.h"
#include "port.h"
#include "gpio.h"

// Hàm delay đơn giản
void delay(void) {
    for (volatile uint32_t i = 0; i < 1000000; i++) {
        __asm("NOP");  // No operation for delay
    }
}

int main(void) {
    // Bước 1: Cấu hình Clock cho PORT và GPIO
    IP_PCC->PCCn[PCC_PORTB_INDEX] |= PCC_PCCn_CGC_MASK;  // Enable clock for PORTB
    IP_PCC->PCCn[PCC_PORTA_INDEX] |= PCC_PCCn_CGC_MASK;  // Enable clock for PORTA

    // Bước 2: Cấu hình PORT và GPIO
    // Cấu hình Red LED (PORTB_PIN_0) làm output
    PORT_Setup(ARM_PORT_ID_B, ARM_PORT_PIN_0, ARM_PORT_MUX_GPIO);  // GPIO mode
    PORT_SetDirection(ARM_PORT_ID_B, ARM_PORT_PIN_0, ARM_GPIO_DIRECTION_OUTPUT);

    // Cấu hình Green LED (PORTB_PIN_1) làm output
    PORT_Setup(ARM_PORT_ID_B, ARM_PORT_PIN_1, ARM_PORT_MUX_GPIO);  // GPIO mode
    PORT_SetDirection(ARM_PORT_ID_B, ARM_PORT_PIN_1, ARM_GPIO_DIRECTION_OUTPUT);

    // Cấu hình Button 1 (PORTA_PIN_4) làm input với pull-up resistor
    PORT_Setup(ARM_PORT_ID_A, ARM_PORT_PIN_4, ARM_PORT_MUX_GPIO);  // GPIO mode
    PORT_SetDirection(ARM_PORT_ID_A, ARM_PORT_PIN_4, ARM_GPIO_DIRECTION_INPUT);
    PORT_SetPullResistor(ARM_PORT_ID_A, ARM_PORT_PIN_4, ARM_GPIO_PULL_UP);  // Enable pull-up resistor

    // Cấu hình Button 2 (PORTA_PIN_5) làm input với pull-up resistor
    PORT_Setup(ARM_PORT_ID_A, ARM_PORT_PIN_5, ARM_PORT_MUX_GPIO);  // GPIO mode
    PORT_SetDirection(ARM_PORT_ID_A, ARM_PORT_PIN_5, ARM_GPIO_DIRECTION_INPUT);
    PORT_SetPullResistor(ARM_PORT_ID_A, ARM_PORT_PIN_5, ARM_GPIO_PULL_UP);  // Enable pull-up resistor

    // Bước 3: Logic điều khiển LED
    while (1) {

        // Đọc trạng thái của Button 1 (PORTA_PIN_4)
        uint32_t button1_state = GPIO_GetInput(ARM_PORT_ID_A, ARM_GPIO_PIN_4);

        // Nếu Button 1 được nhấn (low), toggle Red LED (PORTB_PIN_0)
        if (button1_state == 0) {  // Button pressed (active low)
            GPIO_SetOutput(ARM_PORT_ID_A,ARM_GPIO_PIN_0, !GPIO_GetInput(ARM_PORT_ID_A,ARM_GPIO_PIN_0));  // Toggle Red LED
            delay();  // Delay để tránh bounce
        }

        // Đọc trạng thái của Button 2 (PORTA_PIN_5)
        uint32_t button2_state = GPIO_GetInput(ARM_PORT_ID_B, ARM_GPIO_PIN_5);

        // Nếu Button 2 được nhấn (low), toggle Green LED (PORTB_PIN_1)
        if (button2_state == 0) {  // Button pressed (active low)
            GPIO_SetOutput(ARM_PORT_ID_B,ARM_GPIO_PIN_1, !GPIO_GetInput(ARM_PORT_ID_B,ARM_GPIO_PIN_1));  // Toggle Green LED
            delay();  // Delay để tránh bounce
        }
    }

    return 0;
}


