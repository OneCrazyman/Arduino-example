//LED 점등 예제 : 두개의 LED를 번갈아가며 점등
//양쪽이 모두 한번 점등하고 0.5초씩 딜레이가 늘어남
int del = 1000; //초기 딜레이 시간
int stat = LOW; //LED 상태
int LED_one = 5; 
int LED_two = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_one,OUTPUT);
  pinMode(LED_two,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_one,stat);
  digitalWrite(LED_two,!stat); //5번핀에서 반전된 상태
  Serial.println("Green: " + String(stat) + " Red: " + String(!stat) + " Delay: " + String(del));
  stat = !stat;
  delay(del);
  del+=500;
}
