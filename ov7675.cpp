// 
// 
// 

#include "ov7675.h"

//#define PWM_PIN XCLK
#define PWM_FREQUENCY 3000000
#define PWM_OFF 0

void connect_xvclk( void)
{
	analogWriteFrequency(XCLK_PIN, PWM_FREQUENCY);
}

void disconnect_xvclk(void)
{
	analogWriteFrequency(XCLK_PIN, PWM_OFF);
}

void init_ov7670()
{

  pinMode(HREF_PIN, INPUT);
  pinMode(VSYNC_PIN, INPUT);
  pinMode(XCLK_PIN, OUTPUT);
  pinMode(PCLK_PIN,INPUT);
  pinMode(D0_PIN, INPUT);
  pinMode(D1_PIN, INPUT);
  pinMode(D2_PIN, INPUT);
  pinMode(D3_PIN, INPUT);
  pinMode(D4_PIN, INPUT);
  pinMode(D5_PIN, INPUT);
  pinMode(D6_PIN, INPUT);
  pinMode(D7_PIN, INPUT);
  
  connect_xvclk();
  delay(100); // wait for CLK to start
}



