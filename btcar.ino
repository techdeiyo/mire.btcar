char data = 0;  // Variable for storing received data
int speedA = 255; // Speed for motor A
int speedB = 255; // Speed for motor B

// Motor A connections
int enA = 5;
int in1 = 8;
int in2 = 9;

// Motor B connections
int enB = 6;
int in3 = 10;
int in4 = 11;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Start the serial communication to listen for commands
  Serial.begin(9600);
}

void loop() {
  // Check if any data is available to read
  if (Serial.available() > 0) {
    data = Serial.read();  // Read the incoming data

    // Control the motors based on the received data
    switch(data) {
      case 'F': // Move forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enA, speedA); // Adjust speed if needed
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enB, speedB); // Adjust speed if needed
        break;
      
      case 'B': // Move backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(enA, speedA); // Adjust speed if needed
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enB, speedB); // Adjust speed if needed
        break;

      case 'L': // Turn left
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(enA, speedA); // Adjust speed if needed
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enB, speedB); // Adjust speed if needed
        break;
        

      case 'R': // Turn right
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enA, speedA); // Adjust speed if needed
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enB, speedB); // Adjust speed if needed
        break;

      case 'S': // Stop
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        analogWrite(enB, 0);
        break;

      case '1': // Set speed to level 1
        setSpeedLevel(1);
        break;

      case '2': // Set speed to level 2
        setSpeedLevel(2);
        break;

      case '3': // Set speed to level 3
        setSpeedLevel(3);
        break;

      case '4': // Set speed to level 4
        setSpeedLevel(4);
        break;

      case '5': // Set speed to level 5
        setSpeedLevel(5);
        break;

      case '6': // Set speed to level 6
        setSpeedLevel(6);
        break;

      case '7': // Set speed to level 7
        setSpeedLevel(7);
        break;

      case '8': // Set speed to level 8
        setSpeedLevel(8);
        break;

      case '9': // Set speed to level 9
        setSpeedLevel(9);
        break;
    }
  }
}

void setSpeedLevel(int level) {
  // Map the level (1-9) to a PWM value (0-255)
  int pwmValue = map(level, 1, 9, 0, 255);
  speedA = pwmValue;
  speedB = pwmValue;
}

