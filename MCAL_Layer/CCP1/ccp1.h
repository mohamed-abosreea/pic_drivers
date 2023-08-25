/* 
 * File:   ccp1.h
 * Author: Mohamed Abosreea
 *
 * Created on August 8, 2023, 10:52 AM
 */

#ifndef CCP1_H
#define	CCP1_H
/*  Section : Includes*/
#include "../../std_lib.h"
#include "../../std_types.h"
#include "../Interrupt_Manager/interrupt_cfg.h"
#include "../GPIO/gpio.h"
#include "../TIMER1/timer1.h"
#include "ccp1_cfg.h"
/*  Section : Macro declarations */

/*  Section : Macro Functions declarations */

/*  Section : Data types declarations */
typedef enum {
    CCP_DISABLED = 0x00,
    COMPARE_MODE_TOOGLE_OUTPUT = 0x02,
    COMPARE_MODE_FORCE_HIGH = 0x08,
    COMPARE_MODE_FORCE_LOW = 0x09,
    COMPARE_MODE_GENERATE_SW_INTERRUPT = 0x0A,
    COMPARE_MODE_GENERATE_EVENT = 0x0B,
    CAPTURE_MODE_FALLING_EDGE = 0x04,
    CAPTURE_MODE_RISING_EDGE = 0x05,
    CAPTURE_MODE_4_RISING_EDGE = 0x06,
    CAPTURE_MODE_16_RISING_EDGE = 0x07,
    PWM_MODE = 0x0F
}ccp_mode_t;

typedef struct {
    
};
/*  Section : Functions declarations */

#endif	/* CCP1_H */

