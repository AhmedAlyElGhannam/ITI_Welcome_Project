// motor A (left)
const char motorA_pwm = 5;
const char motorA_dir = 0;

// motor B (right)
const char motorB_pwm = 4;
const char motorB_dir = 2;

// speed
int motor_speed = 250;

#define FORWARD   1
#define BACKWARD  0

void setup() 
{

    // Init serial
    Serial.begin(9600);
    Serial.setTimeout(5);

    // Config pins
    pinMode(motorA_dir, OUTPUT);
    pinMode(motorA_pwm, OUTPUT);
    pinMode(motorB_pwm, OUTPUT);
    pinMode(motorB_dir, OUTPUT);

}

void loop() {

    char codeReceived;
    String numericPart = "";

    while (Serial.available() > 0) {
        String line = Serial.readString();
        for (int i = 0; i < line.length(); i++) 
        {
            int character = line[i];
            if (isDigit(character)) 
            {
                numericPart += (char) character;
            } else if (character != '\n') 
            {
                codeReceived = character;
            } else
            {
                break;
            }
        }
    }

    switch (codeReceived) {
        case 'F': goForward(); delay(500); stop(); break;
        case 'L': turnLeft(); delay(500); stop(); break;
        case 'B': goBack(); delay(500); stop(); break;
        case 'R': turnRight(); delay(500); stop(); break;
        case 'X': stop(); break;
        case 'D': stop(); motor_speed += 100; if (motor_speed >= 450) motor_speed = 450; break;
        case 'Y': stop(); motor_speed -= 100; if (motor_speed <= 150) motor_speed = 150; break;
    }

    delay(10);
}


void goForward() 
{
    analogWrite(motorA_pwm, motor_speed);
	  digitalWrite(motorA_dir, FORWARD);

    analogWrite(motorB_pwm, motor_speed);
    digitalWrite(motorB_dir, FORWARD);
}

void goBack() 
{
    analogWrite(motorA_pwm, motor_speed);
	  digitalWrite(motorA_dir, BACKWARD);

    analogWrite(motorB_pwm, motor_speed);
    digitalWrite(motorB_dir, BACKWARD);
}

void stop() 
{
    digitalWrite(motorA_dir, 0);
    digitalWrite(motorA_pwm, 0);

    digitalWrite(motorB_pwm, 0);
    digitalWrite(motorB_dir, 0);
}

void turnLeft() 
{
    analogWrite(motorA_pwm, motor_speed);
	  digitalWrite(motorA_dir, FORWARD);

    analogWrite(motorB_pwm, 0);
    digitalWrite(motorB_dir, 0);
}

void turnRight() 
{
    analogWrite(motorA_pwm, 0);
	  digitalWrite(motorA_dir, 0);

    analogWrite(motorB_pwm, motor_speed);
    digitalWrite(motorB_dir, FORWARD);
}
