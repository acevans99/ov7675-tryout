/*
  Name:		ov7675_teensy.ino
  Created:	6/3/2016 3:03:33 PM
  Author:	studentlab
*/

// the setup function runs once when you press reset or power the board
#include "ov7675_REG.h"
#include "ov7675.h"
#include "sccb.h"

sccb a;
void setup() {
  a.scanfordevices();
}

// the loop function runs over and over again until power down or reset
void loop() {

}
