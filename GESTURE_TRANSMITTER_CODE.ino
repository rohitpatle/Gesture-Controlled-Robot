
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

  RF24 radio(8,10);
  const byte address[6] = "00001";
  int x = A0;
  int y = A2;
  int arr[2];
  int xAxis;
  int yAxis;


void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void loop() 
{
  xAxis = analogRead(x);
  yAxis = analogRead(y);
  arr[0] = xAxis;
  arr[1] = yAxis;
  radio.write(&arr, sizeof(arr));

  Serial.print(xAxis);
  Serial.print("\t");
  Serial.print(yAxis);
  Serial.println("");
}
