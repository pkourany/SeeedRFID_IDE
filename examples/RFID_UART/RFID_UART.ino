// RFID_UART.ino

#if !defined (PARTICLE)
  #include <SoftwareSerial.h>
#endif
#include <SeeedRFID.h>

#define RFID_RX_PIN 10
#define RFID_TX_PIN 11

// #define DEBUG
#define TEST

SeeedRFID RFID(RFID_RX_PIN, RFID_TX_PIN);	// Serial1 used for Particle
RFIDdata tag;

void setup() {
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

