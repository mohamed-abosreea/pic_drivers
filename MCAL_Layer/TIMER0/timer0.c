#include "timer0.h"
static void (*TIMER0_InterruptHandler)(void) = NULL;
Err_check_t timer0_init(timer0_t *timer)
{
    Err_check_t e_check = OK;
    if(timer == NULL)
    {
        e_check = N_OK;
    }
    else {
        if(timer->timer0_mode == TIMER0_TIMER)
        {
            TIMER0_DISABLE();
            if(timer->prescalar_mode == TIMER0_PRESCALAR_ON)
            {
               TIMER0_PRESCALAR_ENABLE();
               TIMER0_SET_PRESCALAR(timer->prescalar_value);
            }else{
               TIMER0_PRESCALAR_DISABLE(); 
            }
            
            if(timer->timer0_register_size == TIMER0_16BIT)
            {
                TIMER0_16BIT_MODE();
            }else{
                TIMER0_8BIT_MODE();
            }
            TIMER0_InterruptHandler = timer->timer0_callBackFunction ;
            TMR0H = (uint8)(timer ->timer0_preload_vlaue >> 8);
            TMR0L = (uint8)(timer ->timer0_preload_vlaue);
            TIMER0_TIMER_MODE();
            TIMER0_INTERRUPT_DISABLE();
            TIMER0_CLEAR_FLAG();
            TIMER0_ENABLE();
        }else
        {
            TIMER0_DISABLE();    
            
        }
    }
    return e_check;
}

Err_check_t timer0_setValue(timer0_t *timer , uint16 value)
{
    Err_check_t e_check = OK;
    if(timer == NULL)
    {
        e_check = N_OK;
    }else{
        if(timer->timer0_register_size == TIMER0_8BIT)
        {
            TMR0L = value;
        }else if(timer->timer0_register_size == TIMER0_16BIT){
            TMR0H = (uint8)(value >>8);
            TMR0L = (uint8)value; 
        }
    }
    return e_check;
}

Err_check_t timer0_getValue(timer0_t *timer , uint16 *value);

void TIMER0_ISR(void){
    TIMER0_CLEAR_FLAG();
    if(TIMER0_InterruptHandler)
    {
        TIMER0_InterruptHandler();
    }
}