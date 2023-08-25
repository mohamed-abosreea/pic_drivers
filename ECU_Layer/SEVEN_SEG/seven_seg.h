/* 
 * File:   seven_seg.h
 * Author: Mohamed Abosreea
 *
 * Created on April 12, 2023, 1:41 PM
 */

#ifndef SEVEN_SEG_H
#define	SEVEN_SEG_H

/* Section : Includes */
#include "seven_seg_cfg.h"
#include "../../MCAL_Layer/GPIO/gpio.h"
#include "../../std_lib.h"
#include "../../std_types.h"

/*  Section : Macro declarations */

/*  Section : Macro Functions declarations */

/*  Section : Data types declarations */
typedef enum {
    COMMON_ANODE = 0,
    COMMON_CATHODE
} seven_seg_type_t;

typedef struct {
    pin_config_t seven_seg_pins[4];
    seven_seg_type_t seven_seg_type ;
}seven_seg_t;

/*  Section : Functions declarations */
/**
 * This function is used to initialize a seven segment.
 * @param seven_seg [seven_seg_pins - seven segment type]
 * @return OK if function success , N_OK if function fails
 */
Err_check_t seven_seg_init(const seven_seg_t* seven_seg);
/**
 * This function is used to initialize a seven segment.
 * @param seven_seg [seven_seg_pins - seven segment type]
 * @param Num [form 0 to 9 ]
 * @return OK if function success , N_OK if function fails
 */
Err_check_t seven_seg_write_num(const seven_seg_t* seven_seg , uint8 Num);
#endif	/* SEVEN_SEG_H */

