// Author: Lucas Barnello
// Purpose: Providing a base class to the types of signals for RadarSim generation

#include <iostream>
#include <string>

class Base_Signal_Gen{
    private:
        int freq;
        std::string type;
    public: 
        virtual void show() = 0; // Used to print out the signal information to console in child classes
        virtual void display() = 0; // Used for displaying signal in child classes
};

