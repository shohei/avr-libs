#ifndef _ADC_H_
#define _ADC_H

class Adc {
public:
  void adc_init();
  int adc_conv(int pin);
};

#endif
