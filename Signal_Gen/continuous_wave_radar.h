// Author : Lucas Barnello 
// Purpose : Continous Wave Radar Signal Generation 

#ifndef CONTINOUS_WAVE_RADER_H
#define CONTINOUS_WAVE_RADER_H

#include "base_signal_gen.h"
#include <iostream>

class Continuous_Wave_Radar : public Base_Signal_Gen{
    public: 
        Continuous_Wave_Radar(double frequency, double amplitude, double sweepRate, double timeDuration)
        : Base_Signal_Gen(frequency, amplitude), sweepRate_(sweepRate), timeDuration_(timeDuration) {
        waveformType = "Continuous Wave";}

        //generate continuous signal 
        void generateSignal(double time) override{
            std::cout << "Generating Continuos wave signal " << std::endl;
        }

        void display() override{
            std::cout<< "--- Continous Wave Radar Signal " << std::endl;
            std::cout<< "--- Frequency: " << getFrequency() << "Hz" << std::endl;
            std::cout<< "--- Amplitude: " << getAmplitude() << std::endl;
            std::cout<< "--- Sweep Rate: " << sweepRate_ << "Hz/s" << std::endl;
            std::cout<< "--- Time Duration: " << timeDuration_ << "seconds" << std::endl;
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
