
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
  pinMode(1,INPUT);// Takkin á Joystick 
  pinMode(A2, OUTPUT); // 5 row 8
  pinMode(A3, OUTPUT); // 6 Collom  5 
  pinMode(A4, OUTPUT); // 7 Row 6
  pinMode(A5, OUTPUT); // 8 row 3
  pinMode(A0,INPUT); // X ásinn
  pinMode(A1,INPUT); // Y ásinn 
}
  int collomPin[] ={6,11,10,3,A3,4,8,9} ;
  int colloms[][8]={ {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                   {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH},
                   {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH},
                   {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH},
                   {LOW,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW},
                   {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,LOW,HIGH},
                   {HIGH,HIGH,LOW,LOW,LOW,LOW,HIGH,HIGH},
                   {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}};
int x = 5;
int y = 5;
//colloms[0])[3] = LOW;
/*int draw(){
      if (colloms[y][x] == 1){
        int colloms[y][x] = LOW;
      }
      else if (colloms[y][x]==0){
        int colloms[y][x]= HIGH;
  }
}*/
void loop() {
  //Coloms
  //toggle();
  for (int i = 0; i < 8; i++){
  digitalWrite(2,colloms[i][0]);
  digitalWrite(7,colloms[i][1]);
  digitalWrite(A5,colloms[i][2]);
  digitalWrite(5,colloms[i][3]);
  digitalWrite(13,colloms[i][4]);
  digitalWrite(A4,colloms[i][5]);
  digitalWrite(12,colloms[i][6]);
  digitalWrite(A2,colloms[i][7]);
  digitalWrite(collomPin[i],1);
  delay(2);
  digitalWrite(collomPin[i],0);
  }
  x = 7 - map(analogRead(A0), 0, 1023, 0, 7);
  Serial.print(x);
  y = map(analogRead(A1), 0, 1023, 0, 7);
  Serial.print(y);
}
