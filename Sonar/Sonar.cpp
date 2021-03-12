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

      void Sonar::pinSetup(){
    //    _echoPin = echo;
    //    _trigPin = trig;
          pinMode(_trigPin,OUTPUT);
          pinMode(_echoPin,INPUT);
      }


     Sonar::Sonar(int _trig,int _echo){
        _echoPin = _echo;
        _trigPin = _trig;
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




  long Sonar::getDistance(){
    return _distance;
  }
  
