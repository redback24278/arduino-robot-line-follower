#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {

pinMode(52,INPUT);
pinMode(53,INPUT);

}

void loop() {

int lsensor=digitalRead(52);
int rsensor=digitalRead(53);

if((lsensor==HIGH)&&(rsensor==HIGH))
{
  motor1.setSpeed(110);
  motor2.setSpeed(110);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
} else if ((lsensor==HIGH)&&(rsensor==LOW))
{
  motor1.setSpeed(100);
  motor2.setSpeed(90);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
} else if ((lsensor==LOW)&&(rsensor==HIGH))
{
  motor1.setSpeed(90);
  motor2.setSpeed(100);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
} else 
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
}
