///Arduino Gesture Control Robot
//Reciver Circuit 
//Using a Arduino Nano|NRF24L01_RF Module|L298N Motor Driver
//This is unlikely to be of much use in a practical applications
//ID OF USER: Rakeshtsg
//INTERFACE: Arduino 
//You need to install the required libraries before uploading the code.
//To install the libraries first download the library from here https://github.com/nRF24/RF24 then go to sketch > include Library > ADD .ZIP File > Select the downloaded
// libary's Zip file and you're done now. You can upload the the sketch now.


#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

const int x_out = A0;
const int y_out = A1;
RF24 radio(8,10);
const byte address[6] = "00001";
struct data{
  int xAxis;
  int yAxis;

};
data send_data;



void setup() {
  // put your setup code here, to run once:
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MIN);
radio.setDataRate(RF24_250KBPS);
radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
send_data.xAxis = analogRead(x_out);
send_data.yAxis = analogRead(y_out);
radio.write(&send_data, sizeof(data));
}
