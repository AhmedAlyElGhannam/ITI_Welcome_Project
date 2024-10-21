const int pwmMotorA = 5;
const int pwmMotorB = 4;
const int dirMotorA = 0;
const int dirMotorB = 2;

int motorSpeed = 500;

void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(pwmMotorA , OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);

  Serial.println("Motor SHield 12E Initialized");
  delay(5000);
}

// A WORKS BUT B DOES NOT FOR SOME REASON
void loop() {
  Serial.println("Activate A");
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, 1);
  delay(1500);

  Serial.println("Reverse A");
  digitalWrite(dirMotorA, 0);
  delay(1500);

  Serial.println("Stop A");
  digitalWrite(pwmMotorA, 0);
  digitalWrite(dirMotorA, LOW);
  delay(3000);

  Serial.println("Activate B");
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, 1);
  delay(1500);

  Serial.println("Reverse B");
  digitalWrite(dirMotorB, 0);
  delay(1500);

  Serial.println("Stop B");
  digitalWrite(pwmMotorB, 0);
  digitalWrite(dirMotorB, LOW);
  delay(3000);
}
