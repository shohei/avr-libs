#ifndef _USART_H
#define _USART_H

class Usart{
public:
  static void USART_init(unsigned int ubrr);
  static void USART_Transmit(unsigned char data);
  static char USART_recv(void);
  static void putString(char msg[]);
  static int getUBRR(int baud);
  static int getUBRR(int baud,unsigned long fosc);
};

#endif
