#include <Servo.h>

Servo servoLeft;
Servo servoRight;

// Sensor pins
int IR_LED_Left = 10;
int Sensor_Left = 11;

int IR_LED_Front = 6;
int Sensor_Front = 7;

int IR_LED_Right = 2;
int Sensor_Right = 3;

// Scenario LEDs
int LED_R_Right = A0;
int LED_R_Mid = A1;
int LED_R_Left = A2;

int distanceL = 0;
int distanceF = 0;
int distanceR = 0;

void setup()
{
  servoLeft.attach(13);
  servoRight.attach(12);

  pinMode(IR_LED_Left, OUTPUT);
  pinMode(IR_LED_Front, OUTPUT);
  pinMode(IR_LED_Right, OUTPUT);

  pinMode(Sensor_Left, INPUT);
  pinMode(Sensor_Front, INPUT);
  pinMode(Sensor_Right, INPUT);

  pinMode(LED_R_Right, OUTPUT);
  pinMode(LED_R_Mid, OUTPUT);
  pinMode(LED_R_Left, OUTPUT);

  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void loop()
{
  distanceL = find_distance_left();
  distanceF = find_distance_front();
  distanceR = find_distance_right();

  // Close to left wall, close to front wall,
  // open space on right
  if(distanceL <= 3 &&
     distanceF <= 5 &&
     distanceR >= 8)
  {
    // Middle LED flash
    digitalWrite(LED_R_Mid, HIGH);
    delay(1000);
    digitalWrite(LED_R_Mid, LOW);

    // 90 degree clockwise turn
    servoLeft.writeMicroseconds(1550);
    servoRight.writeMicroseconds(1550);
    delay(600);
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);

    delay(200);

    // additional 30 degree clockwise turn
    servoLeft.writeMicroseconds(1550);
    servoRight.writeMicroseconds(1550);
    delay(200);
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);

    delay(200);

    // move forward 5 cm
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1400);
    delay(400);
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);

    delay(200);

    // 30 degree anticlockwise turn
    servoLeft.writeMicroseconds(1450);
    servoRight.writeMicroseconds(1450);
    delay(200);
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);

    delay(200);

    // continue forward
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1400);

    while(true)
    {
    }
  }

  // normal movement
  servoLeft.writeMicroseconds(1600);
  servoRight.writeMicroseconds(1400);
}
