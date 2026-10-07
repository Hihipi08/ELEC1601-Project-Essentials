#include <Servo.h>

Servo servoLeft;
Servo servoRight;

// LEDs
int LED_G_Left = 8;
int LED_G_Right = 4;
int LED_R_Left = 9;
int LED_R_Right = 5;

//LED variables
int LED_Left = 10;
int Sensor_Left = 11;

int LED_Front = 6;
int Sensor_Front = 7;

int IR_LED_Right = 2;
int Sensor_Right = 3;

// Sensor LEDs
int Sensor_LED_Left = A2;
int Sensor_LED_Front = A1;
int Sensor_LED_Right = A0;

// Variables
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

    pinMode(LED_Left, OUTPUT);
    pinMode(LED_Front, OUTPUT);
    pinMode(LED_Right, OUTPUT);

    pinMode(Sensor_Left, INPUT);
    pinMode(Sensor_Front, INPUT);
    pinMode(Sensor_Right, INPUT);

    pinMode(LED_G_Left, OUTPUT);
    pinMode(LED_G_Right, OUTPUT);
    pinMode(LED_R_Left, OUTPUT);
    pinMode(LED_R_Right, OUTPUT);

    // Start with robot stopped
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
}


void loop()
{
    // Measure distances
    distanceL = find_distance_left();
    distanceF = find_distance_front();
    distanceR = find_distance_right();

    // Display distances in Serial Monitor
    Serial.print("Left = ");
    Serial.print(distanceL);

    Serial.print(" Front = ");
    Serial.print(distanceF);

    Serial.print(" Right = ");
    Serial.println(distanceR);

    // CHECK REQUIRED WALL CONFIGURATION

    // Left wall is close
    // Front wall is close
    // Right side is open

    if (distanceL <= 3 &&
        distanceF <= 5 &&
        distanceR >= 8)
    {
        // Turn on red LEDs to indicate manoeuvre
        digitalWrite(LED_R_Left, HIGH);
        digitalWrite(LED_R_Right, HIGH);

        // TURN 90° CLOCKWISE
  
        servoLeft.writeMicroseconds(1550);
        servoRight.writeMicroseconds(1550);

        delay(600);      // Calibrate for 90°

        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);

        delay(200);
        // TURN ANOTHER 30° CLOCKWISE
        servoLeft.writeMicroseconds(1550);
        servoRight.writeMicroseconds(1550);

        delay(200);      // Calibrate for 30°

        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);

        delay(200);
      
        // MOVE FORWARD 5 cm
        servoLeft.writeMicroseconds(1600);
        servoRight.writeMicroseconds(1400);

        delay(400);      // Calibrate for 5 cm

        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);

        delay(200);
        // TURN 30° ANTICLOCKWISE
        servoLeft.writeMicroseconds(1450);
        servoRight.writeMicroseconds(1450);

        delay(200);      // Calibrate for 30°

        servoLeft.writeMicroseconds(1500);
        servoRight.writeMicroseconds(1500);

        delay(200);
        // CONTINUE TRAVELLING STRAIGHT

        servoLeft.writeMicroseconds(1600);
        servoRight.writeMicroseconds(1400);
    }
}
// LEFT DISTANCE SENSOR

int find_distance_left()
{
    tone(LED_Left, 65000);
    delay(1);
    ir_valL = digitalRead(Sensor_Left);

    if (ir_valL == 0)
    {
        distanceL = 2;
    }
    else
    {
        tone(LED_Left, 55000);
        delay(1);
        ir_valL = digitalRead(Sensor_Left);

        if (ir_valL == 0)
        {
            distanceL = 3;
        }
        else
        {
            tone(LED_Left, 45000);
            delay(1);
            ir_valL = digitalRead(Sensor_Left);

            if (ir_valL == 0)
            {
                distanceL = 4;
            }
            else
            {
                tone(LED_Left, 44000);
                delay(1);
                ir_valL = digitalRead(Sensor_Left);

                if (ir_valL == 0)
                {
                    distanceL = 5;
                }
                else
                {
                    tone(LED_Left, 40000);
                    delay(1);
                    ir_valL = digitalRead(Sensor_Left);

                    if (ir_valL == 0)
                    {
                        distanceL = 6;
                    }
                    else
                    {
                        tone(LED_Left, 39000);
                        delay(1);
                        ir_valL = digitalRead(Sensor_Left);

                        if (ir_valL == 0)
                        {
                            distanceL = 8;
                        }
                        else
                        {
                            tone(LED_Left, 38000);
                            delay(1);
                            ir_valL = digitalRead(Sensor_Left);

                            if (ir_valL == 0)
                            {
                                distanceL = 10;
                            }
                            else
                            {
                                distanceL = 11;
                            }
                        }
                    }
                }
            }
        }
    }

    noTone(LED_Left);

    return distanceL;
}

// RIGHT DISTANCE SENSOR

int find_distance_right()
{
    tone(LED_Right, 65000);
    delay(1);
    ir_valR = digitalRead(Sensor_Right);

    if (ir_valR == 0)
    {
        distanceR = 2;
    }
    else
    {
        tone(LED_Right, 55000);
        delay(1);
        ir_valR = digitalRead(Sensor_Right);

        if (ir_valR == 0)
        {
            distanceR = 3;
        }
        else
        {
            tone(LED_Right, 45000);
            delay(1);
            ir_valR = digitalRead(Sensor_Right);

            if (ir_valR == 0)
            {
                distanceR = 4;
            }
            else
            {
                tone(LED_Right, 43000);
                delay(1);
                ir_valR = digitalRead(Sensor_Right);

                if (ir_valR == 0)
                {
                    distanceR = 5;
                }
                else
                {
                    tone(LED_Right, 42000);
                    delay(1);
                    ir_valR = digitalRead(Sensor_Right);

                    if (ir_valR == 0)
                    {
                        distanceR = 6;
                    }
                    else
                    {
                        tone(LED_Right, 40000);
                        delay(1);
                        ir_valR = digitalRead(Sensor_Right);

                        if (ir_valR == 0)
                        {
                            distanceR = 7;
                        }
                        else
                        {
                            tone(LED_Right, 39000);
                            delay(1);
                            ir_valR = digitalRead(Sensor_Right);

                            if (ir_valR == 0)
                            {
                                distanceR = 8;
                            }
                            else
                            {
                                tone(LED_Right, 38000);
                                delay(1);
                                ir_valR = digitalRead(Sensor_Right);

                                if (ir_valR == 0)
                                {
                                    distanceR = 9;
                                }
                                else
                                {
                                    distanceR = 10;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    noTone(LED_Right);

    return distanceR;
}

// FRONT DISTANCE SENSOR

int find_distance_front()
{
    tone(LED_Front, 65000);
    delay(1);
    ir_valF = digitalRead(Sensor_Front);

    if (ir_valF == 0)
    {
        distanceF = 2;
    }
    else
    {
        tone(LED_Front, 55000);
        delay(1);
        ir_valF = digitalRead(Sensor_Front);

        if (ir_valF == 0)
        {
            distanceF = 3;
        }
        else
        {
            tone(LED_Front, 45000);
            delay(1);
            ir_valF = digitalRead(Sensor_Front);

            if (ir_valF == 0)
            {
                distanceF = 4;
            }
            else
            {
                tone(LED_Front, 43000);
                delay(1);
                ir_valF = digitalRead(Sensor_Front);

                if (ir_valF == 0)
                {
                    distanceF = 5;
                }
                else
                {
                    tone(LED_Front, 42000);
                    delay(1);
                    ir_valF = digitalRead(Sensor_Front);

                    if (ir_valF == 0)
                    {
                        distanceF = 6;
                    }
                    else
                    {
                        tone(LED_Front, 41000);
                        delay(1);
                        ir_valF = digitalRead(Sensor_Front);

                        if (ir_valF == 0)
                        {
                            distanceF = 7;
                        }
                        else
                        {
                            tone(LED_Front, 40000);
                            delay(1);
                            ir_valF = digitalRead(Sensor_Front);

                            if (ir_valF == 0)
                            {
                                distanceF = 8;
                            }
                            else
                            {
                                tone(LED_Front, 39000);
                                delay(1);
                                ir_valF = digitalRead(Sensor_Front);

                                if (ir_valF == 0)
                                {
                                    distanceF = 10;
                                }
                                else
                                {
                                    tone(LED_Front, 38000);
                                    delay(1);
                                    ir_valF = digitalRead(Sensor_Front);

                                    if (ir_valF == 0)
                                    {
                                        distanceF = 11;
                                    }
                                    else
                                    {
                                        distanceF = 12;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    noTone(LED_Front);

    return distanceF;
}
