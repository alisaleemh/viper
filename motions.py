import os
import math
import xlwt

def serpentineForward(wb):

    ws = wb.add_sheet('SerpentineForward')
    lag = .5712 # Phase lag between segments
    frequency = 1 # Oscillation frequency of segments.
    amplitude = 40 # Amplitude of the serpentine motion of the snake
    rightOffset = 5 # Right turn offset
    leftOffset = -5 # Left turn offset
    offset = 6 # Variable to correct servos that are not exactly centered
    delayTime = 7 # Delay between limb movements
    startPause = 5000  # Delay time to position robot
    test = -3 # Test varialble takes values from -6 to +5
    # headers in tab
    ws.write(0,0, "Counter (Loop Variable)")

    for motor in range(1,14):
        ws.write(0, motor, "Motor %s" % motor)

    for counter in range(0,360):
        ws.write(counter+1, 0, counter)
        ws.write(counter+1, 1, 90+offset+amplitude*math.cos(frequency*counter*math.pi/180+5*lag))
        ws.write(counter+1, 2, 90+offset+amplitude*math.cos(frequency*counter*math.pi/180+4*lag))
        ws.write(counter+1, 3, 90+offset+amplitude*math.cos(frequency*counter*math.pi/180+3*lag))
        ws.write(counter+1, 4, 90+amplitude*math.cos(frequency*counter*math.pi/180+2*lag))
        ws.write(counter+1, 5, 90+amplitude*math.cos(frequency*counter*math.pi/180+1*lag))
        ws.write(counter+1, 6, 90+amplitude*math.cos(frequency*counter*math.pi/180+0*lag))
        ws.write(counter+1, 7, 90+amplitude*math.cos(frequency*counter*math.pi/180-1*lag))
        ws.write(counter+1, 8, 90+amplitude*math.cos(frequency*counter*math.pi/180-2*lag))
        ws.write(counter+1, 9, 90+amplitude*math.cos(frequency*counter*math.pi/180-3*lag))
        ws.write(counter+1, 10, 90+amplitude*math.cos(frequency*counter*math.pi/180-4*lag))
        ws.write(counter+1, 11, 90+amplitude*math.cos(frequency*counter*math.pi/180-5*lag))
        ws.write(counter+1, 12, 90+amplitude*math.cos(frequency*counter*math.pi/180-6*lag))
        ws.write(counter+1, 13, 75+(15*math.cos(frequency*counter*math.pi/180-(-2*lag+math.pi/2))))


    wb.save('Motions.xls')

    return


def sidewindingRight(wb):

    ws = wb.add_sheet('SidewindingRight')

    counter = 0; # Loop counter variable
    lag = 1.5; # Phase lag between segments
    frequency = 1; # Oscillation frequency of segments.
    ampHor = 40; # Horizontal amplitude of the Sidewind motion of the snake
    ampVert = 40; # Vertical amplitude of Sidewind motion of the snake
    offset = 0;
    delayTime = 7; # Delay between limb movements
    startPause = 5000;  # Delay time
    ws.write(0,0, "Counter (Loop Variable)")

    for motor in range(1,12):
        ws.write(0, motor, "Motor %s" % motor)

    for counter in range (0,360):
        ws.write(counter+1, 0, counter)
        ws.write(counter+1, 1, 90+offset+ampHor*math.cos(frequency*counter*math.pi/180-0*lag));
        ws.write(counter+1, 3, 90+offset+ampHor*math.cos(frequency*counter*math.pi/180-1.25*lag));
        ws.write(counter+1, 5, 90+offset+ampHor*math.cos(frequency*counter*math.pi/180-2.5*lag));
        ws.write(counter+1, 7, 90+offset+ampHor*math.cos(frequency*counter*math.pi/180-3.75*lag));
        ws.write(counter+1, 9, 90+offset+ampHor*math.cos(frequency*counter*math.pi/180-5*lag));
        ws.write(counter+1, 2, 90+offset+ampVert*math.cos(frequency*counter*math.pi/180-0*lag));
        ws.write(counter+1, 4, 90+offset+ampVert*math.cos(frequency*counter*math.pi/180-1.25*lag));
        ws.write(counter+1, 6, 90+offset+ampVert*math.cos(frequency*counter*math.pi/180-2.5*lag));
        ws.write(counter+1, 8, 90+offset+ampVert*math.cos(frequency*counter*math.pi/180-3.75*lag));
        ws.write(counter+1, 10, 90+offset+ampVert*math.cos(frequency*counter*math.pi/180-5*lag));

    wb.save('Motions.xls')

    return


def sidewindingLeft(wb):

    ws = wb.add_sheet('SidewindingLeft')

    counter = 0; # Loop counter variable
    lag = 1.5; # Phase lag between segments
    frequency = 1; # Oscillation frequency of segments.
    ampHor = 40; # Horizontal amplitude of the Sidewind motion of the snake
    ampVert = 40; # Vertical amplitude of Sidewind motion of the snake
    offset = 0;
    delayTime = 7; # Delay between limb movements
    startPause = 5000;  # Delay time
    ws.write(0,0, "Counter (Loop Variable)")

    for motor in range(1,12):
        ws.write(0, motor, "Motor %s" % motor)

    for counter in range (0,360):
        ws.write(counter+1, 0, counter)
        ws.write(counter+1, 1, 90-(offset+ampHor*math.cos(frequency*counter*math.pi/180-0*lag)))
        ws.write(counter+1, 3, 90-(offset+ampHor*math.cos(frequency*counter*math.pi/180-1.25*lag)))
        ws.write(counter+1, 5, 90-(offset+ampHor*math.cos(frequency*counter*math.pi/180-2.5*lag)))
        ws.write(counter+1, 7, 90-(offset+ampHor*math.cos(frequency*counter*math.pi/180-3.75*lag)))
        ws.write(counter+1, 9, 90-(offset+ampHor*math.cos(frequency*counter*math.pi/180-5*lag)))
        ws.write(counter+1, 2, 90-(offset+ampVert*math.cos(frequency*counter*math.pi/180-0*lag)))
        ws.write(counter+1, 4, 90-(offset+ampVert*math.cos(frequency*counter*math.pi/180-1.25*lag)))
        ws.write(counter+1, 6, 90-(offset+ampVert*math.cos(frequency*counter*math.pi/180-2.5*lag)))
        ws.write(counter+1, 8, 90-(offset+ampVert*math.cos(frequency*counter*math.pi/180-3.75*lag)))
        ws.write(counter+1, 10, 90-(offset+ampVert*math.cos(frequency*counter*math.pi/180-5*lag)))

    wb.save('Motions.xls')

    return
