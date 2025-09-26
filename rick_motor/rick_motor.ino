// Define pins
const int limit = 13;
const int drive = 2;
const int button = 3;

// Closed switch pins, these will be checked for door state
const int LimitPins[] = {limit,button};

//Pins for all door motors (Relay control)
const int doorPins[] = {1,2,3,4,5,6};
// Automatically get pin count based on amount of pins in arr
// this will allow the code to "expand" as more motors/doors are added.
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
      /*Print testing
      
        Serial.print("Pin ");
        Serial.print(pins[i]);
        Serial.print(" state: ");
        Serial.println(digitalRead(pins[i]));
        */
    if (digitalRead(LimitPins[i]) == 1) {
      //toggle motor power on for that door.
      //Code would be slightly more efficient if we break here to avoid additional loops but would require
      //electronics to be pretty bullet proof(AKA we are certain that two doors would never be open)
      //This kind of optimization is probably unneccesary
    }     
  }
}

void openDoor(int doorNumb){
  // Check all doors and close and that are open
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
