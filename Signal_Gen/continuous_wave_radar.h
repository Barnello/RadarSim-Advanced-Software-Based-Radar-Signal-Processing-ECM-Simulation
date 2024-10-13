// Author : Lucas Barnello 
// Purpose : Continous Wave Radar Signal Generation 

#ifndef CONTINOUS_WAVE_RADER_H
#define CONTINOUS_WAVE_RADER_H

#include "base_signal_gen.h"
#include <iostream>
#include <cmath>
#include <mutex>
#include <chrono>
#include <unistd.h>

class Continuous_Wave_Radar : public Base_Signal_Gen{
    public: 
        Continuous_Wave_Radar(double frequency, double amplitude, double sweepRate, double timeDuration)
        : Base_Signal_Gen(frequency, amplitude), sweepRate (sweepRate), timeDuration (timeDuration) {
        waveformType = "Continuous Wave";}

        //generate continuous signal 
        void generateSignal(double time = 0) override{
            std::cout << "Generating Continuos wave signal " << std::endl;
            signalData.clear(); // Clear previous data
            
            while (time < timeDuration) {
                // Lock mutex to prevent other threads from accessing shared data
                {
                    std::lock_guard<std::mutex> lock(mtx);

                    double signal_value = amplitude * sin(2 * M_PI * frequency * time);
                    signalData.push_back(signal_value); // Store the generated signal value
                    //std::cout << "Current time: " << time << std::endl;
                }
                
                time += time_step ; 
            }
        }

        void display() override{
            std::cout<< "Displaying the following continuous wave signal  " << std::endl;
            std::cout<< "--- Frequency: " << getFrequency() << "Hz" << std::endl;
            std::cout<< "--- Amplitude: " << getAmplitude() << std::endl;
            std::cout<< "--- Sweep Rate: " << sweepRate << "Hz/s" << std::endl;
            std::cout<< "--- Time Duration: " << timeDuration << "seconds" << std::endl;

            //Printing out all of the values in the signalData vector
            std::lock_guard<std::mutex> lock(mtx);

            for (double value : signalData){
                // mtx.lock();
                std::cout << "CW: " << value << std::endl;
                // mtx.unlock();
            }
        }

        double getSweepRate(){ return sweepRate; }
        double getTimeDuration(){ return timeDuration; }
        void setSweepRate(double newSweepRate){ sweepRate = newSweepRate; }
        void setTimeDuration(double newTimeDuration){ timeDuration = newTimeDuration; }

    private:
        std::mutex mtx;
        double sweepRate;
        double timeDuration;
};

#endif
