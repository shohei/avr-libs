#ifndef _PWM_H
#define _PWM_H

class Pwm{
public:
  static void PWM16_init();
  static void PWM16_write(int percentage);
};

#endif
