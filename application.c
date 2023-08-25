/*
 * File : application.c
 * Author : Mohamed Abosreea
 * 
 * Created on : 25/3/2023
 *      
 */
#include "application.h"
volatile uint8 count = 0;
volatile uint8 count2 = 0;

//void Increment_Seven_Seg(void);
//void Decrement_Seven_Seg(void);
void TOGGLE_LED();
led_t led1 = {
  .port = PORTC_t,
  .pin = GPIO_PIN0,
  .state = LED_OFF
};
timer1_t timer ={
  .preload_value = 15536U,
  .prescalar_value = PRESCALAR_DIV_8,
  .rw_mode = _16BIT_MODE,
  .InterruptHandler = TOGGLE_LED,
  .t1_IntMode = TIMER1_INTERRUPT_ON,
  .t1_mode = TIMER_MODE
};

int main() {
  
    led_init(&led1);
    led_turn_on(&led1);
    Interrupt_GlobalInterruptEnable();
    Interrupt_PeripheralInterruptEnebale();
    timer1_init(&timer);
    while (1) {
    }
    return 0;
}
/*
void Increment_Seven_Seg(void) {
    eeprom_write_byte(0x000, count);
    count++;
    if (count > 9)
        count = 9;
}

void Decrement_Seven_Seg(void) {
    eeprom_read_byte(0x000, &count2);
    seven_seg_write_num(&seven_seg, count2);
}*/
void TOGGLE_LED()
{ 
    static uint8 count = 0 ;
    timer1_setValue(&timer , 15536U);
    count++;
    if(count >= 5)
    {
        led_toggle(&led1);
        count = 0 ;
    }
}