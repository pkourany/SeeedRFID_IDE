RFID Library
============

125Khz RFID library for Arduino. 

This library only support TTL RS232 serial port.

![125Khz RFID Reader][RFID Image]


Particle Devices
----------
Adapted for Spark Core by Paul Kourany, Jan 2015
Updated for Libraries 2.0, Feb 2017

### Usage
Connecting RFID Reader RX, TX to Particle device Core pins.

`Seed    Spark (Serial1 or 2)`
`RX <--> TX`
`TX <--> RX`

Arduino
-------

When read the data from some RFID card, you will get data like `00 91 6f 0b f5`.

Example:
```
your card number: 0009531147
that your data  : 00 91 6f 0b f5
```
**Notice, f5 is the check bit**

`f5 = 00^91^6f^0b`


#### Pins 

1. VCC support 3.3 ~ 5V
2. TX, RX connect to Arduino or Seeeduino
3. T1, T2 is the Signal port for RFID antenna
4. W0, W1 is for wiegand protocol, but this library not support yet.

```
     		+-----------+
++++++++----|VCC	  T1|----
|  +++++----|GND	  T2|----
|  | |++----|TX		 SER|----
|  | |	----|RX		 LED|----	
|  | |	----|W0		BEEP|----
|  | |	----|W1		 GND|----
|  | |		+-----------+
|  | \_________________________________________
|  | 										  |
|  |                             			  |
|  |                           + + + + + + + + + + + + 
|  |                           | | | | | | | | | | | | 
|  |          				  /|-|-|-|-|-|-|-|-|-|-|-|-|
|  |                         | A A A A A A D W R T G V |
|  |                         | 0 1 2 3 4 5 A K X X N I |      
|  |               PARTICLE  |             C P     D N |
|  |                PHOTON   |                		   |
|  |                         |                	 V	   |
|  |                         |                 G B R 3 |
|  |                         | D D D D D D D D N A S V |
|  |       					 | 0 1 2 3 4 5 6 7 D T T 3 |
|  |          				  \|-|-|-|-|-|-|-|-|-|-|-|-|
|  |                           | | | | | | | | | | | | 
|  |                           + + + + + + + + + + + + 
|  |___________________________________________|     |
|____________________________________________________|
	
```

### Usage
Connecting RFID Reader RX, TX to Arduino pin headers.

`RX <--> 10`
`TX <--> 11`

```c
// RFID_UART.ino

#include <SoftwareSerial.h>
#include <SeeedRFID.h>

#define RFID_RX_PIN 10
#define RFID_TX_PIN 11

#define TEST

SeeedRFID RFID(RFID_RX_PIN, RFID_TX_PIN);
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

```


----

This library is written by [Ye Xiaobo][Github Homepage] for seeed studio<br>
and is licensed under [The MIT License](https://github.com/yexiaobo-seeedstudio/RFID_Library/blob/master/LICENSE). <br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>


[RFID Image]: http://www.seeedstudio.com/wiki/images/6/6a/RFID.jpg
[Github Homepage]: https://github.com/yexiaobo-seeedstudio



[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/RFID_Library)](https://github.com/igrigorik/ga-beacon)
