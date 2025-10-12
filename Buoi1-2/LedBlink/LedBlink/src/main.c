/* Copyright 2019, 2023, 2025 NXP */
/* License: BSD 3-clause
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "S32K144.h"

void delay_ms(volatile uint32_t ms);
void init_clock(void);
void init_ports(void);

void init_clock(void) {
    // Enable clock for PORTD in PCC (Peripheral Clock Control)
	IP_PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;  // Enable PORTD clock
}

void init_ports(void) {
    // Configure PTD0, PTD15, PTD16 as GPIO pins
    IP_PORTD->PCR[0]  = PORT_PCR_MUX(1);  // Set as GPIO
    IP_PORTD->PCR[15] = PORT_PCR_MUX(1);  // Set as GPIO
    IP_PORTD->PCR[16] = PORT_PCR_MUX(1);  // Set as GPIO

    // Set PTD0, PTD15, PTD16 as OUTPUT
    IP_PTD->PDDR |= (1 << 0);    // PTD0 output
    IP_PTD->PDDR |= (1 << 15);   // PTD15 output
    IP_PTD->PDDR |= (1 << 16);   // PTD16 output

    // Turn OFF all LEDs initially (because LEDs are active-low)
    IP_PTD->PSOR |= (1 << 0) | (1 << 15) | (1 << 16);
}

void delay_ms(volatile uint32_t ms) {
    // Busy-wait loop delay, calibrated for ~48 MHz default clock
    for (volatile uint32_t i = 0; i < ms * 4000; i++) {
        __asm("NOP");
    }
}

int main(void) {
    // Step 1: Configure clock for PORT D
    init_clock();

    // Step 2: Configure PTD0, PTD15, PTD16 as GPIO output
    init_ports();

    while(1) {
        // Turn ON Red LED (PTD0)
    	IP_PTD->PCOR |= (1 << 0);     // Clear output
    	IP_PTD->PSOR |= (1 << 15);    // Turn OFF Green LED
    	IP_PTD->PSOR |= (1 << 16);    // Turn OFF Blue LED
        delay_ms(3000);

        // Turn ON Green LED (PTD15)
        IP_PTD->PSOR |= (1 << 0);     // Turn OFF Red LED
        IP_PTD->PCOR |= (1 << 15);    // Turn ON Green LED
        IP_PTD->PSOR |= (1 << 16);    // Turn OFF Blue LED
        delay_ms(3000);

        // Turn ON Blue LED (PTD16)
        IP_PTD->PSOR |= (1 << 0);     // Turn OFF Red LED
        IP_PTD->PSOR |= (1 << 15);    // Turn OFF Green LED
        IP_PTD->PCOR |= (1 << 16);    // Turn ON Blue LED
        delay_ms(3000);
    }
    return 0;
}




