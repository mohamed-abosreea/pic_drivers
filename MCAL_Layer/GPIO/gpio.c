#include "gpio.h"
#include "gpio_cfg.h"

volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

#if(ENABLE_GPIO_PINS == ENABLE_GPIO)
Err_check_t gpio_pin_init(const pin_config_t *pin_config)
{
    Err_check_t e_check = OK ;
    if(NULL == pin_config)
    {
        e_check = N_OK ;
    }
    else
    {
        e_check =  gpio_pin_init_direction(pin_config);
        e_check &= gpio_pin_set_state(pin_config , pin_config ->state);
    }
    return e_check ;
}
#endif
#if(ENABLE_GPIO_PINS == ENABLE_GPIO)
Err_check_t gpio_pin_init_direction(const pin_config_t *pin_config) {
    Err_check_t e_check = OK;
    if (NULL == pin_config) {
        e_check = N_OK;
    } else {
        switch (pin_config ->direction) {
            case INPUT:
                SET_BIT(*tris_registers[pin_config ->port], pin_config -> pin);
                break;
            case OUTPUT:
                CLEAR_BIT(*tris_registers[pin_config ->port], pin_config -> pin);
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PINS == ENABLE_GPIO)
Err_check_t gpio_pin_get_direction(const pin_config_t *pin_config, direction_t *dir) {
    Err_check_t e_check = OK;
    if (NULL == pin_config || NULL == dir) {
        e_check = N_OK;
    } else {
        *dir = GET_BIT(*tris_registers[pin_config ->port], pin_config ->pin);
        e_check = OK;
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PINS == ENABLE_GPIO)
Err_check_t gpio_pin_set_direction(const pin_config_t *pin_config, direction_t dir) {
    Err_check_t e_check = OK;
    if (pin_config == NULL) {
        e_check = N_OK;
    } else {
        switch (dir) {
            case INPUT:
                SET_BIT(*tris_registers[pin_config ->port], pin_config -> pin);
                break;
            case OUTPUT:
                CLEAR_BIT(*tris_registers[pin_config ->port], pin_config -> pin);
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PINS == ENABLE_GPIO)
Err_check_t gpio_pin_set_state(const pin_config_t *pin_config, state_t state) {

    Err_check_t e_check = OK;
    if (NULL == pin_config) {
        e_check = N_OK;
    } else {
        switch (state) {
            case HIGH:
                SET_BIT(*lat_registers[pin_config ->port], pin_config -> pin);
                break;
            case LOW:
                CLEAR_BIT(*lat_registers[pin_config ->port], pin_config -> pin);
                break;
            default:
                e_check = N_OK;
        }
    }
        return e_check;
}
#endif
#if(ENABLE_GPIO_PINS == ENABLE_GPIO)
Err_check_t gpio_pin_get_state(const pin_config_t *pin_config, state_t * state) {
    Err_check_t e_check = OK;
    if (NULL == pin_config || NULL == state) {
        e_check = N_OK;
    } else {
        *state = GET_BIT(*port_registers[pin_config -> port], pin_config->pin);
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PINS == ENABLE_GPIO)
Err_check_t gpio_pin_toggle_state(const pin_config_t * pin_config) {
    Err_check_t e_check = OK;
    if (NULL == pin_config) {
        e_check = N_OK;
    } else {
        TOGGLE_BIT(*lat_registers[pin_config ->port], pin_config ->pin);
        e_check = OK;
    }
    return e_check;
}
#endif
/*******************************************************/
#if(ENABLE_GPIO_PORTS == ENABLE_GPIO)
Err_check_t gpio_port_direction_init(port_t port, uint8 dir) {
    Err_check_t e_check = OK;
    if(port >= MAX_PORT_NUMBER)
    {
        e_check = N_OK;
    }
    else
    {
        *tris_registers[port] = dir ;
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PORTS == ENABLE_GPIO)
Err_check_t gpio_port_get_direction(port_t port, uint8 * dir) {
    Err_check_t e_check = OK;
    if (NULL == dir || port >= MAX_PORT_NUMBER) {
        e_check = N_OK;
    } else {
        *dir = *tris_registers[port];
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PORTS == ENABLE_GPIO)
Err_check_t gpio_port_set_state(port_t port, uint8 state) {
    Err_check_t e_check = OK;
    if( port<= MAX_PORT_NUMBER)
    {
        *lat_registers[port] = state;      
    }
    else
    {
        e_check = N_OK;
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PORTS == ENABLE_GPIO)
Err_check_t gpio_port_get_state(port_t port, uint8 * state) {
    Err_check_t e_check = OK;
    if(port <= MAX_PORT_NUMBER)
    {
        *state = *port_registers[port];      
    }
    else
    {
        e_check = N_OK;
    }
    return e_check;
}
#endif
#if(ENABLE_GPIO_PORTS == ENABLE_GPIO)
Err_check_t gpio_port_toggle_state(port_t port)
{
Err_check_t e_check = OK;
uint8 state = *port_registers[port] ;
    if( port<= MAX_PORT_NUMBER)
    {
        *lat_registers[port] = ~state;    
    }
    else
    {
        e_check = N_OK;
    }
    return e_check;   
}
#endif