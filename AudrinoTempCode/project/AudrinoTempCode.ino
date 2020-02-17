/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

#include <math.h>

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k



// the setup routine runs once when you press reset:

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(sensorValue);



  float R = 1023.0 / sensorValue - 1.0;
  R = R0 * R;

  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15; // convert to temperature via datasheet

  Serial.print("temperature = ");
  Serial.println(temperature);
  /*lcd.println("Temperature = ");*/
  lcd.println(temperature);
  delay (100);

  if(temperature < 25)
  {
    digitalWrite(4,HIGH);
  }
  else if (temperature > 35)
  {
    digitalWrite(3,HIGH);
  }
  else
  {
    digitalWrite(2,HIGH);
  }

  /* // Turn off the display:
    lcd.noDisplay();
    delay(0);
    // Turn on the display:
    lcd.display();
    delay(0);*/
}

