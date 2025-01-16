#include "systick.h"

volatile uint32_t ms_counter = 0;

void configure_systick_and_start(void)
{
    SysTick->CTRL = 0x4;     // Deshabilitar SysTick para configuración
    SysTick->LOAD = 3999;    // Configuración para 1 ms (reloj de 4 MHz)  {4MHz / 4000 = 1KHz -> T = 1ms}
    SysTick->CTRL = 0x7;     // Habilitar SysTick con interrupción
}

uint32_t systick_GetTick(void)
{
    return ms_counter;
}

void SysTick_Handler(void)
{
    ms_counter++;
}