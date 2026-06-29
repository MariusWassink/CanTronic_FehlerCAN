#ifndef H_CAN
#define H_CAN

#include "r_canfd.h"
#include "r_can_api.h"
#include "r_canfd_rx_if.h"
#include "r_canfd_rx_pinset.h"

fsp_err_t init_can(void);
fsp_err_t function_CAN (void);

#define TASTENDRUCK_SENDE_ZEIT (15)
#define TASTENDRUCK_SENDE_WIEDERHOLUNG (5)

#define HARDWARE_VERSION (0x01) /// Wird entsprechend der Hardwarerevision (Selektierwiderstaende) angepasst
#define SOFTWARE_VERSION (0x01) /// Wird entsprechend der Hardwarerevision (Selektierwiderstaende) angepasst

#define ID_HEARTBEAT (0x701)

#define ID_TASTENDRUCK (0x300)
#define ID_TASTENDRUCK_BESTAETIGUNG (0x500)

#define ID_TASTENFARBE_1 (0x501)
#define ID_TASTENFARBE_1_ZYKLISCH (0x503)
#define ID_TASTENFARBE_1_BESTAETIGUNG (0x301)

#define ID_TASTENFARBE_2 (0x502)
#define ID_TASTENFARBE_2_ZYKLISCH (0x504)
#define ID_TASTENFARBE_2_BESTAETIGUNG (0x302)

#define ID_TASTENHINTERLEUCHTUNG (0x51F)
#define ID_TASTENHINTERLEUCHTUNG_ZYKLISCH (0x523)
#define ID_TASTENHINTERLEUCHTUNG_BESTAETIGUNG (0x31F)

#define STANDARD_AUSWERTUNG(_id, _auswertungsfunktion)                  \
    case _id:                                                           \
    {                                                                   \
        /* bestaetigung senden*/                                        \
        can_frame_t tx_frame = {                                        \
            .id = _id##_BESTAETIGUNG,                                   \
            .data_length_code = 0,                                      \
        };                                                              \
        R_CAN_TxSet(CH_FZG, 1, &tx_frame);                              \
    }                                                                   \
    /* fallthrough */                                                   \
    case _id##_ZYKLISCH:                                                \
        _auswertungsfunktion(rx_frame.data, rx_frame.data_length_code); \
        break



#endif
