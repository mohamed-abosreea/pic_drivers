/* 
 * File:   interrupt_cfg.h
 * Author: Mohamed Abosreea
 *
 * Created on May 25, 2023, 5:37 PM
 */

#ifndef INTERRUPT_CFG_H
#define	INTERRUPT_CFG_H

/*  Section : Includes*/
#include "../../std_lib.h"
#include "../../std_types.h"
#include "pic18f4620.h"
/*  Section : Macro declarations */
#define INTERRUPT_ENABLE            1
#define INTERRUPT_DISABLE           0
#define INTERRYPT_PERIORITY_ENABLE  1
#define INTERRYPT_PERIORITY_DISABLE 0
#define INTERRUPT_OCCUR             1
#define INTERRUPT_NOT_OCCUR         0

#define INTERRUPT_PRIORITY  INTERRYPT_PERIORITY_DISABLE
/*  Section : Macro Functions declarations */

#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
#define Interrupt_PeriorityEnable()               (RCONbits.IPEN =1)
#define Interrupt_PeriorityDisable()              (RCONbits.IPEN =0)
#define Interrupt_GlobalInterruptHighEnable()     (INTCONbits.GIEH =1)
#define Interrupt_GlobalInterruptHighDisable()    (INTCONbits.GIEH =0)
#define Interrupt_GlobalInterruptLowEnable()      (INTCONbits.GIEL =1)
#define Interrupt_GlobalInterruptLowDisable()     (INTCONbits.GIEL =0)
#else
#define Interrupt_GlobalInterruptEnable()         (INTCONbits.GIE =1)
#define Interrupt_GlobalInterruptDisable()        (INTCONbits.GIE =0)
#define Interrupt_PeripheralInterruptEnebale()    (INTCONbits.PEIE =1)
#define Interrupt_PeripheralInterruptDisebale()   (INTCONbits.PEIE =0)
#endif

/*  Section : Data types declarations */
typedef enum {
    LOW_PRIORITY = 0,
    HIGH_PRIORITY
} interrupt_priority_t;
/*  Section : Functions declarations */
void INT0_ISR();
void INT1_ISR();
void INT2_ISR();
void ADC_ISR();
void TIMER0_ISR();
void TIMER1_ISR();
#endif	/* INTERRUPT_CFG_H */

