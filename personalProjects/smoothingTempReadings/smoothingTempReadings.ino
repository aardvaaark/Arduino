// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 20;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total

int inputPin = A0;

float degreesC, degreesF; //added to tutorial

void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);    //Set AREF to external since using 3.3v: Added to tutorial
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  total = total - readings[readIndex];   // subtract the last reading:
  readings[readIndex] = analogRead(inputPin);  // read from the sensor:
  total = total + readings[readIndex];   // add the reading to the total:
  readIndex = readIndex + 1;   // advance to the next position in the array:

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
      readIndex = 0;    // ...wrap around to the beginning:
    }

  float average = 1.0 * total / numReadings;
  delay(1);

  float avgVoltage = average * 0.00322265625;  //Added to tutorial
  degreesC = (avgVoltage - 0.5) * 100.0; //Added to tutorial
  degreesF = degreesC * (9.0/5.0) + 32.0; //Added to tutorial

  Serial.print("DegreesC: ");  //Added to tutorial
  Serial.print(degreesC);  //Added to tutorial
  Serial.print("DegreesF: "); //Added to tutorial
  Serial.println(degreesF);  //Added to tutorial
  delay(5000); 
}
   
