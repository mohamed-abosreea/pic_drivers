/* 
 * File:   eeprom.h
 * Author: Mohamed Abosreea
 *
 * Created on May 30, 2023, 1:55 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

/*  Section : Includes*/
#include "../Interrupt_Manager/interrupt_cfg.h"
#include "../Device_Config/device_config.h"
#include "../../std_lib.h"
#include "../../std_types.h"

/*  Section : Macro declarations */

/*  Section : Macro Functions declarations */
#define EEPROM_Memory_Select()      (EECON1 &= ~(0b11000000))
#define EEPROM_Write_Enable()       (EECON1bits.WREN = 1)
#define EEPROM_Write_Disable()       (EECON1bits.WREN = 0)
#define EEprom_Write_Start()        (EECON1bits.WR = 1)
#define EEprom_Read_Start()        (EECON1bits.RD = 1)
/*  Section : Data types declarations */

/*  Section : Functions declarations */
Err_check_t eeprom_init();

Err_check_t eeprom_write_byte(uint16 Address , uint8 data);

Err_check_t eeprom_read_byte(uint16 Address , uint8 * data);

Err_check_t eeprom_interrupt_enabel(void(*eeprom_isr)(void) , interrupt_priority_t priority);
#endif	/* EEPROM_H */

