/*##############################################################################*/
/* lookup table is used to decide if pos needs to be incremented or decremented */
/* based on current quadrature encoder binary state.                            */
/*##############################################################################*/
#ifndef readEncoder_h
#define readEncoder_h
#include "Arduino.h"

volatile int posi = 0;
void readEncoder()
{
  static int8_t lookup_table[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  static uint8_t enc_val = 0;

  enc_val = enc_val << 2;
  enc_val = enc_val | ((PIND & 0b1100) >> 2);

  posi = posi + lookup_table[enc_val & 0b1111];
}
#endif
