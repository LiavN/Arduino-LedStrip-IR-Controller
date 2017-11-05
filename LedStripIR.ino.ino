#include <IRremote.h>

int RECV_PIN = 6;
int LED_PIN = 3;
int level = 1;
IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_PIN, LOW);// turn off the light when start
}

void loop() {
  if (irrecv.decode(&results)) {
    
      Serial.print("Code In Numbers:  ");
      Serial.println(results.value);
       
      if(results.value==16599733){
            switch (level){
              case 0:
                analogWrite(LED_PIN,255);
                level++;
              break;
              case 1:
                analogWrite(LED_PIN,0);
                level = 0;
              break;
            }
            Serial.println(level);
            delay(100);
      }
    irrecv.resume();
  }
}
