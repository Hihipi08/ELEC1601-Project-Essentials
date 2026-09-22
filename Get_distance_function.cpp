// this code contains a function  to find the distance the robot is from a wall based on the data we collected
// it has a lot of delays so I am unsure if this is the best way to write this function so open to more ideas on how to do this better
// also each sensor had slightly different data, hence there are three functions
// can be used to help code scenarios for the robot

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

void loop()
{
}

int find_distance_left()
{
  tone(IR_LED_Left, 45000);
  delay(1);
  ir_valL = digitalRead(Sensor_Left);
  if (ir_valL == 1) { distanceL = 4; }
  else
  {
    tone(IR_LED_Left, 44000);
    delay(1);
    ir_valL = digitalRead(Sensor_Left);
    if (ir_valL == 1) { distanceL = 5; }
    else
    {
      tone(IR_LED_Left, 40000);
      delay(1);
      ir_valL = digitalRead(Sensor_Left);
      if (ir_valL == 1) { distanceL = 6; }
      else
      {
        tone(IR_LED_Left, 39000);
        delay(1);
        ir_valL = digitalRead(Sensor_Left);
        if (ir_valL == 1) { distanceL = 8; }
        else
        {
          tone(IR_LED_Left, 38000);
          delay(1);
          ir_valL = digitalRead(Sensor_Left);
          if (ir_valL == 1) { distanceL = 10; }
          else { distanceL = 11; }   // not detected even at 38kHz → out of range
        }
      }
    }
  }

  noTone(IR_LED_Left);
  return distanceL;
}

int find_distance_right() //done
{
  tone(IR_LED_Right, 45000);
  delay(1);
  ir_valR = digitalRead(Sensor_Right);
  if (ir_valR == 1) { distanceR = 4; }
  else
  {
    tone(IR_LED_Right, 44000);
    delay(1);
    ir_valR = digitalRead(Sensor_Right);
    if (ir_valR == 1) { distanceR = 5; }
    else
    {
      tone(IR_LED_Right, 42000);
      delay(1);
      ir_valR = digitalRead(Sensor_Right);
      if (ir_valR == 1) { distanceR = 6; }
      else
      {
        tone(IR_LED_Right, 41000);
        delay(1);
        ir_valR = digitalRead(Sensor_Right);
        if (ir_valR == 1) { distanceR = 7; }
        else
        {
          tone(IR_LED_Right, 39000);
          delay(1);
          ir_valR = digitalRead(Sensor_Right);
          if (ir_valR == 1) { distanceR = 8; }
          else 
          {
            tone(IR_LED_Right, 38000);
          	delay(1);
          	ir_valR = digitalRead(Sensor_Right);
          	if (ir_valR == 1) { distanceR = 9; }
            else 
            {distanceR = 10; } 
            
          }
        }
      }
    }
  }

  noTone(IR_LED_Right);
  return distanceR;
}
  

int find_distance_front() //done
{
  tone(IR_LED_Front, 45000);
  delay(1);
  ir_valF = digitalRead(Sensor_Front);
  if (ir_valF == 1) { distanceF = 4; }
  else
  {
    tone(IR_LED_Front, 43000);
    delay(1);
    ir_valF = digitalRead(Sensor_Front);
    if (ir_valF == 1) { distanceF = 5; }
    else
    {
      tone(IR_LED_Front, 42000);
      delay(1);
      ir_valF = digitalRead(Sensor_Front);
      if (ir_valF == 1) { distanceF = 6; }
      else
      {
        tone(IR_LED_Front, 41000);
        delay(1);
        ir_valF = digitalRead(Sensor_Front);
        if (ir_valF == 1) { distanceF = 7; }
        else
        {
          tone(IR_LED_Front, 40000);
          delay(1);
          ir_valF = digitalRead(Sensor_Front);
          if (ir_valF == 1) { distanceF = 8; }
          else 
          {
            tone(IR_LED_Front, 39000);
          	delay(1);
          	ir_valF = digitalRead(Sensor_Front);
          	if (ir_valF == 1) { distanceF = 10; }
          	else 
            {
              tone(IR_LED_Front, 38000);
          	  delay(1);
          	  ir_valF = digitalRead(Sensor_Front);
          	  if (ir_valF == 1) { distanceF = 11; }
              else {distanceF = 12; }
            }
          }
        }
      }
    }
  }

  noTone(IR_LED_Front);
  return distanceF;
}
