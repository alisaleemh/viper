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
int smoothnessDelay = 25;
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




    // Put snake in straight starting position
    s1.attach(31);
    s2.attach(30);
    s3.attach(29);
    s4.attach(28);
    s5.attach(27);
    s6.attach(26);
    s7.attach(25);
    s8.attach(24);
    s9.attach(23);
    s10.attach(22);



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
        s9.write(90-pos);
        s7.write(90+(2*pos));
        s5.write(90-pos);
        s3.write(90-(2*pos));
        delay(smoothnessDelay);
    }

    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     s9.write(90-flex+pos);
    //     s7.write(90+2*flex-3*pos);
    //     s5.write(90-flex+3*pos);
    //     s3.write(90-pos);
    //     delay(smoothnessDelay);
    // }
    //
    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     s9.write(90-flex+pos);
    //     s7.write(90+2*flex-3*pos);
    //     s5.write(90-flex+3*pos);
    //     s3.write(90-pos);
    //     delay(smoothnessDelay);
    // }
    //
    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     s7.write(90-flex+pos);
    //     s5.write(90+2*flex-3*pos);
    //     s3.write(90-flex+3*pos);
    //     s1.write(90-pos);
    //     delay(smoothnessDelay);
    // }

    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     //s5.write(90-flex+pos);
    //     s5.write(90+2*flex-3*pos);
    //     s3.write(90-flex+3*pos);
    //     s1.write(90-pos);
    //     delay(smoothnessDelay);
    // }
    //
    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     s7.write(90-flex+pos);
    //     s6.write(90+2*flex-3*pos);
    //     s5.write(90-flex+3*pos);
    //     s4.write(90-pos);
    //     delay(smoothnessDelay);
    // }
    //
    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     s6.write(90-flex+pos);
    //     s5.write(90+2*flex-3*pos);
    //     s4.write(90-flex+3*pos);
    //     s3.write(90-pos);
    //     delay(smoothnessDelay);
    // }
    //
    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     s5.write(90-flex+pos);
    //     s4.write(90+2*flex-3*pos);
    //     s3.write(90-flex+3*pos);
    //     s2.write(90-pos);
    //     delay(smoothnessDelay);
    // }
    //
    // delay(delayTime);
    // for(pos = 0; pos < flex; pos +=  1)
    // {
    //     s5.write(90-flex+pos);
    //     s3.write(90+2*flex-2*pos);
    //     s1.write(90-flex+pos);
    //     delay(smoothnessDelay);
    // }
    //

}
