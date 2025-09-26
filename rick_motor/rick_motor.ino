// Define pins
const int limit = 13;
const int drive = 2;
const int button = 3;

// Closed switch pins, these will be checked for door state
const int LimitPins[] = {limit,button};

//Pins for all door motors (Relay control)
const int doorPins[] = {1,2,3,4,5,6};

const int LimPinCount = sizeof(LimitPins)/sizeof(LimitPins[0]);
const int doorPinCount = sizeof(doorPins)/sizeof(doorPins[0]);

void setup() {
  //Begin serial connection
  Serial.begin(9600);
  for (int i = 0; i < LimPinCount; i++)
    pinMode(LimitPins[i],INPUT);
  for (int i = 0; i < doorPinCount; i++)
    pinMode(doorPins[i],OUTPUT);
}

// checks the state of all motors and toggles power on if not closed.
void checkState(){
   // Loop over array
  for (int i = 0; i < LimPinCount; i++) {
      
    if (digitalRead(LimitPins[i]) == 1) {
      

    }     
  }
}

void openDoor(int doorNumb){
  // Check all doors, close any that are open
  checkState();
  // Open selected door.
  digitalWrite(doorPins[doorNumb],HIGH);
  delay(1000);
  //Stop powering motor.
  digitalWrite(doorPins[doorNumb],LOW);
  
}

void loop() {
 // Listen for call to change motor state

}
