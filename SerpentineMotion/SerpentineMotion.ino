/*
Remote control file for serpentine motion
of a snake robot with 12 servos
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
int forwardPin = 14;  // Remote control movement pins
int reversePin = 15;
int rightPin = 16;
int leftPin = 17;

int forwardVal = 0;  // Remote control variables
int reverseVal = 0;
int rightVal = 0;
int leftVal = 0;

int counter = 0; // Loop counter variable
float lag = .5712; // Phase lag between segments
int frequency = 2; // Oscillation frequency of segments.
int amplitude = 40; // Amplitude of the serpentine motion of the snake
int amplitude7 = 5;
int rightOffset = 5; // Right turn offset
int leftOffset = -5; // Left turn offset
int offset = 6; // Variable to correct servos that are not exactly centered
int delayTime = 8; // Delay between limb movements
int startPause = 500;  // Delay time to position robot
int test = -3; // Test varialble takes values from -6 to +5

void setup()
{



    // Put snake in starting position
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

    // //Put snake in starting position
    // s1.write(90);
    // s2.write(90);
    // s3.write(90);
    // s4.write(90);
    // s5.write(90);
    s8.write(90);
    // s7.write(90);
    // s8.write(90);
    // s9.write(90);
    // s10.write(90);
    delay(startPause);  // Pause to position robot


}


void loop()
{
    //Forward motion
    for(counter = 0; counter < 360; counter += 1)  {
        delay(delayTime);

        // s1.write(110);
        // s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
        //s3.write(75+(15*+sin(frequency*counter*3.14159/180-(3.14159/2)))); //Set this motor to less than 90 for Forward motion
        // s3.write(70);
        // s4.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
        // s5.write(90);
        s8.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
        //s6.write(90);
        //s7.write(90+amplitude7*cos(frequency*counter*3.14159/180+2*lag));
        // s7.write(90);
        // s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));
        // s9.write(90); //Set this motor to less than 90 for Backward motion
        // s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    }
}

    // Reverse motion
    /*
    if (reverseVal == HIGH){
    for(counter = 360; counter > 0; counter -= 1)  {
    delay(delayTime);
    s1.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
    s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
    s3.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
    s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
    s5.write(90+amplitude*cos(frequency*counter*3.14159/180+1*lag));
    s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));
    s7.write(90+amplitude*cos(frequency*counter*3.14159/180-1*lag));
    s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));
    s9.write(90+amplitude*cos(frequency*counter*3.14159/180-3*lag));
    s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));
    s11.write(90+amplitude*cos(frequency*counter*3.14159/180-5*lag));
    s12.write(90+amplitude*cos(frequency*counter*3.14159/180-6*lag));
}
}

// Right turn
if (rightVal == HIGH){
// Ramp up turn offset
for(counter = 0; counter < 10; counter += 1)  {
delay(delayTime);
s1.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
s2.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
s3.write(90+offset+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
s4.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
s5.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
s6.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
s7.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
s8.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));
s9.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
s10.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
s11.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));
s12.write(90+.1*counter*rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));
}
// Continue right turn
for(counter = 11; counter < 350; counter += 1)  {
delay(delayTime);
s1.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
s2.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
s3.write(90+offset+rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
s4.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
s5.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
s6.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
s7.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
s8.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));
s9.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
s10.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
s11.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));
s12.write(90+rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));
}
// Ramp down turn offset
for(counter = 350; counter < 360; counter += 1)  {
delay(delayTime);
s1.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
s2.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
s3.write(90+offset+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
s4.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
s5.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
s6.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
s7.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
s8.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));
s9.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
s10.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
s11.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));
s12.write(90+.1*(360-counter)*rightOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));
}
}

// Left turn
if (leftVal == HIGH){
// Ramp up turn offset
for(counter = 0; counter < 10; counter += 1)  {
delay(delayTime);
s1.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
s2.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
s3.write(90+offset+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
s4.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
s5.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
s6.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
s7.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
s8.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));
s9.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
s10.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
s11.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));
s12.write(90+.1*counter*leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));
}
// Continue left turn
for(counter = 11; counter < 350; counter += 1)  {
delay(delayTime);
s1.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
s2.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
s3.write(90+offset+leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
s4.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
s5.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
s6.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
s7.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
s8.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));
s9.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
s10.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
s11.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));
s12.write(90+leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));
}
// Ramp down turn offset
for(counter = 350; counter < 360; counter += 1)  {
delay(delayTime);
s1.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+5*lag));
s2.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
s3.write(90+offset+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+3*lag));
s4.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+2*lag));
s5.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+1*lag));
s6.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180+0*lag));
s7.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-1*lag));
s8.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-2*lag));
s9.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-3*lag));
s10.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-4*lag));
s11.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-5*lag));
s12.write(90+.1*(360-counter)*leftOffset+amplitude*cos(frequency*counter*3.14159/180-6*lag));
}

// } */
