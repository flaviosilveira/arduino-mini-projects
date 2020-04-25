// this constant won't change:
const int buttonPin[3] = {2, 3, 4};     // pins that the pushbutton is attached to
const int ledPin[3] = {13, 11, 12};     // pins that the LED is attached to

// Variables will change:
int buttonPushCounter[3] = {0, 0, 0};   // counters for the number of buttons presses
int buttonState[3] = {0, 0, 0};         // current states of the buttons
int lastButtonState[3] = {0, 0, 0};     // previous states of the buttons

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    // initialize the button pins as inputs:
    pinMode(buttonPin[i], INPUT);
    // initialize the LEDs as outputs:
    pinMode(ledPin[i], OUTPUT);
  }
}


void loop() {
  for (int i = 0; i < 3; i++) {
    // read the pushbutton inputs pin:
    buttonState[i] = digitalRead(buttonPin[i]);
    Serial.println(buttonPushCounter[i]);

    // compare the buttonStates to its previous states
    if (buttonState[i] != lastButtonState[i]) {
      // if the state has changed, increment the counter
      if (buttonState[i] == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        buttonPushCounter[i]++;
      }
      // avoid bouncing
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonState[i] = buttonState[i];

    // turns on the LED every four button pushes by checking the modulo of the
    // button push counter. the modulo function gives you the remainder of the
    // division of two numbers:
    if (buttonPushCounter[i] % 2 == 0) {
      digitalWrite(ledPin[i], HIGH);
    } else {
      digitalWrite(ledPin[i], LOW);
    }
  }
}
