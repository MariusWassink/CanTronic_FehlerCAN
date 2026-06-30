#include "r_smc_entry.h"
#include "can.h"
#include "main.h"
#include "portdefine.h"
#include "mydefines.h"

int main(void)
{
  init_can();
  
  while (1)
  {
    //volatile uint32_t afl8_idr = *(volatile uint32_t *)0x000A81A0;
    //volatile uint32_t afcr = *(volatile uint32_t *)0x000A8028;
    
//    if((CANFD.AFCR.BIT.PAGE) == 0)
//    {
//      //if(afl8_idr == 0x00000020)
//      if(CANFD.AFL[8].IDR.BIT.ID == 0x00000020)
//      {
//        AUSGANG_1 = 1;
//      }
//      else
//      {
//        AUSGANG_1 = 0;
//      }
//    }
//    function_CAN();
  }
}
