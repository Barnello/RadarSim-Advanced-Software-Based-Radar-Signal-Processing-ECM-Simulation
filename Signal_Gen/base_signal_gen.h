// Author: Lucas Barnello
// Purpose: Providing a base class for radar signal generation in RadarSim

#ifndef SIGNAL_GEN_H
#define SIGNAL_GEN_H

#include <string> // Required for std::string

class Base_Signal_Gen {
public:
    // Constructor
    Base_Signal_Gen(int frequency, const std::string& signalType);

    // Virtual destructor (important for base classes with virtual methods)
    virtual ~Base_Signal_Gen() = default;

    // Pure virtual functions that must be implemented by derived classes
    virtual void show() = 0; // Print signal information to console
    virtual void display() = 0; // Visualize the signal in some form

protected:
    int frequency_;          // Frequency of the signal
    std::string signalType_;  // Type of signal (e.g., Pulse, FMCW)
};

#endif
