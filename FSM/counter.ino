#include <Arduino.h>

int W,X,Y,Z;
int D,C,B,A;

void disp_7447(int D,int C,int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB
}

void setup() {
 
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);
pinMode(13, OUTPUT);

}

void loop() {

digitalWrite(13, HIGH);
delay(100);

disp_7447(D,C,B,A);

W = digitalRead(6);
X = digitalRead(7);
Y = digitalRead(8);
Z = digitalRead(9);
    
    A = (!W);
B = (!Z&&!X&&W)||(!W&&X);
C = (!X&&Y) || (!Y&&X&&W) || (!W&&Y);
D = (W&&X&&Y)||(!W&&Z);
delay(100);
W = A;
X = B; 
Y = C;
Z = D;

digitalWrite(13, LOW);
delay(500);
}
