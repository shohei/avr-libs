#ifndef _USART_H
#define _USART_H

class Usart{
public:
  void USART_init(unsigned int ubrr);
  void USART_Transmit(unsigned char data);
  char USART_recv(void);
  void putString(char msg[]);
  int getUBRR(int baud);
  int getUBRR(int baud,unsigned long fosc);
};

#endif
