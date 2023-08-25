#include "timer1.h"
static Err_check_t timer_selectMode(const timer1_t *timer1);
static Err_check_t timer_set_RW_Mode(const timer1_t *timer1);
static Err_check_t timer_setPrescalar(const timer1_t *timer1);
static Err_check_t timer_setDefaultPreloadValue(const timer1_t *timer1);
static Err_check_t timer_checkInterrupt(const timer1_t *timer1);
void (*Timer1_InterruptHandler)(void) = NULL;
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
static Err_check_t timer_setPriority(const timer1_t *timer1);
#endif

Err_check_t timer1_init(const timer1_t *timer1) {
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        /* Disable Timer1*/
        TIMER1_DISABLE();
        /* Set timer1 mode [timer - counter]*/
        e_check &= timer_selectMode(timer1);
        /* Set read-write mode*/
        e_check &= timer_set_RW_Mode(timer1);
        /* Set pre-scalar value*/
        e_check &= timer_setPrescalar(timer1);
        /* Set pre-load value */
        e_check &= timer_setDefaultPreloadValue(timer1);
        /* Check priority feature*/
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
        e_check &= timer_setPriority(timer1);
#endif
        /* Check interrupt feature*/
        e_check = timer_checkInterrupt(timer1);
        /* Enable Timer1*/
        TIMER1_ENABLE();
    }
    return e_check;
}

Err_check_t timer1_deInit(const timer1_t *timer1) {
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        TIMER1_DISABLE();
        TIMER1_CLEAR_FLAG();
        TIMER1_INTERRUPT_DISABLE();
    }
    return e_check;
}

Err_check_t timer1_setValue(const timer1_t *timer1, uint16 value) {
        Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        switch (timer1->rw_mode) {
            case _16BIT_MODE:
                TMR1 = value;
                break;
            case _8BIT_MODE:
                TMR1H = (uint8) (value >> 8);
                TMR1L = (uint8) (value);
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

Err_check_t timer1_getValue(const timer1_t *timer1, uint16 *value) {
    Err_check_t e_check = OK;
    if (timer1 == NULL || value == NULL) {
        e_check = N_OK;
    } else {
        uint8 tmr1L , tmr1H;
        switch (timer1->rw_mode) {
            case _16BIT_MODE:
                *value = TMR1;
                break;
            case _8BIT_MODE:
                tmr1L = TMR1L;
                tmr1H = TMR1H;
                *value = (uint16)((tmr1H<<8) + tmr1L);
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

static Err_check_t timer_selectMode(const timer1_t *timer1) {
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        if (timer1 ->t1_mode == TIMER_MODE) {
            TIMER1_TIMER_MODE();
        } else if (timer1 ->t1_mode == COUNTER_MODE) {
            TIMER1_COUNTER_MODE();
        } else {
            e_check = N_OK;
        }
    }
    return e_check;
}

static Err_check_t timer_set_RW_Mode(const timer1_t *timer1) {
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        if (timer1 ->rw_mode == _16BIT_MODE) {
            TIMER1_16BIT_RW_ENABLE();
        } else if (timer1 ->rw_mode == _8BIT_MODE) {
            TIMER1_8BIT_RW_ENABLE();
        } else {
            e_check = N_OK;
        }
    }
    return e_check;
}

static Err_check_t timer_setPrescalar(const timer1_t *timer1) {
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        switch (timer1->prescalar_value) {
            case NO_PRESCALAR:
                T1CONbits.T1CKPS = 0;
                break;
            case PRESCALAR_DIV_2:
                T1CONbits.T1CKPS = 1;
                break;
            case PRESCALAR_DIV_4:
                T1CONbits.T1CKPS = 2;
                break;
            case PRESCALAR_DIV_8:
                T1CONbits.T1CKPS = 3;
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

static Err_check_t timer_setDefaultPreloadValue(const timer1_t *timer1) {
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        switch (timer1->rw_mode) {
            case _16BIT_MODE:
                TMR1 = timer1->preload_value;
                break;
            case _8BIT_MODE:
                TMR1H = (uint8) (timer1->preload_value >> 8);
                TMR1L = (uint8) (timer1->preload_value);
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)

static Err_check_t timer_setPriority(const timer1_t *timer1) {
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        if (timer1->priority == TIMER0_PRIORITY_LOW) {
            TIMER0_INTERRUPT_PRIORITY_LOW();
        } else if (timer1->priority == TIMER0_PRIORITY_HIGH) {
            TIMER0_INTERRUPT_PRIORITY_HIGH();
        } else {
            e_check = N_OK;
        }
    }
    return e_check;
}
#endif

static Err_check_t timer_checkInterrupt(const timer1_t *timer1)
{
    Err_check_t e_check = OK;
    if (timer1 == NULL) {
        e_check = N_OK;
    } else {
        if (timer1 ->t1_IntMode == TIMER1_INTERRUPT_OFF) {
            TIMER1_CLEAR_FLAG();
            TIMER1_INTERRUPT_DISABLE();
        } else if (timer1 ->t1_IntMode == TIMER1_INTERRUPT_ON  || timer1 ->InterruptHandler == NULL) {
            Timer1_InterruptHandler = timer1->InterruptHandler;
            TIMER1_CLEAR_FLAG();
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
        if (timer1->priority == TIMER0_PRIORITY_LOW) {
            Interrupt_GlobalInterruptLowEnable();
        } else if (timer1->priority == TIMER0_PRIORITY_HIGH) {
            Interrupt_GlobalInterruptHighEnable();
        } else {
            e_check = N_OK;
        }
#else
            Interrupt_GlobalInterruptEnable();
            Interrupt_PeripheralInterruptEnebale();
            TIMER1_INTERRUPT_ENABLE();
#endif
        } else {
            e_check = N_OK;
        }
    }
    return e_check;
}

void TIMER1_ISR(void){
    TIMER1_CLEAR_FLAG();
    if(Timer1_InterruptHandler)
    {
        Timer1_InterruptHandler();
    }
}