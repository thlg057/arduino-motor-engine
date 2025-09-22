
const int back = -1;
const int forward = 1;
const int stopEngine = 0;

const int motor1 = 0;
const int motor2 = 1;

const int engineCmd1 = 0;
const int engineCmd2 = 1;

const byte motors[2][2] = {
  { 10,  9 }, // motor 1
  { 5, 6  } // motor 2
};

int _direction = stopEngine;
int _speed = 0;

void setup() {
  // initialisation des commandes
  pinMode (motors[motor1][engineCmd1], OUTPUT);
  pinMode (motors[motor1][engineCmd2], OUTPUT);
  pinMode (motors[motor2][engineCmd1], OUTPUT);
  pinMode (motors[motor2][engineCmd2], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  MoveForward (100);
  delay(2000);
  Stop();
  delay(500);
  MoveBack(100);
  delay(2000);
  Stop();
  delay(500);  
  Left();
  delay(2000);
  Stop();
  delay(2000);  
  Right();
  delay(2000);
  Stop();
  delay(2000);  
}

void SetEngine(int motorId, int power, int action)
{
  if (power < 0)
  {
    power = 0;
  }

  if (power > 100)
  {
    power = 100;
  }
  
  int puissance=map(power,0,100,0,255);
  switch(action)
  {
    case stopEngine:
      analogWrite (motors[motorId][engineCmd1], 0);
      analogWrite (motors[motorId][engineCmd2], 0);
      break;
    case forward:
      analogWrite (motors[motorId][engineCmd1], puissance);
      analogWrite (motors[motorId][engineCmd2], 0);
      break;
    case back:
      analogWrite (motors[motorId][engineCmd1], 0);
      analogWrite (motors[motorId][engineCmd2], puissance);
      break;
  }
}

void MoveForward(int power)
{
  SetEngine(motor1, power, forward);
  SetEngine(motor2, power, forward);
}

void MoveBack(int power)
{
  SetEngine(motor1, power, back);
  SetEngine(motor2, power, back);
}

void Left()
{
  SetEngine(motor1, 40, forward);
  SetEngine(motor2, 40, back);
}

void Right()
{
  SetEngine(motor1, 40, back);
  SetEngine(motor2, 40, forward);
}

void Stop()
{
  SetEngine(motor1, 0, stopEngine);
  SetEngine(motor2, 0, stopEngine);
}
