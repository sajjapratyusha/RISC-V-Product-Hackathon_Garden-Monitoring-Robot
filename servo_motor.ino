#include<Servo.h>
 Servo motor;
 void setup()
 {
 motor.attach(9);
 }

 void loop()
 {
 motor.write(0);
 delay(2000); 
 motor.write(45);
 delay(2000);
 motor.write(90);
 delay(2000);
 motor.write(135);
 delay(2000);
 motor.write(180);
 delay(2000);
 }
