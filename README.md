# Establishing Communication Between MATLAB and Arduino Uno via Serial Port.
## OBJECTIVE.
    The purpose of the tutorial is to write and read data to and from an Arduino board.
## ARDUINO CODE 
 This program listens for incoming data on the serial port, assuming that data is formatted as comma-separated values with a minimum length of 16 characters. It reads up to four integer values and prints them, each line of output representing a set of four values. This code is a basic example of how to receive and process data sent from another device over a serial connection.

```
const int MaxStr = 4; //  maximum number of values to be received.
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
```
##MATLAB CODE
   The provided MATLAB code establishes serial communication with an Arduino using the serialport function and sends an array of ASCII numbers to the Arduino. 
```
% Open the serial port to the microcontroller
for x=1:2
arduinoSerial = serialport('COM6',9600);  

% Array of ASCII numbers to send
dataToSend = [53, 53, 48, 48]; 

% Send each number with an "Enter" key activated
for i = 1:length(dataToSend)
    write(arduinoSerial, dataToSend(i),'uint8');
    write(arduinoSerial, 13,'uint8');
    write(arduinoSerial, 10,'uint8');
end
  
pause(1);  % Adjust the pause duration as needed

for i=1:10
   readline(arduinoSerial)
end

% Close the serial port
clear arduinoSerial;
end
```
