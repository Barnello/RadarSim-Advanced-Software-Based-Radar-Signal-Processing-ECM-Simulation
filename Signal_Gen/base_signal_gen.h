// Author: Lucas Barnello
// Purpose: Providing a base class for radar signal generation in RadarSim

////TODO: 
    // Determing characteristics of the signal 
    // Create the algorithm that will produce the signal 
    // Create the funtion (maybe in the base class) that will perform FFTW
    // Create Getters and Setters for the protected variables 

#ifndef SIGNAL_GEN_H
#define SIGNAL_GEN_H

#include <string> // Required for std::string
#include <functional> // MAY BE REMOVED

class Base_Signal_Gen {
public:
    // Constructors
    Base_Signal_Gen(double frequency, double amplitude) 
    : frequency(frequency), amplitude(amplitude){}

    // Virtual destructor (important for base classes with virtual methods)
    // virtual ~Base_Signal_Gen(){}

    // Pure virtual functions that must be implemented by derived classes
    virtual void generateSignal(double time) = 0;       // Print signal information to console
    virtual void display() = 0;    // Visualize the signal in some form

    // Getters
    double getFrequency(){return frequency;}
    double getAmplitude(){return amplitude;}
    std::string getWaveType(){return waveformType;}

    // Setters
    void setFrequency(double newFreq){frequency = newFreq;}
    void setAmplitude(double newAmplitude){amplitude = newAmplitude;}
    

protected:
    // Shared attributes list for all signals
    double frequency;                // Operating frequency (in Hz)
    double amplitude;             // Amplitude of the signal
    std::string waveformType;     // Type of waveform (e.g., "Pulse", "FMCW")
};

#endif
