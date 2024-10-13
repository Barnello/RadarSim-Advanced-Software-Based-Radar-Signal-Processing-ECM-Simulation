// Author : Lucas Barnello 
// Purpose : Continous Wave Radar Signal Generation 

#ifndef CONTINOUS_WAVE_RADER_H
#define CONTINOUS_WAVE_RADER_H

#include "base_signal_gen.h"
#include <iostream>
#include <cmath>

class Continuous_Wave_Radar : public Base_Signal_Gen{
    public: 
        Continuous_Wave_Radar(double frequency, double amplitude, double sweepRate, double timeDuration)
        : Base_Signal_Gen(frequency, amplitude), sweepRate_(sweepRate), timeDuration_(timeDuration) {
        waveformType = "Continuous Wave";}

        //generate continuous signal 
        void generateSignal(double time) override{
            std::cout << "Generating Continuos wave signal " << std::endl;
            signalData.clear(); // Clear previous data
            for (double t = 0; t < time; t += time_step) {
                double signal_value = amplitude * std::cos(2 * M_PI * frequency * t);
                signalData.push_back(signal_value); // Store generated value
            }
        }

        void display() override{
            std::cout<< "Displaying the following continuous wave signal  " << std::endl;
            std::cout<< "--- Frequency: " << getFrequency() << "Hz" << std::endl;
            std::cout<< "--- Amplitude: " << getAmplitude() << std::endl;
            std::cout<< "--- Sweep Rate: " << sweepRate_ << "Hz/s" << std::endl;
            std::cout<< "--- Time Duration: " << timeDuration_ << "seconds" << std::endl;

            //Printing out all of the values in the signalData vector
            for (double value : signalData){
                std::cout << "CW: " << value << std::endl;
            }
        }

        double getSweepRate(){ return sweepRate_; }
        double getTimeDuration(){ return timeDuration_; }
        void setSweepRate(double newSweepRate){ sweepRate_ = newSweepRate; }
        void setTimeDuration(double newTimeDuration){ timeDuration_ = newTimeDuration; }

    private:
        double sweepRate_;
        double timeDuration_;
};

#endif
