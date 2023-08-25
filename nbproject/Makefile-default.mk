#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pic_drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pic_drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/BUTTON/button.c ECU_Layer/KEYPAD/keypad.c ECU_Layer/LCD/lcd.c ECU_Layer/LED/led.c ECU_Layer/SEVEN_SEG/seven_seg.c MCAL_Layer/ADC/adc.c MCAL_Layer/Device_Config/device_config.c MCAL_Layer/EEPROM/eeprom.c MCAL_Layer/External_Interrupt/external_interrupt.c MCAL_Layer/GPIO/gpio.c MCAL_Layer/Interrupt_Manager/interrupt_cfg.c MCAL_Layer/TIMER0/timer0.c MCAL_Layer/TIMER1/timer1.c application.c MCAL_Layer/CCP1/ccp1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/BUTTON/button.p1 ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1 ${OBJECTDIR}/ECU_Layer/LED/led.p1 ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1 ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1 ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1 ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1 ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/BUTTON/button.p1.d ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1.d ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1.d ${OBJECTDIR}/ECU_Layer/LED/led.p1.d ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1.d ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1.d ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1.d ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1.d ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1.d ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/BUTTON/button.p1 ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1 ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1 ${OBJECTDIR}/ECU_Layer/LED/led.p1 ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1 ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1 ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1 ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1 ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1

# Source Files
SOURCEFILES=ECU_Layer/BUTTON/button.c ECU_Layer/KEYPAD/keypad.c ECU_Layer/LCD/lcd.c ECU_Layer/LED/led.c ECU_Layer/SEVEN_SEG/seven_seg.c MCAL_Layer/ADC/adc.c MCAL_Layer/Device_Config/device_config.c MCAL_Layer/EEPROM/eeprom.c MCAL_Layer/External_Interrupt/external_interrupt.c MCAL_Layer/GPIO/gpio.c MCAL_Layer/Interrupt_Manager/interrupt_cfg.c MCAL_Layer/TIMER0/timer0.c MCAL_Layer/TIMER1/timer1.c application.c MCAL_Layer/CCP1/ccp1.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/pic_drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/BUTTON/button.p1: ECU_Layer/BUTTON/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1 ECU_Layer/BUTTON/button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/BUTTON/button.d ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1: ECU_Layer/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1 ECU_Layer/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.d ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LCD/lcd.p1: ECU_Layer/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1 ECU_Layer/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LCD/lcd.d ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/led.p1: ECU_Layer/LED/led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/led.p1 ECU_Layer/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/led.d ${OBJECTDIR}/ECU_Layer/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1: ECU_Layer/SEVEN_SEG/seven_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/SEVEN_SEG" 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1 ECU_Layer/SEVEN_SEG/seven_seg.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.d ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/adc.p1: MCAL_Layer/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 MCAL_Layer/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/adc.d ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1: MCAL_Layer/Device_Config/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Device_Config" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1 MCAL_Layer/Device_Config/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.d ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1: MCAL_Layer/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1 MCAL_Layer/EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1: MCAL_Layer/External_Interrupt/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/External_Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1 MCAL_Layer/External_Interrupt/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.d ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1: MCAL_Layer/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1 MCAL_Layer/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1: MCAL_Layer/Interrupt_Manager/interrupt_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt_Manager" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1 MCAL_Layer/Interrupt_Manager/interrupt_cfg.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.d ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1: MCAL_Layer/TIMER0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1 MCAL_Layer/TIMER0/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.d ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1: MCAL_Layer/TIMER1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1 MCAL_Layer/TIMER1/timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.d ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1: MCAL_Layer/CCP1/ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1 MCAL_Layer/CCP1/ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.d ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/BUTTON/button.p1: ECU_Layer/BUTTON/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1 ECU_Layer/BUTTON/button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/BUTTON/button.d ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/BUTTON/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1: ECU_Layer/KEYPAD/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1 ECU_Layer/KEYPAD/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.d ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/KEYPAD/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LCD/lcd.p1: ECU_Layer/LCD/lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1 ECU_Layer/LCD/lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LCD/lcd.d ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LCD/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/led.p1: ECU_Layer/LED/led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/led.p1 ECU_Layer/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/led.d ${OBJECTDIR}/ECU_Layer/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1: ECU_Layer/SEVEN_SEG/seven_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/SEVEN_SEG" 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1 ECU_Layer/SEVEN_SEG/seven_seg.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.d ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/SEVEN_SEG/seven_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/adc.p1: MCAL_Layer/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1 MCAL_Layer/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/adc.d ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1: MCAL_Layer/Device_Config/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Device_Config" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1 MCAL_Layer/Device_Config/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.d ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Device_Config/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1: MCAL_Layer/EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1 MCAL_Layer/EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1: MCAL_Layer/External_Interrupt/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/External_Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1 MCAL_Layer/External_Interrupt/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.d ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/External_Interrupt/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1: MCAL_Layer/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1 MCAL_Layer/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1: MCAL_Layer/Interrupt_Manager/interrupt_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt_Manager" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1 MCAL_Layer/Interrupt_Manager/interrupt_cfg.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.d ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt_Manager/interrupt_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1: MCAL_Layer/TIMER0/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1 MCAL_Layer/TIMER0/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.d ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/TIMER0/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1: MCAL_Layer/TIMER1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1 MCAL_Layer/TIMER1/timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.d ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/TIMER1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1: MCAL_Layer/CCP1/ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1 MCAL_Layer/CCP1/ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.d ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP1/ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/pic_drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/pic_drivers.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/pic_drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/pic_drivers.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/pic_drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/pic_drivers.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/pic_drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif