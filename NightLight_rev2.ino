/*
http://vikneshan.blogspot.com/2017/02/led-night-light-with-arduino.html
https://www.arduino.cc/en/Tutorial/Fade
https://learn.adafruit.com/photocells/using-a-photocell
https://www.arduino.cc/en/Reference/Random
 */

int led1 = 9;           // the PWM pin the LED is attached to
int led2 = 10;
int led3 = 11;
int led4 = 5;
int led5 = 3;
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
//unsigned long time;
long randNumber;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT); 
  
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));  
}

// the loop routine runs over and over again forever:
void loop() {
  // a random number from 0, 1
  randNumber = random(2);
  photocellReading = analogRead(photocellPin);

  if (photocellReading <80)
  {
    while(photocellReading <80){
      photocellReading = analogRead(photocellPin);
      if (randNumber>0){
        // set the brightness of pins:
        analogWrite(led1, brightness);
        analogWrite(led2, brightness);
        analogWrite(led3, brightness);
        analogWrite(led4, brightness);
        analogWrite(led5, brightness);
      
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;
      
        // reverse the direction of the fading at the ends of the fade:
        if (brightness <= 0 || brightness >= 255) {
          fadeAmount = -fadeAmount;
        }
          // wait for 50 milliseconds to see the dimming effect
        delay(50);

      }
      else
      {
        analogWrite(led1, 254);
        analogWrite(led2, 254);
        analogWrite(led3, 254);
        analogWrite(led4, 254);
        analogWrite(led5, 254);
        delay(50);
      }
    }
 

  }
  else
  {
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
    delay(50);
  }
}
