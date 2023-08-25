#include "adc.h"
Err_check_t static adc_portConfiguration(adc_channel_select_t channel);
static void (*ADC_InterruptHandler)(void) = NULL;

Err_check_t adc_init(const adc_cfg_t *adc) {
    Err_check_t e_check = OK;
    if (adc == NULL) {
        e_check = N_OK;
    } else {
        /* Disable ADC module*/
        ADC_DISABLE();
        /* COnfigure acquisition time*/
        ADCON2bits.ACQT = adc->acquisition_time;
        /* Configure conversion clock*/
        ADCON2bits.ADCS = adc->conversion_clk;
        /* Configure the adc channel*/
        ADCON0bits.CHS = adc->adc_channel;
        adc_portConfiguration(adc->adc_channel);
        /* Configure interrupt of adc*/
#if(ADC_INTERRUPT == INTERRUPT_ENABLE)
        if(adc->adc_callBackFunction)
        {
            ADC_InterruptHandler = adc->adc_callBackFunction ;
        }
#endif
        /* Configure adc result format*/
        ADC_FORMAT_JUSTIFICATION(adc->result_format);
        /* Configure adc voltage reference source*/
        ADC_VOLTAGE_REFERENCE_CONFIG(adc->voltage_ref);
        /* Enable ADC module*/
        ADC_ENABLE();
    }
    return e_check;
}

Err_check_t adc_deInit(const adc_cfg_t *adc) {
    Err_check_t e_check = OK;
    if (adc == NULL) {
        e_check = N_OK;
    } else {
        ADC_DISABLE();
        ADC_PORT_CONFIGURATION_CONTROL(ADC_ALL_DIGITAL_CFG);
    }
    return e_check;
}

Err_check_t adc_startConversion(const adc_cfg_t *adc) {
    Err_check_t e_check = OK;
    if (adc == NULL) {
        e_check = N_OK;
    } else {
        ADC_START_CONVERSION();
    }
    return e_check;
}

Err_check_t adc_channelSelect(const adc_cfg_t *adc, adc_channel_select_t channel) {
    Err_check_t e_check = OK;
    if (adc == NULL) {
        e_check = N_OK;
    } else {
        ADCON0bits.CHS = channel;
        adc_portConfiguration(channel);
    }
    return e_check;
}

Err_check_t adc_isConversionDone(const adc_cfg_t *adc, uint8 *status) {
    Err_check_t e_check = OK;
    if (adc == NULL || status == NULL) {
        e_check = N_OK;
    } else {
        
        *status = (uint8)!ADC_CONVERSION_STATUS();
    }
    return e_check;
}

Err_check_t adc_getConversionResult(const adc_cfg_t *adc, uint16 *result) {
    Err_check_t e_check = OK;
    if (adc == NULL || NULL == result) {
        e_check = N_OK;
    } else {
        e_check &= adc_startConversion(adc);
        while(ADCON0bits.GO_nDONE);
        if(adc->result_format == ADC_LEFT)
        {
            *result = (uint16)((ADRESH << 8) + (ADRESL>>6));
        }else if(adc->result_format == ADC_RIGHT)
        {
            *result = (uint16 )((ADRESH << 8) + ADRESL);
        } 
        else
        {
            e_check = N_OK;
            /*Do Nothing*/
        }
    }
    return e_check;
}

Err_check_t static adc_portConfiguration(adc_channel_select_t channel) {
    Err_check_t e_check = OK;
    switch (channel) {
        case ADC_CHANNEL_AN0:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN0_ANALOG_CFG);
            SET_BIT(TRISA , 0);
            break;
        case ADC_CHANNEL_AN1:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN1_ANALOG_CFG);
            SET_BIT(TRISA , 1);
            break;
        case ADC_CHANNEL_AN2:
            SET_BIT(TRISA , 2);
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN2_ANALOG_CFG);
            break;
        case ADC_CHANNEL_AN3:
            SET_BIT(TRISA , 3);
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN3_ANALOG_CFG);
            break;
        case ADC_CHANNEL_AN4:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN4_ANALOG_CFG);
            SET_BIT(TRISA , 5);
            break;
        case ADC_CHANNEL_AN5:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN5_ANALOG_CFG);
            SET_BIT(TRISE , 0);
            break;
        case ADC_CHANNEL_AN6:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN6_ANALOG_CFG);
            SET_BIT(TRISE , 1);
            break;
        case ADC_CHANNEL_AN7:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN7_ANALOG_CFG);
            SET_BIT(TRISE , 2);
            break;
        case ADC_CHANNEL_AN8:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN8_ANALOG_CFG);
            SET_BIT(TRISB , 2);
            break;
        case ADC_CHANNEL_AN9:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN9_ANALOG_CFG);
            SET_BIT(TRISB , 3);
            break;
        case ADC_CHANNEL_AN10:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN10_ANALOG_CFG);
            SET_BIT(TRISB , 1);
            break;
        case ADC_CHANNEL_AN11:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN11_ANALOG_CFG);
            SET_BIT(TRISB , 4);
            break;
        case ADC_CHANNEL_AN12:
            ADC_PORT_CONFIGURATION_CONTROL(ADC_AN12_ANALOG_CFG);
            SET_BIT(TRISB , 0);
            break;
        default:
            e_check = N_OK;
    }
    return e_check;
}
Err_check_t adc_interruptEnable()
{
    Err_check_t e_check = OK ;
    ADC_INTERRUPT_ENABLE();
    return e_check;
}
        
Err_check_t adc_interruptDisable()
{
    Err_check_t e_check = OK ;
    ADC_INTERRUPT_DISABLE();
    return e_check;
}

void ADC_ISR(void)
{
    ADC_INTERRUPT_CLEAR_FLAG();
    if(ADC_InterruptHandler)
    {
        ADC_InterruptHandler();
    }
}