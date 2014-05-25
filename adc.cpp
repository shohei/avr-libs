#include "adc.h"
#include <avr/io.h>

#define sbi(BYTE,BIT) BYTE|=_BV(BIT) 
#define cbi(BYTE,BIT) BYTE&=~_BV(BIT) 

void Adc::adc_init(){
  ADMUX |= _BV(REFS0);//AVCC as Vref
  ADCSRA |= _BV(ADEN)|_BV(ADSC);//ADC enable, Start conversation;
}

int Adc::adc_conv(int pin){
  int res;  
  ADMUX = _BV(REFS0)|pin;
  cbi(ADCSRA,ADIF);
  sbi(ADCSRA,ADSC);
  loop_until_bit_is_set(ADCSRA,ADIF);
  res = ADCL; 
  res += (ADCH<<8); 
  return res;
}

