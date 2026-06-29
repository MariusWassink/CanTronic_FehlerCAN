/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name    : r_canfd_rx_pinset.c
* Version      : 1.0.2
* Device(s)    : R5F52618BxFL
* Tool-Chain   : RXC toolchain
* Description  : Setting of port and mpc registers
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_canfd_rx_pinset.h"
#include "platform.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_CANFD_PinSet_CANFD0
* Description  : This function initializes pins for r_canfd_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_CANFD_PinSet_CANFD0()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set CRX0 pin */
    PORT1.PMR.BIT.B5 = 0U;
    PORT1.PDR.BIT.B5 = 0U;
    MPC.P15PFS.BYTE = 0x10U;
    PORT1.PMR.BIT.B5 = 1U;
    PORT1.PDR.BIT.B5 = 0U;

    /* Set CTX0 pin */
    PORT1.PMR.BIT.B4 = 0U;
    PORT1.PDR.BIT.B4 = 0U;
    MPC.P14PFS.BYTE = 0x10U;
    PORT1.PMR.BIT.B4 = 1U;
    PORT1.PDR.BIT.B4 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

