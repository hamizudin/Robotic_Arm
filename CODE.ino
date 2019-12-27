`#include <Servo.h>

/////m driver 1
const int pwm_a = 13 ;
const int in_1 = 12 ;
const int in_2 = 11 ;
const int pwm_b = 10 ;
const int in_3 = 9 ;
const int in_4 = 8 ;
/////m driver 2/////
const int pwm_a1 = 7 ;
const int in_a1 = 6 ;
const int in_a2 = 5 ;
const int pwm_b1 = 4 ;
const int in_b1 = 3 ;
const int in_b2 = 2 ;

Servo myservo; 

int pos = 0; 

//For providing logic to L298 IC to choose the direction of the DC motor 

void setup()
{
 Serial.begin(9600); //making serial connection
  // set all the motor control pins to outputs 
 pinMode(pwm_a,OUTPUT) ;//we have to set PWM pin as output
 pinMode(pwm_b,OUTPUT) ;
 pinMode(pwm_a1,OUTPUT) ;   
 pinMode(pwm_b1,OUTPUT) ;   
 pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
 pinMode(in_2,OUTPUT) ;
 pinMode(in_3,OUTPUT) ;  
 pinMode(in_4,OUTPUT) ; 
 pinMode(in_a1,OUTPUT) ;  
 pinMode(in_a2,OUTPUT) ; 
 pinMode(in_b1,OUTPUT) ;  
 pinMode(in_b2,OUTPUT) ; 
 myservo.attach(44); 
}

void loop()
{
  if(Serial.available()> 0)
  {
    char serialData = Serial.read();
    
/////////////motor 1////////////////////////////////////////////////////    
  if(serialData=='A')
  {
  m1_forward(); //FORWARD
  m1_stop(); //stop
  }
   if(serialData=='a')
  {
  m1_stop(); //stop
  }
  else if(serialData=='B')
  {
  m1_reverse();//REVERSE
  m1_stop(); //stop
  }
  else if(serialData=='b')
  {
  m1_stop(); //stop
  }
/////////////motor 2///////////////////////////////////////////////////
  if(serialData=='C')
  {
    m2_forward(); //FORWARD
    m2_stop(); //stop
  }
   if(serialData=='c')
  {
  m2_stop(); //stop
  }
  else if(serialData=='D')
  {
  m2_reverse();//REVERSE
  m2_stop(); //stop
  }
  else if(serialData=='d')
  {
  m2_stop(); //stop
  }
 //////////////motor 3///////////////////////////////////////////////////
  if(serialData=='E')
  {
    m3_forward(); //FORWARD
    m3_stop(); //stop
  }
   if(serialData=='e')
  {
  m3_stop(); //stop
  }
  else if(serialData=='F')
  {
  m3_reverse();// REVERSE
  m3_stop(); //stop
  }
  else if(serialData=='f')
  {
  m3_stop(); //stop
  }
 //////////////motor 4///////////////////////////////////////////////////base
  if(serialData=='G')
  {
    m4_forward(); //FORWARD
    m4_stop(); //stop
  }
   if(serialData=='g')
  {
  m4_stop(); //stop
  }
  else if(serialData=='H')
  {
  m4_reverse();// REVERSE
  m4_stop(); //stop
  }
  else if(serialData=='h')
  {
  m4_stop(); //stop
  } 
 //////////////////////////gripper///////////////////////////////////////// 
  else if(serialData=='I')
  {
  gripON();
  }
  else if(serialData=='J')
  {
  gripOFF();
  } 
  }
 }

///////////////////////sub function/////////////////////////////////////////////////////////////


void m1_forward(){
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;
analogWrite(pwm_a,255) ;
delay(1000) ;
}

void m1_reverse(){
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW);
analogWrite(pwm_a,255);
delay(1000) ;  
}

void m1_stop(){
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
}

void m2_forward(){
digitalWrite(in_3,LOW) ;
digitalWrite(in_4,HIGH) ;
analogWrite(pwm_b,255) ;
delay(1000) ;
}

void m2_reverse(){
digitalWrite(in_3,HIGH) ;
digitalWrite(in_4,LOW);
analogWrite(pwm_b,255);
delay(1000) ;  
}

void m2_stop(){
digitalWrite(in_3,HIGH) ;
digitalWrite(in_4,HIGH) ;
}

void m3_forward(){
digitalWrite(in_a1,LOW) ;
digitalWrite(in_a2,HIGH) ;
analogWrite(pwm_a1,255) ;
delay(1000) ;
}

void m3_reverse(){
digitalWrite(in_a1,HIGH) ;
digitalWrite(in_a2,LOW);
analogWrite(pwm_a1,255);
delay(1000) ;  
}

void m3_stop(){
digitalWrite(in_a1,HIGH) ;
digitalWrite(in_a2,HIGH) ;
}

void m4_forward(){
digitalWrite(in_b1,LOW) ;
digitalWrite(in_b2,HIGH) ;
analogWrite(pwm_b1,255) ;
delay(1000) ;
}

void m4_reverse(){
digitalWrite(in_b1,HIGH) ;
digitalWrite(in_b2,LOW);
analogWrite(pwm_b1,255);
delay(1000) ;  
}

void m4_stop(){
digitalWrite(in_b1,HIGH) ;
digitalWrite(in_b2,HIGH) ;
}

void gripON(){
for (pos = 0; pos <= 30; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
}
}

void gripOFF(){
   for (pos = 45; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position 
}
}
