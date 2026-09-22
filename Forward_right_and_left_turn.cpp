// C++ code
//
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

void setup()
{
  Serial.begin(9600);

  servoLeft.attach(13);
  servoRight.attach(12);
  
  pinMode(IR_LED_Right, OUTPUT);
  pinMode(IR_LED_Left, OUTPUT);
  pinMode(Sensor_Left, INPUT);
  pinMode(Sensor_Right, INPUT);
  delay(5000);
}
void loop()
{
  if (irDetectFrequencyRight() == 1 && irDetectFrequencyLeft() == 1)
  {
    servoLeft.writeMicroseconds(1568); 
    servoRight.writeMicroseconds(1432);
    
    Serial.println("going forward");
  }

  else if (irDetectFrequencyRight() == 0 && irDetectFrequencyLeft() == 0)
  {
    servoLeft.writeMicroseconds(1568);
    servoRight.writeMicroseconds(1432);
    
    Serial.println("going forward");
  }
    
  
  else if (irDetectFrequencyLeft() == 0 && irDetectFrequencyRight() == 1) //left turn
    {
      delay(900);
      servoLeft.writeMicroseconds(1550);
      servoRight.writeMicroseconds(1550);

      Serial.println("turning left");
      delay(830);
      servoLeft.writeMicroseconds(1568);
      servoRight.writeMicroseconds(1432);
      delay(500);
    }

    else if (irDetectFrequencyRight() == 0 && irDetectFrequencyLeft() == 1) //right turn
    {
      delay(900);
      servoLeft.writeMicroseconds(1450);
      servoRight.writeMicroseconds(1450);
      Serial.println("turning right");
      delay(780);
      servoLeft.writeMicroseconds(1568);
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
