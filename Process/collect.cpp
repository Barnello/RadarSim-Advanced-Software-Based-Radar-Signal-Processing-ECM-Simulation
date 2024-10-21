// This class will collect the data from the waveforms to store into a database and further process
// Database: SQLLite 
#include <iostream>
#include <sqlite3.h>


// use to create database for waveforms
// file name will be provided and databse sql functionality will be organized in this class
class Waveform_Database{

    private: 
        const char* filename; // filename to the database 
        sqlite* database; // pointer to the 
    
    public: 
        // Open the database 
        // func here 

        // Write to the database 
        // func here 

        // Read from the database 
        // func here 
};


int main(){

    return 0;
}