
// we can also use this idea for leftParallel

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

const int IR_LED_Left  = 10;
const int Sensor_Left  = 11;
const int IR_LED_Front = 6;
const int Sensor_Front = 7;
const int IR_LED_Right = 2;
const int Sensor_Right = 3;

const int Sensor_LED_Right = A0;
const int Sensor_LED_Front = A1;
const int Sensor_LED_Left = A2;

const int STOP = 1500;
const int FORWARD_LEFT = 1568;
const int FORWARD_RIGHT = 1432;
const int ANTICLOCKWISE = 1550;
const int CLOCKWISE = 1450;
const int REVERSE_LEFT = 1432;
const int REVERSE_RIGHT = 1568;

const int PARALLEL_THRESHOLD = 1; // in cm
const int INITIAL_DIFFERENCE = 2; // cm

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

  pinMode(IR_LED_Left, OUTPUT);
  pinMode(IR_LED_Front, OUTPUT);
  pinMode(IR_LED_Right, OUTPUT);

  pinMode(Sensor_Left, INPUT);
  pinMode(Sensor_Front, INPUT);
  pinMode(Sensor_Right, INPUT);

  pinMode(Sensor_LED_Right, OUTPUT);
  pinMode(Sensor_LED_Front, OUTPUT);
  pinMode(Sensor_LED_Left, OUTPUT);

  // we need right led A0 OFF, middle led A1 ON, left led A2 ON
  digitalWrite(Sensor_LED_Right, LOW);
  digitalWrite(Sensor_LED_Front, HIGH);
  digitalWrite(Sensor_LED_Left, HIGH);

  delay(2000);
}

// THIS IS STILL PSEUDOCODE, SORRY
void loop()
{
    IF left sees wall
    AND right sees wall
    AND front >= 10 cm
    AND left - right > PARALLEL_THRESHOLD:

        rotate clockwise

        WHILE abs(left - right) > PARALLEL_THRESHOLD:
            keep rotating clockwise

        move forward

        // Continue checking parallelism while moving

        WHILE not at corridor centre:
            adjust heading

        // If necessary
        reverse slightly

        STOP
}

// my sister wants to know how git works