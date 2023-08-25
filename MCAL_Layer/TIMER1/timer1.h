/* 
 * File:   timer1.h
 * Author: Mohamed Abosreea
 *
 * Created on August 6, 2023, 10:48 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H
/*  Section : Includes*/
#include "../Device_Config/device_config.h"
#include "../GPIO/gpio.h"
#include "../Interrupt_Manager/interrupt_cfg.h"
#include "../../std_lib.h"
#include "../../std_types.h"

/*  Section : Macro declarations */

/*  Section : Macro Functions declarations */
#define TIMER1_ENABLE()               (T1CONbits.TMR1ON = 1)
#define TIMER1_DISABLE()              (T1CONbits.TMR1ON = 0)
#define TIMER1_COUNTER_MODE()         (T1CONbits.TMR1CS = 1)
#define TIMER1_TIMER_MODE()           (T1CONbits.TMR1CS = 0)
#define TIMER1_COUNTER_ASYNC()        (T1CONbits.T1SYNC = 1)
#define TIMER1_COUNTER_SYNC()         (T1CONbits.T1SYNC = 0)
#define TIMER1_OSC_ENABLE()           (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_DISABLE()          (T1CONbits.T1OSCEN = 0)
#define TIMER1_SYSTEM_CLK_STATUS()    (T1CONbits.T1SYNC)
#define TIMER1_16BIT_RW_ENABLE()      (T1CONbits.RD16 = 1)
#define TIMER1_8BIT_RW_ENABLE()       (T1CONbits.RD16 = 0)
#define TIMER1_INTERRUPT_ENABLE()     (PIE1bits.TMR1IE = 1)
#define TIMER1_INTERRUPT_DISABLE()    (PIE1bits.TMR1IE = 0)
#define TIMER1_CLEAR_FLAG()           (PIR1bits.TMR1IF = 0)
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)      
#define TIMER1_LOW_PRIORITY_ENABLE()  (IPR1bits.TMR1IP = 0)
#define TIMER1_HIGH_PRIORITY_ENABLE() (IPR1bits.TMR1IP = 1)
#endif

/*  Section : Data types declarations */
typedef enum {
    NO_PRESCALAR = 0,
    PRESCALAR_DIV_2,
    PRESCALAR_DIV_4,
    PRESCALAR_DIV_8
} timer1_prescalar_t;

typedef enum {
    COUNTER_MODE = 0,
    TIMER_MODE
} timer1_mode_t;

typedef enum {
    SYNCHRONOUS,
    ASYNCHRONOUS
} timer1_synchronization_t;

typedef enum {
    _8BIT_MODE,
    _16BIT_MODE
} timer1_rw_mode_t;

#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)      
typedef enum {
    TIMER1_LOW_PRIORITY,
    TIMER1_HIGH_PRIORITY
} timer1_priority_t;
#endif

typedef enum  {
    TIMER1_INTERRUPT_OFF,
    TIMER1_INTERRUPT_ON
}timer1_interrupt_mode_t;
typedef struct {
    timer1_mode_t t1_mode;
    timer1_prescalar_t prescalar_value;
    timer1_synchronization_t sync_mode;
    timer1_rw_mode_t rw_mode;
    timer1_interrupt_mode_t t1_IntMode;
    uint16 preload_value;
    void (*InterruptHandler)(void);
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)      
    timer1_priority_t priotity;
#endif
}timer1_t;
/*  Section : Functions declarations */
/**
 * This function is used to initialize timer1 configuration
 * @param timer1
 * @return OK if function success, N_OK if function fails
 */
Err_check_t timer1_init(const timer1_t *timer1);
/**
 * This function is used to de-initialize timer1 configuration
 * @param timer1
 * @return OK if function success, N_OK if function fails
 */
Err_check_t timer1_deInit(const timer1_t *timer1);
/**
 * This function is used to set value to timer1
 * @param timer1
 * @param value
 * @return OK if function success, N_OK if function fails
 */
Err_check_t timer1_setValue(const timer1_t *timer1 , uint16 value);
/**
 * This function is used to get value to timer1
 * @param timer1
 * @param value
 * @return OK if function success, N_OK if function fails
 */
Err_check_t timer1_getValue(const timer1_t *timer1 , uint16 *value);
#endif	/* TIMER1_H */

