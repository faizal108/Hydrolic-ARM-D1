
/*
  there is two push button for hydrolic pump [up, down]
  if up button press then pump comes out and get reading step increses using encoder.
  if down button press then pump goes inside and reading step decreases using encoder.

  you can also able to record and play the move you perform on hydrolic.
*/
/*
  "Author" : "Faizal Kadiwal",
  "Github" : faizal108
*/

//encoder pins
#define CLK1 2  //intrupt pins
#define DT1 3   //intrupt pins
#define BTN1 4  //button

int increment1 = 1;

int counter1 = 0;

//encoders initialization
int currentStateCLK1;
int lastStateCLK1;

//UP button
const int upBtnPin = 5;
const int upLedPin = 6;
int upBtnState = 0;

//DOWN button
const int downBtnPin = 7;
const int downLedPin = 8;
int downBtnState = 0;

//Recording button
const int recordBtnPin = 9;
const int recordLedPin = 10;
int recordBtnState = 0;

//Play button
const int playBtnPin = 11;
const int playLedPin = 12;
int playBtnState = 0;

//record&play memorys setting
int p1_prevPos = 0;

int p1_memory[200];
int p1_index = 0;

int seq_pointer[200];
int seq_index = 0;


void setup() {
  // Set encoder pins as inputs
  //  pinMode(CLK1, INPUT);
  //  pinMode(DT1, INPUT);
  //  pinMode(BTN1, INPUT);
  pinMode(CLK1, INPUT_PULLUP);
  pinMode(DT1, INPUT_PULLUP);

  // Setup Serial Monitor
  Serial.begin(115200);

  // Read the initial state of CLK1
  lastStateCLK1 = digitalRead(CLK1);

  //  attachInterrupt(digitalPinToInterrupt(2), freeMove, CHANGE);
  //  attachInterrupt(digitalPinToInterrupt(3), freeMove, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2), ai0, RISING);
  attachInterrupt(digitalPinToInterrupt(3), ai1, RISING);

  //  UP button & Led configuration
  pinMode(upBtnPin, INPUT);
  digitalWrite(upBtnPin, LOW);
  pinMode(upLedPin, OUTPUT);
  digitalWrite(upLedPin, LOW);

  //  DOWN button & Led configuration
  pinMode(downBtnPin, INPUT);
  digitalWrite(downBtnPin, LOW);
  pinMode(downLedPin, OUTPUT);
  digitalWrite(downLedPin, LOW);

  //  Record button & Led configuration
  pinMode(recordBtnPin, INPUT);
  digitalWrite(recordBtnPin, LOW);
  pinMode(recordLedPin, OUTPUT);
  digitalWrite(recordLedPin, LOW);

  //  Play button & Led configuration
  pinMode(playBtnPin, INPUT);
  digitalWrite(playBtnPin, LOW);
  pinMode(playLedPin, OUTPUT);
  digitalWrite(playLedPin, LOW);
}

void ai0() {
  if (digitalRead(3) == LOW) {
    //    counter++;
    counter1 = counter1 + increment1;
  } else {
    //    counter--;
    counter1 = counter1 - increment1;
  }

  Serial.print("Counter1: ");
  Serial.print(counter1);
  Serial.print("\t");
}

void ai1() {
  if (digitalRead(2) == LOW) {
    //    counter--;
    counter1 = counter1 - increment1;
  } else {
    //    counter++;
    counter1 = counter1 + increment1;
  }

  Serial.print("Counter1: ");
  Serial.print(counter1);
  Serial.print("\t");
}

void loop() {
  upBtnState = digitalRead(upBtnPin);          //UP button
  downBtnState = digitalRead(downBtnPin);      //DOWN button
  recordBtnState = digitalRead(recordBtnPin);  //record button
  playBtnState = digitalRead(playBtnPin);      //play button

  //for UP
  if (upBtnState == HIGH) {
    //    Serial.println("UP");
    digitalWrite(upLedPin, HIGH);
  } else {
    digitalWrite(upLedPin, LOW);
  }

  //for DOWN
  if (downBtnState == HIGH) {
    //    Serial.println("DOWN");
    digitalWrite(downLedPin, HIGH);
  } else {
    digitalWrite(downLedPin, LOW);
  }

  //for recording
  if (recordBtnState == HIGH && seq_index < 200) {
    digitalWrite(recordLedPin, HIGH);
    Serial.println("Recording your moves.......");
    startRecording();
  } else {
    digitalWrite(recordLedPin, LOW);
  }

  //for playing a record
  if (playBtnState == HIGH) {
    digitalWrite(playLedPin, HIGH);
    Serial.println("Playing your moves.......");
    startPlaying();
  } else {
    digitalWrite(playLedPin, LOW);
  }

  //For clearing the recorded moves
  if (Serial.available() && Serial.read() == 'c') {
    p1_index = 0;
    seq_index = 0;
  }
}
