#ifndef H_CAN
#define H_CAN

#include "r_canfd.h"
#include "r_can_api.h"
#include "r_canfd_rx_if.h"
#include "r_canfd_rx_pinset.h"

fsp_err_t init_can(void);
fsp_err_t function_CAN (void);

#endif
