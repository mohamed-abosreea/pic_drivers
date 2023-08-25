#include "button.h"


Err_check_t button_init(const button_t *btn) {
    Err_check_t e_check = OK;
    if(NULL == btn)
    {
        e_check = N_OK ;
    }
    else
    {
        e_check =  gpio_pin_init_direction(&(btn->btn_pin));
    }
    return e_check;
}

Err_check_t button_get_state(const button_t *btn, button_state_t *btn_state) {
    Err_check_t e_check = OK;
    if(NULL == btn || NULL == btn_state)
    {
        e_check = N_OK ;
    }
    else
    {
        state_t state ;
        e_check = gpio_pin_get_state(&(btn ->btn_pin) , &state);
        switch(btn ->btn_conn)
        {
            case PULL_UP :
                switch(state)
                {
                    case LOW :
                        *btn_state = PRESSED ;
                        break;
                    case HIGH :
                        *btn_state = RELEASED ;
                        break;
                    default :
                        e_check &= N_OK ;
                }
                break;
            case PULL_DOWN :
                switch(state)
                {
                    case LOW :
                        *btn_state = RELEASED ;
                        break;
                    case HIGH :
                        *btn_state = PRESSED ;
                        break;
                    default :
                        e_check &= N_OK ;
                }
                break;
            default:
                e_check &= N_OK ;
        }
    }
    return e_check;
}