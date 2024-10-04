// Author: Lucas Barnello
// Purpose: Generation of pulse signals 

#include "base_signal_gen.h"

#ifndef PULSE_SIGNAL_GEN_H
#define PULSE_SIGNAL_GEN_H

class Pulse_Radar : public Base_Signal_Gen{
public:
    // Constructor
    Pulse_Radar(double frequency, double amplitude, const std::string &waveformType);

    // Virtual destructor (important for base classes with virtual methods)
    virtual ~Pulse_Radar() = default;

    // Pure virtual functions that must be implemented by derived classes
    void show() override;  // Print pulse signal information to console
    void display() override; // Visualize the pulse signal in some form
};

#endif
