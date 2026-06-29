/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_PORT.c
* Component Version: 2.4.1
* Device(s)        : R5F52618BxFL
* Description      : This file implements device driver for Config_PORT.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_PORT_Create(void)
{
    /* Set PORT1 registers */
    PORT1.PODR.BYTE = _00_Pm7_OUTPUT_0;
    PORT1.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT | _00_Pm5_CMOS_OUTPUT | _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORT1.PMR.BYTE = _00_Pm7_PIN_GPIO;
    PORT1.PDR.BYTE = _80_Pm7_MODE_OUTPUT | _0F_PDR1_DEFAULT;

    /* Set PORT3 registers */
    PORT3.PODR.BYTE = _00_Pm1_OUTPUT_0;
    PORT3.ODR0.BYTE = _00_Pm1_CMOS_OUTPUT;
    PORT3.ODR1.BYTE = _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORT3.PCR.BYTE = _01_Pm0_PULLUP_ON;
    PORT3.PMR.BYTE = _00_Pm0_PIN_GPIO | _00_Pm1_PIN_GPIO;
    PORT3.PDR.BYTE = _00_Pm0_MODE_INPUT | _02_Pm1_MODE_OUTPUT | _1C_PDR3_DEFAULT;

    /* Set PORT4 registers */
    PORT4.PODR.BYTE = _00_Pm0_OUTPUT_0 | _00_Pm1_OUTPUT_0 | _00_Pm2_OUTPUT_0;
    PORT4.PCR.BYTE = _00_Pm5_PULLUP_OFF | _00_Pm7_PULLUP_OFF;
    PORT4.PMR.BYTE = _00_Pm0_PIN_GPIO | _00_Pm1_PIN_GPIO | _00_Pm2_PIN_GPIO | _00_Pm5_PIN_GPIO | _00_Pm7_PIN_GPIO;
    PORT4.PDR.BYTE = _01_Pm0_MODE_OUTPUT | _02_Pm1_MODE_OUTPUT | _04_Pm2_MODE_OUTPUT | _00_Pm5_MODE_INPUT | 
                     _00_Pm7_MODE_INPUT | _18_PDR4_DEFAULT;

    /* Set PORTA registers */
    PORTA.PODR.BYTE = _00_Pm1_OUTPUT_0 | _00_Pm3_OUTPUT_0 | _00_Pm4_OUTPUT_0 | _00_Pm6_OUTPUT_0;
    PORTA.ODR0.BYTE = _00_Pm1_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORTA.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT | _00_Pm6_CMOS_OUTPUT;
    PORTA.PMR.BYTE = _00_Pm1_PIN_GPIO | _00_Pm3_PIN_GPIO | _00_Pm4_PIN_GPIO | _00_Pm6_PIN_GPIO;
    PORTA.PDR.BYTE = _02_Pm1_MODE_OUTPUT | _08_Pm3_MODE_OUTPUT | _10_Pm4_MODE_OUTPUT | _40_Pm6_MODE_OUTPUT | 
                     _A5_PDRA_DEFAULT;

    /* Set PORTB registers */
    PORT.PSRB.BYTE = _00_PORT_PSEL0_PB0 | _00_PORT_PSEL1_PB1 | _00_PORT_PSEL3_PB3 | _00_PORT_PSEL5_PB5;
    PORTB.PODR.BYTE = _00_Pm0_OUTPUT_0 | _00_Pm1_OUTPUT_0 | _00_Pm3_OUTPUT_0 | _00_Pm5_OUTPUT_0;
    PORTB.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORTB.ODR1.BYTE = _00_Pm5_CMOS_OUTPUT;
    PORTB.PMR.BYTE = _00_Pm0_PIN_GPIO | _00_Pm1_PIN_GPIO | _00_Pm3_PIN_GPIO | _00_Pm5_PIN_GPIO;
    PORTB.PDR.BYTE = _01_Pm0_MODE_OUTPUT | _02_Pm1_MODE_OUTPUT | _08_Pm3_MODE_OUTPUT | _20_Pm5_MODE_OUTPUT | 
                     _D4_PDRB_DEFAULT;

    /* Set PORTC registers */
    PORTC.PODR.BYTE = _00_Pm5_OUTPUT_0;
    PORTC.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORTC.ODR1.BYTE = _00_Pm5_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORTC.PCR.BYTE = _10_Pm4_PULLUP_ON | _40_Pm6_PULLUP_ON;
    PORTC.PMR.BYTE = _00_Pm4_PIN_GPIO | _00_Pm5_PIN_GPIO | _00_Pm6_PIN_GPIO;
    PORTC.PDR.BYTE = _00_Pm4_MODE_INPUT | _20_Pm5_MODE_OUTPUT | _00_Pm6_MODE_INPUT | _0F_PDRC_DEFAULT;

    /* Set PORTE registers */
    PORTE.PODR.BYTE = _00_Pm1_OUTPUT_0 | _00_Pm2_OUTPUT_0 | _00_Pm3_OUTPUT_0 | _00_Pm4_OUTPUT_0;
    PORTE.ODR0.BYTE = _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORTE.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT;
    PORTE.PMR.BYTE = _00_Pm1_PIN_GPIO | _00_Pm2_PIN_GPIO | _00_Pm3_PIN_GPIO | _00_Pm4_PIN_GPIO;
    PORTE.PDR.BYTE = _02_Pm1_MODE_OUTPUT | _04_Pm2_MODE_OUTPUT | _08_Pm3_MODE_OUTPUT | _10_Pm4_MODE_OUTPUT | 
                     _E1_PDRE_DEFAULT;

    /* Set PORTH registers */
    PORTH.PCR.BYTE = _00_Pm0_PULLUP_OFF | _00_Pm3_PULLUP_OFF;
    PORTH.PMR.BYTE = _00_Pm0_PIN_GPIO | _00_Pm3_PIN_GPIO;
    PORTH.PDR.BYTE = _00_Pm0_MODE_INPUT | _00_Pm3_MODE_INPUT | _F6_PDRH_DEFAULT;

    R_Config_PORT_Create_UserInit();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
