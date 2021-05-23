#include <Servo.h>
int GREEN = 5;
int YELLOW = 6;
int RED = 7;  // these three represent traffic lights;

int twoCar=8;
int fourCar=9;
int sixCar=10; // these three represent three push button switch indicating number of vehicles on the road;

Servo myservo;

// basic functions

void setup()
{
  myservo.attach(4);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
}

void loop() {
  int mTwoCar=digitalRead(8);
  int mFourCar=digitalRead(9);
  int mSixCar=digitalRead(10);
  if(mTwoCar==0 && mFourCar ==0 && mSixCar==1)
  {
    forSixCar();
    myservo.write(90);
    delay(10000);
    myservo.write(0);
  }
  else if(mTwoCar==0 && mFourCar ==1 && mSixCar==0)
  {
    forFourCar();
    myservo.write(90);
    delay(20000);
    myservo.write(0);
  }
  else
  {
    forTwoCar();
    myservo.write(90);
    delay(1000);
    myservo.write(0);
  }
}


void forTwoCar()
{
  green_light();  
}
void forFourCar()
{
  red_light();
  delay(10000);
  yellow_light();
  delay(1000);
  green_light();  
}
void forSixCar()
{
  red_light();
  delay(20000);
  yellow_light();
  delay(1000);
  green_light();  
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}
void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}
void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}
