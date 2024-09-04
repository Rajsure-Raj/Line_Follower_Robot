#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define echoPin 6 // Echo Pin
#define trigPin 7 // Trigger Pin

const int buzzer = A3;

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

const int motor1Pin = 8;
const int motor2Pin = 9;
const int motor3Pin = 10;
const int motor4Pin = 11;

int motor1State = 0;
int motor2State = 0;
int motor3State = 0;
int motor4State = 0;

const int ir1Pin = 4;
int ir1State = 0;

const int ir2Pin = 3;
int ir2State = 0;


void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ir1Pin, INPUT);
  pinMode(ir2Pin, INPUT);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  motor1State = LOW;
  motor2State = LOW;
  motor3State = LOW;
  motor4State = LOW;
  digitalWrite(motor1Pin, motor1State);
  digitalWrite(motor2Pin, motor2State);
  digitalWrite(motor3Pin, motor3State);
  digitalWrite(motor4Pin, motor4State);

  // initialize the LCD
  lcd.begin();
  lcd.print("LINE FOLLOWING");
  lcd.setCursor(0, 1); // Sets cursor at Column 0 and Line 1
  lcd.print("     ROBOT    ");
  delay(3000);
}

void loop()

{


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;

  Serial.println(distance);
  lcd.clear();
  lcd.print("Dist:");
  lcd.print(distance);
  delay(20);

  if (distance < 10)
  {
    motor1State = LOW;
    motor2State = LOW;
    motor3State = LOW;
    motor4State = LOW;
    digitalWrite(motor1Pin, motor1State);
    digitalWrite(motor2Pin, motor2State);
    digitalWrite(motor3Pin, motor3State);
    digitalWrite(motor4Pin, motor4State);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.print("Obstacle Detected");
    delay(5000);
    digitalWrite(buzzer, LOW);
  }


  ir1State = digitalRead(ir1Pin);
  ir2State = digitalRead(ir2Pin);

  if (ir1State == LOW && ir2State == HIGH)
  {
    motor1State = LOW;
    motor2State = HIGH;
    motor3State = HIGH;
    motor4State = LOW;
    digitalWrite(motor1Pin, motor1State);
    digitalWrite(motor2Pin, motor2State);
    digitalWrite(motor3Pin, motor3State);
    digitalWrite(motor4Pin, motor4State);
  }
  if (ir1State == HIGH && ir2State == LOW)
  {
    motor1State = HIGH;
    motor2State = LOW;
    motor3State = LOW;
    motor4State = HIGH;
    digitalWrite(motor1Pin, motor1State);
    digitalWrite(motor2Pin, motor2State);
    digitalWrite(motor3Pin, motor3State);
    digitalWrite(motor4Pin, motor4State);
  }

  if (ir1State == LOW && ir2State == LOW)
  {
    motor1State = LOW;
    motor2State = HIGH;
    motor3State = LOW;
    motor4State = HIGH;
    digitalWrite(motor1Pin, motor1State);
    digitalWrite(motor2Pin, motor2State);
    digitalWrite(motor3Pin, motor3State);
    digitalWrite(motor4Pin, motor4State);
  }


}
