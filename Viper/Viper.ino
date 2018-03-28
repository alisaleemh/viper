#include <Servo.h>

#include <XBOXRECV.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>


//void Sidewind();
//void SidewindInitial();

USB Usb;
XBOXRECV Xbox(&Usb);

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

const int INIT = 1;

const int SIDEWINDR = 2;
const int SIDEWINDL = 3;

const int SERPFORWARD = 4;
const int SERPLEFT = 5;
const int SERPRIGHT = 6;
const int SERPBACK = 7;

const int LEFTTURN = 8;
const int RIGHTTURN = 9;


void setup() {
    Serial.begin(115200);
    #if !defined(__MIPSEL__)
    while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
    #endif
    if (Usb.Init() == -1) {
        Serial.print(F("\r\nOSC did not start"));
        while (1); //halt
    }
    Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
    // Attach segments to pins
    s1.attach(22);
    s2.attach(23);
    s3.attach(24);
    s4.attach(25);
    s5.attach(26);
    s6.attach(27);
    s7.attach(28);
    s8.attach(29);
    s9.attach(30);
    s10.attach(31);
}
void loop() {
    Usb.Task();
    if (Xbox.XboxReceiverConnected) {
        for (uint8_t i = 0; i < 4; i++) {
            if (Xbox.Xbox360Connected[i]) {
                if(Xbox.getButtonClick(L2, i))
                {
                    Serial.println(Xbox.getButtonClick(L2,i));
                    Serial.println(F("L2"));
                    Sidewind(SIDEWINDL);
                }

                if(Xbox.getButtonClick(R2, i))
                {
                    Serial.println(Xbox.getButtonClick(L2,i));
                    Serial.println(F("R2"));
                    Sidewind(SIDEWINDR);
                }

                if (Xbox.getButtonClick(DOWN, i)) {
                    Sidewind(INIT);
                    Serial.println(F("Setting Init Pos"));
                }
                if (Xbox.getButtonClick(A, i)) {
                    Serpentine(SERPFORWARD);
                    Serial.println(F("Serpentine Forward"));
                }

                if (Xbox.getButtonClick(Y, i)) {
                    Serpentine(INIT);
                    Serial.println(F("Serpentine Ifnit"));
                }

                if (Xbox.getButtonClick(B, i)) {

                    Turn(RIGHTTURN);
                    Serial.println(F("Turn Right"));
                }

                if (Xbox.getButtonClick(X, i)) {
                    Turn(LEFTTURN);
                    Serial.println(F("Turn Left"));
                }
            }
        }
    }
}

void Sidewind(const int function) {

    // Define variables
    int counter = 0; // Loop counter variable
    float lag = 1.5; // Phase lag between segments
    int frequency = 1; // Oscillation frequency of segments.
    int ampHor = 40; // Horizontal amplitude of the Sidewind motion of the snake
    int ampVert = 40; // Vertical amplitude of Sidewind motion of the snake
    int offset = 0;
    int delayTime = 7; // Delay between limb movements
    int startPause = 5000;  // Delay time to position robot

    if (function == SIDEWINDR) {
        Serial.println("SIDEWINDING TO THE RIGHT BITCH");
        for(counter = 0; counter < 360; counter += 1)  {
            delay(delayTime);
            s1.write(90-(offset+ampHor*cos(frequency*counter*3.14159/180-0*lag)));
            s3.write(90-(offset+ampHor*cos(frequency*counter*3.14159/180-1.25*lag)));
            s5.write(90-(offset+ampHor*cos(frequency*counter*3.14159/180-2.5*lag)));
            s7.write(90-(offset+ampHor*cos(frequency*counter*3.14159/180-3.75*lag)));
            s9.write(90-(offset+ampHor*cos(frequency*counter*3.14159/180-5*lag)));

            s2.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-0*lag));
            s4.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-1.25*lag));
            s6.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-2.5*lag));
            s8.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-3.75*lag));
            s10.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-5*lag));
        }
    }
    else if (function == SIDEWINDL) {
        Serial.println("SIDEWINDING TO THE LEFT BITCH");
        for(counter = 0; counter < 360; counter += 1)  {
            delay(delayTime);
            s1.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-0*lag));
            s3.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-1.25*lag));
            s5.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-2.5*lag));
            s7.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-3.75*lag));
            s9.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-5*lag));

            s2.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-0*lag));
            s4.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-1.25*lag));
            s6.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-2.5*lag));
            s8.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-3.75*lag));
            s10.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-5*lag));
        }
    }
    else if (function == INIT)
    {
        //Put snake in starting position
        s1.write(90+ampHor*cos(0*lag));
        s3.write(90+ampHor*cos(1*lag));
        s5.write(90+ampHor*cos(2*lag));
        s7.write(90+ampHor*cos(3*lag));
        s9.write(90+ampHor*cos(4*lag));

        s2.write(90+ampVert*cos(0*lag));
        s4.write(90+ampVert*cos(1*lag));
        s6.write(90+ampVert*cos(2*lag));
        s8.write(90+ampVert*cos(3*lag));
        s10.write(90+ampVert*cos(4*lag));
    }
}

void Serpentine(const int function)
{
    int counter = 0; // Loop counter variable
    float lag = .5712; // Phase lag between segments
    int frequency = 1; // Oscillation frequency of segments.
    int amplitude = 40; // Amplitude of the serpentine motion of the snake
    int amplitude7 = 5;
    int rightOffset = 5; // Right turn offset
    int leftOffset = -5; // Left turn offset
    int offset = 6; // Variable to correct servos that are not exactly centered
    int delayTime = 2; // Delay between limb movements
    int startPause = 5000;  // Delay time to position robot
    int test = -3; // Test varialble takes values from -6 to +5

    if (function == SERPFORWARD)
    {
        for(counter = 0; counter < 360; counter += 1)  {
            delay(delayTime);

            s2.write(90+offset+amplitude*cos(frequency*counter*3.14159/180+4*lag));
            s4.write(90+amplitude*cos(frequency*counter*3.14159/180+2*lag));
            s6.write(90+amplitude*cos(frequency*counter*3.14159/180+0*lag));
            s8.write(90+amplitude*cos(frequency*counter*3.14159/180-2*lag));
            s10.write(90+amplitude*cos(frequency*counter*3.14159/180-4*lag));

            s1.write(60);
            s3.write(120); //Set this motor to less than 90 for Forward motion
            s5.write(110);
            //s7.write(90+amplitude7*cos(frequency*counter*3.14159/180+2*lag));
            s7.write(75);
            s9.write(90); //Set this motor to less than 90 for Backward motion
        }
    }

    else if (function == INIT)
    {
        //Put snake in starting position
        s1.write(90);
        s3.write(90);
        s5.write(100);
        s7.write(110);
        s9.write(75);

        s2.write(90);
        s4.write(90);
        s6.write(90);
        s8.write(90);
        s10.write(90);

    }
}

void Turn(const int function) {

    int delayTime = 1000;

    s1.write(90);
    s2.write(90);
    s3.write(90);
    s4.write(90);
    s5.write(10);
    s6.write(90);
    s7.write(90);
    s8.write(90);
    s9.write(90);
    s10.write(90);

    delay(delayTime);

    s1.write(90);
    s2.write(90);
    s3.write(90);
    s4.write(90);
    //s5.write(90);
    s6.write(90);
    s7.write(90);
    s8.write(40);
    s9.write(90);
    s10.write(90);

    delay(delayTime);

    s1.write(90);
    s2.write(90);
    s3.write(90);
    s4.write(90);
    s5.write(90);
    s6.write(90);
    s7.write(90);
    //s8.write(90);
    s9.write(90);
    s10.write(90);

    delay(delayTime);

    s8.write(90);

    // s1.write(90);
    // s2.write(90);
    // s3.write(90);
    // s4.write(170);
    // s5.write(90);
    // s6.write(10);
    // s7.write(90);
    // s8.write(90);
    // s9.write(90);
    // s10.write(90);



}
