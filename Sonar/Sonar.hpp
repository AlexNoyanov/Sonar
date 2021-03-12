//
//  Sonar.hpp
//  
//
//  Created by Alex Noyanov on 11/03/2021.
//

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef Sonar_hpp
#define Sonar_hpp

#include <stdio.h>

#endif /* Sonar_hpp */

class Sonar {
    private:
      long _distance;                // Distance value
      int _echoPin,_trigPin,_onePin;  // Sensor pins
      long _duration,_oneDuration;     // Time to calculate distance value
    
    
    public:
        Sonar();
        Sonar(int trig,int echo);
        Sonar(int universalPin);           // Constructor for single pin solution
    
        void setPin(int trig,int echo);
    
        void serialTest();                  // For testing
        void readDistance();                // Read distance value
        void pinSetup();                    // Sensor Setup
        long getDistance();                 // Get distance value
    
        void oneReadDistance();             // Read distance with one pin
};
