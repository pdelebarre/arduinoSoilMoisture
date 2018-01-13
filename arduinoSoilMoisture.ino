/*

Innovativetom.com
Flower Pot Soil Mosture Sensor

A0 - Soil Mosture Sensor
Connect the Soil Mosture Sensor to anolog input pin 0,

*/

//#include <Servo.h>

int ledBLUE = 4;
int ledGREEN = 5;
int ledRED = 6;

int ENA = 7;
int IN1 = 8;
int IN2 = 9; //pump

int waterLevel = 10;

//int anodePump=8; // +
//int cathodePump=7;

int moistureSensor = 0;

void setup() {
  // Serial Begin so we can see the data from the moisture sensor in our serial input window.
  Serial.begin(9600);
  // setting the led pins to outputs
  pinMode(ledRED, OUTPUT);
  pinMode(ledGREEN, OUTPUT);
  pinMode(ledBLUE, OUTPUT);

  pinMode(waterLevel, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int analogWaterLevel=0;
 for(int i=0;i<10;i++) {
   analogWaterLevel+= analogRead(waterLevel);
 Serial.print("analogWL = ");
  Serial.println(analogWaterLevel); }
 analogWaterLevel/=10;
  Serial.print("avg analogWL = ");
  Serial.println(analogWaterLevel);
  if (analogWaterLevel<901) {
    analogWrite(ledRED, 0);
    analogWrite(ledGREEN, 255);
    analogWrite(ledBLUE, 255);
    water(false);
  } else {

    // read the input on analog pin 0:
    int sensorValue = analogRead(moistureSensor);
    // print out the value you read:

    Serial.println(sensorValue);


    if (sensorValue >= 820)
    {
      analogWrite(ledRED, 255);
      analogWrite(ledGREEN, 255);
      analogWrite(ledBLUE, 0);
      water(true);
    }
    else if (sensorValue >= 615  && sensorValue < 820)
    {
      analogWrite(ledRED, 255);
      analogWrite(ledGREEN, 180);
      analogWrite(ledBLUE, 80);
      water(true);
    }
    else if (sensorValue >= 410 && sensorValue < 615)
    {
      analogWrite(ledRED, 255);
      analogWrite(ledGREEN, 100);
      analogWrite(ledBLUE, 160);
      water(true);
    }
    else if (sensorValue >= 250 && sensorValue < 410)
    {
      analogWrite(ledRED, 255);
      analogWrite(ledGREEN, 0);
      analogWrite(ledBLUE, 255);

      water(false);
    }
    else if (sensorValue >= 0 && sensorValue < 250)
    {
      analogWrite(ledRED, 255);
      analogWrite(ledGREEN, 0);
      analogWrite(ledBLUE, 255);
      water(false);
    }
  }
}

void water(boolean b) {
  Serial.print("water ");
  Serial.println(b);
  if (b) {
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    analogWrite(IN2, LOW);
  } else {
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    analogWrite(IN2, LOW);
  }
  delay(1000);
}
