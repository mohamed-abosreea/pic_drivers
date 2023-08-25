#include "lcd.h"
#if LCD_ENABLE_APIs == ENABLE_LCD

static Err_check_t lcd_set_cursor(const lcd_t *lcd, row_t row, col_t col) {
    Err_check_t e_check = OK;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        switch (row) {
            case ROW0:
                lcd_send_command(lcd, (0x80 + col));
                break;
            case ROW1:
                lcd_send_command(lcd, (0xc0 + col));
                break;
            case ROW2:
                lcd_send_command(lcd, (0x94 + col));
                break;
            case ROW3:
                lcd_send_command(lcd, (0xD4 + col));
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}

Err_check_t lcd_init(const lcd_t *lcd) {
    Err_check_t e_check = OK;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        if (lcd ->lcd_connection == _4_BIT) {
            e_check &= gpio_pin_init(&(lcd->lcd_en));
            e_check &= gpio_pin_init(&(lcd->lcd_rs));
            for (uint8 count = 0; count < 4; count++) {
                e_check &= gpio_pin_init(&(lcd->lcd_data_pins[count]));
            }

            __delay_ms(20);
            e_check &= lcd_send_command(lcd, _LCD_8BIT_2LINE);
            __delay_ms(5);
            e_check &= lcd_send_command(lcd, _LCD_8BIT_2LINE);
            __delay_us(150);
            e_check &= lcd_send_command(lcd, _LCD_8BIT_2LINE);

            e_check &= lcd_send_command(lcd, _LCD_RETURN_HOME);
            e_check &= lcd_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
            e_check &= lcd_send_command(lcd, _LCD_CLEAR);
            e_check &= lcd_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
            e_check &= lcd_send_command(lcd, _LCD_4BIT_2LINE);

        } else if (lcd ->lcd_connection == _8_BIT) {
            e_check &= gpio_pin_init(&(lcd->lcd_en));
            e_check &= gpio_pin_init(&(lcd->lcd_rs));
            for (uint8 count = 0; count < 8; count++) {
                e_check &= gpio_pin_init(&(lcd->lcd_data_pins[count]));
            }
            __delay_ms(20);
            e_check &= lcd_send_command(lcd, _LCD_8BIT_2LINE);
            __delay_ms(5);
            e_check &= lcd_send_command(lcd, _LCD_8BIT_2LINE);
            __delay_us(150);
            e_check &= lcd_send_command(lcd, _LCD_8BIT_2LINE);

            e_check &= lcd_send_command(lcd, _LCD_CLEAR);
            e_check &= lcd_send_command(lcd, _LCD_RETURN_HOME);
            e_check &= lcd_send_command(lcd, _LCD_CURSOR_OFF_DISPLAY_ON);
        } else {
            /*Do Nothing*/
        }
    }
    return e_check;
}

Err_check_t lcd_send_command(const lcd_t *lcd, uint8 command) {
    Err_check_t e_check = OK;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        e_check &= gpio_pin_set_state(&(lcd->lcd_rs), LOW);
        if (lcd->lcd_connection == _4_BIT) {
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[0]), GET_BIT(command, 4));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[1]), GET_BIT(command, 5));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[2]), GET_BIT(command, 6));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[3]), GET_BIT(command, 7));
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), HIGH);
            __delay_us(5);
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), LOW);
            __delay_us(5);
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[0]), GET_BIT((command), 0));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[1]), GET_BIT((command), 1));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[2]), GET_BIT((command), 2));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[3]), GET_BIT((command), 3));
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), HIGH);
            __delay_us(5);
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), LOW);
            __delay_us(5);
        } else if (lcd->lcd_connection == _8_BIT) {
            for (uint8 count = 0; count < 8; count++) {
                e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[count]), GET_BIT(command, count));
            }
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), HIGH);
            __delay_us(5);
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), LOW);
        } else {
            /*Do Nothing*/
        }
    }
    return e_check;
}

Err_check_t lcd_send_chr(const lcd_t *lcd, uint8 character) {
    Err_check_t e_check = OK;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        e_check &= gpio_pin_set_state(&(lcd->lcd_rs), HIGH);
        if (lcd->lcd_connection == _4_BIT) {
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[0]), GET_BIT(character, 4));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[1]), GET_BIT(character, 5));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[2]), GET_BIT(character, 6));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[3]), GET_BIT(character, 7));

            e_check &= gpio_pin_set_state(&(lcd->lcd_en), HIGH);
            __delay_us(10);
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), LOW);

            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[0]), GET_BIT((character), 0));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[1]), GET_BIT((character), 1));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[2]), GET_BIT((character), 2));
            e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[3]), GET_BIT((character), 3));
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), HIGH);
            __delay_us(10);
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), LOW);
        } else if (lcd->lcd_connection == _8_BIT) {
            for (uint8 count = 0; count < 8; count++) {
                e_check &= gpio_pin_set_state(&(lcd->lcd_data_pins[count]), GET_BIT(character, count));
            }
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), HIGH);
            __delay_us(10);
            e_check &= gpio_pin_set_state(&(lcd->lcd_en), LOW);
        } else {
            /*Do Nothing*/
        }
    }
    return e_check;
}

Err_check_t lcd_send_chr_pos(const lcd_t *lcd, uint8 character, row_t row, col_t col) {
    Err_check_t e_check = OK;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        e_check &= lcd_set_cursor(lcd, row, col);
        e_check &= lcd_send_chr(lcd, character);
    }
    return e_check;
}

Err_check_t lcd_send_string(const lcd_t *lcd, uint8* data) {
    Err_check_t e_check = OK;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        for (uint8 index = 0; data[index] != '\0'; index++) {
            e_check &= lcd_send_chr(lcd, data[index]);
        }
    }
    return e_check;
}

Err_check_t lcd_send_string_pos(const lcd_t *lcd, uint8 * data, row_t row, col_t col) {
    Err_check_t e_check = OK;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        e_check &= lcd_set_cursor(lcd, row, col);
        e_check &= lcd_send_string(lcd, data);
    }
    return e_check;
}

Err_check_t lcd_send_number_pos(const lcd_t *lcd, uint16 num, row_t row, col_t col) {
    Err_check_t e_check = OK;
    uint8 data1[6] , data2[6] ;
    uint8 count1 = 0 , count2 = 0 ;
    if (NULL == lcd) {
        e_check = N_OK;
    } else {
        e_check &= lcd_set_cursor(lcd, row, col);
        if(num == 0 )
        {
            e_check &= lcd_send_chr(lcd , '0');
        }
        else{
            while(num > 0)
            {
                data1[count1] = ((num % 10) + '0');
                num /= 10 ;
                count1++;
            }
            data1[count1] = '\0';
            for(count2 = 0 ; count2 < count1 ; count2++)
            {
                data2[count2] = data1[count1-count2-1];
            }
            e_check &= lcd_send_string(lcd , data2);
        }
    }
    return e_check;
}

Err_check_t lcd_send_custome_chr_pos(const lcd_t *lcd, uint8 * arr[], uint8 mem_pos, row_t row, col_t col) {
    Err_check_t e_check = OK;
    if (NULL == lcd || NULL == arr) {
        e_check = N_OK;
    } else {
        e_check &= lcd_send_command(lcd, (_LCD_CGRAM_START + (mem_pos * 8)));
        for(uint8 count = 0 ; count < 8  ;count++)
        {
            e_check &= lcd_send_chr(lcd , arr[count]);
        }
        e_check &= lcd_send_chr_pos(lcd , mem_pos , row , col);
    }
    return e_check;
}

#endif