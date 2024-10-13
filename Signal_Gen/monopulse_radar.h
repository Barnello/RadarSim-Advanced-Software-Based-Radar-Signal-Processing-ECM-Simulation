// Author: Lucas Barnello
// Purpose: Monopulse Radar Signal Generation

#ifndef MONOPULSE_RADAR_H
#define MONOPULSE_RADAR_H

#include "pulse_radar.h"
#include <iostream>

class Monopulse_Radar : public Pulse_Radar {
public:
    // Constructor
    Monopulse_Radar(double frequency, double amplitude, double pulseWidth, double PRI, double dutyCycle, double azimuth, double elevation)
        : Pulse_Radar(frequency, amplitude, pulseWidth, PRI, dutyCycle), azimuth_(azimuth), elevation_(elevation) {
        waveformType = "Monopulse";
    }

    void generateSignal(double time) override {
        std::cout << "Generating Monopulse Radar Signal at time: " << time << std::endl;
    }

    void display() override {
        Pulse_Radar::display();
        std::cout << "Azimuth: " << azimuth_ << " degrees" << std::endl;
        std::cout << "Elevation: " << elevation_ << " degrees" << std::endl;
    }

    // Getters and Setters 
    double getAzimuth() { return azimuth_; }
    double getElevation() { return elevation_; }
    void setAzimuth(double newAzimuth) { azimuth_ = newAzimuth; }
    void setElevation(double newElevation) { elevation_ = newElevation; }

private:
    double azimuth_;    // Azimuth angle (degrees)
    double elevation_;  // Elevation angle (degrees)
};

#endif 
