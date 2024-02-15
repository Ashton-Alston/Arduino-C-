
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

void loop() {// begining of challenge 1 and 2

  int switchStatus = digitalRead(7); 
  Serial.print("Switch Status = ");

  Serial.println(switchStatus);   

  if(switchStatus == 1){ 
    stop(); // pause before it starts in order to let me take my hand off
    delay(1000);
    figure8_1();// call the first half of one loop
    delay(4290);
    figure8_2();// calls full second loop
    delay(5350);
    straight(); // calls function to continue the figure 8
    delay(2000);
    right(); // position the robot to run again
    delay(850);
    stop();// stop the robot 
    delay(700);
  }

  if(switchStatus == 0){ //set condition for stop function
    stop();

  }
}


void stop(){  //makes robot stop moving

  myservo1.writeMicroseconds(1500);
  myservo2.writeMicroseconds(1500);
}
void figure8_1(){// function for first loop
  myservo1.writeMicroseconds(1200);
  myservo2.writeMicroseconds(1950);

}
void figure8_2(){// function for second full loop
  myservo1.writeMicroseconds(1070);
  myservo2.writeMicroseconds(1700);
}
void straight(){// function for returning back to other half of loop
  myservo1.writeMicroseconds(1100);
  myservo2.writeMicroseconds(1770);
}
void right(){// function to position robot in correct manner to run the code again
  myservo1.writeMicroseconds(1250);
  myservo2.writeMicroseconds(1950);

}