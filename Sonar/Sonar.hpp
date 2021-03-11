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

class Sonar{
    private:
      long _distance;        // Distance value
      int _echoPin,_trigPin;  // Sensor pins
      long _duration;        // Time to calculate distance value
    
    public:
        Sonar(int _trig,int _echo);
        void serialTest();                  // For testing
        void readDistance();                // Read distance value
        void pinSetup(int echo,int trig);   // Sensor Setup
        long getDistance();                 // Get distance value
};
