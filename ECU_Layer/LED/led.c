#include "led.h"

#if (ENABLE_LED_APIS == ENABLE_LED)
Err_check_t led_init(const led_t *led)
{
    Err_check_t e_check = OK ;
    if(NULL == led)
    {
        e_check = N_OK ;
    }
    else
    {
        pin_config_t pin_config ;
        pin_config.port = led ->port ;
        pin_config.pin = led ->pin ;
        pin_config.direction = OUTPUT ;
        pin_config.state = (state_t)led ->state;
        e_check =  gpio_pin_init_direction(&pin_config);
        e_check &= gpio_pin_set_state(&pin_config ,pin_config.state);
    }
    return e_check ;
}
#endif

#if (ENABLE_LED_APIS == ENABLE_LED)
Err_check_t led_get_state(const led_t *led , led_state_t *state)
{
    Err_check_t e_check = OK ;
    if(NULL == led || NULL == state)
    {
        e_check = N_OK ;
    }
    else
    {
        pin_config_t pin_config ;
        pin_config.port = led ->port ;
        pin_config.pin = led ->pin ;
        pin_config.direction = OUTPUT ;
        pin_config.state = (state_t)led -> state;
        e_check =  gpio_pin_get_state(&pin_config , (state_t *)state);
    }
    return e_check ;
}
#endif

#if (ENABLE_LED_APIS == ENABLE_LED)
Err_check_t led_turn_on(const led_t *led)
{
    Err_check_t e_check = OK ;
    if(NULL == led)
    {
        e_check = N_OK ;
    }
    else
    {
        pin_config_t pin_config ;
        pin_config.port = led ->port ;
        pin_config.pin = led ->pin ;
        pin_config.direction = OUTPUT ;
        pin_config.state = HIGH;
        e_check =  gpio_pin_set_state(&pin_config , pin_config.state);
    }
    return e_check ;
}
#endif

#if (ENABLE_LED_APIS == ENABLE_LED)
Err_check_t led_turn_off(const led_t *led)
{
    Err_check_t e_check = OK ;
    if(NULL == led)
    {
        e_check = N_OK ;
    }
    else
    {
        pin_config_t pin_config ;
        pin_config.port = led ->port ;
        pin_config.pin = led ->pin ;
        pin_config.direction = OUTPUT ;
        pin_config.state = LOW;
        e_check =  gpio_pin_set_state(&pin_config , pin_config.state);
    }
    return e_check ;
}
#endif

#if (ENABLE_LED_APIS == ENABLE_LED)
Err_check_t led_toggle(const led_t *led)
        {
    Err_check_t e_check = OK ;
    if(NULL == led)
    {
        e_check = N_OK ;
    }
    else
    {
        pin_config_t pin_config ;
        pin_config.port = led ->port ;
        pin_config.pin = led ->pin ;
        pin_config.direction = OUTPUT ;
        pin_config.state = (state_t)led ->state;
        e_check =  gpio_pin_toggle_state(&pin_config);
    }
    return e_check ;
}
#endif