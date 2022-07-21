//Caleb Turner && Jared St. John && Hannah Gex
//contibuters Juan Barron

boolean h = HIGH;
boolean l = LOW;

const int motor1 = 10; //pins for motor
const int motor2 = 11;
const int motor3 = 12;
//const int motor4 = 12;

const int dirPin1 = 32;//white wires are direction
const int dirPin2 = 40;
const int dirPin3 = 38; // dont use pin 36
//const int dirPin4 = 32;

const int pwrbrd1 = 53;
const int pwrbrd2 = 49;
const int pwrbrd3 = 45;
//const int pwrbrd4 = 8;

double voltage = 1.25;//keep this between .59 && 3.75 or fuse will blow

int spd = (51 * voltage);

void setup() {
  Serial.begin(9600);

  pinMode(motor1, OUTPUT); //Speed outputs
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  //pinMode(motor4, OUTPUT);

  pinMode(dirPin1, OUTPUT); //Directional control outputs
  pinMode(dirPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
 // pinMode(dirPin4, OUTPUT);

  pinMode(pwrbrd1, OUTPUT); 
  pinMode(pwrbrd2, OUTPUT);
  pinMode(pwrbrd3, OUTPUT);
 // pinMode(pwrbrd4, OUTPUT);

  upPWMFrequency(10); //sets PWM frequency to acceptable levels
  upPWMFrequency(11); 
  upPWMFrequency(12);
 // upPWMFrequency(13);
  


}

void loop() {
  if (Serial.available() > 0){
    char inbyte = Serial.read();
    Serial.println(inbyte);

//    if (inbyte == 'w') {
//      digitalWrite(dirPin3, h);
//      digitalWrite(dirPin2, h);//side motors
//      digitalWrite(pwrbrd1, l);//vertical 
//      
//      }
    
      


  switch (inbyte) {
    case 'w': //forwards
      
      digitalWrite(dirPin2, l);//side motors
      digitalWrite(pwrbrd2, l);
      analogWrite(motor2, spd);
      
      digitalWrite(dirPin3, l);
      digitalWrite(pwrbrd3, l);
      analogWrite(motor1, spd);

      digitalWrite(dirPin1, h);//vertica
      digitalWrite(pwrbrd1, l);//vertica
      analogWrite(motor1, 0);

        break;
        
    case 's': //backward 
    
      digitalWrite(dirPin3, h);
      digitalWrite(pwrbrd3, l);//vertica
      analogWrite(motor3, spd);
      
      digitalWrite(dirPin2, h);//side motors
      digitalWrite(pwrbrd2, 1);
      analogWrite(motor2, spd);
      

      digitalWrite(dirPin1, h);//vertica
      digitalWrite(pwrbrd1, l);//vertical
      analogWrite(motor1, 0);
        break;
        
    case 'a': //left
      digitalWrite(dirPin2, l);//side motors
      digitalWrite(pwrbrd2, l);
      analogWrite(motor2, spd);
      
      digitalWrite(dirPin3, h);
      digitalWrite(pwrbrd3, l);
      analogWrite(motor3, spd);

      digitalWrite(dirPin1, h);//vertica
      digitalWrite(pwrbrd1, l);//vertica
      analogWrite(motor1, 0);
        break;

    case 'd': //right
      digitalWrite(dirPin2, h);//side motors
      digitalWrite(pwrbrd2, l);
      analogWrite(motor2, spd);

      digitalWrite(dirPin3, l);
      digitalWrite(pwrbrd3, l);
      analogWrite(motor3, spd);

      digitalWrite(dirPin1, h);//vertica
      digitalWrite(pwrbrd1, l);//vertica
      analogWrite(motor1, 0);

        break;

    case 'q': //down
      digitalWrite(dirPin3, h);
      digitalWrite(pwrbrd3, l);
      analogWrite(motor3, 0);

      digitalWrite(dirPin2, h);//side motors
      digitalWrite(pwrbrd2, l);
      analogWrite(motor2, 0);

      digitalWrite(dirPin1, l);//vertica
      digitalWrite(pwrbrd1, l);//vertica
      analogWrite(motor1, spd);
        break;

    case 'e': //up 
      digitalWrite(dirPin3, h);
      digitalWrite(pwrbrd3, 1);
      analogWrite(motor3, 0);
      
      digitalWrite(dirPin2, h);//side motors
      digitalWrite(pwrbrd2, 1);
      analogWrite(motor2, 0);

      digitalWrite(dirPin1, h);//vertica
      digitalWrite(pwrbrd1, l);//vertica
      analogWrite(motor1, spd);
        break;

    case 'p': //stop completely
      digitalWrite(pwrbrd1, l );//vertica
      analogWrite(motor1, 0);
      digitalWrite(pwrbrd2, l);
      analogWrite(motor2, 0);
      digitalWrite(pwrbrd3, l);
      analogWrite(motor3, 0);
        break;

    default:
      digitalWrite(pwrbrd1, l );//vertica
      
      digitalWrite(pwrbrd2, l);
      
      digitalWrite(pwrbrd3, l);
      

    }
      
  }
}
  void upPWMFrequency(int pin) {
  byte mode = 0x01;
  if(pin == 5 || pin == 6) {
    TCCR0B = TCCR0B & 0b11111000 | mode;
  }
  else if(pin == 9 || pin == 10) {
    TCCR1B = TCCR1B & 0b11111000 | mode;
  } 
  else if(pin == 3 || pin == 11) {
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
