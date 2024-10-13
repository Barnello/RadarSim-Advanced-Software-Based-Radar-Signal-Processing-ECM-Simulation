// Author: Lucas Barnello 
// PUrpose: FMCW Radar Signal Generation
#ifndef FMCW_RADAR_H
#define FMCW_RADAR_H

#include "continuous_wave_radar.h"
#include <iostream>
#include <cmath>

class FMCW_Radar : public Continuous_Wave_Radar { 
    public: 
        FMCW_Radar(double frequency, double amplitude, double sweepRate, double timeDuration, double bandwidth, double chirpDuration)
        : Continuous_Wave_Radar(frequency, amplitude, sweepRate, timeDuration), bandwidth_(bandwidth), chirpDuration_(chirpDuration) {
        waveformType = "FMCW";
        }

        void generateSignal(double time) override {
            std::cout << "Generating FMCW RadarSignal at time " << time << std::endl;
            signalData.clear();
            
            for (double t = 0; t < time; t += time_step) {
                double freq_t = frequency + (bandwidth_ / this->getSweepRate()) * t; // Frequency at time t
                double signal_value = amplitude * std::cos(2 * M_PI * freq_t * t);
                signalData.push_back(signal_value);
            }
        }

        void display() override {
            Continuous_Wave_Radar::display();
            std::cout << "Displaying the values for the following FMCW signal " << std::endl;
            std::cout << "Bandwidth: " << bandwidth_ << " Hz" << std::endl;
            std::cout << "Chirp Duration: " << chirpDuration_ << " seconds" << std::endl;

            // Print out all of the valuse in the signalData vector
            for(double value : signalData){
                std::cout << "FMCW: " << value << std::endl;
            }
        }

        double getBandwidth() { return bandwidth_; }
        double getChirpDuration() { return chirpDuration_; }
        void setBandwidth(double newBandwidth) { bandwidth_ = newBandwidth; }
        void setChirpDuration(double newChirpDuration) { chirpDuration_ = newChirpDuration; }

    private:
        double bandwidth_;       // Bandwidth of the frequency sweep
        double chirpDuration_; 
};

#endif 