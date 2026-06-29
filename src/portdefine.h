// PORT-Definitionen
#ifndef PORTDEFINE_H
#define PORTDEFINE_H
#include "r_smc_entry.h"

// - - - - - - - - - - - - - - - - - Input - - - - - - - - - - - - - - - - - - -

#define EINGANG_1                       PORTC.PIDR.BIT.B4       // X201.6 - Eingang Plus/Minus - tastend
#define CAN_RX                          PORT1.PIDR.BIT.B5       // Flankenerkennung - Sleep Modus ab HW_V02
#define CAN_EINGANG                     PORT3.PIDR.BIT.B1       // Flankenerkennung - Sleep Modus HW_V01

// - - - - - - - - - - - - - - - - - Output - - - - - - - - - - - - - - - - - - 
#define ENABLE_CAN_TRANSCEIVER_FZG     	PORTE.PODR.BIT.B2       // CAN-Transceiver FZG
#define CAN_TRANSCEIVER_TERMINIERUNG    PORTC.PODR.BIT.B5       // CAN-Transceiver FZG Terminierung

#define AUSGANG_1                       PORTB.PODR.BIT.B1       // X202.1 (Ausgang max.1A)
#define AUSGANG_2                       PORTB.PODR.BIT.B5       // X202.2 (Ausgang max.1A)
#define AUSGANG_3                       PORTE.PODR.BIT.B4       // X202.3 (Ausgang max.1A)
#define AUSGANG_4                       PORTA.PODR.BIT.B3       // X202.4 (Ausgang max.1A)
#define AUSGANG_5                       PORTA.PODR.BIT.B6       // X202.5 (Ausgang max.1A)
#define AUSGANG_6                       PORT4.PODR.BIT.B2       // X202.6 (Ausgang max.1A)
#define AUSGANG_7                       PORT4.PODR.BIT.B0       // X202.7 (Ausgang max.1A)
#define AUSGANG_8                       PORTB.PODR.BIT.B0       // X202.8 (Ausgang max.1A)
#define AUSGANG_9                       PORTB.PODR.BIT.B3       // X202.9 (Ausgang max.1A)
#define AUSGANG_10                      PORTE.PODR.BIT.B3       // X202.10 (Ausgang max.1A)
#define AUSGANG_11                      PORTA.PODR.BIT.B1       // X202.11 (Ausgang max.1A)
#define AUSGANG_12                      PORTA.PODR.BIT.B4       // X202.12 (Ausgang max.1A)
#define AUSGANG_13                      PORTE.PODR.BIT.B1       // X202.13 (Ausgang max.1A)
#define AUSGANG_14                      PORT4.PODR.BIT.B1       // X202.14 (Ausgang max.1A)

#define CAN_TRANSCEIVER_PWR             PORTE.PODR.BIT.B2       // Power Can-Transceiver

#define EINGANG_PLUS_MINUS_TASTEND      PORT3.PODR.BIT.B1       //Eingang Plustastend einstellen 

#define POK_LED                         PORT1.PODR.BIT.B7       // Power Okay LED       

#endif
