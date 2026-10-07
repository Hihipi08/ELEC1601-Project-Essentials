#include <Servo.h>

Servo servoLeft;
Servo servoRight;
//sorry for so many variables
int val_right = 0;
int val_left = 0;
int LED_G_Left = 8;
int LED_G_Right = 4;
int LED_R_Left = 9;
int LED_R_Right = 5;
int IR_LED_Left = 10;
int Sensor_Left = 11;
int IR_LED_Front = 6;
int Sensor_Front = 7;
int IR_LED_Right = 2;
int Sensor_Right = 3;
int Sensor_LED_Left = A2;
int Sensor_LED_Front = A1;
int Sensor_LED_Right = A0;
int ir_valL = 0;
int ir_valF = 0;
int ir_valR = 0;
int distanceL = 0;
int distanceF = 0;
int distanceR = 0;


void setup()
{
  Serial.begin(9600);

  servoLeft.attach(13);
  servoRight.attach(12);
  
  pinMode(2, INPUT);
  pinMode(10, INPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
}


