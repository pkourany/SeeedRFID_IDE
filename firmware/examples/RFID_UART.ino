// RFID_UART.ino

#if defined (PLATFORM_ID)
#include "SeeedRFID/SeeedRFID.h"
#else
#include <SoftwareSerial.h>
#include <SeeedRFID.h>
#endif

#define RFID_RX_PIN 10
#define RFID_TX_PIN 11

// #define DEBUGRFID
#define TEST

SeeedRFID RFID(RFID_RX_PIN, RFID_TX_PIN);
RFIDdata tag;

void setup() {
	Serial1.begin(9600);	//Done here to prevent SeeedRFID constructor system crash
	
	Serial.begin(57600);
	Serial.println("Hello, double bk!");
}

void loop() { 
	if(RFID.isAvailable()){
		tag = RFID.data();
		Serial.print("RFID card number: ");
		Serial.println(RFID.cardNumber());
#ifdef TEST
	Serial.print("RFID raw data: ");
	for(int i=0; i<tag.dataLen; i++){
	    Serial.print(tag.raw[i], HEX);
	    Serial.print('\t');
		}
#endif
	}
}

