# Motor Control via Serial Communication

This Arduino project allows you to control the movement of a robot using serial communication. You can send commands to move the robot forward, backward, left, or right, as well as stop it and adjust its speed. The project uses two DC motors connected to an L298N motor driver.

## Features

- **Control Directions**: Move the robot forward, backward, left, or right.
- **Speed Control**: Adjust motor speed using a simple level system (1-9).
- **Stop Functionality**: Instantly stop the robot's movement.

## Components Required

- Arduino (e.g., Uno, Nano)
- L298N Motor Driver
- DC Motors (x2)
- Power Supply (for motors)
- Serial Communication Interface (e.g., USB cable)

## Pin Connections

### Motor A (Left Motor):
- **`enA`** (PWM control): Pin 5
- **`in1`** (Motor direction control): Pin 8
- **`in2`** (Motor direction control): Pin 9

### Motor B (Right Motor):
- **`enB`** (PWM control): Pin 6
- **`in3`** (Motor direction control): Pin 10
- **`in4`** (Motor direction control): Pin 11

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/techdeiyo/mire.btcar
   ```

2. **Upload the code to your Arduino:**
   - Open the `motor_control_serial.ino` file in the Arduino IDE.
   - Select your Arduino board and the correct COM port.
   - Upload the sketch.

3. **Connect your motors and power supply** as per the pin connections mentioned above.

## Usage

Once the code is uploaded, open the Serial Monitor in the Arduino IDE, set the baud rate to `9600`, and use the following commands:

- **`F`**: Move forward
- **`B`**: Move backward
- **`L`**: Turn left
- **`R`**: Turn right
- **`S`**: Stop movement
- **`1-9`**: Set speed level (1 is slowest, 9 is fastest)

### Example Commands

- To move forward at speed level 5:
  ```
  F
  5
  ```
- To turn right at the current speed:
  ```
  R
  ```
- To stop the robot:
  ```
  S
  ```

## Customization

- **Adjusting Speed**: Modify the `speedA` and `speedB` variables to set a default speed.
- **Expanding Commands**: You can expand the `switch-case` block in the `loop()` function to add more commands or actions.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
