#include <iostream>
#include "continuous_wave_radar.h"
#include "fmcw_radar.h"
#include "pulse_radar.h"
#include <thread>
#include <exception>
int main() {
    // Create a continuous wave radar signal
    Continuous_Wave_Radar cwRadar(10e9, 1.0, 10000, 2);
    std::thread cwGen(&Continuous_Wave_Radar::generateSignal, &cwRadar, 1.0);
    std::thread cwDisplay(&Continuous_Wave_Radar::display, &cwRadar);

    cwGen.join();
    cwDisplay.join();
    // cwRadar.generateSignal(1.0);
    // cwRadar.display();

    // Create an FMCW radar signal
    // FMCW_Radar fmcwRadar(10e9, 1.0, 100, 5, 200e6, 1e-3);
    // fmcwRadar.generateSignal(1.0);
    // fmcwRadar.display();

    // Create a pulsed radar signal
    // Pulse_Radar pulseRadar(10e9, 1.0, 1e-6, 1e-3, 0.001);
    // pulseRadar.generateSignal(1.0);
    // pulseRadar.display();

    // Create a monopulse radar signal
    // Monopulse_Radar monoRadar(10e9, 1.0, 1e-6, 1e-3, 0.001, 45, 10);
    // monoRadar.generateSignal(1.0);
    // monoRadar.display();

    return 0;
}
