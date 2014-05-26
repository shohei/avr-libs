#ifndef _ADC_H_
#define _ADC_H

class Adc {
public:
  static void adc_init();
  static int adc_conv(int pin);
};

#endif
