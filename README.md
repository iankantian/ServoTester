# ServoTester
=======
Joshua Brown 2016

I needed a servo tester that could be controlled via serial command.
Servo motors typically are center postion with pulses of 1500 uS, and can sweep through about 90 degrees.
Sending serial 'q' will take 100 uS off the pulse width of the servo on pin 9
   'e' will add 100 uS
   'a' will -10 uS, 'd' will +10 uS
   'z' will -1 uS, 'd' will +1 uS
Every time you change the pulse width, the Serial port will print position, but on some serial terminals, simply typing the letter will execute, as the characters are sent immediately.

The use-case I have is commanding servos will beyond the range of 1000 to 2000 uS.  As I have some servos I need for 180 degree operation.  This was easier for me than modifying the position sensing potentiometer inside the servo housing.  However the complexity is that servos will then have slightly different end points, thus the need for this testing software to find them for each servo.

The servos I am using are the [Power HD1900 9 gram servo](http://www.hobbyking.com/hobbyking/store/__7471__Power_HD_1900A_Servo_1_7kg_0_08sec_9g.html).

=======

TODO:
Add some sweeping functions, so the servo can wiggle back and forth to show it's operation.

