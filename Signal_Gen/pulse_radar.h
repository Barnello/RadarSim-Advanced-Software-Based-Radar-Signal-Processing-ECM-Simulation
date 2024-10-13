// Author: Lucas Barnello
// Purpose: Pulsed Radar Signal Generation

#ifndef PULSED_RADAR_H
#define PULSED_RADAR_H

#include "base_signal_gen.h"
#include <cmath>

class Pulse_Radar : public Base_Signal_Gen {
public:
    // Constructor
    Pulse_Radar(double frequency, double amplitude, double pulseWidth, double PRI, double dutyCycle)
        : Base_Signal_Gen(frequency, amplitude), pulseWidth(pulseWidth), PRI(PRI), dutyCycle(dutyCycle) {
        waveformType = "Pulsed";
    }

    // Generate the pulsed signal
    void generateSignal(double time) override {
        std::cout << "Generating Pulse Signal" << '\n';
        std::vector<double> signal_data;
        double dt = 1.0 / (10 * frequency); // Sampling rate
        signal_data.clear();
        double currentTime = 0.0;

        while (currentTime < time) {
            if (fmod(currentTime, PRI) <= pulseWidth) {
                double value = amplitude * std::cos(2 * M_PI * frequency * currentTime);
                signal_data.push_back(value);
            } else {
                signal_data.push_back(0.0);
            }
            currentTime += dt;
    }
    }

    void display() override {
        std::cout << "--- Pulsed Radar Signal ---" << std::endl;
        std::cout << "Frequency: " << getFrequency() << " Hz" << std::endl;
        std::cout << "Amplitude: " << getAmplitude() << std::endl;
        std::cout << "Pulse Width: " << pulseWidth << " seconds" << std::endl;
        std::cout << "PRI: " << PRI << " seconds" << std::endl;
        std::cout << "Duty Cycle: " << dutyCycle * 100 << " %" << std::endl;
    }

    // Getters and Setters
    double getPulseWidth() { return pulseWidth; }
    double getPRI() { return PRI; }
    double getDutyCycle() { return dutyCycle; }
    void setPulseWidth(double newPulseWidth) { pulseWidth = newPulseWidth; }
    void setPRI(double newPRI) { PRI = newPRI; }
    void setDutyCycle(double newDutyCycle) { dutyCycle = newDutyCycle; }

private:
    double pulseWidth;  
    double PRI;         // Pulse Repetition Interval (seconds)
    double dutyCycle;   
};

#endif 