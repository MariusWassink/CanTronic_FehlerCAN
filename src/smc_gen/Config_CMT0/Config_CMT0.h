/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_CMT0.h
* Component Version: 2.3.0
* Device(s)        : R5F52618BxFL
* Description      : This file implements device driver for Config_CMT0.
***********************************************************************************************************************/

#ifndef CFG_Config_CMT0_H
#define CFG_Config_CMT0_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_cmt.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define CMT0_PCLK_COUNTER_DIVISION          (8)

/* Compare Match Constant Register (CMCOR) */
#define _0027_CMT0_CMCOR_VALUE              (0x0027U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_CMT0_Create(void);
void R_Config_CMT0_Create_UserInit(void);
void R_Config_CMT0_Start(void);
void R_Config_CMT0_Stop(void);
/* Start user code for function. Do not edit comment generated here */
#define TIMER_FREQUENZ_KHZ (100)

#define TIME_1MS (1)
#define TIME_10MS (10 * TIME_1MS)
#define TIME_100MS (100 * TIME_1MS)
#define TIME_1S (1000 * TIME_1MS)
#define TIME_1M (60 * TIME_1S)
#define TIME_1H (60 * TIME_1M)

typedef uint64_t time_t;

void Timer_warte_ms(const uint16_t wait);

__monitor time_t Timer_get_time(void);
/* End user code. Do not edit comment generated here */
#endif
