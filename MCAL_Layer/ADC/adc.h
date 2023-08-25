/* 
 * File:   adc.h
 * Author: Mohamed Abosreea
 *
 * Created on July 8, 2023, 10:31 AM
 */

#ifndef ADC_H
#define	ADC_H

/*  Section : Includes*/
#include "../../std_lib.h"
#include "../../std_types.h"
#include "../GPIO/gpio.h"
#include "../Interrupt_Manager/interrupt_cfg.h"
#include "adc_cfg.h"
/*  Section : Macro declarations */
#define ADC_ALL_DIGITAL_CFG     (0x0F)
#define ADC_AN0_ANALOG_CFG      (0x0E)
#define ADC_AN1_ANALOG_CFG      (0x0D)
#define ADC_AN2_ANALOG_CFG      (0x0C)
#define ADC_AN3_ANALOG_CFG      (0x0B)
#define ADC_AN4_ANALOG_CFG      (0x0A)
#define ADC_AN5_ANALOG_CFG      (0x09)
#define ADC_AN6_ANALOG_CFG      (0x08)
#define ADC_AN7_ANALOG_CFG      (0x07)
#define ADC_AN8_ANALOG_CFG      (0x06)
#define ADC_AN9_ANALOG_CFG      (0x05)
#define ADC_AN10_ANALOG_CFG     (0x04)
#define ADC_AN11_ANALOG_CFG     (0x03)
#define ADC_AN12_ANALOG_CFG     (0x02)

/*  Section : Macro Functions declarations */
#define ADC_CONVERSION_STATUS()                     (ADCON0bits.GODONE)
#define ADC_START_CONVERSION()                      (ADCON0bits.GODONE = 1)
#define ADC_ENABLE()                                (ADCON0bits.ADON = 1)
#define ADC_DISABLE()                               (ADCON0bits.ADON = 0)
#define ADC_PORT_CONFIGURATION_CONTROL(CONFIG)      (ADCON1bits.PCFG = CONFIG)
#define ADC_FORMAT_JUSTIFICATION(COFIG)             (ADCON2bits.ADFM = COFIG)
#define ADC_VOLTAGE_REFERENCE_CONFIG(COFIG)         (ADCON1bits.VCFG = COFIG)
#if(ADC_INTERRUPT == INTERRUPT_ENABLE)
#define ADC_INTERRUPT_ENABLE()                      (PIE1bits.ADIE = 1)
#define ADC_INTERRUPT_DISABLE()                     (PIE1bits.ADIE = 0)
#define ADC_INTERRUPT_CLEAR_FLAG()                  (PIR1bits.ADIF = 0)
#if(INTERRUPT_PRIORITY == INTERRYPT_PERIORITY_ENABLE)
#define ADC_INTERRUPT_PRIORITY_HIGH()               (IPR1bits.ADIP = 1)
#define ADC_INTERRUPT_PRIORITY_LOW()                (IPR1bits.ADIP = 0)
#endif
#endif

/*  Section : Data types declarations */
typedef enum {
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12
} adc_channel_select_t;

typedef enum {
    ADC_0TAD = 0,
    ADC_2TAD,
    ADC_4TAD,
    ADC_6TAD,
    ADC_8TAD,
    ADC_12TAD,
    ADC_16TAD,
    ADC_20TAD
} adc_acquisition_time_select_t;

typedef enum {
    ADC_FOCS_2 = 0,
    ADC_FOCS_8,
    ADC_FOCS_32,
    ADC_FOCS_RC,
    ADC_FOCS_4,
    ADC_FOCS_16,
    ADC_FOCS_64
} adc_conversion_clk_select_t;

typedef enum {
    ADC_LEFT = 0,
    ADC_RIGHT
} adc_result_format_t;

typedef enum {
    ADC_VOLTAGE_REF_DISABLE = 0,
    ADC_VOLTAGE_REF_ENABLE = 3
} adc_voltage_ref_t;

typedef struct {
    adc_channel_select_t adc_channel;
    adc_acquisition_time_select_t acquisition_time;
    adc_conversion_clk_select_t conversion_clk;
    adc_result_format_t result_format;
    adc_voltage_ref_t voltage_ref;
#if(ADC_INTERRUPT == INTERRUPT_ENABLE)
    void(*adc_callBackFunction)(void);
#endif
} adc_cfg_t;
/*  Section : Functions declarations */
/**
 * This function is used to initialize Analog-To-Digital module
 * @param adc [adc_channel , acquisition_time ,conversion_clk ,result_format ,voltage_ref, callBackFunction]
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t adc_init(const adc_cfg_t *adc);
/**
 * This function is used to de-initialize Analog-To-Digital module
 * @param adc [adc_channel , acquisition_time ,conversion_clk ,result_format ,voltage_ref, callBackFunction]
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t adc_deInit(const adc_cfg_t *adc);
/**
 * This funstion is used to start adc conversion
 * @param adc [adc_channel , acquisition_time ,conversion_clk ,result_format ,voltage_ref, callBackFunction]
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t adc_startConversion(const adc_cfg_t *adc);
/**
 * This function is used to select channel in an ADC module
 * @param adc
 * @param channel
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t adc_channelSelect(const adc_cfg_t *adc, adc_channel_select_t channel);
/**
 * This function is used to get status of adc conversion operation
 * @param adc
 * @param status
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t adc_isConversionDone(const adc_cfg_t *adc, uint8 *status);
/**
 * This function is used to get result of adc conversion operation
 * @param adc
 * @param result
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t adc_getConversionResult(const adc_cfg_t *adc, uint16 *result);
/**
 * This function is used to enable ADC interrupt
 * @return OK if function success fine , N_OK if function fails
 */
Err_check_t adc_interruptEnable();
/**
 * This function is used to disable ADC interrupt
 * @return OK if function success fine , N_OK if function fails
 */       
Err_check_t adc_interruptDisable();
#endif	/* ADC_H */

