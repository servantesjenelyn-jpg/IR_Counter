const int OUT = 2;          // IR Proximity Sensor pin

int Number_of_Object = 0;   // Counter for objects
int SensorState = 0;        // Current sensor reading
int lastSensorState = HIGH; // Previous sensor reading

const int LED_10s[7] = {32, 33, 25, 26, 27, 14, 13};
const int LED_1s[7]  = {19, 18, 5, 17, 16, 4, 22};


void setup() {
  Serial.begin(115200);
  pinMode(OUT, INPUT);
  
  for(int i = 0; i < 7; i++){
    pinMode(LED_10s[i], OUTPUT);
    pinMode(LED_1s[i], OUTPUT);
  }
}
#include "Decode.h"

void loop() {
  SensorState = digitalRead(OUT);

  if (SensorState == LOW && lastSensorState == HIGH) {
    Number_of_Object++;
    
    if(Number_of_Object > 99) {
      Number_of_Object = 0;
    }
    
    Serial.print("Object detected! Total: ");
    Serial.println(Number_of_Object);
    
    delay(200); 
  }
  decode(Number_of_Object);
  display();
  
  lastSensorState = SensorState;
}