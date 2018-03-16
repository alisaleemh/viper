/*
Sidewind motion for a snake robot with 12 segments
*/

// #include <Servo.h>
// #include <XBOXRECV.h>
// #include <SPI.h>

// // Satisfy the IDE, which needs to see the include statment in the ino too.
// #ifdef dobogusinclude
// #include <spi4teensy3.h>
// #endif
//
// void Sidewind();
// void SidewindInitial();
// void Rectilinear();
// void RectilinearInitial();
//
// // Define servo objects for the snake segments
// Servo s1;
// Servo s2;
// Servo s3;
// Servo s4;
// Servo s5;
// Servo s6;
// Servo s7;
// Servo s8;
// Servo s9;
// Servo s10;
// Servo s11;
// Servo s12;
//
//
// // USB host and XBOX controller
// USB Usb;
// XBOXRECV Xbox(&Usb);
//
//
// // Define variables
// int counter = 0; // Loop counter variable
// float lag = 1.5; // Phase lag between segments
// int frequency = 1; // Oscillation frequency of segments.
// int ampHor = 40; // Horizontal amplitude of the Sidewind motion of the snake
// int ampVert = 40; // Vertical amplitude of Sidewind motion of the snake
// int offset = 0;
// int delayTime = 7; // Delay between limb movements
// int startPause = 5000;  // Delay time to position robot
//
//
// void setup()
// {
//     Serial.begin(115200);
//     #if !defined(__MIPSEL__)
//     while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
//     #endif
//     if (Usb.Init() == -1) {
//         Serial.print(F("\r\nOSC did not start"));
//         while (1); //halt
//     }
//     Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
//
//
//
//
//
//
//     // Attach segments to pins
//     s1.attach(2);
//     s2.attach(3);
//     s3.attach(4);
//     s4.attach(5);
//     s5.attach(6);
//     s6.attach(7);
//     s7.attach(8);
//     s8.attach(9);
//     s9.attach(10);
//     s10.attach(11);
//     s11.attach(12);
//     s12.attach(13);
//
//     //Put snake in starting position
//     s1.write(90+ampHor*cos(0*lag));
//     s3.write(90+ampHor*cos(1.25*lag));
//     s5.write(90+ampHor*cos(2.5*lag));
//     //s7.write(90+ampHor*cos(3.142/2));
//     s7.write(0);
//     s9.write(90+ampHor*cos(5*lag));
//     //s11.write(90+ampHor*cos(5*lag));
//
//     s2.write(90+ampVert*cos(0*lag));
//     s4.write(90+ampVert*cos(1.25*lag));
//     s6.write(90+ampVert*cos(2.5*lag));
//     s8.write(90+ampVert*cos(3.75*lag));
//     s10.write(90+ampVert*cos(5*lag));
//     //s12.write(90+ampVert*cos(5*lag));
//
//     delay(startPause);  // Pause to position robot
// }
//
// void loop() {
//   Usb.Task();
//   if (Xbox.XboxReceiverConnected) {
//     for (uint8_t i = 0; i < 4; i++) {
//       if (Xbox.Xbox360Connected[i]) {
//         if (Xbox.getButtonPress(L2, i) || Xbox.getButtonPress(R2, i)) {
//           Serial.print("L2: ");
//           Serial.print(Xbox.getButtonPress(L2, i));
//           Serial.print("\tR2: ");
//           Serial.println(Xbox.getButtonPress(R2, i));
//           Xbox.setRumbleOn(Xbox.getButtonPress(L2, i), Xbox.getButtonPress(R2, i), i);
//         }
//
//         if (Xbox.getAnalogHat(LeftHatX, i) > 7500 || Xbox.getAnalogHat(LeftHatX, i) < -7500 || Xbox.getAnalogHat(LeftHatY, i) > 7500 || Xbox.getAnalogHat(LeftHatY, i) < -7500 || Xbox.getAnalogHat(RightHatX, i) > 7500 || Xbox.getAnalogHat(RightHatX, i) < -7500 || Xbox.getAnalogHat(RightHatY, i) > 7500 || Xbox.getAnalogHat(RightHatY, i) < -7500) {
//           if (Xbox.getAnalogHat(LeftHatX, i) > 7500 || Xbox.getAnalogHat(LeftHatX, i) < -7500) {
//             Serial.print(F("LeftHatX: "));
//             Serial.print(Xbox.getAnalogHat(LeftHatX, i));
//             Serial.print("\t");
//           }
//           if (Xbox.getAnalogHat(LeftHatY, i) > 7500 || Xbox.getAnalogHat(LeftHatY, i) < -7500) {
//             Serial.print(F("LeftHatY: "));
//             Serial.print(Xbox.getAnalogHat(LeftHatY, i));
//             Serial.print("\t");
//           }
//           if (Xbox.getAnalogHat(RightHatX, i) > 7500 || Xbox.getAnalogHat(RightHatX, i) < -7500) {
//             Serial.print(F("RightHatX: "));
//             Serial.print(Xbox.getAnalogHat(RightHatX, i));
//             Serial.print("\t");
//           }
//           if (Xbox.getAnalogHat(RightHatY, i) > 7500 || Xbox.getAnalogHat(RightHatY, i) < -7500) {
//             Serial.print(F("RightHatY: "));
//             Serial.print(Xbox.getAnalogHat(RightHatY, i));
//           }
//           Serial.println();
//         }
//
//         if (Xbox.getButtonClick(UP, i)) {
//           Xbox.setLedOn(LED1, i);
//           Serial.println(F("Up"));
//         }
//         if (Xbox.getButtonClick(DOWN, i)) {
//           Xbox.setLedOn(LED4, i);
//           Serial.println(F("Down"));
//         }
//         if (Xbox.getButtonClick(LEFT, i)) {
//           Xbox.setLedOn(LED3, i);
//           Serial.println(F("Left"));
//         }
//         if (Xbox.getButtonClick(RIGHT, i)) {
//           Xbox.setLedOn(LED2, i);
//           Serial.println(F("Right"));
//         }
//
//         if (Xbox.getButtonClick(START, i)) {
//           Xbox.setLedMode(ALTERNATING, i);
//           Serial.println(F("Start"));
//         }
//         if (Xbox.getButtonClick(BACK, i)) {
//           Xbox.setLedBlink(ALL, i);
//           Serial.println(F("Back"));
//         }
//         if (Xbox.getButtonClick(L3, i))
//           Serial.println(F("L3"));
//         if (Xbox.getButtonClick(R3, i))
//           Serial.println(F("R3"));
//
//         if (Xbox.getButtonClick(L1, i))
//           Serial.println(F("L1"));
//         if (Xbox.getButtonClick(R1, i))
//           Serial.println(F("R1"));
//         if (Xbox.getButtonClick(XBOX, i)) {
//           Xbox.setLedMode(ROTATING, i);
//           Serial.print(F("Xbox (Battery: "));
//           Serial.print(Xbox.getBatteryLevel(i)); // The battery level in the range 0-3
//           Serial.println(F(")"));
//         }
//         if (Xbox.getButtonClick(SYNC, i)) {
//           Serial.println(F("Sync"));
//           Xbox.disconnect(i);
//         }
//
//         if (Xbox.getButtonClick(A, i))
//           Serial.println(F("A"));
//         if (Xbox.getButtonClick(B, i))
//           Serial.println(F("B"));
//         if (Xbox.getButtonClick(X, i))
//           Serial.println(F("X"));
//         if (Xbox.getButtonClick(Y, i))
//           Serial.println(F("Y"));
//       }
//     }
//   }
// }
//
// // void loop()
// // {
// //     Usb.Task();
// //     if (Xbox.XboxReceiverConnected)
// //     {
// for (uint8_t i = 0; i < 4; i++)
// {
//     if (Xbox.Xbox360Connected[i])
//     {
//         // right turn
//         if (Xbox.getButtonClick(RIGHT, i) || Xbox.getButtonClick(X, i))
//         {
//             SidewindInitial();
//             Sidewind();
//         }
//         if (Xbox.getButtonClick(LEFT, i) || Xbox.getButtonClick(B, i))
//         {
//             Sidewind();
//         }
//         if (Xbox.getButtonClick(UP, i) || Xbox.getButtonClick(Y, i))
//         {
//             Rectilinear();
//         }
//         if (Xbox.getButtonClick(DOWN, i) || Xbox.getButtonClick(A, i))
//         {
//             Rectilinear();
//         }
//     }
// }
// //     }
// // }
//


// }
// void Sidewind ()
// {
//     for(counter = 0; counter < 360; counter += 1)  {
//         delay(delayTime);
//         s1.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-0*lag));
//         s3.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-1.25*lag));
//         s5.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-2.5*lag));
//         s7.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-3.75*lag));
//         s9.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-5*lag));
//         //s11.write(90+offset+ampHor*cos(frequency*counter*3.14159/180-5*lag));
//
//         s2.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-0*lag));
//         s4.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-1.25*lag));
//         s6.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-2.5*lag));
//         s8.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-3.75*lag));
//         s10.write(90+offset+ampVert*cos(frequency*counter*3.14159/180-5*lag));
//     }
// }
//
// void Rectilinear()
// {
//
// }

/*
Example sketch for the Xbox Wireless Reciver library - developed by Kristian Lauszus
It supports up to four controllers wirelessly
For more information see the blog post: http://blog.tkjelectronics.dk/2012/12/xbox-360-receiver-added-to-the-usb-host-library/ or
send me an e-mail:  kristianl@tkjelectronics.com
*/
/*
Example sketch for the Xbox Wireless Reciver library - developed by Kristian Lauszus
It supports up to four controllers wirelessly
For more information see the blog post: http://blog.tkjelectronics.dk/2012/12/xbox-360-receiver-added-to-the-usb-host-library/ or
send me an e-mail:  kristianl@tkjelectronics.com
*/
//
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

const char SIDEWINDR = 'r';
const char SIDEWINDL = 'l';
// Define variables
int counter = 0; // Loop counter variable
float lag = 1.5; // Phase lag between segments
int frequency = 1; // Oscillation frequency of segments.
int ampHor = 40; // Horizontal amplitude of the Sidewind motion of the snake
int ampVert = 40; // Vertical amplitude of Sidewind motion of the snake
int offset = 0;
int delayTime = 7; // Delay between limb movements
int startPause = 5000;  // Delay time to position robot

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
                    Serial.println(F("L2"));
                    Sidewind(SIDEWINDR);
                }

                if (Xbox.getButtonClick(DOWN, i)) {
                    SidewindInitial();
                    Xbox.setLedOn(LED4, i);
                    Serial.println(F("Setting Init Pos"));
                }
            }
        }
    }
}

void Sidewind(char direction) {

    if (direction == SIDEWINDR) {
        Serial.println("SIDEWINDING TO THE RIGHT BITCH");
        for(counter = 0; counter < 360; counter += 1)  {
            delay(delayTime);
            s1.write(90-offset+ampHor*cos(frequency*counter*3.14159/180-0*lag));
            s3.write(90-offset+ampHor*cos(frequency*counter*3.14159/180-1.25*lag));
            s5.write(90-offset+ampHor*cos(frequency*counter*3.14159/180-2.5*lag));
            s7.write(90-offset+ampHor*cos(frequency*counter*3.14159/180-3.75*lag));
            s9.write(90-offset+ampHor*cos(frequency*counter*3.14159/180-5*lag));

            s2.write(90-offset+ampVert*cos(frequency*counter*3.14159/180-0*lag));
            s4.write(90-offset+ampVert*cos(frequency*counter*3.14159/180-1.25*lag));
            s6.write(90-offset+ampVert*cos(frequency*counter*3.14159/180-2.5*lag));
            s8.write(90-offset+ampVert*cos(frequency*counter*3.14159/180-3.75*lag));
            s10.write(90-offset+ampVert*cos(frequency*counter*3.14159/180-5*lag));
        }
    }
    else if (direction == SIDEWINDL) {
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
}

void SidewindInitial()
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
