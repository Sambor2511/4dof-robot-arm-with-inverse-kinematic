#include <Servo.h>
#include <ezButton.h>
#define Xaxis_pin A0
#define Yaxis_pin A1

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
ezButton button(2);

// Define lengths of the robot arm segments
const float L1 = 10;
const float L2 = 8.9;
const float L3 = 12.8;


void setup() {
  pinMode(Xaxis_pin, INPUT);
  pinMode(Yaxis_pin, INPUT);
  // Attach the servos to their respective pins
  servo0.attach(8);
  // servo0.write(90);
  servo1.attach(9);
  // servo1.write(180);
  servo2.attach(10);
  // servo2.write(90);
  servo3.attach(11);
  // servo3.write(90);
  servo4.attach(12);
  servo4.write(0);
  Serial.begin(9600);
  button.setDebounceTime(50);
  kinematic(0, 0, 7);
}

float x1 = 3, y1 = 7;
int yread;
int xread;
bool btnstate = false;
bool timestate = false;
bool servostate = false;
unsigned long time;
void loop() {
  button.loop();
  int xread = analogRead(A0);
  int yread = analogRead(A1);
  int btn = button.getState();
  int pot = analogRead(A3);
  int status = analogRead(A5);
  int angle = 180 - map(pot, 0, 1023, 0, 180);
  if (xread > 890) {
    if (x1 < 17) {
      x1 += 0.6;
    }
    kinematic(x1, 0, y1);
    delay(50);
  } else if (xread < 200) {
    if (x1 > 0) {
      x1 -= 0.6;
    }
    kinematic(x1, 0, y1);
    delay(50);
  }
  if (yread > 890) {
    if (y1 > -8) {
      y1 -= 0.6;
    }
    kinematic(x1, 0, y1);
    delay(50);
  } else if (yread < 200) {
    if (y1 < 8) {
      y1 += 0.6;
    }
    kinematic(x1, 0, y1);
    delay(50);
  }
  if (button.isPressed()) {
    if (timestate == false) {
      time = millis();
      timestate = true;
    }
    if (btnstate == false) {
      servo4.write(180);
      btnstate = true;
    } else {
      servo4.write(0);
      btnstate = false;
    }
  } else if (button.isReleased()) {
    timestate = false;
    if ((millis() - time) > 1500) {
      if (servostate) {
        servostate = false;
        kinematic(x1, 0, y1);
      } else {
        servostate = true;
        kinematic(x1, 0, y1);
      }
    }
  }
  servo0.write(angle);
  Serial.print(x1);
  Serial.print(" ");
  Serial.println(y1);
}


void kinematic(float x, float y, float z) {
  // theta 1
  float theta1 = atan2(y, x);
  float theta1deg = degrees(theta1);
  float p = x / cos(theta1);
  // theta 2
  float d = sqrt(pow(p, 2) + pow(z, 2));
  float alpha1 = acos((pow(L1, 2) + pow(d, 2) - pow(L2, 2))/ (2 * L1 * d));
  float alpha2 = atan2(z, p);
  float theta2 = alpha1+alpha2;
  float theta2deg = degrees(theta2);
  //theta 3
  float theta3 = acos((pow(L1, 2) + pow(L2, 2) - pow(d, 2)) / (2 * L1 * L2));
  float theta3deg = 180 - degrees(theta3);
  servo1.write(theta2deg);
  servo2.write(theta3deg);
  if (servostate) {
    float offsetangle = (90 - (theta2deg - theta3deg)) + 30 - 110;
    servo3.write(offsetangle);

  } else {
    float offsetangle = (90 - (theta2deg - theta3deg)) + 30;
    servo3.write(offsetangle);
  }
}

void motion() {
  servo4.write(0);
  servo0.write(160);
  delay(700);
  
  kinematic(12, 0, -1);
  delay(700);
  servo4.write(180);
  delay(700);
  kinematic(12, 0, 7);
  delay(700);
  servo0.write(120);
  delay(700);
  kinematic(8, 0, -1);
  delay(700);
  servo4.write(0);
  delay(700);
  kinematic(12, 0, 7);
}
