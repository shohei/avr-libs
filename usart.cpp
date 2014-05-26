#include <avr/io.h>
#include "usart.h"

int Usart::getUBRR(int baud){
  unsigned long fosc = 16000000;
  return (fosc/(16*(unsigned long)baud)-1);
}

int Usart::getUBRR(int baud, unsigned long fosc){
  return (fosc/(16*(unsigned long)baud)-1);
}

void Usart::USART_init(unsigned int ubrr){
  UBRR0H = (ubrr>>8);
  UBRR0L = ubrr;
  UCSR0B = _BV(RXEN0)|_BV(TXEN0)|_BV(RXCIE0); 
  UCSR0C = (3<<UCSZ00);
}

void Usart::USART_Transmit(unsigned char data){
  loop_until_bit_is_set(UCSR0A,UDRE0);
  UDR0 = data;
}

char Usart::USART_recv(void)
{
  while(!(UCSR0A & (1<<RXC0)));
  return UDR0;
}

void Usart::putString(char msg[])
{
  int i;
  for(i=0;msg[i];i++){
    USART_Transmit(msg[i]);
  }
}

