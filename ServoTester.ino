// Ugly Servo Tester
/*
   Hitting 'q' and all after you hit 'enter' will take 100 uS off the pulse width of the servo on pin 9
   'e' will add 100 uS
   'a' will -10 uS, 'd' will +10 uS
   'z' will -1 uS, 'd' will +1 uS
   Every time you change the pulse width, the Serial port will print
*/
int servoPin = 9;
void setup() {
  Serial.begin(9600);
  Serial.println("ServoTester  Josh Brown 2016");
  Serial.println("Will begin with 1500 uS pulses at 50 Hz");
  Serial.println("'q' = decrement 100 uS");
  Serial.println("'e' = increment 100 uS");
  Serial.println("'a' = decrement 10 uS");
  Serial.println("'d' = increment 10 uS");
  Serial.println("'z' = decrement 1 uS");
  Serial.println("'c' = increment 1 uS");
  Serial.println("return = execute change");
  Serial.println("'h' = print help!");
  pinMode(servoPin, OUTPUT);
}

// Hex 0 Servo: 500 to 2324
// Hex 1 Servo: 540 to 2620 with hardstop still installed, could go further

int pos = 1500;

void loop() {
  if (Serial.available() > 0) {
    switch ( Serial.read() ) {
      case 'q':
        pos -= 100;
        Serial.println( pos );
        break;
      case 'e':
        pos += 100;
        Serial.println( pos );
        break;
      case 'a':
        pos -= 10;
        Serial.println( pos );
        break;
      case 'd':
        pos += 10;
        Serial.println( pos );
        break;
      case 'z':
        pos -= 1;
        Serial.println( pos );
        break;
      case 'c':
        pos += 1;
        Serial.println( pos );
        break;
      case 'h':
        Serial.println("ServoTester Help!");
        Serial.println("Initially the Servo will be pulsed at 50 Hz with a 1500 uS pulse.  For most");
        Serial.println("applications this will command a servo to go to center position.  To incre-");
        Serial.println("ment and decrement position, you use the Serial Monitor tool, or an app like");
        Serial.println("puTTY, to send letters.  Each change of servo position will return the cur-");
        Serial.println("rent postion to the terminal.  For a larger change, you can enter multiple");
        Serial.println("characters in a string to the terminal, for instance 'qqq' would decrement");
        Serial.println("servo position pulse by 300 uS.");
        Serial.println("'q' = decrement 100 uS");
        Serial.println("'e' = increment 100 uS");
        Serial.println("'a' = decrement 10 uS");
        Serial.println("'d' = increment 10 uS");
        Serial.println("'z' = decrement 1 uS");
        Serial.println("'c' = increment 1 uS");
        Serial.println("return = execute change");
        Serial.println("'h' = print help!");
        break;
      case '\n':
        break;
      default:
        Serial.println("Unknown Command");
        break;
    }
  }
  digitalWrite(servoPin, HIGH);
  delayMicroseconds( pos );
  digitalWrite(servoPin, LOW);
  delay( 20 );
}

