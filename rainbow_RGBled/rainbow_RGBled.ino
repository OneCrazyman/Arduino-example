//RGB LED이용한 빨주노초파남보(무지개색) 점등
//해당핀 지정
int pinR = 11;
int pinG = 10;
int pinB = 9;

//7가지 색을 배열로 구현
int RGB[][3]={
  {255,0,0},
  {255,50,0},
  {255,160,0},
  {0,255,0},
  {0,0,255},
  {20,0,170},
  {200,0,255}
};


//아웃풋 지정
void setup() {
  // put your setup code here, to run once:
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  //콘솔 명령을 보기위해 설정
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //7가지 색을 하나씩 반복하여 입력
  for (int i=0; i<7; i++){
    analogWrite(pinR,RGB[i][0]);
    analogWrite(pinG,RGB[i][1]);
    analogWrite(pinB,RGB[i][2]);
    
    delay(1000);
  }
}
