// ov7675.h

#ifndef _OV7675_h
#define _OV7675_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ov7675_REG.h"

// All data pins on the same port for the teensy for dma
// pins 18 and 19 used by wire library

#define D0_PIN 2
#define D1_PIN 15
#define D2_PIN 7
#define D3_PIN 8
#define D4_PIN 6
#define D5_PIN 20
#define D6_PIN 21
#define D7_PIN 5
#define HREF_PIN 4 //(PTA13)
#define VSYNC_PIN 17 //(PTC2)
#define XCLK_PIN 3
#define PCLK_PIN 23 
;
void connect_xvclk (void);
void disconnect_xvclk (void);
void init_ov7675();

#endif // end include guard


