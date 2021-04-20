//
//  Sonar.cpp
//  
//
//  Created by Alex Noyanov on 11/03/2021.
//

/*
*    =============================================
*      Ultrasonic Sensor HC-SR04 Library
*      Fast, Simple and Safe
*      By Alex Noyanov, March 11th 2021,Moscow
*    =============================================
*
*/

#include "Sonar.hpp"

// For Serial testing
//  void Sonar::serialTest(Serial _serial){
//      _serial.print("Distance: ");
//      _serial.print(_distance);
//      _serial.println(" cm");
//  }

      void Sonar::pinSetup() {
    //    _echoPin = echo;
    //    _trigPin = trig;
          pinMode(_trigPin,OUTPUT);
          pinMode(_echoPin,INPUT);
      }

    Sonar::Sonar() {
        _objectCounter++;
    }
    
     Sonar::Sonar(int trig,int echo){
         setPin(trig, echo);
         _objectCounter++;
    }

    Sonar::Sonar(int universalPin){
        _onePin = universalPin;
        pinMode(_onePin,OUTPUT);
        _objectCounter++;
    }

void Sonar::setPin(int trig,int echo)
    {
        _echoPin = echo;
        _trigPin = trig;
        pinSetup();
    }


  // Reading distance:
   void Sonar::readDistance(){
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
       
  // Reads the echoPin, returns the sound wave travel time in microseconds
  _duration = pulseIn(_echoPin, HIGH);
       
  // Calculating the distance
  _distance = _duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  // ==== USE serialTest(); TO CALIBRATE SENSOR! =====
  //return _distance;
  }

void Sonar::oneReadDistance(){
    /*
        --- Basic alghorithm: ---
     1) Set pinMode(OUTPUT)
     2) Generate ultrasonic signal
     3) Change pinMode(INPUT)
     4) Read signal and get time
     5) Calculate distance value
     Done!
     */
    
    pinMode(_onePin, OUTPUT);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(_onePin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_onePin, LOW);
    
    // Change pin mode to read signal:
    pinMode(_onePin,INPUT);
    //delay(1);
    // Reads the echoPin, returns the sound wave travel time in microseconds
     _oneDuration = pulseIn(_onePin, HIGH);
    
    // Calculating the distance
    _distance = _duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
          
}


  long Sonar::getDistance(){
    return _distance;
  }

void Sonar::objectCounter(){
    return _objectCounter;
}
  
