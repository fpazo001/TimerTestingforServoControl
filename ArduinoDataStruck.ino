#include <Servo.h>
Servo myservo;
Servo myservo1;

String readString;
String conf;

const int pin0 = 9;
const int pin = 11;

int CurrentPosition = 0;
int CurrentPosition0 = 0;

int ind0;      //STRING LOCATIONS FOR PARSING
int ind1;         
int ind2;

int x;
int y;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  myservo.attach(pin);
  myservo1.attach(pin0);
  //Serial.setTimeout(10);
}

void loop()
{
  String newPosition;
  String newPosition1;


  //------------------------------------------------------------------PARSING------------------------------------------------------------------------------------
 
  if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == '*') {
     
      ind0 = readString.indexOf(',');  //finds location of first ,
      conf = readString.substring(0, ind0);   //captures first data String
                  
      ind1 = readString.indexOf(',', ind0 + 1);  //finds location of second ,
      newPosition = readString.substring(ind0+1, ind1+1);   //captures second data String
      x = newPosition.toInt();
      
      ind2 = readString.indexOf(',', ind1 + 1 ); //finds location of third ,
      newPosition1 = readString.substring(ind1 + 1, ind2 - 1); //captures third data String
      y = newPosition1.toInt();
      
      readString = ""; //clears variable for new input
      conf = "";
      newPosition = "";
      newPosition1 = "";
    }
    else {
      readString += c; //makes the string readString;
    }
    
  }


  //--------------------------------------------------------------------SERVO 1--------------------------------------------------------------------------------------
  
   
    for (; CurrentPosition < x; CurrentPosition++)
    {
      myservo.write(CurrentPosition);
      delay(15);
    }

    for (; CurrentPosition > x; CurrentPosition--)
    {
      myservo.write(CurrentPosition);
      delay(15);
    }
  

  //-------------------------------------------------------------------------SERVO2MOVEMNET------------------------------------------------------------------
  
   
    for (; CurrentPosition0 < y; CurrentPosition0++)
    {
      myservo1.write(CurrentPosition0);
      delay(15);
    }

    for (; CurrentPosition0 > y; CurrentPosition0--)
    {
      myservo1.write(CurrentPosition0);
      delay(15);
    }
  
  
//----------------------------------------------------------------------------------------------------------------------------------------------------------
/*
  Serial.print("\n");
  Serial.print("captured String is : "); 
  Serial.println(readString);
  delay(1);
  Serial.print("\n");
  Serial.print("\n");  
  Serial.print("X:");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("CurrentPosition: ");
  Serial.print(CurrentPosition);
  Serial.print("\n");
  Serial.print("\n");
  delay(1);
  Serial.print("Y:");
  Serial.print(y);
  Serial.print("\n");
  Serial.print("CurrentPosition0: ");
  Serial.print(CurrentPosition0);
  Serial.print("\n");
  Serial.print("\n");
  delay(1);
  */
}
