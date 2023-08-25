/* 
 * File:   button.h
 * Author: Mohamed Abosreea
 *
 * Created on April 8, 2023, 10:54 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H
/*  Section : Includes */

#include "button_cfg.h"
#include "../../MCAL_Layer/GPIO/gpio.h"
#include "../../std_types.h"
#include "../../std_lib.h"
#include "button_cfg.h"
/*  Section : Macro declarations */

/*  Section : Macro Functions declarations */

/*  Section : Data types declarations */
typedef enum {
    PULL_DOWN = 0,
    PULL_UP
} button_connection_t;

typedef enum {
    RELEASED = 0,
    PRESSED
}button_state_t;

typedef struct
{
    pin_config_t btn_pin ;
    button_connection_t btn_conn;
    button_state_t btn_state ;
}button_t;
/*  Section : Functions declarations */
/**
 * This function is used to initialize a button
 * @param btn [pin_config  - button_connection - button_state]
 * @return OK if function success , N_OK if function fails
 */
#if (ENABLE_BUTTON_APIS == ENABLE_BUTTON)
Err_check_t button_init(const button_t *btn);
#endif
/**
 * This function is used to initialize a button
 * @param btn [pin_config  - button_connection - button_state]
 * @param btn_state [PRESSED - RELEASED]
 * @return OK if function success , N_OK if function fails
 */
#if (ENABLE_BUTTON_APIS == ENABLE_BUTTON)
Err_check_t button_get_state(const button_t *btn , button_state_t *btn_state);
#endif
#endif	/* BUTTON_H */

