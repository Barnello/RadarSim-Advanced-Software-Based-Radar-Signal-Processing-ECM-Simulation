//Author: Lucas Barnello
//Purpose: Creating a synthetic pulse signal programatically

#include "pulse_radar.h"
#include <iostream>
#include <math.h>

// Constructor Definition
Pulse_Radar::Pulse_Radar(double inFrequency, double inPulseWidth, double inPri, double inAmplitude) 
: Base_Signal_Gen::Base_Signal_Gen(inFrequency, inAmplitude), pri(inPri), pulse_width(inPulseWidth) 
{
    std::cout << "--- Pulse Radar Signal Information " << '\n';
    std::cout << "--- Frequency: " << this->getFrequency() << '\n';
    std::cout << "--- Amplitude: " << this->getAmplitude() << '\n';
    std::cout << "--- Waveform Type: " << this->getType() << '\n';
    std::cout << "--- Pulse Width: " << this->getPW() << '\n';
    std::cout << "--- Pulse Repitition Interval: " << this->getPRI() << '\n';
}

// Destructor Defintion 
Pulse_Radar::~Pulse_Radar(){}

// Override Function Signal
void Pulse_Radar::generateSignal(double time){
    std::cout << "Generating Signal..." << '\n';

    double dt = 1.0 / (10 * frequency); // Sampling rate
    signal_data.clear();
    double currentTime = 0.0;

    while (currentTime < time) {
        if (fmod(currentTime, pri) <= pulse_width) {
            double value = amplitude * std::cos(2 * M_PI * frequency * currentTime);
            signal_data.push_back(value);
        } else {
            signal_data.push_back(0.0);
        }
        currentTime += dt;
    }
}

// Override Function Signal
//TODO: Where the graphical interface application can be implmented 
void Pulse_Radar::display(){
    for (const auto& val : signal_data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(){
    Pulse_Radar pr(200.0, 100.0, 30.0, 20.0);  
    std::cout << '\n';
    pr.generateSignal(1);
    std::cout << '\n';
    pr.display();

    return 0;
}