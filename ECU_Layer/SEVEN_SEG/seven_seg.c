#include "seven_seg.h"

#if ENABLE_SEVEN_SEG_API == ENABLE_SEVEN_SEG

Err_check_t seven_seg_init(const seven_seg_t* seven_seg) {
    Err_check_t e_check = OK;
    if (NULL == seven_seg) {
        e_check = N_OK;
    } else {
        gpio_pin_init(&(seven_seg ->seven_seg_pins[0]));
        gpio_pin_init(&(seven_seg ->seven_seg_pins[1]));
        gpio_pin_init(&(seven_seg ->seven_seg_pins[2]));
        gpio_pin_init(&(seven_seg ->seven_seg_pins[3]));
    }
    return e_check;
}
#endif
#if ENABLE_SEVEN_SEG_API == ENABLE_SEVEN_SEG
Err_check_t seven_seg_write_num(const seven_seg_t* seven_seg , uint8 Num) {
    Err_check_t e_check = OK;
    if (NULL == seven_seg || Num > 9 || Num < 0) {
        e_check = N_OK;
    } else {
        switch (seven_seg ->seven_seg_type) {
            case COMMON_ANODE:
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[0]) , GET_BIT(Num ,0));
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[1]) , GET_BIT(Num ,1));
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[2]) , GET_BIT(Num ,2));
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[3]) , GET_BIT(Num ,3));
                break;
            case COMMON_CATHODE:
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[0]) , !GET_BIT(Num ,0));
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[1]) , !GET_BIT(Num ,1));
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[2]) , !GET_BIT(Num ,2));
                e_check &= gpio_pin_set_state(&(seven_seg->seven_seg_pins[3]) , !GET_BIT(Num ,3));
                break;
            default:
                e_check = N_OK;
        }
    }
    return e_check;
}
#endif