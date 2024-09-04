Line Following Robot with Obstacle Detection
This project is a simple line-following robot with an added obstacle detection feature using an ultrasonic sensor. The robot follows a black line on a white surface and stops when an obstacle is detected within a certain distance.

Hardware Components
Arduino (any model compatible with the libraries used)
L298N Motor Driver Module
DC Motors (x4)
Ultrasonic Sensor (HC-SR04)
IR Sensors (x2)
Buzzer
I2C LCD Display (16x2)
Power Supply
Connecting Wires
Chassis
Pin Configuration
Ultrasonic Sensor (HC-SR04)
Trig Pin: Pin 7
Echo Pin: Pin 6
Motor Driver (L298N)
Motor 1: Pin 8 (IN1), Pin 9 (IN2)
Motor 2: Pin 10 (IN3), Pin 11 (IN4)
IR Sensors
IR Sensor 1: Pin 4
IR Sensor 2: Pin 3
Buzzer
Buzzer Pin: Pin A3
LCD Display (16x2)
I2C Address: 0x27 (Default for most modules)
Code Explanation
Initialization:

The LCD is initialized and displays a welcome message.
Motor and sensor pins are set as inputs or outputs.
Loop:

The ultrasonic sensor measures the distance to any obstacle.
If an obstacle is detected within 10 cm, the robot stops, and the buzzer is triggered.
The IR sensors continuously check the line:
Left sensor active: Robot turns left.
Right sensor active: Robot turns right.
Both sensors active: Robot moves forward.
How to Use
Wiring: Connect the components as described in the pin configuration.
Upload the Code: Use the Arduino IDE to upload the provided code to your Arduino board.
Power On: Once everything is connected and powered, the robot will start following the line and avoid obstacles.
Notes
Ensure that the robot is placed on a surface with a clear black line for the IR sensors to detect.
Adjust the distance threshold in the code if needed (distance < 10).
Make sure the motors are connected correctly for the robot to move as intended.
Troubleshooting
Robot not moving: Check the motor connections and ensure the motor driver is receiving power.
Buzzer constantly on: This could indicate a faulty or misaligned ultrasonic sensor.
Line not detected: Ensure the IR sensors are calibrated and positioned correctly above the line.
Libraries Used
Wire.h: For I2C communication with the LCD.
LiquidCrystal_I2C.h: For controlling the LCD display.
License
This project is open-source and free to use under the MIT License. Feel free to modify and improve the code as needed.
