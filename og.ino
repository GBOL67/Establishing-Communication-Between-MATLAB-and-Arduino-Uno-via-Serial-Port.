const int MaxStr = 4;
const int MaxStr1 = 16;
int receivedValue[MaxStr + 1]; 
const int Idx = 3;
int Value;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  Serial.flush();
  if (Serial.available() >= MaxStr1) { 
    for (int i = 0; i < MaxStr; i++) {
      receivedValue[i] = Serial.parseInt(); // Read each byte one by one
    }
  }
     Serial.flush();
     receivedValue[MaxStr] = '\0'; // Null-terminate the received data
      Serial.print(receivedValue[0]);
      Serial.print(',');
      Serial.print(receivedValue[1]);
      Serial.print(',');
      Serial.print(receivedValue[2]);
      Serial.print(',');
      Serial.println(receivedValue[3]);
}
