// Author: Lucas Barnello
// Purpose: Providing a base class for radar signal generation in RadarSim

//TODO
    // Create CMAKE file for easy compliation
    // Implement all of the class and derived classes 
    // Generate time function of the signal in the specific classes (derived from the base class with no implementation)
    // Generate frequency function of the signal in the base class and override the functionality in child classes
    // TNEN create a new class  to display the data in the a window - possipbly multiple 
    // Create new class for the advanced detection and tracking algorithms 
    // Simulate various EXM techniques such as noise, jamming, deception jamming, frequency hopping etc
    // Create a visual model of the response to the ECM and create algorithms to improve radar resilience 
    
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
    virtual ~Base_Signal_Gen() = default; 

    // Pure virtual functions that must be implemented by derived classes
    virtual void generateSignal(double time) = 0;       // Generate the signal to be used in the display functionality
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
    std::vector<double> signalData; // Attribute for all of the signal calsses to stor signal 
    double time_step = 1 / (2*getFrequency());
};

#endif
