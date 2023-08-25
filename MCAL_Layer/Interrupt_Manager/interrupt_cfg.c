#include "interrupt_cfg.h"

#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)

void __interrupt() InterruptManagerHigh(void) {
    if ((INTCONbits.INT0E == 1)&& (INTCONbits.INT0IF == 1)) {
        INT0_ISR();
    } else {
        /*Do Nothing*/
    };
    if ((PIE1bits.ADIE == 1) && (PIR1bits.ADIF == 1) && (IPR1bits.ADIP == 1)) {
        ADC_ISR();
    } else {
        /* Do Nothing */
    };
    if ((INTCONbits.T0IE == 1) && (INTCONbits.T0IF == 1) && (INTCON2bits.TMR0IP == 1)) {
        TIMER0_ISR();
    } else {
        /* Do Nothing */
    };
     if((PIE1bits.TMR1IE == 1) &&(PIR1bits.TMR1IF == 1) && (IPR1bits.TMR1IP == 1))
    {
        TIMER1_ISR();
    }else{
         /* Do Nothing */
    }
}

void __interrupt(low_priority) InterruptManagerLow(void) {
    if ((INTCON3bits.INT1IE == 1)&& (INTCON3bits.INT1IF == 1)) {
        INT1_ISR();
    } else {
        /*Do Nothing*/
    };
    if ((PIE1bits.ADIE == 1) && (PIR1bits.ADIF == 1) && (IPR1bits.ADIP == 0)) {
        ADC_ISR();
    } else {
        /* Do Nothing */
    };
    if ((INTCONbits.T0IE == 1) && (INTCONbits.T0IF == 1) && (INTCON2bits.TMR0IP == 0)) {
        TIMER0_ISR();
    } else {
        /* Do Nothing */
    }
    
    if((PIE1bits.TMR1IE == 1) &&(PIR1bits.TMR1IF == 1) && (IPR1bits.TMR1IP == 0))
    {
        TIMER1_ISR();
    }else{
         /* Do Nothing */
    }
}
#else

void __interrupt() InterruptManager(void) {
    if ((INTCONbits.INT0E == 1)&& (INTCONbits.INT0IF == 1)) {
        INT0_ISR();
    } else {
        /*Do Nothing*/
    };
    if ((INTCON3bits.INT1IE == 1)&& (INTCON3bits.INT1IF == 1)) {
        INT1_ISR();
    } else {
        /*Do Nothing*/
    };

    if ((INTCON3bits.INT2IE == 1)&& (INTCON3bits.INT2IF == 1)) {
        INT2_ISR();
    } else {
        /*Do Nothing*/
    };
    if ((PIE1bits.ADIE == 1) && (PIR1bits.ADIF == 1)) {
        ADC_ISR();
    } else {
        /* Do Nothing */
    };
    if((INTCONbits.T0IE == 1) &&(INTCONbits.T0IF == 1))
    {
        TIMER0_ISR();
    }else{
         /* Do Nothing */
    }
    if((PIE1bits.TMR1IE == 1) &&(PIR1bits.TMR1IF == 1))
    {
        TIMER1_ISR();
    }else{
         /* Do Nothing */
    }
}
#endif