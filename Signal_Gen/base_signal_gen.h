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
    Base_Signal_Gen(double frequency, double amplitude, const std::string& signalType) 
    : frequency_(frequency), amplitude_(amplitude), waveformType_(signalType){}

    // Virtual destructor (important for base classes with virtual methods)
    virtual ~Base_Signal_Gen(){}

    // Pure virtual functions that must be implemented by derived classes
    virtual void show() = 0;       // Print signal information to console
    virtual void display() = 0;    // Visualize the signal in some form

    // Getters
    double getFrequency(){return frequency_;}
    double getBandwidth(){return bandwidth_;}
    double getAmplitude(){return amplitude_;}
    double getDuration(){return duration_;}
    double getPhase(){return phase_;}
    double getNoiseLevel(){return noiseLevel_;}
    int getSamplingRate(){return samplingRate_;}
    std::string getWaveType(){return waveformType_;}

    // Setters
    void setFrequency(double newFreq){frequency_ = newFreq;}
    void setBandwidth(double newBandwidth){bandwidth_ = newBandwidth;}
    void setAmplitude(double newAmplitude){amplitude_ = newAmplitude;}
    void setDuration(double newDuration){duration_ = newDuration;}
    void setPhase(double newPhase){phase_ = newPhase;}
    void setNoiseLevel(double newNoiseLevel){noiseLevel_ = newNoiseLevel;}
    void setSamplingRate(int newSamplingRate){samplingRate_ = newSamplingRate;}
    // std::string setWaveformType(std::string newWaveformType){waveformType_ = newWaveformType;}
    

protected:
    // Attributes for all signals
    double frequency_;                // Operating frequency (in Hz)
    double bandwidth_;             // Bandwidth (in Hz)
    double amplitude_;             // Amplitude of the signal
    double duration_;              // Pulse or chirp duration (in seconds)
    std::string waveformType_;     // Type of waveform (e.g., "Pulse", "FMCW")
    double phase_;                 // Phase of the signal (in radians)
    int samplingRate_;             // Sampling rate (samples per second)
    std::function<double(double)> modulation_;  // Carrier frequency modulation function
    double noiseLevel_;            // Noise level or SNR
};

#endif
