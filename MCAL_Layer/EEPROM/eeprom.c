#include "eeprom.h"

Err_check_t eeprom_init() {

}

Err_check_t eeprom_write_byte(uint16 Address, uint8 data) {
    Err_check_t e_check = OK;
    if (Address > 0x3F) {
        e_check = N_OK;
    } else {
        uint8 GIE = INTCONbits.GIE;

        /*Set Address of EEPROM location*/
        EEADR = (uint8) (Address & 0xFF);
        EEADRH = (uint8) ((Address >> 8) & 0x03);
        EEDATA = data;
        EEPROM_Memory_Select();
        EEPROM_Write_Enable();
        Interrupt_GlobalInterruptDisable();
        EECON2 = 0x55;
        EECON2 = 0xAA;
        EEprom_Write_Start();
        while (EECON1bits.WR);
        EEPROM_Write_Disable();
        INTCONbits.GIE = GIE;
    }
    return e_check;
}

Err_check_t eeprom_read_byte(uint16 Address, uint8 * data) {
    Err_check_t e_check = OK;
    if (Address > 0x3F || data == NULL) {
        e_check = N_OK;
    } else {
        /*Set Address of EEPROM location*/
        EEADR = (uint8) (Address & 0xFF);
        EEADRH = (uint8) ((Address >> 8) & 0x03);
        EEPROM_Memory_Select();
        EEprom_Read_Start();
        NOP();
        NOP();
        *data = EEDATA;
    }
    return e_check;
}

Err_check_t eeprom_interrupt_enabel(void(*eeprom_isr)(void), interrupt_priority_t priority) {

}