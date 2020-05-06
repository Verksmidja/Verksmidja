#include <Servo.h>

Servo servo_9;
// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

int cm = 0;
int speed = 0;
int x = 0;
int y = 0;
void setup()
{Serial.begin(9600);
   Wire.begin(SLAVE_ADDR);
 Wire.onReceive(receiveEvent);
  servo_9.attach(3);
   pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
 Wire.onRequest(returnCm);
}

void returnCm(){
  cm = 0.01723 * readUltrasonicDistance(7, 8);
  Serial.print("Request");
  Wire.write(cm);
}
int rd = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void receiveEvent(int howMany){
  // read one character from the I2C
  rd = Wire.read();
  y = rd/10;
  x = rd%10;
  Serial.print(x);
    Serial.print(",");
    Serial.println(y);
  // Print value of incoming data
  //Serial.println(rd);
}
void car (){
  if (y == 0){
  //Serial.print("Nothing");
    speed = 0;
  }
  else if (y == 1){
  		//Serial.print("Forwards");
    forwards();
  }
  else if (y == 2){
  		//Serial.print("Backwards");
    backwards();
  }
    if (x == 0){
  //Serial.println("Forward");
    forward();
  }
  else if (x == 1){
  		//Serial.println("left");
    left();
  }
  else if (x == 2){
  		//Serial.println("Rigth");
    rigth();
  }
}

 void forwards(){
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
   speed = 255;
  }
void backwards(){
   digitalWrite(5,HIGH);
 digitalWrite(4,LOW);
  speed = 192;
  }
void forward(){
  servo_9.write(90);
}
void left(){
  servo_9.write(135);
  speed = 128;
}
void rigth(){
  servo_9.write(45);
  speed = 128;
}
void loop(){
  car();
  analogWrite(6,speed);
}	