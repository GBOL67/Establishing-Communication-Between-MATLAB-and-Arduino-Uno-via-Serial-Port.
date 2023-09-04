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
  for i=1:10
   readline(arduinoSerial)
end
pause(1);  % Adjust the pause duration as needed

% Close the serial port
clear arduinoSerial;
end
