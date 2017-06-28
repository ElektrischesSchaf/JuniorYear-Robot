#include <Servo.h>　
int s5int=70;
int s5=s5int;
int s3int=50;
int s3=s3int;
int s4int=110;
int s4=s4int;
int dc07ENA=7;
int dc07IN1=22;
int dc07IN2=24;
int dc08ENA=8;
int dc08IN1=28;
int dc08IN2=30;
int connectled=52;
int power1=33;
int power2=35;
int power3=37;
int dcspeed=255;
int gap=5;
int pushcount=0;

Servo servo3;
Servo servo4;
Servo servo5;


void setup() { 

 s5int=70;
 s5=s5int;
 s3int=50;
 s3=s3int;
 s4int=110;
 s4=s4int;

 Serial.begin(9600);
 servo5.attach(5);
 servo3.attach(3);
 servo4.attach(4);

 pinMode(connectled,OUTPUT);
 pinMode(power1,OUTPUT);
 pinMode(power2,OUTPUT);
 pinMode(power3,OUTPUT);
 pinMode(dc07ENA,OUTPUT);
 pinMode(dc07IN1,OUTPUT);
 pinMode(dc07IN2,OUTPUT);
 digitalWrite(power1,HIGH);
 digitalWrite(power2,HIGH);
 digitalWrite(power3,HIGH);

}

void loop() {
  char data=Serial.read();
  switch(data){
    
   case'q':
  //連線測試
  digitalWrite(connectled,HIGH);
  digitalWrite(power1,HIGH);
  digitalWrite(power2,HIGH);
  digitalWrite(power3,HIGH);
  delay(1000);
  digitalWrite(connectled,LOW);
  digitalWrite(power1,LOW);
  digitalWrite(power2,LOW);
  digitalWrite(power3,LOW);
  break;
  
   case 'a':
  // 伺服馬達快回原點
  s5=s5int;
  s3=s3int;
  s4=s4int;
  servo5.write(s5);
  servo3.write(s3);
  servo4.write(s4);
  break;

   case 'z':
  // 伺服馬達慢回原點
  s5=s5int;
  s3=s3int;
  s4=s4int;
  servo4.write(s4);
  delay(500);
  servo5.write(s5);
  delay(500);
  servo3.write(s3);
  delay(500);

  break;

  case'b':  // 放置三階準備
  s3=s3int;
  servo3.write(s3);
  s4=s4int;
  servo4.write(s4);
  delay(500);
  
  s3=s3-25;   //JJJJJ
  servo3.write(s3);
  delay(500);

  s4=s4-30;  //NNNNNN
  servo4.write(s4);
  delay(500);

  s4=s4-25;  //NNNNNH
  servo4.write(s4);
  s3=s3-5;
  servo3.write(s3);  
  delay(500);  
  break;
  
   case'c':   
   // 後退
digitalWrite (dc07IN1,HIGH);
digitalWrite (dc07IN2,LOW);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,LOW);
digitalWrite (dc08IN2,HIGH);
analogWrite (dc08ENA,dcspeed);
   break;

   case'v':
//右後
digitalWrite (dc07IN1,HIGH);
digitalWrite (dc07IN2,LOW);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,LOW);
digitalWrite (dc08IN2,LOW);
analogWrite (dc08ENA,dcspeed);
   break;

   case'x':
//左後
digitalWrite (dc07IN1,LOW);
digitalWrite (dc07IN2,LOW);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,LOW);
digitalWrite (dc08IN2,HIGH);
analogWrite (dc08ENA,dcspeed);
   break;
   
  case'e':   
   // 前進
digitalWrite (dc07IN1,LOW);
digitalWrite (dc07IN2,HIGH);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,HIGH);
digitalWrite (dc08IN2,LOW);
analogWrite (dc08ENA,dcspeed);
   break;

case'r':
// 右前
digitalWrite (dc07IN1,LOW);
digitalWrite (dc07IN2,HIGH);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,LOW);
digitalWrite (dc08IN2,LOW);
analogWrite (dc08ENA,dcspeed);
break;

   case'w':
// 左前
digitalWrite (dc07IN1,LOW);
digitalWrite (dc07IN2,LOW);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,HIGH);
digitalWrite (dc08IN2,LOW);
analogWrite (dc08ENA,dcspeed);
break;

     case's':   
   // 原地左轉
digitalWrite (dc07IN1,HIGH);
digitalWrite (dc07IN2,LOW);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,HIGH);
digitalWrite (dc08IN2,LOW);
analogWrite (dc08ENA,dcspeed);
   break;
   
 case'f':   
   //原地右轉
digitalWrite (dc07IN1,LOW);
digitalWrite (dc07IN2,HIGH);
analogWrite (dc07ENA,dcspeed);
digitalWrite (dc08IN1,LOW);
digitalWrite (dc08IN2,HIGH);
analogWrite (dc08ENA,dcspeed);
   break;
   
  case 'd':   
  // 煞車
  digitalWrite(connectled,LOW);
  digitalWrite(dc07IN1,LOW);
  digitalWrite(dc07IN2,LOW);
  digitalWrite(dc08IN1,LOW);
  digitalWrite(dc08IN2,LOW);
  //delay(1000); 
  break;  
  
  case't':
  //

  break;
  
  case'g':
  //
 
  break;
  

    
  //夾頭
  case'y':
   if(s5<85){
    s5=s5+gap;
     servo5.write(s5);
  }   
  break;
  
  case'u':
   if(s5>35){
    s5=s5-gap;
    servo5.write(s5);
  }
  
  break;
  
  //二桿
  case 'h':
  if(s3<120){
    s3=s3+gap;
     servo3.write(s3);
  }
 
  break;
  
  case 'j':
  if(s3>20){
    s3=s3-gap;
    servo3.write(s3);
  }
 
  break;

  //三桿
  case 'm':
  if(s4<140){
    s4=s4+gap;
     servo4.write(s4);
  }
 
  break;
  
  case 'n':
  if(s4>20){
    s4=s4-gap;
     servo4.write(s4);
  }
 
  break;
  


  //自動收進
  case'i':
  s3=s3int;
  s4=s4int;  
  servo3.write(s3);
  servo4.write(s4);
  delay(500);
  
  s3=s3-20;
  servo3.write(s3);
  delay(500);
  
  s4=s4-50;
  servo4.write(s4);
  delay(500);
  
  s3=s3+10;
  s4=s4+5;
  servo3.write(s3);
  servo4.write(s4);
  delay(500);

   s3=s3+5;
  s4=s4+5;
  servo3.write(s3);
  servo4.write(s4);
  delay(500);

  
   s3=s3+5;
  s4=s4+5;
  servo3.write(s3);
  servo4.write(s4);
  delay(500);

  s3=s3+5;
  s4=s4+15;
  servo3.write(s3);
  servo4.write(s4);
 delay(500);  

  s4=s4+10; 
  servo4.write(s4);
 delay(500);  
  
  s3=s3+5;
  servo3.write(s3);
  delay(500);
  break;

  
  //擋下
  case'o':
  s5=s5int;
  s3=s3int;
  s4=s4int;
  servo5.write(s5);
  servo3.write(s3);
  servo4.write(s4);
  delay(500);

  //s4=s4-25;
  s4=s4-20;
  servo4.write(s4);
  delay(500);

  s3=s3+10;
  servo3.write(s3);
  delay(500);

   s4=s4+5;
   servo4.write(s4);
   delay(500);
  s3=s3+5;
  servo3.write(s3);
  delay(500);
   
  break;

  //推子到預備位置
  case'p':
  pushcount=1;
  s3=s3int;
  s4=s4int;
  servo3.write(s3);
  servo4.write(s4);
  delay(500);

  s3=s3-15;
  servo3.write(s3);
  delay(500);

  s4=s4+15;
  servo4.write(s4);
  delay(500);

  s3=s3+15;
  servo3.write(s3);
  delay(500);
  
   break;

   //推子往前
  case'k':    //NNH NNH NNNNN
  s4=s4int+15;
  servo4.write(s4);
  s3=s3int;
  servo3.write(s3);

  if(pushcount==1) //NNH
  {
    s4=s4-10;
    servo4.write(s4);
    s3=s3+5;
    servo3.write(s3);
    delay(500);
    pushcount++;
    break;
  }
  if(pushcount==2)  //NNH
  {
    s4=s4-10;
    s3=s3+5;
    servo3.write(s3);
    servo4.write(s4);
    delay(500);

    s4=s4-10;
    s3=s3+5;
    servo3.write(s3);
    servo4.write(s4);
    pushcount++;
    break;
  }
  if(pushcount==3)  //NN
  {
    s4=s4-20;
    s3=s3+10;
    servo3.write(s3);
    servo4.write(s4);
    delay(500);

    s4=s4-10;  
    servo4.write(s4);
   pushcount++;
   break;
  }
  if(pushcount==4)  //NN
  {
    s4=s4-30;
    s3=s3+10;
    servo3.write(s3);
    servo4.write(s4);
    delay(500);

   s4=s4-10;
   servo4.write(s4);
   pushcount++;
   break;
  }
  if(pushcount==5)  //N
  {
    s4=s4-40;
    s3=s3+10;
    servo3.write(s3);
    servo4.write(s4);
    delay(500);
    

    s4=s4-5;
   servo4.write(s4);

    delay(1000);
//稍微收回
    s3=s3-15;
    servo3.write(s3);
    delay(1000);    
    s4=s4+10;
    servo4.write(s4);
    delay(500);
    s4=s4+10;
    servo4.write(s4);
    delay(500);
   
   
  s3=s3int;
  s4=s4int;
  servo3.write(s3);
  servo4.write(s4);
  delay(500);
  pushcount=1;
   break;
  }
  break;

   //推子噴射 NNH NNH NNNNN
   case'l':
  s4=s4int+15;
  servo4.write(s4);
  s3=s3int;
  servo3.write(s3);
  delay(500);
  
  s4=s4-15; //NNH
  servo4.write(s4);
  s3=s3+5;
  servo3.write(s3);
  delay(500);
  
    s4=s4-15;    //NNH
    s3=s3+5;
    servo3.write(s3);
    servo4.write(s4);
    delay(500);

    s4=s4-25;   //NNNNN
   
    servo3.write(s3);
    servo4.write(s4);
    
    //稍微收回
    delay(1000);

    s3=s3-15;
    servo3.write(s3);
    delay(1000);    
    s4=s4+10;
    servo4.write(s4);
    delay(500);
    s4=s4+10;
    servo4.write(s4);
    delay(500);
    
   break;
}
}
