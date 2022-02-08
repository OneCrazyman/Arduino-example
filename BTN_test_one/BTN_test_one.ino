//버튼 테스트
#define btn_one 2
#define spk_one 3

void setup() {
  // put your setup code here, to run once:
  pinMode(btn_one,INPUT);
  pinMode(spk_one,INPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

int r,g,b;

void loop() {
  // put your main code here, to run repeatedly:
  if(btn_one == 1){
   r += random(10)*10;
   g += random(10)*10;
   b += random(10)*10;
   Serial.println("r: "+String(r));
   Serial.println("g: "+String(g));
   Serial.println("b: "+String(b));
   if(r > 255){
    
   }
  }
}
