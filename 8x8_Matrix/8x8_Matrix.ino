
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); //1 Row 5  sets the digital pin 13-1 as output
  pinMode(12, OUTPUT); //2 row 7
  pinMode(11, OUTPUT); //3 collom 2
  pinMode(10, OUTPUT);//4 Collom 3
  pinMode(9, OUTPUT); // 16 Collom 8 
  pinMode(8, OUTPUT); // 15 Collom 7
  pinMode(7, OUTPUT); // 14 Row 2
  pinMode(6, OUTPUT); // 13 collom 1
  pinMode(5, OUTPUT); // 12 Row 4
  pinMode(4, OUTPUT); // 11 Colllom 6
  pinMode(3, OUTPUT); // 10 Collom 4
  pinMode(2, OUTPUT); // 9 row 1
  pinMode(1,INPUT);// Reset takki
  pinMode(0,INPUT);// Takkin á Joystick 
  pinMode(A2, OUTPUT); // 5 row 8
  pinMode(A3, OUTPUT); // 6 Collom  5 
  pinMode(A4, OUTPUT); // 7 Row 6
  pinMode(A5, OUTPUT); // 8 row 3
  pinMode(A0,INPUT); // X ásinn
  pinMode(A1,INPUT); // Y ásinn 
}
  int Rows[] = {2,7,A5,5,13,A4,12,A2};
  int collomPin[] ={6,11,10,3,A3,4,8,9} ;
  int colloms[8][8]={ {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                      {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                      {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                      {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                      {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                      {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                      {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                      {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}};
int x = 5;
int y = 5;
void clearMatrix(){
    for (int c = 0; c < 8; c++){
    for (int r = 0;r <8; r++){
    colloms[c][r]= 1;
    }
  }
}
void draw(){
  for (int c = 0; c < 8; c++){
    for (int r = 0;r <8; r++){
      digitalWrite(Rows[r],colloms[c][r]);
    }
    digitalWrite(collomPin[c],1);
    digitalWrite(collomPin[c],0);
  }
}
void loop() {
draw();
    if (digitalRead(0) == 0){
      if (colloms[y][x] == 1){
        colloms[y][x] = 0;
      }
      else if (colloms[y][x]==0){
        colloms[y][x]= 1;
  }
    }
    /*else{
      colloms[y][x]=1;
      delay(3);
      colloms[y][x]=0;
    }*/
    if (digitalRead(1)==1){
      clearMatrix();
    }
  x = 7 - map(analogRead(A0), 0, 1023, 0, 7);
  //Serial.print(x);
  y = map(analogRead(A1), 0, 1023, 0, 7);
  //Serial.print(y);
  //Serial.print(digitalRead(0));    
}
