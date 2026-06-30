#include "can.h"
#include <string.h>
#include "r_smc_entry.h"
#include "main.h"
#include "portdefine.h"

/* CAN */
#include "r_canfd.h"
#include "r_can_api.h"
#include "r_canfd_rx_if.h"
#include "r_canfd_rx_pinset.h"
/* Ennde CAN */

/* Acceptance filter array parameters */
#define CAN_MAILBOX_NUMBER_0 (0U) // mail box number
#define CANFD_FILTER_ID (0x00000000)
#define MASK_ID (0x00000000)
#define MASK_ID_MODE (1)
#define ZERO (0U)            // Array Index value
#define WAIT_TIME (1000000U) // Wait time value
#define SIZE_64 (64u)
#define RESET_VALUE (0x00)

uint32_t canFdVersion = 0;

/* Flag in the interrupt function */
bool b_canfd_tx_complete;
bool b_canfd_rx_complete;
bool b_canfd_err_status;

/* Variable to store rx frame status info*/
can_info_t can0_p_info =
    {
        .error_code = RESET_VALUE,
        .error_count_receive = RESET_VALUE,
        .error_count_transmit = RESET_VALUE,
        .rx_fifo_status = RESET_VALUE,
        .rx_mb_status = 1,
        .status = RESET_VALUE,
};

/* Acceptance filter array parameters */
canfd_afl_entry_t g_canfd_afl[CANFD_CFG_AFL_CH0_RULE_NUM] =
{
  {
    .id = 0x11F,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_1,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x225,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_2,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x274,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_3,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x14F,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_4,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x15F,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_5,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x397,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_6,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x33D,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_7,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x343,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_8,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x020,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_9,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x309,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_10,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x2FB,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_11,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x351,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_12,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x39B,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_13,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x0B1,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_14,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x3A5,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_15,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x339,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_16,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x437,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_17,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x001,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_18,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x3A3,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_19,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x337,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_20,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x46B,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_21,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_22,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_23,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_24,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_25,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_26,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_27,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_28,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_29,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_30,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
  {
    .id = 0x000,
    .rs = 0,
    .frame_type = CAN_FRAME_TYPE_DATA,
    .id_mode = CAN_ID_MODE_STANDARD,
    
    .mask_id = 0x7FF,
    .rs1 = 0,
    .mask_frame_type = 1,
    .mask_id_mode = 1,
    
    .minimum_dlc = (canfd_minimum_dlc_t)ZERO,
    .rs2 = 0,
    .rx_buffer = CANFD_RX_MB_31,
    .rs3 = 0,
    .fifo_select_flags = CANFD_RX_FIFO_0,
  },
};

void canfd_callback(can_callback_args_t *p_args);


fsp_err_t init_can(void)
{
  // CAN initialisieren
  ENABLE_CAN_TRANSCEIVER_FZG = 1; // Disable CAN-Transceiver

  canFdVersion = R_CANFD_GetVersion();

  static fsp_err_t err_init_can;
  g_canfd0_extended_cfg.p_afl = g_canfd_afl;
  g_canfd0_cfg.p_callback = canfd_callback;

  R_CANFD_PinSet_CANFD0();

  err_init_can = R_CANFD_Open(&g_canfd0_ctrl, &g_canfd0_cfg);
  assert(FSP_SUCCESS == err_init_can);

  g_canfd_on_canfd.modeTransition(&g_canfd0_ctrl, CAN_OPERATION_MODE_NORMAL, CAN_TEST_MODE_DISABLED);
  

  ENABLE_CAN_TRANSCEIVER_FZG = 0; // Enable CAN-Transceiver
  
  return FSP_SUCCESS;
}

fsp_err_t function_CAN(void)
{
  fsp_err_t err;
 
  can_frame_t frame;
  static volatile uint32_t id_001_empfangen = 0;
  static volatile uint32_t id_020_empfangen = 0;
  static volatile uint32_t id_337_empfangen = 0;

  err = R_CANFD_InfoGet(&g_canfd0_ctrl, &can0_p_info);
  if (err == FSP_SUCCESS)
  {
    for (size_t i = 0; i < CANFD_CFG_AFL_CH0_RULE_NUM; i++)
    {
      if (can0_p_info.rx_mb_status & (1UL << i))
      {
        R_CANFD_Read(&g_canfd0_ctrl, i, &frame);
        if (frame.id == 0x001)
        {
          id_001_empfangen++;
        }
        if (frame.id == 0x020)
        {
          id_020_empfangen++;
        }
        if (frame.id == 0x337)
        {
          id_337_empfangen++;
        }
      }
    }
  }

  return err;
}

void canfd_callback(can_callback_args_t *p_args)
{
  if (p_args == NULL)
    return;

  switch (p_args->event)
  {
  case CAN_EVENT_RX_COMPLETE:
    // R_CAN_RxMsgReceive(&p_args->frame);
    // b_canfd_rx_complete = true; // set flag bit
    break;

  case CAN_EVENT_TX_COMPLETE:
    // Sendung erfolgreich
    b_canfd_tx_complete = true; // set flag bit
    break;

  default:
    // Fehler oder andere Ereignisse
    break;
  }
}