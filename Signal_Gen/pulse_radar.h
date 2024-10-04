// Author: Lucas Barnello
// Purpose: Generation of pulse signals 

//TODO: 
    // Determing characteristics of the signal 
    // Create the algorithm that will produce the signal 
    // Create the funtion (maybe in the base class) that will perform FFTW

#include "base_signal_gen.h"

#ifndef PULSE_SIGNAL_GEN_H
#define PULSE_SIGNAL_GEN_H

class Pulse_Radar {
public:
    // Constructor
    Pulse_Radar(){
        
    }

    // Virtual destructor (important for base classes with virtual methods)
    virtual ~Pulse_Radar() = default;

    // Pure virtual functions that must be implemented by derived classes
    void show(); // Print pulse signal information to console
    void display(); // Visualize the pulse signal in some form

protected:
    int frequency_;          // Frequency of the signal
};

#endif
