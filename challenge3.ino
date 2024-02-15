
#include <Servo.h>
Servo myservo1;
Servo myservo2; // assigns servos 1 and 2



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //tells serial reader what bit rate
myservo1.attach(12); // Assigns Servo1 to pin 13
myservo2.attach(13); // Assigns Servo2 to pin 12 
pinMode(7, INPUT); // Assigns pin 7 to input
}

void loop() {// start of challenge 3

  int switchStatus = digitalRead(7); 
  Serial.print("Switch Status = ");

  Serial.println(switchStatus);   

  if(switchStatus == 1){ 
    stop(); // pause before it starts in order to let me take my hand off
    delay(1000);
    foward(); //call on foward function
    delay(3000);//do it for 3 seconds
    spin2();
    delay(1000);// change direction)
    spin();// call on spin function
    delay(3000);// do it for 3 seconds
    spin2();
    delay(1000);
    backwards();// call on backwords function
    delay(3000);// do it for 3 seconds
    stop();// stop the robot
    int i = 0;// set a value for i
    while (i < 6) { // start a while loop to blink my leds in a pattern
      digitalWrite(3,HIGH);// led on for 1 sec
      delay(1000);
      digitalWrite(3,LOW);//led off for 1/2 a sec
      delay(500);
      digitalWrite(2,HIGH);// led 2 on for 1 sec
      delay(1000);
      digitalWrite(2,LOW);//led off for 1/2 a sec
      delay(500);
      i++;// increment i by 1
    }
    

  }

  if(switchStatus == 0){ //set condition for stop function
    stop();

  }
}


void stop(){  //makes robot stop moving

  myservo1.writeMicroseconds(1500);
  myservo2.writeMicroseconds(1500);
}
void foward(){// make robot go foward
  myservo1.writeMicroseconds(1000);
  myservo2.writeMicroseconds(2000);

}
void spin(){ // make robot spin
  myservo1.writeMicroseconds(1000);
  myservo2.writeMicroseconds(1000);
  
}
void backwards(){// make robot go backwards
  myservo1.writeMicroseconds(2000);
  myservo2.writeMicroseconds(1000);
}
void spin2(){ // make robot spin
  myservo1.writeMicroseconds(2000);
  myservo2.writeMicroseconds(2000);
  
}