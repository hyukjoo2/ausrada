
int m_delay_start = 0;
int m_delay_short = 0;
int m_delay_long = 0 ;
int m_delay_between_char = 0;
int m_delay_space = 0;
int m_delay_sentence = 0;

void setup() {

  Serial.begin(115200);

  m_delay_start = 3000;
  m_delay_short = 200;
  m_delay_long = m_delay_short * 2;
  m_delay_between_char = 500;
  m_delay_space = 1000;
  m_delay_sentence = m_delay_space;

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("");
  Serial.println("Hello");
  Serial.println("This is a demo program to learn");
  Serial.println("1. how to handle string");
  Serial.println("2. how to control LED");
  Serial.println("");
  Serial.println("===== START =====");
}

void write_to_morse_code(String message) {

  Serial.println("message = " + message);
  Serial.println("Wrote to morse code...");
  
  String c = "";
  String morse_code = "";
  
  if (message.length() > 0) {
    if (message == " ") {
      Serial.println("");
      delay(m_delay_space);
    } else {
      for (int i = 0; i < message.length(); i++) {
        c = message.substring(i, i+1);
        if (c == "A") {
          morse_code = ".-";
        } else if (c == "B") {
          morse_code = "-...";
        } else if (c == "C") {
          morse_code = "-.-.";
        } else if (c == "D") {
          morse_code = "-..";
        } else if (c == "E") {
          morse_code = ".";
        } else if (c == "F") {
          morse_code = "..-.";
        } else if (c == "G") {
          morse_code = "--.";
        } else if (c == "H") {
          morse_code = "....";
        } else if (c == "I") {
          morse_code = "..";
        } else if (c == "J") {
          morse_code = ".---";
        } else if (c == "K") {
          morse_code = "-.-";
        } else if (c == "L") {
          morse_code = ".-..";
        } else if (c == "M") {
          morse_code = "--";
        } else if (c == "N") {
          morse_code = "-.";
        } else if (c == "O") {
          morse_code = "---";
        } else if (c == "P") {
          morse_code = ".--.";
        } else if (c == "Q") {
          morse_code = "--.-";
        } else if (c == "R") {
          morse_code = ".-.";
        } else if (c == "S") {
          morse_code = "...";
        } else if (c == "T") {
          morse_code = "-";
        } else if (c == "U") {
          morse_code = "..-";
        } else if (c == "V") {
          morse_code = "...-";
        } else if (c == "W") {
          morse_code = ".--";
        } else if (c == "X") {
          morse_code = "-..-";
        } else if (c == "Y") {
          morse_code = "-.--";
        } else if (c == "Z") {
          morse_code = "--..";
        } else if (c == "1") {
          morse_code = ".----";
        } else if (c == "2") {
          morse_code = "..---";
        } else if (c == "3") {
          morse_code = "...--";
        } else if (c == "4") {
          morse_code = "....-";
        } else if (c == "5") {
          morse_code = ".....";
        } else if (c == "6") {
          morse_code = "-....";
        } else if (c == "7") {
          morse_code = "--...";
        } else if (c == "8") {
          morse_code = "---..";
        } else if (c == "9") {
          morse_code = "----.";
        } else if (c == "0") {
          morse_code = "-----";
        } else if (c == ".") {
          morse_code = ".-.-.-";
        } else if (c == ",") {
          morse_code = "--..--";
        } else if (c == "(" || c == "[" || c == "<") {
          morse_code = "-.--.";
        } else if (c == ")" || c == "]" || c == ">") {
          morse_code = "-.--.-";
        } else if (c == "?") {
          morse_code = "..--..";
        } else if (c == "/") {
          morse_code = "-..-.";
        } else if (c == " ") {
          morse_code = "SPACE";
        }

        if (morse_code == "SPACE") {
          Serial.println("{SPACE}");
          delay(m_delay_space);
        } else {
          Serial.println(c + " => " + morse_code);
          writeToLED(morse_code);
          delay(m_delay_between_char);
        }
        
      }      
    }

  }  
}


void writeToLED(String codes) {

  if (codes.length() > 0) {
    for (int i = 0; i < codes.length(); i++) {      
      if (codes.substring(i, i+1) == ".") {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(m_delay_short);
        digitalWrite(LED_BUILTIN, LOW);
        delay(m_delay_short);
      } else {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(m_delay_long);
        digitalWrite(LED_BUILTIN, LOW);
        delay(m_delay_short);
      }
    }
  }
}

void loop() {

  Serial.println("");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(m_delay_start);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  
  String message = "SOS Save Our Ship ";
  message.toUpperCase();
  
  write_to_morse_code(message);
  delay(m_delay_sentence);
}
