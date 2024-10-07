#include "ownArduino.h"
#include <util/delay.h>

int main() {
  ownPinMode(5, 1); //internal led als output
  ownPinMode(1, 2); //pin 9 op uno als input
  while(1){
      /*ownDigitalWrite(5, 1);
      _delay_ms(500);
      ownDigitalWrite(5, 0);
      _delay_ms(500);*/
    if (ownDigitalRead(1)==1)
    {
      ownDigitalWrite(5,1);
    } else{
      ownDigitalWrite(5,0);
    }
    
  }
  return 0;
}
