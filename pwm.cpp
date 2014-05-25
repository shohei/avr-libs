#include <avr/io.h>
#include "pwm.h"

void Pwm::PWM16_init(){
  DDRB |= _BV(PORTB1);//For PWM output
  TCCR1A = _BV(COM1A1)|_BV(WGM11); //Compare match A enable,Fast PWM (ICR1 as TOP)
  TCCR1B = _BV(WGM13)|_BV(WGM12)|_BV(CS10); //Fast PWM (ICR1 as TOP),Clock Source enable
  ICR1 = 65000;
}

void Pwm::PWM16_write(int percentage){
  int value = 65000 * percentage/(float)100;
  OCR1A = value;
}
