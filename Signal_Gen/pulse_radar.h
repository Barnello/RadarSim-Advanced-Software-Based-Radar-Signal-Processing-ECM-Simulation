// Author: Lucas Barnello
// Purpose: Generation of pulse signals 

#include "base_signal_gen.h"

#ifndef PULSE_SIGNAL_GEN_H
#define PULSE_SIGNAL_GEN_H

class Pulse_Radar : public Base_Signal_Gen{
private: 
    double pulse_width  = 0.0; 
    double pri = 0.0; // Pulse repitiion interval        
    std::vector<double> signal_data; // Store generated signal data points
    const std::string waveform_type = "Pulse";
public:
    // Constructor
    Pulse_Radar(double inFrequency, double inPulseWidth, double inPri, double inAmplitude);
   
    // Destructor
    ~Pulse_Radar();

    // Override functions from the base class 
    void generateSignal(double time) override;  // Print pulse signal information to console
    void display() override; // Visualize the pulse signal in some form

    // Getters and Setters 
    double getPW(){ return pulse_width; } // Return pulse width
    double getPRI(){ return pri; } // Return pulse repotition interval
    void setPW(double newPW){ pulse_width = newPW; } // Set PW value
    void setPRI(double newPRI){ pri = newPRI; } // Set PRI value 
    std::string getType(){return waveform_type;} // Return waveform type
};

#endif
