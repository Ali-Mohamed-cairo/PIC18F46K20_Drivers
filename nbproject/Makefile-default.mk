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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=main.c HAL/LED/LED_Prog.c HAL/Push_Button/Push_Button_Prog.c MCAL/DIO/DIO_Prog.c MCAL/EXT_Interrupt/EXT_Interrupt_Prog.c Device_Config.c HAL/KeyPad/KeyPad_Prog.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.p1 ${OBJECTDIR}/HAL/LED/LED_Prog.p1 ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1 ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1 ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1 ${OBJECTDIR}/Device_Config.p1 ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/main.p1.d ${OBJECTDIR}/HAL/LED/LED_Prog.p1.d ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1.d ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1.d ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1.d ${OBJECTDIR}/Device_Config.p1.d ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.p1 ${OBJECTDIR}/HAL/LED/LED_Prog.p1 ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1 ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1 ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1 ${OBJECTDIR}/Device_Config.p1 ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1

# Source Files
SOURCEFILES=main.c HAL/LED/LED_Prog.c HAL/Push_Button/Push_Button_Prog.c MCAL/DIO/DIO_Prog.c MCAL/EXT_Interrupt/EXT_Interrupt_Prog.c Device_Config.c HAL/KeyPad/KeyPad_Prog.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/LED/LED_Prog.p1: HAL/LED/LED_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/LED" 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_Prog.p1.d 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/LED/LED_Prog.p1 HAL/LED/LED_Prog.c 
	@-${MV} ${OBJECTDIR}/HAL/LED/LED_Prog.d ${OBJECTDIR}/HAL/LED/LED_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/LED/LED_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1: HAL/Push_Button/Push_Button_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/Push_Button" 
	@${RM} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1.d 
	@${RM} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1 HAL/Push_Button/Push_Button_Prog.c 
	@-${MV} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.d ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1: MCAL/DIO/DIO_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/DIO" 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1 MCAL/DIO/DIO_Prog.c 
	@-${MV} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.d ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1: MCAL/EXT_Interrupt/EXT_Interrupt_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EXT_Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1 MCAL/EXT_Interrupt/EXT_Interrupt_Prog.c 
	@-${MV} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.d ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Device_Config.p1: Device_Config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Device_Config.p1.d 
	@${RM} ${OBJECTDIR}/Device_Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Device_Config.p1 Device_Config.c 
	@-${MV} ${OBJECTDIR}/Device_Config.d ${OBJECTDIR}/Device_Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Device_Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1: HAL/KeyPad/KeyPad_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/KeyPad" 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1.d 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1 HAL/KeyPad/KeyPad_Prog.c 
	@-${MV} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.d ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/LED/LED_Prog.p1: HAL/LED/LED_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/LED" 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_Prog.p1.d 
	@${RM} ${OBJECTDIR}/HAL/LED/LED_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/LED/LED_Prog.p1 HAL/LED/LED_Prog.c 
	@-${MV} ${OBJECTDIR}/HAL/LED/LED_Prog.d ${OBJECTDIR}/HAL/LED/LED_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/LED/LED_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1: HAL/Push_Button/Push_Button_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/Push_Button" 
	@${RM} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1.d 
	@${RM} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1 HAL/Push_Button/Push_Button_Prog.c 
	@-${MV} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.d ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/Push_Button/Push_Button_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1: MCAL/DIO/DIO_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/DIO" 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1 MCAL/DIO/DIO_Prog.c 
	@-${MV} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.d ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/DIO/DIO_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1: MCAL/EXT_Interrupt/EXT_Interrupt_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EXT_Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1 MCAL/EXT_Interrupt/EXT_Interrupt_Prog.c 
	@-${MV} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.d ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EXT_Interrupt/EXT_Interrupt_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Device_Config.p1: Device_Config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Device_Config.p1.d 
	@${RM} ${OBJECTDIR}/Device_Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Device_Config.p1 Device_Config.c 
	@-${MV} ${OBJECTDIR}/Device_Config.d ${OBJECTDIR}/Device_Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Device_Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1: HAL/KeyPad/KeyPad_Prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/HAL/KeyPad" 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1.d 
	@${RM} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1 HAL/KeyPad/KeyPad_Prog.c 
	@-${MV} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.d ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HAL/KeyPad/KeyPad_Prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PICDrivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
