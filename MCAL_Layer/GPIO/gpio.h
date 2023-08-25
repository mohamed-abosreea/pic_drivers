/* 
 * File:   gpio.h
 * Author: Mohamed Abosreea
 *
 * Created on March 25, 2023, 1:59 PM
 */

#ifndef GPIO_H
#define	GPIO_H

/*  Section : Includes*/
#include "../Device_Config/device_config.h"
#include "pic18f4620.h"
#include "../../std_types.h"
#include "../../std_lib.h"

/*  Section : Macro declarations */
#define MAX_PORT_NUMBER 5
/*  Section : Macro Functions declarations */

/*  Section : Data types declarations */
typedef enum 
{
    INPUT = 1 ,
    OUTPUT = 0
}direction_t;

typedef enum
{
    HIGH = 1 ,
    LOW = 0
}state_t;

typedef enum 
{
    GPIO_PIN0 = 0 ,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_num_t;

typedef enum 
{
    PORTA_t = 0,
    PORTB_t,
    PORTC_t,
    PORTD_t,
    PORTE_t
}port_t;

typedef struct
{
    port_t port;
    pin_num_t pin ;
    direction_t direction ;
    state_t state ;
}pin_config_t;

/*  Section : Functions declarations */
/**
 * This function is used to initialize a pin.
 * @param pin_config
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_pin_init(const pin_config_t *pin_config);
/**
 * This function is used to initialize direction of a pin.
 * @param pin_config 
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_pin_init_direction(const pin_config_t *pin_config);
/**
 * This function is used to get pin direction in a port
 * @param pin_config
 * @param dir
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_pin_get_direction(const pin_config_t *pin_config, direction_t *dir);
/**
 * This function is used to set direction of a pin 
 * @param pin_config
 * @param dir [ INPUT - OUTPUT ]
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_pin_set_direction(const pin_config_t *pin_config , direction_t dir);
/**
 * This function is used to write a logic on a pin
 * @param pin_config
 * @param state [HIGH - LOW]
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_pin_set_state(const pin_config_t *pin_config , state_t state);
/**
 * This function is used to write a logic on a pin
 * @param pin_config
 * @param state
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_pin_get_state(const pin_config_t *pin_config , state_t *state);
/**
 * This function is used to toggle a logic on a pin
 * @param pin_config
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_pin_toggle_state(const pin_config_t *pin_config);
/*********************************************************************/
/**
 * This function is used to initialization a GPIO port.
 * @param port
 * @param dir
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_port_direction_init(port_t port ,uint8 dir);
/**
 * This function is used to get direction of a GPIO port.
 * @param port
 * @param dir
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_port_get_direction(port_t port , uint8 *dir);
/**
 * This function is used to edit logic of a GPIO Port.
 * @param port
 * @param state {HIGH - LOW]
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_port_set_state(port_t port , uint8 state);
/**
 * This function is used to get state of a GPIO port.
 * @param port
 * @param state
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_port_get_state(port_t port , uint8 *state);
/**
 * This function is used to toggle state of a GPIO port.
 * @param port
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t gpio_port_toggle_state(port_t port);

#endif	/* GPIO_H */

