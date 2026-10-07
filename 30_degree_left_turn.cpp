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

    servoLeft.attach(12);
    servoRight.attach(13);


    pinMode(IR_LED_Right, OUTPUT);
    pinMode(IR_LED_Left, OUTPUT);
    pinMode(IR_LED_Front, OUTPUT);

    pinMode(Sensor_Left, INPUT);
    pinMode(Sensor_Right, INPUT);
    pinMode(Sensor_Front, INPUT);

    pinMode(Sensor_LED_Right, OUTPUT);
    pinMode(Sensor_LED_Left, OUTPUT);
    pinMode(Sensor_LED_Front, OUTPUT);

    digitalWrite(Sensor_LED_Right, HIGH);
    digitalWrite(Sensor_LED_Left, HIGH);
    digitalWrite(Sensor_LED_Front, HIGH);
}

void loop()
{
    if (find_distance_right() <= 4 && find_distance_front() <= 12 && find_distance_left() == 11) {
      servoLeft.writeMicroseconds(1450); //turn
      servoRight.writeMicroseconds(1450);
      digitalWrite(Sensor_LED_Right, HIGH);
      digitalWrite(Sensor_LED_Left, LOW);
      digitalWrite(Sensor_LED_Front, HIGH);
      delay(200); // change the delay so it turns properly
      servoLeft.writeMicroseconds(1500);
      servoRight.writeMicroseconds(1500);
    }

    else if (find_distance_left() <= 4 && find_distance_front() <= 12 && find_distance_right() >= 8) {
        servoLeft.writeMicroseconds(1550); //turn
        servoRight.writeMicroseconds(1550);
        digitalWrite(Sensor_LED_Right, HIGH);
        digitalWrite(Sensor_LED_Left, HIGH);
        digitalWrite(Sensor_LED_Front, HIGH);
        delay(200); // change the delay so it turns properly
        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);
}
}
    

int find_distance_left()
{
  tone(IR_LED_Left, 65000);
  delay(1);
  ir_valL = digitalRead(Sensor_Left);
  if (ir_valL == 0) { distanceL = 2; }
  else
  {
    tone(IR_LED_Left, 55000);
    delay(1);
    ir_valL = digitalRead(Sensor_Left);
    if (ir_valL == 0) { distanceL = 3; }
    else
    {
      tone(IR_LED_Left, 45000);
      delay(1);
      ir_valL = digitalRead(Sensor_Left);
      if (ir_valL == 0) { distanceL = 4; }
      else
      {
        tone(IR_LED_Left, 44000);
        delay(1);
        ir_valL = digitalRead(Sensor_Left);
        if (ir_valL == 0) { distanceL = 5; }
        else
        {
          tone(IR_LED_Left, 40000);
          delay(1);
          ir_valL = digitalRead(Sensor_Left);
          if (ir_valL == 0) { distanceL = 6; }
          else 
          { 
            tone(IR_LED_Left, 39000);
            delay(1);
            ir_valL = digitalRead(Sensor_Left);
            if (ir_valL == 0) { distanceL = 8; }
            else
            {
              tone(IR_LED_Left, 38000);
              delay(1);
              ir_valL = digitalRead(Sensor_Left);
              if (ir_valL == 0) { distanceL = 10; }
              else { distanceL = 11;}
            }
          } 
        }
      }
    }
  }

  noTone(IR_LED_Left);
  return distanceL;
}

int find_distance_right() //done
{
  tone(IR_LED_Right, 65000);
  delay(1);
  ir_valR = digitalRead(Sensor_Right);
  if (ir_valR == 0) { distanceR = 2; }
  else
  {
    tone(IR_LED_Right, 55000);
    delay(1);
    ir_valR = digitalRead(Sensor_Right);
    if (ir_valR == 0) { distanceR = 3; }
    else
    {
      tone(IR_LED_Right, 45000);
      delay(1);
      ir_valR = digitalRead(Sensor_Right);
      if (ir_valR == 0) { distanceR = 4; }
      else
      {
        tone(IR_LED_Right, 43000);
        delay(1);
        ir_valR = digitalRead(Sensor_Right);
        if (ir_valR == 0) { distanceR = 5; }
        else
        {
          tone(IR_LED_Right, 42000);
          delay(1);
          ir_valR = digitalRead(Sensor_Right);
          if (ir_valR == 0) { distanceR = 6; }
          else 
          {
            tone(IR_LED_Right, 40000);
          	delay(1);
          	ir_valR = digitalRead(Sensor_Right);
          	if (ir_valR == 0) { distanceR = 7; }
            else 
            {
              tone(IR_LED_Right, 39000);
              delay(1);
              ir_valR = digitalRead(Sensor_Right);
              if (ir_valR == 0) { distanceR = 8; }
              else 
              {
                tone(IR_LED_Right, 38000);
                delay(1);
                ir_valR = digitalRead(Sensor_Right);
                if (ir_valR == 0) { distanceR = 9; }
                else {distanceR = 10;}
                 
            
              }
            }
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
  tone(IR_LED_Front, 65000);
  delay(1);
  ir_valF = digitalRead(Sensor_Front);
  if (ir_valF == 0) { distanceF = 2; }
  else
  {
    tone(IR_LED_Front, 55000);
    delay(1);
    ir_valF = digitalRead(Sensor_Front);
    if (ir_valF == 0) { distanceF = 3; }
    else
    {
      tone(IR_LED_Front, 45000);
      delay(1);
      ir_valF = digitalRead(Sensor_Front);
      if (ir_valF == 0) { distanceF = 4; }
      else
      {
        tone(IR_LED_Front, 43000);
        delay(1);
        ir_valF = digitalRead(Sensor_Front);
        if (ir_valF == 0) { distanceF = 5; }
        else
        {
          tone(IR_LED_Front, 42000);
          delay(1);
          ir_valF = digitalRead(Sensor_Front);
          if (ir_valF == 0) { distanceF = 6; }
          else 
          {
            tone(IR_LED_Front, 41000);
          	delay(1);
          	ir_valF = digitalRead(Sensor_Front);
          	if (ir_valF == 0) { distanceF = 7; }
          	else 
            {
              tone(IR_LED_Front, 40000);
          	  delay(1);
          	  ir_valF = digitalRead(Sensor_Front);
          	  if (ir_valF == 0) { distanceF = 8; }
              else {
                tone(IR_LED_Front, 39000);
                delay(1);
                ir_valF = digitalRead(Sensor_Front);
                if (ir_valF == 0) { distanceF = 10; }
                else 
                {
                  tone(IR_LED_Front, 38000);
                  delay(1);
                  ir_valF = digitalRead(Sensor_Front);
                  if (ir_valF == 0) { distanceF = 11; }
                  else {distanceF = 12;}
                }
              }
            }
          }
        }
      }
    }
  }

  noTone(IR_LED_Front);
  return distanceF;
}
