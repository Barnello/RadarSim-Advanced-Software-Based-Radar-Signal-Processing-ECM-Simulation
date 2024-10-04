//Author: Lucas Barnello
//Purpose: Creating a synthetic pulse signal programatically


#include <iostream>
#include "pulse_radar.h"

// class Pulse_Radar : public Base_Signal_Gen {
//     private:
//         double freq;
        
//     public:
//         void show(){
//             std::cout << "--- Pulse Radar Signal Information ---" << std::endl;
//         }
//         void display(){
//             std::cout << "--- Pulse Radar Signal Displayed ---" << std::endl;
//         }

// };

void Pulse_Radar::show(){
    std::cout << "--- Pulse Radar Signal Information ---" << std::endl;
}

void Pulse_Radar::display(){
    std::cout << "--- Pulse Radar Signal Displayed ---" << std::endl;
}

int main(){
    Pulse_Radar p; 
    p.show();
    p.display();

    return 0;
}