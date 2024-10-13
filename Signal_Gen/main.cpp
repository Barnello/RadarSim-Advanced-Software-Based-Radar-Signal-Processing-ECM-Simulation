#include <iostream>
#include "continuous_wave_radar.h"
#include "fmcw_radar.h"
#include "pulse_radar.h"
#include <thread>
#include <exception>
int main() {
    // Create a continuous wave radar signal
    Continuous_Wave_Radar cwRadar(10e9, 1.0, 100, 3);
    std::thread cwGen(&Continuous_Wave_Radar::generateSignal, &cwRadar, 1.0);
    std::thread cwDisplay(&Continuous_Wave_Radar::display, &cwRadar);

    // Create an FMCW radar signal
    FMCW_Radar fmcwRadar(10e9, 1.0, 100, 5, 200e6, 1e-3);
    std::thread fmcwGen(&FMCW_Radar::generateSignal, &fmcwRadar, 1.0);
    std::thread fmcwDisplay(&FMCW_Radar::display, &fmcwRadar);

    // Create a pulsed radar signal
    Pulse_Radar pulseRadar(10e9, 1.0, 1e-6, 1e-3, 0.001);
    std::thread pulseGen(&Pulse_Radar::generateSignal, &pulseRadar, 1.0);
    std::thread pulseDisplay(&Pulse_Radar::display, &pulseRadar);

    cwGen.join();
    cwDisplay.join();
    fmcwGen.join();
    fmcwDisplay.join();
    pulseGen.join();
    pulseDisplay.join();

    return 0;
}
