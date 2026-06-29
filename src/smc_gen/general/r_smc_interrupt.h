/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_smc_interrupt.h
* Version          : 1.2.52
* Device(s)        : R5F52618BxFL
* Description      : This file implements interrupt setting.
***********************************************************************************************************************/

#ifndef SMC_INTERRUPT_H
#define SMC_INTERRUPT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/* Priority level of interrupt source. 
 * These macro definitions are used to set the IPR register directly
 */
#define _00_ICU_PRIORITY_LEVEL0                    (0x00U) /* Level 0 (disabled)  */
#define _01_ICU_PRIORITY_LEVEL1                    (0x01U) /* Level 1  */
#define _02_ICU_PRIORITY_LEVEL2                    (0x02U) /* Level 2  */
#define _03_ICU_PRIORITY_LEVEL3                    (0x03U) /* Level 3  */
#define _04_ICU_PRIORITY_LEVEL4                    (0x04U) /* Level 4  */
#define _05_ICU_PRIORITY_LEVEL5                    (0x05U) /* Level 5  */
#define _06_ICU_PRIORITY_LEVEL6                    (0x06U) /* Level 6  */
#define _07_ICU_PRIORITY_LEVEL7                    (0x07U) /* Level 7  */
#define _08_ICU_PRIORITY_LEVEL8                    (0x08U) /* Level 8  */
#define _09_ICU_PRIORITY_LEVEL9                    (0x09U) /* Level 9  */
#define _0A_ICU_PRIORITY_LEVEL10                   (0x0AU) /* Level 10  */
#define _0B_ICU_PRIORITY_LEVEL11                   (0x0BU) /* Level 11  */
#define _0C_ICU_PRIORITY_LEVEL12                   (0x0CU) /* Level 12  */
#define _0D_ICU_PRIORITY_LEVEL13                   (0x0DU) /* Level 13  */
#define _0E_ICU_PRIORITY_LEVEL14                   (0x0EU) /* Level 14  */
#define _0F_ICU_PRIORITY_LEVEL15                   (0x0FU) /* Level 15  */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define FAST_INTERRUPT_VECTOR                      (0)

/* The macro definitions below list the full set of priority levels as selected in the Interrupts tab
 * Please do not modify this file manually
 */
#define ICU_BSC_BUSERR_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RAM_RAMERR_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_FCU_FRDYI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_SWINT_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMT0_CMI0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMT1_CMI1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMT2_CMI2_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMT3_CMI3_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CAC_FERRF_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CAC_MENDF_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CAC_OVFF_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_D0FIFO0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_D1FIFO0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_USBI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_POEG_POEGGAI_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_POEG_POEGGBI_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_POEG_POEGGCI_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_POEG_POEGGDI_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSPI0_SPEI0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSPI0_SPRI0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSPI0_SPTI0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSPI0_SPII0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DOC_DOPCF_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPB_CMPB0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPB_CMPB1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CTSU_CTSUWR_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CTSU_CTSURD_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CTSU_CTSUFN_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RTC_CUP_PRIORITY                       (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ0_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ1_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ2_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ3_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ4_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ5_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ6_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ7_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ELC_ELSR8I_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SYSTEM_SNZI_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_LVD_LVD1_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_LVD_LVD2_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_USBR0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RTC_ALM_PRIORITY                       (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RTC_PRD_PRIORITY                       (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_REMC0_REMCI0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD_S12ADI0_PRIORITY                 (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD_GBADI_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ELC_ELSR18I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ELC_ELSR19I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCIA0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCIB0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCIC0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCID0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCIE0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCIF0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCIV0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW0_GTCIU0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCIA1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCIB1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCIC1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCID1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCIE1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCIF1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCIV1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW1_GTCIU1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIA2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIB2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIC2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCID2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIE2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIF2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIV2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIU2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIA3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIB3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIC3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCID3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIE3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIF3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIV3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIU3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCIA4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCIB4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCIC4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCID4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCIE4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCIF4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCIV4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW4_GTCIU4_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCIA5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCIB5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCIC5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCID5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCIE5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCIF5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCIV5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW5_GTCIU5_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCIA6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCIB6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCIC6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCID6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCIE6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCIF6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCIV6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW6_GTCIU6_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCIA7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCIB7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCIC7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCID7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCIE7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCIF7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCIV7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW7_GTCIU7_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR0_CMIA0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR0_CMIB0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR0_OVI0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR1_CMIA1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR1_CMIB1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR1_OVI1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR2_CMIA2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR2_CMIB2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR2_OVI2_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR3_CMIA3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR3_CMIB3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR3_OVI3_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CANFD_RFRI_PRIORITY                    (_0C_ICU_PRIORITY_LEVEL12)
#define ICU_CANFD_GLEI_PRIORITY                    (_0C_ICU_PRIORITY_LEVEL12)
#define ICU_CANFD_RMRI_PRIORITY                    (_0C_ICU_PRIORITY_LEVEL12)
#define ICU_CANFD_RFDREQ0_PRIORITY                 (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CANFD_RFDREQ1_PRIORITY                 (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CANFD_EC1EI_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CANFD_EC2EI_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CANFD_ECOVI_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CANFD0_CHTI_PRIORITY                   (_0C_ICU_PRIORITY_LEVEL12)
#define ICU_CANFD0_CHEI_PRIORITY                   (_0C_ICU_PRIORITY_LEVEL12)
#define ICU_CANFD0_CFRI_PRIORITY                   (_0C_ICU_PRIORITY_LEVEL12)
#define ICU_CANFD0_CFDREQ0_PRIORITY                (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC0I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC1I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC2I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC3I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_PROC_BUSY_PRIORITY                (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_ROMOK_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_LONG_PLG_PRIORITY                 (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_TEST_BUSY_PRIORITY                (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_WRRDY0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_WRRDY2_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_RDRDY0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_INTEGRATE_RDRDY_PRIORITY          (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_INTEGRATE_WRRDY_PRIORITY          (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSIP_ECCERR_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI9_BFD_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI9_AED_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI0_ERI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI0_RXI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI0_TXI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI0_TEI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI1_ERI1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI1_RXI1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI1_TXI1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI1_TEI1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI5_ERI5_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI5_RXI5_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI5_TXI5_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI5_TEI5_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI6_ERI6_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI6_RXI6_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI6_TXI6_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI6_TEI6_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI8_ERI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI8_RXI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI8_TXI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI8_TEI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI9_ERI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI9_RXI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI9_TXI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSCI9_TEI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_ERI12_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_RXI12_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_TXI12_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_TEI12_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_SCIX0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_SCIX1_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_SCIX2_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_SCIX3_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RIIC0_EEI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RIIC0_RXI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RIIC0_TXI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RIIC0_TEI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_LPT_LPTCMI1_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Interrupt_Create(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
