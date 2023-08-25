/* 
 * File:   application.h
 * Author: Mohamed Abosreea
 *
 * Created on March 26, 2023, 12:02 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include <stdio.h>
#include <stdlib.h>
#include "MCAL_Layer/GPIO/gpio.h"
#include "MCAL_Layer/Device_Config/device_config.h"
#include "ECU_Layer/LED/led.h"
#include "ECU_Layer/BUTTON/button.h"
#include "ECU_Layer/SEVEN_SEG/seven_seg.h"
#include "ECU_Layer/KEYPAD/keypad.h"
#include "ECU_Layer/LCD/lcd.h"
#include "MCAL_Layer/Interrupt_Manager/interrupt_cfg.h"
#include "MCAL_Layer/External_Interrupt/external_interrupt.h"
#include "MCAL_Layer/EEPROM/eeprom.h"
#include "MCAL_Layer/ADC/adc.h"
#include "MCAL_Layer/TIMER1/timer1.h"
/*
interrupt_intx_t btn_1 = {
    .int_src = INT_0,
    .int_edge = FALLING
};

interrupt_intx_t btn_2 = {
    .int_src = INT_1,
    .int_edge = RISING,
    
};*/
/*
pin_config_t seg1 = {
    .port = PORTD_t,
    .pin = GPIO_PIN4,
    .state = LOW,
    .direction = OUTPUT
};

pin_config_t seg2 = {
    .port = PORTD_t,
    .pin = GPIO_PIN5,
    .state = LOW,
    .direction = OUTPUT
};

pin_config_t seg3 = {
    .port = PORTD_t,
    .pin = GPIO_PIN6,
    .state = LOW,
    .direction = OUTPUT
};

pin_config_t seg4 = {
    .port = PORTD_t,
    .pin = GPIO_PIN7,
    .state = LOW,
    .direction = OUTPUT
};
*/
/*
seven_seg_t seven_seg = {
    .seven_seg_pins[0].port = PORTD_t,
    .seven_seg_pins[0].pin = GPIO_PIN0,
    .seven_seg_pins[0].direction = OUTPUT,
    .seven_seg_pins[0].state = LOW,
    .seven_seg_pins[1].port = PORTD_t,
    .seven_seg_pins[1].pin = GPIO_PIN1,
    .seven_seg_pins[1].direction = OUTPUT,
    .seven_seg_pins[1].state = LOW,
    .seven_seg_pins[2].port = PORTD_t,
    .seven_seg_pins[2].pin = GPIO_PIN2,
    .seven_seg_pins[2].direction = OUTPUT,
    .seven_seg_pins[2].state = LOW,
    .seven_seg_pins[3].port = PORTD_t,
    .seven_seg_pins[3].pin = GPIO_PIN3,
    .seven_seg_pins[3].direction = OUTPUT,
    .seven_seg_pins[3].state = LOW,

    .seven_seg_type = COMMON_ANODE
};

keypad_t keypad = {
    .keypad_rows[0].port = PORTB_t,
    .keypad_rows[0].pin = GPIO_PIN0,
    .keypad_rows[0].direction = OUTPUT,
    .keypad_rows[0].state = LOW,
    
    .keypad_rows[1].port = PORTB_t,
    .keypad_rows[1].pin = GPIO_PIN1,
    .keypad_rows[1].direction = OUTPUT,
    .keypad_rows[1].state = LOW,
    
    .keypad_rows[2].port = PORTB_t,
    .keypad_rows[2].pin = GPIO_PIN2,
    .keypad_rows[2].direction = OUTPUT,
    .keypad_rows[2].state = LOW,
    
    .keypad_rows[3].port = PORTB_t,
    .keypad_rows[3].pin = GPIO_PIN3,
    .keypad_rows[3].direction = OUTPUT,
    .keypad_rows[3].state = LOW,
    
    .keypad_cols[0].port = PORTB_t,
    .keypad_cols[0].pin = GPIO_PIN4,
    .keypad_cols[0].direction = INPUT,
    .keypad_cols[0].state = LOW,
    
    .keypad_cols[1].port = PORTB_t,
    .keypad_cols[1].pin = GPIO_PIN5,
    .keypad_cols[1].direction = INPUT,
    .keypad_cols[1].state = LOW,
    
    .keypad_cols[2].port = PORTB_t,
    .keypad_cols[2].pin = GPIO_PIN6,
    .keypad_cols[2].direction = INPUT,
    .keypad_cols[2].state = LOW,
    
    .keypad_cols[3].port = PORTB_t,
    .keypad_cols[3].pin = GPIO_PIN7,
    .keypad_cols[3].direction = INPUT,
    .keypad_cols[3].state = LOW,
};
*/
lcd_t lcd1 = {
.lcd_en.port = PORTD_t ,
.lcd_en.pin = GPIO_PIN0,
.lcd_en.direction = OUTPUT,
.lcd_en.state = LOW,

.lcd_rs.port = PORTD_t ,
.lcd_rs.pin = GPIO_PIN1,
.lcd_rs.direction = OUTPUT,
.lcd_rs.state = LOW,

.lcd_connection = _4_BIT,

.lcd_data_pins[0].port = PORTD_t,
.lcd_data_pins[0].pin = GPIO_PIN2,
.lcd_data_pins[0].direction = OUTPUT,
.lcd_data_pins[0].state = LOW,

.lcd_data_pins[1].port = PORTD_t,
.lcd_data_pins[1].pin = GPIO_PIN3,
.lcd_data_pins[1].direction = OUTPUT,
.lcd_data_pins[1].state = LOW,

.lcd_data_pins[2].port = PORTD_t,
.lcd_data_pins[2].pin = GPIO_PIN4,
.lcd_data_pins[2].direction = OUTPUT,
.lcd_data_pins[2].state = LOW,

.lcd_data_pins[3].port = PORTD_t,
.lcd_data_pins[3].pin = GPIO_PIN5,
.lcd_data_pins[3].direction = OUTPUT,
.lcd_data_pins[3].state = LOW,
};
/*
lcd_t lcd2 = {
.lcd_en.port = PORTC_t ,
.lcd_en.pin = GPIO_PIN0,
.lcd_en.direction = OUTPUT,
.lcd_en.state = LOW,

.lcd_rs.port = PORTC_t ,
.lcd_rs.pin = GPIO_PIN1,
.lcd_rs.direction = OUTPUT,
.lcd_rs.state = LOW,

.lcd_connection = _8_BIT,

.lcd_data_pins[0].port = PORTC_t,
.lcd_data_pins[0].pin = GPIO_PIN2,
.lcd_data_pins[0].direction = OUTPUT,
.lcd_data_pins[0].state = LOW,

.lcd_data_pins[1].port = PORTC_t,
.lcd_data_pins[1].pin = GPIO_PIN3,
.lcd_data_pins[1].direction = OUTPUT,
.lcd_data_pins[1].state = LOW,

.lcd_data_pins[2].port = PORTC_t,
.lcd_data_pins[2].pin = GPIO_PIN4,
.lcd_data_pins[2].direction = OUTPUT,
.lcd_data_pins[2].state = LOW,

.lcd_data_pins[3].port = PORTC_t,
.lcd_data_pins[3].pin = GPIO_PIN5,
.lcd_data_pins[3].direction = OUTPUT,
.lcd_data_pins[3].state = LOW,

.lcd_data_pins[4].port = PORTC_t,
.lcd_data_pins[4].pin = GPIO_PIN6,
.lcd_data_pins[4].direction = OUTPUT,
.lcd_data_pins[4].state = LOW,

.lcd_data_pins[5].port = PORTC_t,
.lcd_data_pins[5].pin = GPIO_PIN7,
.lcd_data_pins[5].direction = OUTPUT,
.lcd_data_pins[5].state = LOW,

.lcd_data_pins[6].port = PORTD_t,
.lcd_data_pins[6].pin = GPIO_PIN6,
.lcd_data_pins[6].direction = OUTPUT,
.lcd_data_pins[6].state = LOW,

.lcd_data_pins[7].port = PORTD_t,
.lcd_data_pins[7].pin = GPIO_PIN7,
.lcd_data_pins[7].direction = OUTPUT,
.lcd_data_pins[7].state = LOW,
};
 * */
#endif	/* APPLICATION_H */

