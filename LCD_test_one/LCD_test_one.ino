//LCD를 활용한 현재 날짜 시간 표시
#define SWITCH 8
#define SWITCH2 7
#define RELAY 9

#define CLK 5
#define DAT 4
#define RST 3

#include <ThreeWire.h>
#include <RtcDS1302.h>       
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //lcd 객체 선언

ThreeWire myWire(DAT,CLK,RST);
RtcDS1302<ThreeWire> Rtc(myWire);

void setup(){
  Serial.begin(9600);
  lcd.begin(); //LCD 사용 시작
  pinMode(SWITCH,INPUT_PULLUP);
  pinMode(SWITCH2,INPUT_PULLUP);
  pinMode(RELAY,OUTPUT);

  Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__,__TIME__);
  if(!Rtc.IsDateTimeValid()){
    Serial.println(0);
    Rtc.SetDateTime(compiled);
  }
  if(Rtc.GetIsWriteProtected()){
    Serial.println(1);
    Rtc.SetIsWriteProtected(false);
  }
  if(!Rtc.GetIsRunning()){
    Serial.println(2);
    Rtc.SetIsRunning(true);
  }
  
  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled){
    Rtc.SetDateTime(compiled);
    Serial.println(3);
  }
}

void loop(){
  RtcDateTime now = Rtc.GetDateTime();
  char buf[50];
  //날짜출력
  sprintf(buf, "%d-%02d-%02d ", now.Year(), now.Month(), now.Day());
  lcd.setCursor(0,0);
  lcd.print(buf);
  //시간출력
  sprintf(buf, "%02d:%02d:%02d    ", now.Hour(), now.Minute(), now.Second());
  lcd.setCursor(0,1);
  lcd.print(buf);
}
