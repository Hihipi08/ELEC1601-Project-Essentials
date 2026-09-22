// this code includes going forwards, ideal 90 degree right and left turn, dead end and does 180 degree turn
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

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
int ir_valL = 0;
int ir_valF = 0;
int ir_valR = 0;
int distanceL = 0;
int distanceF = 0;
int distanceR = 0;
int Sensor_LED_Left = A2;
int Sensor_LED_Front = A1;
int Sensor_LED_Right = A0;

void setup()
{
  Serial.begin(9600);

  servoLeft.attach(13);
  servoRight.attach(12);
  
  pinMode(IR_LED_Right, OUTPUT);
  pinMode(IR_LED_Left, OUTPUT);
  pinMode(IR_LED_Front, OUTPUT);
  pinMode(Sensor_Left, INPUT);
  pinMode(Sensor_Right, INPUT);
  pinmode(Sensor_Front, INPUT);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(2000); //just so robot is stationary when placing it in the maze
}
void loop()
{
  if (irDetectFrequencyRight() == 1 && irDetectFrequencyLeft() == 1 && irDetectFrequencyLeft() == 0) //forwards
  {
    servoLeft.writeMicroseconds(1568); 
    servoRight.writeMicroseconds(1432);
    digitalWrite(Sensor_LED_Left, HIGH);
    digitalWrite(Sensor_LED_Right, HIGH);
    digitalWrite(Sensor_LED_Front, LOW);
  }

  else if (irDetectFrequencyRight() == 0 && irDetectFrequencyLeft() == 0 && irDetectFrequencyLeft() == 0) //forwards
  {
    servoLeft.writeMicroseconds(1568);
    servoRight.writeMicroseconds(1432);
    digitalWrite(Sensor_LED_Left, LOW);
    digitalWrite(Sensor_LED_Right, LOW);
    digitalWrite(Sensor_LED_Front, LOW);
  }
    
  
  else if (irDetectFrequencyLeft() == 0 && irDetectFrequencyRight() == 1 && irDetectFrequencyLeft() == 0) //left turn
    {
      delay(900);
      servoLeft.writeMicroseconds(1550); //turn
      servoRight.writeMicroseconds(1550);
      digitalWrite(Sensor_LED_Right, HIGH);
      digitalWrite(Sensor_LED_Left, LOW);
      digitalWrite(Sensor_LED_Front, LOW);
      delay(830);
      servoLeft.writeMicroseconds(1568); //moves forwards before checking where it is again
      servoRight.writeMicroseconds(1432);
      delay(500);
    }

    else if (irDetectFrequencyRight() == 0 && irDetectFrequencyLeft() == 1 && irDetectFrequencyLeft() == 0) //right turn
    {
      delay(900);
      servoLeft.writeMicroseconds(1450); //turn
      servoRight.writeMicroseconds(1450);
      digitalWrite(Sensor_LED_Left, HIGH);
      digitalWrite(Sensor_LED_Right, LOW);
      digitalWrite(Sensor_LED_Front, LOW);
      delay(780);
      servoLeft.writeMicroseconds(1568); //moves forwards before checking where it is again
      servoRight.writeMicroseconds(1432);
      delay(500);
    }

    // Dead end, does 180 turn then moves forward
    if (irDetectFrequencyFront() == 1 && irDetectFrequencyRight() == 1 && irDetectFrequencyLeft() == 1)
    {
      servoLeft.writeMicroseconds(1500); //stops for half a second
      servoRight.writeMicroseconds(1500);
      digitalWrite(Sensor_LED_Right, HIGH);
      digitalWrite(Sensor_LED_Left, HIGH);
      digitalWrite(Sensor_LED_Front, HIGH);
      delay(500);
      servoLeft.writeMicroseconds(1550); //180 degree turn
      servoRight.writeMicroseconds(1550);
      delay(1660);
      servoLeft.writeMicroseconds(1568); // goes forwards for half a second
      servoRight.writeMicroseconds(1432);
      delay(500);
    }
  
}

int irDetectFrequencyLeft() 
{
  tone(IR_LED_Left, 38000);
  delay(1);
  ir_valL = digitalRead(Sensor_Left);
  noTone(IR_LED_Left);
  delay(1);
  return ir_valL;
}

int irDetectFrequencyRight()
{
  tone(IR_LED_Right, 38000);
  delay(1);
  ir_valR = digitalRead(Sensor_Right);
  noTone(IR_LED_Right);
  delay(1);
  return ir_valR;
}

int irDetectFrequencyFront()
{
  tone(IR_LED_Front, 38000);
  delay(1);
  ir_valR = digitalRead(Sensor_Front);
  noTone(IR_LED_Front);
  delay(1);
  return ir_valF;
}
