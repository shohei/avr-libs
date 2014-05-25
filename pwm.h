#ifndef _PWM_H
#define _PWM_H

class Pwm{
public:
  void PWM16_init();
  void PWM16_write(int percentage);
};

#endif
