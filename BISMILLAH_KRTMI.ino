#include <PS2X_lib.h>
#include <Wire.h>
#include <Servo.h>

#define M1_1  2 // PIN 2
#define M1_2  3 // PIN 3
#define M2_1  4 // PIN 4
#define M2_2  5 // PIN 5
#define M3_1  8 // PIN 8
#define M3_2  9 // PIN 8
#define M4_1  10 // PIN 10
#define M4_2  11 // PIN 11

#define PS2_DAT 24 //PIN 24
#define PS2_CMD 23 //PIN 23
#define PS2_SEL 22 //PIN 22
#define PS2_CLK 25 //PIN 25

#define servo1  42
#define servo2  43
#define servo3  44
#define servo4  50

PS2X ps2x;  //Controller
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

  int pos1a = 80;        
  int pos1b = 150;  
  int pos2a = 30;  
  int pos2b = 10; 
  int pos3a = 0;  
  int pos3b= 90;
  int pos4 = 80;  

int servo_count;


int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {
  Serial.begin(9600);
  pinMode(M1_1, OUTPUT);
  pinMode(M1_2, OUTPUT);
  pinMode(M2_1, OUTPUT);
  pinMode(M2_2, OUTPUT);
  pinMode(M3_1, OUTPUT);
  pinMode(M3_2, OUTPUT);
  pinMode(M4_1, OUTPUT);
  pinMode(M4_2, OUTPUT);

  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT);
  type  = ps2x.readType(); 

  myservo1.attach(servo1);   //servo capit depan
  myservo2.attach(servo2);   //servo leher capit
  myservo3.attach(servo3);   //servo lengan atas
  myservo4.attach(servo4);   // servo lengan besar
  
  myservo1.write(pos1a);
  myservo2.write(pos2a);
  myservo3.write(pos3a);
  myservo4.write(pos4);
  
   
  Serial.print("error code = ");
  Serial.println(error);
  Serial.print("type = ");
  Serial.println(type); 
}

void loop() {

   ps2x.read_gamepad();
    if (ps2x.Button(PSB_PAD_LEFT)) {
    Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    Serial.print("LEFT held this hard: ");
    digitalWrite(M1_1, HIGH);
    digitalWrite(M1_2, LOW);
    digitalWrite(M2_1, HIGH);
    digitalWrite(M2_2, LOW);
    digitalWrite(M3_1, HIGH);
    digitalWrite(M3_2, LOW);
    digitalWrite(M4_1, HIGH);
    digitalWrite(M4_2, LOW);
  }

  else if (ps2x.Button(PSB_PAD_RIGHT)) {
    Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    Serial.println("Right held this hard: ");
    digitalWrite(M1_1, LOW);
    digitalWrite(M1_2, HIGH);
    digitalWrite(M2_1, LOW);
    digitalWrite(M2_2, HIGH);
    digitalWrite(M3_1, LOW);
    digitalWrite(M3_2, HIGH);
    digitalWrite(M4_1, LOW);
    digitalWrite(M4_2, HIGH);
  }

   else if (ps2x.Button(PSB_PAD_UP)) {
    digitalWrite(M1_1, HIGH);
    digitalWrite(M1_2, LOW);
    digitalWrite(M2_1, HIGH);
    digitalWrite(M2_2, LOW);
    digitalWrite(M3_1, LOW);
    digitalWrite(M3_2, HIGH);
    digitalWrite(M4_1, LOW);
    digitalWrite(M4_2, HIGH);
  }
  
  else if (ps2x.Button(PSB_PAD_DOWN)) {
    digitalWrite(M1_1, LOW);
    digitalWrite(M1_2, HIGH);
    digitalWrite(M2_1, LOW);
    digitalWrite(M2_2, HIGH);
    digitalWrite(M3_1, HIGH);
    digitalWrite(M3_2, LOW);
    digitalWrite(M4_1, HIGH);
    digitalWrite(M4_2, LOW);
  }

  else if (ps2x.Button(PSB_PINK)) {
    digitalWrite(M1_1, HIGH);
    digitalWrite(M1_2, LOW);
    digitalWrite(M2_1, LOW);
    digitalWrite(M2_2, HIGH);
    digitalWrite(M3_1, LOW);
    digitalWrite(M3_2, HIGH);
    digitalWrite(M4_1, HIGH);
    digitalWrite(M4_2, LOW);
  }

  else if (ps2x.Button(PSB_RED)) {
    digitalWrite(M1_1, LOW);
    digitalWrite(M1_2, HIGH);
    digitalWrite(M2_1, HIGH);
    digitalWrite(M2_2, LOW);
    digitalWrite(M3_1, HIGH);
    digitalWrite(M3_2, LOW);
    digitalWrite(M4_1, LOW);
    digitalWrite(M4_2, HIGH);
  }
  
  else {
    digitalWrite(M1_1, LOW);
    digitalWrite(M1_2, LOW);
    digitalWrite(M2_1, LOW);
    digitalWrite(M2_2, LOW);
    digitalWrite(M3_1, LOW);
    digitalWrite(M3_2, LOW);
    digitalWrite(M4_1, LOW);
    digitalWrite(M4_2, LOW);
  }

 if(ps2x.ButtonPressed(PSB_R1))                  //will be TRUE if button was JUST pressed
      {  
        
        if (servo_count == 0)
            {
              myservo1.write(pos1a);              // tell servo to go to position in variable 'pos'
              delay(15); 
              
              Serial.println("servo hold");      //relay penjepit
              servo_count++;
            }
        else
            {
              myservo1.write(pos1b);              // tell servo to go to position in variable 'pos'
              delay(15); 
              
              Serial.println("servo UP");      //relay penjepit
              servo_count = 0;
            }
      }

 if(ps2x.ButtonPressed(PSB_R2))                  //will be TRUE if button was JUST pressed
      {  
        
        if (servo_count == 0)
            {
              myservo2.write(pos2a);              // tell servo to go to position in variable 'pos'
              delay(15); 
              
              Serial.println("servo hold");      //relay penjepit
              servo_count++;
            }
        else
            {
              myservo2.write(pos2b);              // tell servo to go to position in variable 'pos'
              delay(15); 
              
              Serial.println("servo UP");      //relay penjepit
              servo_count = 0;
            }
            

 if(ps2x.ButtonPressed(PSB_L1))                  //will be TRUE if button was JUST pressed
      {  
        
        if (servo_count == 0)
            {
              myservo3.write(pos3a);              // tell servo to go to position in variable 'pos'
              delay(15); 
              
              Serial.println("servo hold");      //relay penjepit
              servo_count++;
            }
        else
            {
              myservo3.write(pos3b);              // tell servo to go to position in variable 'pos'
              delay(15); 
              
              Serial.println("servo UP");      //relay penjepit
              servo_count = 0;
            }
      }
      
      
  //if (ps2x.Analog(PSS_LY)) servo2.write(10);
  //if (ps2x.Analog(PSS_LX)) servo2.write(30);

         
if (ps2x.ButtonPressed(PSB_GREEN)) myservo4.write(80); // atas
if (ps2x.ButtonPressed(PSB_BLUE)) myservo4.write(105);  // bawah
      } 
      }
  //if (ps2x.ButtonPressed(PSB_R2)) servo4.write(150);  // jepit kanan buka gripper
  //if (ps2x.ButtonPressed(PSB_R1)) servo4.write(80);  // jepit kanan tutup gripper
  
 // if (ps2x.ButtonPressed(PSB_L1)) servo2.write(45);  //  atas
  //if (ps2x.ButtonPressed(PSB_L2)) servo2.write(30);  // bawah

 //if (ps2x.ButtonPressed(PSB_L1)) servo3.write(90); // posisi 0
 //if (ps2x.ButtonPressed(PSB_L2)) servo3.write(0);  // belok kiri 

// if (ps2x.ButtonPressed(PSB_GREEN)) servo4.write(5); // atas
// if (ps2x.ButtonPressed(PSB_BLUE)) servo4.write(55);  // bawah
