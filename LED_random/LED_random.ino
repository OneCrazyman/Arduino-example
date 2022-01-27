#define R 11
#define G 10
#define B 9

void setup() {
  // put your setup code here, to run once:
  //랜덤난수 시드값 초기화
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  //0~255까지의 밝기를 PWM을 통해 랜덤으로 조절
  analogWrite(R,random(255));
  analogWrite(G,random(255));
  analogWrite(B,random(255));
  delay(500);
}
