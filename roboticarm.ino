#include <Servo.h>

Servo base1;
Servo base2;
Servo elbow;
Servo gripper;

void setup() {
  Serial.begin(9600);
  
  base1.attach(8);
  base2.attach(9);
  elbow.attach(10);
  gripper.attach(11);
}

void loop() {
  if (Serial.available() > 0) {
    int angle1 = Serial.parseInt();
    int angle2 = Serial.parseInt();
    int angle3 = Serial.parseInt();
    int angle4 = Serial.parseInt();

    base1.write(angle1);
    base2.write(angle2);
    elbow.write(angle3);
    gripper.write(angle4);

    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
