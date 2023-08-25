/* 
 * File:   timer0.h
 * Author: Mohamed Abosreea
 *
 * Created on August 1, 2023, 10:27 AM
 */

#ifndef TIMER0_H
#define	TIMER0_H

/*  Section : Includes*/
#include "../../std_lib.h"
#include "../../std_types.h"
#include "../Device_Config/device_config.h"
#include "../Interrupt_Manager/interrupt_cfg.h"
#include "../GPIO/gpio.h"
/*  Section : Macro declarations */


/*  Section : Macro Functions declarations */
#define TIMER0_ENABLE()                     (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE()                    (T0CONbits.TMR0ON = 0)
#define TIMER0_8BIT_MODE()                  (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_MODE()                 (T0CONbits.T08BIT = 0)
#define TIMER0_COUNTER_MODE()               (T0CONbits.T0CS = 1)
#define TIMER0_TIMER_MODE()                 (T0CONbits.T0CS = 0)
#define TIMER0_FALLING_EDGE_SELECT()        (T0CONbits.T0SE = 1)
#define TIMER0_RISING_EDGE_SELECT()         (T0CONbits.T0SE = 0)
#define TIMER0_PRESCALAR_ENABLE()           (T0CONbits.PSA = 0)
#define TIMER0_PRESCALAR_DISABLE()          (T0CONbits.PSA = 1)
#define TIMER0_SET_PRESCALAR(VALUE)         (T0CONbits.T0PS = VALUE)
#define TIMER0_INTERRUPT_ENABLE()           (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_DISABLE()          (INTCONbits.TMR0IE = 0)
#define TIMER0_CLEAR_FLAG()                 (INTCONbits.T0IF = 0)
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
#define TIMER0_INTERRUPT_PRIORITY_HIGH()    (INTCON2bits.TMR0IP = 1)
#define TIMER0_INTERRUPT_PRIORITY_LOW()     (INTCON2bits.TMR0IP = 0)
#endif

/*  Section : Data types declarations */
typedef enum {
    TIMER0_TIMER = 0,
    TIMER0_COUNTER
} timer0_mode_t;

typedef enum {
    TIMER0_PRESCALAR_2 = 0,
    TIMER0_PRESCALAR_4,
    TIMER0_PRESCALAR_8,
    TIMER0_PRESCALAR_16,
    TIMER0_PRESCALAR_32,
    TIMER0_PRESCALAR_64,
    TIMER0_PRESCALAR_128,
    TIMER0_PRESCALAR_256
} timer0_prescalar_value_t;

typedef enum {
    TIMER0_PRESCALAR_ON = 0,
    TIMER0_PRESCALAR_OFF
} timer0_prescalar_mode_t;

typedef enum {
    TIMER0_16BIT = 0,
    TIMER0_8BIT
} timer0_register_size_t;

typedef enum {
    TIMER0_PRIORITY_LOW = 0,
    TIMER0_PRIORITY_HIGH
} timer0_priority_t;

typedef struct {
    timer0_mode_t timer0_mode;
    timer0_prescalar_mode_t prescalar_mode;
    timer0_prescalar_value_t prescalar_value;
    timer0_register_size_t timer0_register_size;
    uint16 timer0_preload_vlaue;
    void (*timer0_callBackFunction)(void);
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
    timer0_priority_t priority;
#endif
} timer0_t;

/*  Section : Functions declarations */
/**
 * This function is used to initialize timer0
 * @param timer [mode - prescalar_mode - prescalar_value - registerSize - callBackFunction]
 * @return OK if function works properly , N_Ok if function fails
 */
Err_check_t timer0_init(timer0_t *timer);
/**
 * @param timer [mode - prescalar_mode - prescalar_value - registerSize - callBackFunction]
 * @param value [16bit value for preload timer]
 * @return OK if function works properly , N_Ok if function fails
 */
Err_check_t timer0_setValue(timer0_t *timer, uint16 value);
/**
 * @param timer [mode - prescalar_mode - prescalar_value - registerSize - callBackFunction]
 * @param value [16bit value for preload timer]
 * @return OK if function works properly , N_Ok if function fails
 */
Err_check_t timer0_getValue(timer0_t *timer, uint16 *value);


#endif	/* TIMER0_H */

