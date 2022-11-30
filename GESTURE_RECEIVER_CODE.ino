
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

  RF24 radio(9, 8);
  const byte address[6] = "00001";
  int IN1 = 2;
  int IN2 = 3;
  int IN3 = 4;
  int IN4 = 7;
  int ENA = 5;
  int ENB = 6;
  int SPD = 200;
  int arr[2];
  int xAxis;
  int yAxis;
  

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}


void loop() 
{
  while(radio.available()) 
  {
    radio.read(&arr, sizeof(arr));
    xAxis = arr[0];
    yAxis = arr[1];
    
    if(yAxis > 390)
    {
      Forward();
    }
    
    else if(yAxis < 310)
    {
      Back();
    }
    
    else if(xAxis < 310)
    {
      Left();
    } 
    
    else if(xAxis > 390)
    {
      Right();
    }
    
    else
    {
     Stop();
    }
  }
}

void Forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, SPD);
  analogWrite(ENB, SPD);
  Serial.println("Forward");
}

void Back()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, SPD);
  analogWrite(ENB, SPD);
  Serial.println("Back");
}

void Right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, SPD);
  analogWrite(ENB, SPD);
  Serial.println("Right");
}

void Left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, SPD);
  analogWrite(ENB, SPD);
  Serial.println("Left");
}

void Stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stop");
}
