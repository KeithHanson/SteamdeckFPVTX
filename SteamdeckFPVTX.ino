/*
  RadioLib SX126x FSK Modem Example

  This example shows how to use FSK modem in SX126x chips.

  NOTE: The sketch below is just a guide on how to use
        FSK modem, so this code should not be run directly!
        Instead, modify the other examples to use FSK
        modem and use the appropriate configuration
        methods.

  For default module settings, see the wiki page
  https://github.com/jgromes/RadioLib/wiki/Default-configuration#sx126x---fsk-modem

  For full API reference, see the GitHub Pages
  https://jgromes.github.io/RadioLib/
*/

#define RADIOLIB_VERBOSE
// include the library
#include <RadioLib.h>

// or detect the pinout automatically using RadioBoards
// https://github.com/radiolib-org/RadioBoards

SX1262 radio = new Module(8, 13, 12, 14);

void setup() {
  Serial.begin(115200);
  radio.beginFSK(300, 10, 467.0, 8, 0, false);
}

int cnt = 0;

const int buflen = 0;

char* outbuf = new char[buflen+1];

void loop() {
  sprintf(outbuf, "Msgno=%d", cnt++);
  Serial.print("Msg");
  Serial.println(cnt);
  int state = radio.transmit(outbuf);
  if (state != 0) {
    Serial.print(F("Unable to transmit data, code "));
    Serial.println(state);
    return;
  }
  delay(10);
}
