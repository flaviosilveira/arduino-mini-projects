const int led1 = 13;
const int led2 = 12; 
const int led3 = 11; 

const int button1 = 2; 
const int button2 = 3; 
const int button3 = 4; 

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0; 

void setup(){
 pinMode(led1, OUTPUT);
 pinMode(button1, INPUT);
 pinMode(led2, OUTPUT);
 pinMode(button2, INPUT);
 pinMode(led3, OUTPUT);
 pinMode(button3, INPUT);
}

void loop(){
  buttonState1 = digitalRead(button1); buttonState2 = digitalRead(button2); buttonState3 = digitalRead(button3);
  
  if (buttonState1 == HIGH){ 
    digitalWrite(led1, HIGH); 
  } else{
    digitalWrite(led1, LOW);
  }
  
  if (buttonState2 == HIGH){
    digitalWrite(led2, HIGH);
  } else{
    digitalWrite(led2, LOW);
  }
  
  if (buttonState3 == HIGH){
    digitalWrite(led3, HIGH);
  } else{
    digitalWrite(led3, LOW);
  }
}
