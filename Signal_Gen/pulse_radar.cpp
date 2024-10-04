//Author: Lucas Barnello
//Purpose: Creating a synthetic pulse signal programatically

#include "pulse_radar.h"
#include <iostream>

//TODO
    // Create CMAKE file for easy compliation
    // Finalize necessary data initialization
    // Create time function of signal
    // Create Freq Function of signal
    // Ensure all edge cases in pulse signal types are covered
    // Display signal
    

Pulse_Radar::Pulse_Radar(double frequency, double amplitude, const std::string &waveformType)
: Base_Signal_Gen(frequency, amplitude, waveformType){
    std::cout << "--- Pulse Signal Generated " << '\n';
}

void Pulse_Radar::show(){
    std::cout << "--- Pulse Radar Signal Information " << '\n';
    std::cout << "--- Frequency: " << this->getFrequency() << '\n';
    std::cout << "--- Amplitude: " << this->getAmplitude() << '\n';
    std::cout << "--- Waveform Type: " << this->getWaveType() << '\n';
}

void Pulse_Radar::display(){
    std::cout << "--- Pulse Radar Signal Displayed ---" << '\n';
}

int main(){
    //Pulse_Radar* p = new PulseRadar(200, 2, "Pulse"); 
    // p->show();
    // p->display();
    Pulse_Radar p(200, 2, "pulse"); 
    p.show();

    return 0;
}