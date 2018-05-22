
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

void setup() {

  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {


 
  Serial.begin(9600);

{

  Serial.println(sensor);  // display tempature
 
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
    if (val == HIGH) // When the flame sensor detects a signal, LED flashes
  {

  }
  else

  }


  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
  }
  
}

int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the flame sensor interface
int analoog = A3; // define the flame sensor interface
 
int val ;// define numeric variables val
float sensor; //read analoog value
 
