#ifndef GPIO_PIN_DEFINITIONS_H
#define GPIO_PIN_DEFINITIONS_H
#include <muondetector_shared_global.h>

// define the pins which are used to interface the raspberry pi
// UBIAS_EN is the power on/off pin for bias voltage
// PREAMP_1/2 enables the DC voltage to power the preamp through the signal cable
// EVT_AND, EVT_XOR are the event inputs from AND and XOR gates
// Note: The pin definitions are enum constants and have nothing to do with the actual pin numbers
// of the RPi GPIO header. To be independent of the specific hardware implementation,
// the pin numbers for these signals are defined in pin_mapping.h on the daemon side

enum GPIO_PIN {	UBIAS_EN, 
					PREAMP_1, PREAMP_2, 
					EVT_AND, EVT_XOR, 
					GAIN_HL, ADC_READY, 
					TIMEPULSE, 
					TIME_MEAS_OUT, 
					STATUS1, STATUS2, STATUS3, 
					PREAMP_FAULT
				};


#endif // GPIO_PIN_DEFINITIONS_H