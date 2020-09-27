/*
 * AT+NAMEhjhc06
 * AT+PIN5871
 * AT+BAUD4 -> 9600
 * Install Bluetootl Terminal from Googl Play on Android
 */


#include <SoftwareSerial.h>

#define pinRxD 2
#define pinTxD 3
#define pinLED 12

enum Components {
  LED = 1,
  ServoMotor = 2
};

SoftwareSerial BTSerial(pinTxD, pinRxD);
String m_messages = "";

void setup() {
  
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void handler_led(String str_operation) {
  
  if (str_operation.equals("on")) {
    digitalWrite(pinLED, HIGH);
    Serial.println("turnning on the led was executed.");
  } else {
    digitalWrite(pinLED, LOW);
    Serial.println("turnning off the led was executed.");
  }
}

void processMessage(String messages) {

  Components comp;
  String recv_type = "";
  String recv_message = "";
  
  recv_type = getValue(messages, ':', 0);
  recv_type.toUpperCase();
  Serial.println("Target type is " + recv_type);

  recv_message = getValue(messages, ':', 1);
  Serial.println("Message is \"" + recv_message + "\"");

  if (recv_type.equals("LED")) {
    comp = LED;
  }

  switch (comp) {
    case LED:
      handler_led(recv_message);
      break;
    default:
      break;  
  }
}

void loop() {

  while(BTSerial.available()) {
    delay(2); // delay to allow byte to arrive in input buffer
    char c = BTSerial.read();
    m_messages += c;
  }

  if (m_messages.length() > 0) {
    Serial.println("You have a new message with \"" + m_messages + "\"");
    m_messages.trim();
    processMessage(m_messages);
    
    m_messages = "";
    Serial.println("received message was set to empty.");
    Serial.println("");
  }
}
