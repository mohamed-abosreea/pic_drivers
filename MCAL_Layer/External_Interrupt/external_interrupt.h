/* 
 * File:   external_interrupt.h
 * Author: Mohamed Abosreea
 *
 * Created on May 25, 2023, 5:42 PM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H
/*  Section : Includes*/
#include "../Interrupt_Manager/interrupt_cfg.h"
#include "../GPIO/gpio.h"
#include "../../std_lib.h"
#include "../../std_types.h"

/*  Section : Macro declarations */
#define INTx_Enable        INTERRUPT_ENABLE
#define Interrupt_OnChange INTERRUPT_ENABLE
/*  Section : Macro Functions declarations */
#if INTx_Enable == INTERRUPT_ENABLE

#define EXT_INT0_Enable()       (INTCONbits.INT0E = 1)
#define EXT_INT0_Disable()      (INTCONbits.INT0E = 0)
#define EXT_INT0_ClrFlag()      (INTCONbits.INT0IF = 0)
#define EXT_INT0_RisingEdge()   (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_FallingEdge()   (INTCON2bits.INTEDG0 = 0)

#define EXT_INT1_Enable()       (INTCON3bits.INT1E = 1)
#define EXT_INT1_Disable()      (INTCON3bits.INT1E = 0)
#define EXT_INT1_ClrFlag()      (INTCON3bits.INT1IF = 0)
#define EXT_INT1_RisingEdge()   (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_FallingEdge()   (INTCON2bits.INTEDG1 = 0)

#define EXT_INT2_Enable()       (INTCON3bits.INT2E = 1)
#define EXT_INT2_Disable()      (INTCON3bits.INT2E = 0)
#define EXT_INT2_ClrFlag()      (INTCON3bits.INT2IF = 0)
#define EXT_INT2_RisingEdge()   (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_FallingEdge()   (INTCON2bits.INTEDG2 = 0)

#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
#define EXT_INT1_SetHighPeriority()   (INTCON3bits.INT1IP = 1)
#define EXT_INT1_SetLowPeriority()    (INTCON3bits.INT1IP = 0)
#define EXT_INT2_SetHighPeriority()   (INTCON3bits.INT2IP = 1)
#define EXT_INT2_SetLowPeriority()    (INTCON3bits.INT2IP = 0)
#endif
#endif

#if Interrupt_OnChange == INTERRUPT_ENABLE
#define EXT_RBx_Enable()        (INTCONbits.RBIE = 1)
#define EXT_RBx_Disable()        (INTCONbits.RBIE = 0)
#define EXT_RBx_ClrFlag()        (INTCONbits.RBIF = 0)
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
#define EXT_Rbx_SetHighPeriority()  (INTCON2bits.RBIP = 1)
#define EXT_Rbx_SetLowPeriority()  (INTCON2bits.RBIP = 0)
#endif
#endif

/*  Section : Data types declarations */
typedef enum {
    FALLING = 0,
    RISING
} interrupt_Intx_edge_t;

typedef enum {
    INT_0 = 0,
    INT_1,
    INT_2
} interrupt_Intx_src_t;

typedef struct {
   interrupt_Intx_src_t int_src;
   interrupt_Intx_edge_t int_edge;
   interrupt_priority_t int_priority;
   void (* EXT_InterruptHandler)(void);
}interrupt_intx_t;

typedef struct {
   void (* EXT_InterruptHandler)(void);
   interrupt_priority_t int_priority;
}interrupt_rbx_t;
/*  Section : Functions declaration*/

/**
 * This function is used to initialize external interrupt
 * @param intx_obj [interrupt source , interrupt edge , interrupt priority level , callback function]
 * @return OK if function works properly , NOK if function fails 
 */
Err_check_t interrupt_INTx_int(const interrupt_intx_t *intx_obj);
/**
 * This function is used to de-initialize external interrupt
 * @param intx_obj [interrupt source , interrupt edge , interrupt priority level , callback function]
 * @return OK if function works properly , NOK if function fails
 */
Err_check_t interrupt_INTx_deint(const interrupt_intx_t *intx_obj);
/**
 * This function is used to initialize on change external interrupt
 * @param rbx_obj [interrupt priority level , call back function]
 * @return OK if function works properly , NOK if function fails
 */
Err_check_t interrupt_RBx_int(const interrupt_rbx_t *rbx_obj);
/**
 * This function is used to de-initialize on change external interrupt
 * @param rbx_obj [interrupt priority level , call back function]
 * @return OK if function works properly , NOK if function fails
 */
Err_check_t interrupt_RBx_deint(const interrupt_rbx_t *rbx_obj);
#endif	/* EXTERNAL_INTERRUPT_H */

