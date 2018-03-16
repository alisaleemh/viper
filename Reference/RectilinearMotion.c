/*
Rectilinear motion file for 12 segment snake robot
*/


#include <Servo.h>

// Define servo objects for the snake segments
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;
Servo s7;
Servo s8;
Servo s9;
Servo s10;
Servo s11;
Servo s12;


// Define variables
int flex = 45; // Angle to flex a joint
int delayTime = 5; // Delay between limb movements
int startPause = 5000; // Delay to allow robot placement before movement
int pos = 0;  // Loop counter
int smoothnessDelay = 15;
int wheelState = 0;



int forwardPin =  15;
int wheelTogglePin = 16;
int leftPin = 17;
int rightPin = 18;

int forwardVal = 0;
int wheelToggleVal = 0;
int leftVal = 0;
int rightVal = 0;


void setup()
{
    // Set movement pins as inputs
    pinMode(forwardPin, INPUT);
    pinMode(wheelTogglePin, INPUT);
    pinMode(rightPin, INPUT);
    pinMode(leftPin, INPUT);

    // Set movement pins to low
    digitalWrite(forwardPin, LOW);
    digitalWrite(wheelTogglePin, LOW);
    digitalWrite(rightPin, LOW);
    digitalWrite(leftPin, LOW);

    // Attach segments to PWM pins
    s1.attach(2);
    s2.attach(3);
    s3.attach(4);
    s4.attach(5);
    s5.attach(6);
    s6.attach(7);
    s7.attach(8);
    s8.attach(9);
    s9.attach(10);
    s10.attach(11);
    s11.attach(12);
    s12.attach(13);


    // Put snake in straight starting position
    s1.write(0);
    s2.write(90);
    s3.write(90);
    s4.write(90);
    s5.write(90);
    s6.write(90);
    s7.write(90);
    s8.write(90);
    s9.write(90);
    s10.write(90);
    s11.write(90);
    s12.write(90);


    // Delay to give time to position robot
    delay(startPause);
}


void loop()
{
    //  Read movement pins
    forwardVal = digitalRead(forwardPin);
    wheelToggleVal = digitalRead(wheelTogglePin);
    rightVal = digitalRead(rightPin);
    leftVal = digitalRead(leftPin);

    // Forward motion

    for(pos = 0; pos < flex; pos +=  1)
    {
        s12.write(90-pos);
        s11.write(90+2*pos);
        s10.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s12.write(90-flex+pos);
        s11.write(90+2*flex-3*pos);
        s10.write(90-flex+3*pos);
        s9.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s11.write(90-flex+pos);
        s10.write(90+2*flex-3*pos);
        s9.write(90-flex+3*pos);
        s8.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s10.write(90-flex+pos);
        s9.write(90+2*flex-3*pos);
        s8.write(90-flex+3*pos);
        s7.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s9.write(90-flex+pos);
        s8.write(90+2*flex-3*pos);
        s7.write(90-flex+3*pos);
        s6.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s8.write(90-flex+pos);
        s7.write(90+2*flex-3*pos);
        s6.write(90-flex+3*pos);
        s5.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s7.write(90-flex+pos);
        s6.write(90+2*flex-3*pos);
        s5.write(90-flex+3*pos);
        s4.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s6.write(90-flex+pos);
        s5.write(90+2*flex-3*pos);
        s4.write(90-flex+3*pos);
        s3.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s5.write(90-flex+pos);
        s4.write(90+2*flex-3*pos);
        s3.write(90-flex+3*pos);
        s2.write(90-pos);
        delay(smoothnessDelay);
    }

    delay(delayTime);
    for(pos = 0; pos < flex; pos +=  1)
    {
        s4.write(90-flex+pos);
        s3.write(90+2*flex-2*pos);
        s2.write(90-flex+pos);
        delay(smoothnessDelay);
    }


}
