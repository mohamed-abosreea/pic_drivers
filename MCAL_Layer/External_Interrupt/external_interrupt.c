#include "external_interrupt.h"
#include "../Device_Config/device_config.h"

static void (*INT0_InterruptHandler)(void) = NULL;
static void (*INT1_InterruptHandler)(void) = NULL;
static void (*INT2_InterruptHandler)(void) = NULL;

static Err_check_t interrupt_INTx_Enable(const interrupt_intx_t *intx_obj);
static Err_check_t interrupt_INTx_Disable(const interrupt_intx_t *intx_obj);
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
static Err_check_t interrupt_INTx_Priority_Cfg(const interrupt_intx_t *intx_obj);
#endif
static Err_check_t interrupt_INTx_Edge_Cfg(const interrupt_intx_t *intx_obj);
static Err_check_t interrupt_INTx_Pin_Init(const interrupt_intx_t *intx_obj);
static Err_check_t interrupt_INTx_Clear_Flag(const interrupt_intx_t *intx_obj);
static Err_check_t interrupt_INTx_SetHandler(const interrupt_intx_t *intx_obj);

static Err_check_t interrupt_RBx_Enable(const interrupt_intx_t *intx_obj);
static Err_check_t interrupt_RBx_Disable(const interrupt_intx_t *intx_obj);
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
static Err_check_t interrupt_Rbx_Priority_Cfg(const interrupt_intx_t *intx_obj);
#endif
static Err_check_t interrupt_RBx_Pin_Init(const interrupt_intx_t *intx_obj);
static Err_check_t interrupt_RBx_Clear_Flag(const interrupt_intx_t *intx_obj);
static Err_check_t interrupt_RBx_SetHandler(const interrupt_intx_t *intx_obj);

Err_check_t interrupt_INTx_int(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        e_check &= interrupt_INTx_Disable(intx_obj);
        e_check &= interrupt_INTx_Clear_Flag(intx_obj);
        #if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
        e_check &= interrupt_INTx_Priority_Cfg(intx_obj);
        #endif
        e_check &= interrupt_INTx_Pin_Init(intx_obj);
        e_check &= interrupt_INTx_SetHandler(intx_obj);
        e_check &= interrupt_INTx_Edge_Cfg(intx_obj);
        e_check &= interrupt_INTx_Enable(intx_obj);
    }
    return e_check;
}

Err_check_t interrupt_INTx_deint(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        e_check &= interrupt_INTx_Disable(intx_obj);
    }
    return e_check;
}

Err_check_t interrupt_RBx_int(const interrupt_rbx_t *rbx_obj) {
    Err_check_t e_check = OK;
    if (NULL == rbx_obj) {
        e_check = N_OK;
    } else {

    }
    return e_check;
}

Err_check_t interrupt_RBx_deint(const interrupt_rbx_t *rbx_obj) {
    Err_check_t e_check = OK;
    if (NULL == rbx_obj) {
        e_check = N_OK;
    } else {

    }
    return e_check;
}

static Err_check_t interrupt_INTx_Enable(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        switch (intx_obj ->int_src) {
            case INT_0:
                EXT_INT0_Enable();
                break;
            case INT_1:
                EXT_INT1_Enable();
                break;
            case INT_2:
                EXT_INT2_Enable();
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

static Err_check_t interrupt_INTx_Disable(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        switch (intx_obj ->int_src) {
            case INT_0:
                EXT_INT0_Disable();
                break;
            case INT_1:
                EXT_INT1_Disable();
                break;
            case INT_2:
                EXT_INT2_Disable();
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)

static Err_check_t interrupt_INTx_Priority_Cfg(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        switch (intx_obj ->int_src) {
            case INT_1:
                if (intx_obj ->int_priority == HIGH_PRIORITY) {
                    EXT_INT1_SetHighPeriority();
                } else if (intx_obj ->int_priority == LOW_PRIORITY) {
                    EXT_INT1_SetLowPeriority();
                } else {
                    e_check = N_OK;
                }
                break;
            case INT_2:
                if (intx_obj ->int_priority == HIGH_PRIORITY) {
                    EXT_INT2_SetHighPeriority();
                } else if (intx_obj ->int_priority == LOW_PRIORITY) {
                    EXT_INT2_SetLowPeriority();
                } else {
                    e_check = N_OK;
                }
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}
#endif

static Err_check_t interrupt_INTx_Edge_Cfg(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        switch (intx_obj ->int_src) {
            case INT_0:
                if (intx_obj ->int_edge == FALLING) {
                    EXT_INT0_FallingEdge();
                } else if (intx_obj ->int_edge == RISING) {
                    EXT_INT0_RisingEdge();
                } else {
                    e_check = N_OK;
                }
                break;
            case INT_1:
                if (intx_obj ->int_edge == FALLING) {
                    EXT_INT1_FallingEdge();
                } else if (intx_obj ->int_edge == RISING) {
                    EXT_INT1_RisingEdge();
                } else {
                    e_check = N_OK;
                }
                break;
            case INT_2:
                if (intx_obj ->int_edge == FALLING) {
                    EXT_INT2_FallingEdge();
                } else if (intx_obj ->int_edge == RISING) {
                    EXT_INT2_RisingEdge();
                } else {
                    e_check = N_OK;
                }
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

static Err_check_t interrupt_INTx_Pin_Init(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        pin_config_t pin;
        switch (intx_obj ->int_src) {
            case INT_0:
                pin.port = PORTB_t;
                pin.pin = GPIO_PIN0;
                pin.direction = INPUT;
                e_check &= gpio_pin_init_direction(&pin);
                break;
            case INT_1:
                pin.port = PORTB_t;
                pin.pin = GPIO_PIN1;
                pin.direction = INPUT;
                e_check &= gpio_pin_init_direction(&pin);
                break;
            case INT_2:
                pin.port = PORTB_t;
                pin.pin = GPIO_PIN2;
                pin.direction = INPUT;
                e_check &= gpio_pin_init_direction(&pin);
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

static Err_check_t interrupt_INTx_Clear_Flag(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (NULL == intx_obj) {
        e_check = N_OK;
    } else {
        switch (intx_obj ->int_src) {
            case INT_0:
                EXT_INT0_ClrFlag();
                break;
            case INT_1:
                EXT_INT1_ClrFlag();
                break;
            case INT_2:
                EXT_INT2_ClrFlag();
                break;
            default:
                e_check = N_OK;
                break;
        }
    }
    return e_check;
}

static Err_check_t interrupt_INTx_SetHandler(const interrupt_intx_t *intx_obj) {
    Err_check_t e_check = OK;
    if (intx_obj == NULL) {
        e_check = N_OK;
    } else {
        switch (intx_obj ->int_src) {
            case INT_0:
                if (intx_obj ->EXT_InterruptHandler != NULL) {
                    INT0_InterruptHandler = intx_obj ->EXT_InterruptHandler;
                } else {
                    e_check = N_OK;
                }
                break;
            case INT_1:
                if (intx_obj ->EXT_InterruptHandler != NULL) {
                    INT1_InterruptHandler = intx_obj ->EXT_InterruptHandler;
                } else {
                    e_check = N_OK;
                }
                break;
            case INT_2:
                if (intx_obj ->EXT_InterruptHandler != NULL) {
                    INT2_InterruptHandler = intx_obj ->EXT_InterruptHandler;
                } else {
                    e_check = N_OK;
                }
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

void INT0_ISR(void) {
    EXT_INT0_ClrFlag();
    if (INT0_InterruptHandler) {
        INT0_InterruptHandler();
    }
}

void INT1_ISR(void) {
    EXT_INT1_ClrFlag();
    if (INT1_InterruptHandler) {
        INT1_InterruptHandler();
    }
}

void INT2_ISR(void) {
    EXT_INT2_ClrFlag();
    if (INT2_InterruptHandler) {
        INT2_InterruptHandler();
    }
}