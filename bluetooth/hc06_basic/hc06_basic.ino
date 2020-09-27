#include <SoftwareSerial.h>

#define RxD = 2;
#define TxD = 3;

SoftwareSerial BTSerial(3, 2);
String recv_message = "";

void setup() {
  
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {

  while(BTSerial.available()) {
    char recv_char = (char)BTSerial.read();
    recv_message += recv_char;
    delay(5); // to prevent disconnection
  }

  if (!recv_message.equals("")) {
      Serial.println("input value: " + recv_message);
      recv_message = "";
  }
}
