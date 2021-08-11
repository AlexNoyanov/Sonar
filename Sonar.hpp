//
//  Sonar.hpp
//  
//
//  Created by Alex Noyanov on 11/03/2021.
//
// HC-SR04 Ulrasonic Sensor
//

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <SoftwareSerial.h> // For Waterproof Sonar

#ifndef Sonar_hpp
#define Sonar_hpp

#include <stdio.h>

#endif /* Sonar_hpp */

// Experiment with one pin setup
//#define UNIPIN

class Sonar {
    private:
      long _distance;                // Distance value
      int _echoPin,_trigPin,_onePin;   // Sensor pins
      long _duration,_oneDuration;     // Time to calculate distance value
    
      bool _isWp;                   // Set for waterproof sonar
      bool _isMM;                   // Is values in mm ()
    
//      SoftwareSerial mySerial(11,10); // RX, TX
      //SoftwareSerial mySerial; // RX, TX
      unsigned char data[4];
    
    public:
        Sonar();
        Sonar(int trig, int echo);
        Sonar(int trig, int echo, bool isWp);
#ifdef  UNIPIN
        Sonar(int universalPin, bool isWp);           // Constructor for single pin solution
#endif
    
    // For mm/CM values:
        Sonar(int trig, int echo, bool isWp, bool isMM);           // Constructor for single pin solution
    
        void setPin(int trig,int echo);
    
        void setWp(bool wpMode);            // Setting the waterproof
        void setMM(bool isMM);
    
        void serialTest();                  // For testing
        void readDistance();                // Read distance value
        
        void readDistanceNWpMM();            // Read distance value
    
        void pinSetup();                    // Sensor Setup
        long getDistance();                 // Get distance value
        void oneReadDistance();             // Read distance with one pin
private:
        long getDistanceNWp();              // For distance waterproof
        long getDistanceWp();               // For distance not waterproof
        void readDistanceWp();
        void readDistanceNWp();
public:
};

// Waterproof sonar class:
class WPSonar: public Sonar {
    //SoftwareSerial _mySerial;
    
    public:
    // Constructor
    WPSonar(int trig, int echo);
        
};

//class WPSonar{
//    private:
//        long _distance;
//        int _echoPin,_trigPin;
//}

