/* Assignment 2
 * Chris Schiller 11377773
 *
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <array>

#include "generator.h"
#include "radar.h"
#include "ranger.h"
#include "sonar.h"
#include "laser.h"
#include "rangerfusion.h"

using namespace std;

// This if statement determines if the program is being run in windows or linux, and sets "delay()" to refer to the correct platform method for delaying code

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

  #include <windows.h>

  inline void delay( unsigned long ms )
    {
        Sleep( ms );
    }

#else  /* presume POSIX */

  #include <unistd.h>

  inline void delay( unsigned long ms )
    {
        usleep( ms * 1000 );
    }

#endif

bool port0Taken = false;
bool port1Taken = false;
bool port2Taken = false;

/*
 *  nextPort method returns the number (int) of the next free port. eg. if port 0 is taken, it will return 1; if port 1 and 2 are taken, will return 0
 */

int nextPort()
{
    if (port0Taken)
    {
        if (port1Taken)
        {
            return 2;
        }
        else return 1;
    }
    else return 0;
}

/*
 *  portTaken method takes an input between 0 and 2 and sets the relevant portTaken variable to true
 */

void portTaken(int input)
{
    switch (input)
    {
        case 0:
            port0Taken = true;
            break;
        case 1:
            port1Taken = true;
            break;
        case 2:
            port2Taken = true;
            break;
    }
}



int main( int argc, char ** argv )
{
    int uinput; // user input for ints
    cout << "Program started" << endl;
    Laser laser1;
    Radar radar1;
    Sonar sonar1;
    cout << "Rangers created" << endl;


    Ranger* tempArray[3]; // stores one of each type of sensor in an array. Note that they can be reordered any way desired
    tempArray[2] = &laser1;
    tempArray[0] = &radar1;
    tempArray[1] = &sonar1;

    Ranger* rangerArray[3];
    cout << "Ranger Array created" << endl;


//     Sort array so that:
//     laser (sensorType = 0) is slot 0
//     radar (sensorType = 1) is slot 1
//     sonar (sensorType = 2) is slot 2
//     NB: This code still assumes that there is only one of each sensor type

    for (int i = 0; i < 3; i++)
    {
        if ((tempArray[i]->getSensorType()) == 0)
            rangerArray[0] = tempArray[i];
        if ((tempArray[i]->getSensorType()) == 1)
            rangerArray[1] = tempArray[i];
        if ((tempArray[i]->getSensorType()) == 2)
            rangerArray[2] = tempArray[i];
    }

    //////////////////////////////////////////////
    /******* LASER FIXED PARAMETERS PRINT *******/
    //////////////////////////////////////////////

    cout << "*****LASER*****" << endl;
    cout << "Fixed Parameters" << endl;
    cout << "Model: " << rangerArray[0]->getModel() << endl;
    cout << "Field of View (FOV): " << rangerArray[0]->getFOV() << "degrees" << endl;
    cout << "Scan range: " << rangerArray[0]->getMinDistance() << "m - " << rangerArray[0]->getMaxDistance() << "m" << endl << endl;

    //////////////////////////////////////////
    /******* LASER SETTING PARAMETERS *******/
    //////////////////////////////////////////

    cout << "Setting non-fixed parameters" << endl;


    /**** PORT SET ****/

    cout << "Default Port: " << rangerArray[0]->getPortDir() << rangerArray[0]->getPortNumber() << endl;
    cout << "Set Port Number (0,1,2) " << rangerArray[0]->getPortDir();
    cin >> uinput;

    if (rangerArray[0]->setPORT(uinput) == 0) // checks setPort method was successful (returns 1)
    {
        cout << "Unable to set port - incorrect value entered. Reverting to default: " << rangerArray[0]->getPortNumber() << endl;
        port0Taken = true;
    }
    cout << "Port set to: " << rangerArray[0]->getPortDir() << rangerArray[0]->getPortNumber() << endl << endl;
    portTaken(uinput);


    /**** BAUD SET ****/

    cout << "Default Baud: " << rangerArray[0]->getBaud() << endl;
    cout << "Set Baud (38400 or 115200): ";
    cin >> uinput;

    if (rangerArray[0]->setBaud(uinput) == 0) // checks setBaud method was successful (returns 1)
    {
        cout << "Unable to set Baud - incorrect value entered. Reverting to default: " << rangerArray[0]->getBaud() << endl;
    }
    cout << "Baud set to: " << rangerArray[0]->getBaud() << endl << endl;


    /**** ANGULAR RESOLUTION SET ****/

    cout << "Default Angular Resolution (AngRes): " << rangerArray[0]->getAngularResolution() << endl;
    cout << "Set AngRes (15 or 30) degrees: ";
    cin >> uinput;

    if (rangerArray[0]->setAngularResolution(uinput) == 0) // checks setAngRes method was successful (returns 1)
    {
        cout << "Unable to set AngRes - incorrect value entered. Reverting to default: " << rangerArray[0]->getAngularResolution() << endl;
    }
    cout << "AngRes set to: " << rangerArray[0]->getAngularResolution() << endl << endl;


    /**** LASER ALL PARAMETERS PRINT ****/

    cout << "----- FINAL SET VALUES -----" << endl;
    cout << "Model: " << rangerArray[0]->getModel() << endl;
    cout << "Baud: " << rangerArray[0]->getBaud() << endl;
    cout << "Port: " << rangerArray[0]->getPortDir() << rangerArray[0]->getPortNumber() << endl;
    cout << "FOV: " << rangerArray[0]->getFOV() << endl;
    cout << "AngRes: " << rangerArray[0]->getAngularResolution() << endl;
    cout << "Min Distance: " << rangerArray[0]->getMinDistance() << endl;
    cout << "Max Distance: " << rangerArray[0]->getMaxDistance() << endl;
    cout << endl;


    //////////////////////////////////////////////
    /******* RADAR FIXED PARAMETERS PRINT *******/
    //////////////////////////////////////////////

    cout << "*****RADAR*****" << endl;
    cout << "Fixed Parameters" << endl;
    cout << "Model: " << rangerArray[1]->getModel() << endl;
    cout << "Scan range: " << rangerArray[1]->getMinDistance() << "m - " << rangerArray[1]->getMaxDistance() << "m" << endl << endl;


    //////////////////////////////////////////
    /******* RADAR SETTING PARAMETERS *******/
    //////////////////////////////////////////

    cout << "Setting non-fixed parameters" << endl;


    /**** PORT SET ****/

    cout << "Default Port: " << rangerArray[1]->getPortDir() << rangerArray[1]->getPortNumber() << endl;
    cout << "Set Port Number (0,1,2) " << rangerArray[1]->getPortDir();
    cin >> uinput;

    if (uinput != rangerArray[0]->getPortNumber()) // checks if the port entered clashes with the laser sensor port
    {
        // Does not clash with laser
        if (rangerArray[1]->setPORT(uinput) == 0) // checks setPort method was successful (returns 1)
        {
            cout << "Unable to set port - incorrect value entered. Choosing next available port." << endl;
            if (rangerArray[1]->setPORT(nextPort()) == 1) // gets next free port, sends it to be set, then checks it was successful
            {
                cout << "Port set to: " << rangerArray[1]->getPortNumber() << endl;
                portTaken(nextPort()); // sets portTaken to true for port that has been set
            }

        }
        else // success
        {
            cout << "Port set to: " << rangerArray[1]->getPortNumber() << endl;
            portTaken(uinput); // sets portTaken to true for port that has been set
        }
    }
    else // clashes
    {
        cout << "Port unavailable. Choosing next available port. " << endl;
        if (rangerArray[1]->setPORT(nextPort()) == 1) // gets next free port, sends it to be set, then checks it was successful
        {
            cout << "Port set to: " << rangerArray[1]->getPortNumber() << endl;
            portTaken(nextPort()); // sets portTaken to true for port that has been set
        }
    }


    /**** BAUD SET ****/

    cout << "Default Baud: " << rangerArray[1]->getBaud() << endl;
    cout << "Set Baud (38400 or 115200): ";
    cin >> uinput;

    if (rangerArray[1]->setBaud(uinput) == 0) // checks setBaud method was successful (returns 1)
    {
        cout << "Unable to set Baud - incorrect value entered. Reverting to default: " << rangerArray[1]->getBaud() << endl;
    }
    cout << "Baud set to: " << rangerArray[1]->getBaud() << endl << endl;


    /**** FOV SET ****/

    cout << "Default FOV: " << rangerArray[1]->getFOV() << endl;
    cout << "Set FOV (20 or 40) degrees: ";
    cin >> uinput;

    if (rangerArray[1]->setFOV(uinput) == 0) // checks setPort method was successful (returns 1)
    {
        cout << "Unable to set FOV - incorrect value entered. Reverting to default: " << rangerArray[1]->getFOV() << endl;
    }
    cout << "FOV set to: " << rangerArray[1]->getFOV() << endl << endl;


    /**** RADAR ALL PARAMETERS PRINT ****/

    cout << "----- FINAL SET VALUES -----" << endl;
    cout << "Model: " << rangerArray[1]->getModel() << endl;
    cout << "Baud: " << rangerArray[1]->getBaud() << endl;
    cout << "Port: " << rangerArray[1]->getPortDir() << rangerArray[1]->getPortNumber() << endl;
    cout << "FOV: " << rangerArray[1]->getFOV() << endl;
    cout << "Min Distance: " << rangerArray[1]->getMinDistance() << endl;
    cout << "Max Distance: " << rangerArray[1]->getMaxDistance() << endl;
    cout << endl;


    //////////////////////////////////////////////
    /******* SONAR FIXED PARAMETERS PRINT *******/
    //////////////////////////////////////////////

    cout << "*****SONAR*****" << endl;
    cout << "Fixed Parameters" << endl;
    cout << "Model: " << rangerArray[2]->getModel() << endl;
    cout << "Scan range: " << rangerArray[2]->getMinDistance() << "m - " << rangerArray[2]->getMaxDistance() << "m" << endl << endl;


    //////////////////////////////////////////
    /******* SONAR SETTING PARAMETERS *******/
    //////////////////////////////////////////

    cout << "Setting non-fixed parameters" << endl;


    /**** PORT SET ****/

    cout << "Default Port: " << rangerArray[2]->getPortDir() << rangerArray[2]->getPortNumber() << endl;
    cout << "Set Port Number (0,1,2) " << rangerArray[2]->getPortDir();
    cin >> uinput;

    if ((uinput != rangerArray[0]->getPortNumber()) && (uinput != rangerArray[1]->getPortNumber())) // checks if the port entered clashes with the laser sensor port or radar port
    {
        // Does not clash with laser or radar
        if (rangerArray[2]->setPORT(uinput) == 0) // checks setPort method was successful (returns 1)
        {
            cout << "Unable to set port - incorrect value entered. Choosing next available port." << endl;
            if (rangerArray[2]->setPORT(nextPort()) == 1) // gets next free port, sends it to be set, then checks it was successful
            {
                cout << "Port set to: " << rangerArray[2]->getPortNumber() << endl;
                portTaken(nextPort()); // sets portTaken to true for port that has been set
            }

        }
        else // success
        {
            cout << "Port set to: " << rangerArray[2]->getPortNumber() << endl;
            portTaken(uinput); // sets portTaken to true for port that has been set
        }
    }
    else // clashes
    {
        cout << "Port unavailable. Choosing next available port. " << endl;
        if (rangerArray[2]->setPORT(nextPort()) == 1) // gets next free port, sends it to be set, then checks it was successful
        {
            cout << "Port set to: " << rangerArray[2]->getPortNumber() << endl;
            portTaken(nextPort()); // sets portTaken to true for port that has been set
        }
    }


    /**** BAUD SET ****/

    cout << "Default Baud: " << rangerArray[2]->getBaud() << endl;
    cout << "Set Baud (38400 or 115200): ";
    cin >> uinput;

    if (rangerArray[2]->setBaud(uinput) == 0) // checks setBaud method was successful (returns 1)
    {
        cout << "Unable to set Baud - incorrect value entered. Reverting to default: " << rangerArray[2]->getBaud() << endl;
    }
    cout << "Baud set to: " << rangerArray[2]->getBaud() << endl << endl;


    /**** LASER ALL PARAMETERS PRINT ****/

    cout << "----- LASER FINAL SET VALUES -----" << endl;
    cout << "Model: " << rangerArray[0]->getModel() << endl;
    cout << "Baud: " << rangerArray[0]->getBaud() << endl;
    cout << "Port: " << rangerArray[0]->getPortDir() << rangerArray[0]->getPortNumber() << endl;
    cout << "FOV: " << rangerArray[0]->getFOV() << endl;
    cout << "AngRes: " << rangerArray[0]->getAngularResolution() << endl;
    cout << "Min Distance: " << rangerArray[0]->getMinDistance() << endl;
    cout << "Max Distance: " << rangerArray[0]->getMaxDistance() << endl;
    cout << endl;

    /**** RADAR ALL PARAMETERS PRINT ****/

    cout << "----- RADAR FINAL SET VALUES -----" << endl;
    cout << "Model: " << rangerArray[1]->getModel() << endl;
    cout << "Baud: " << rangerArray[1]->getBaud() << endl;
    cout << "Port: " << rangerArray[1]->getPortDir() << rangerArray[1]->getPortNumber() << endl;
    cout << "FOV: " << rangerArray[1]->getFOV() << endl;
    cout << "Min Distance: " << rangerArray[1]->getMinDistance() << endl;
    cout << "Max Distance: " << rangerArray[1]->getMaxDistance() << endl;
    cout << endl;

    /**** SONAR ALL PARAMETERS PRINT ****/

    cout << "----- SONAR FINAL SET VALUES -----" << endl;
    cout << "Model: " << rangerArray[2]->getModel() << endl;
    cout << "Baud: " << rangerArray[2]->getBaud() << endl;
    cout << "Port: " << rangerArray[2]->getPortDir() << rangerArray[2]->getPortNumber() << endl;
    cout << "FOV: " << rangerArray[2]->getFOV() << endl;
    cout << "Min Distance: " << rangerArray[2]->getMinDistance() << endl;
    cout << "Max Distance: " << rangerArray[2]->getMaxDistance() << endl;
    cout << endl;

    RangerFusion fusion;
    cout << "Choose fusion method (min = 0, avg = 1, max = 2): " << endl;
    cin >> uinput;

    double outputArray[10000][13]; // Creates a 2 dimensional array. The first value (column) will be used to store up to 10,000 arrays of values. The second is the array of values generated by fusion
    int y = 0; //The counter for sequence, and mover between arrays


    if (uinput == 0) // Minimum
    {
        while(1)
        {
            cout << "Minimum Values" << endl;
            fusion.minFusion(rangerArray);
            for (int i = 0; i < 13; i++)
            {
                outputArray[y][i] = (fusion.getArray())[i]; // Populates the output Array with all 13 values from fusion
                cout << "Sequence #[" << y <<"]:["<< i*15 << "] = " << outputArray[y][i] << endl;
            }
            cout << endl;
            y++;
            delay(1000);
        }
    }

    if (uinput == 1) // Average
    {
        while(1)
        {
            cout << "Average Values" << endl;
            fusion.avgFusion(rangerArray);
            for (int i = 0; i < 13; i++)
            {
                outputArray[y][i] = (fusion.getArray())[i]; // Populates the output Array with all 13 values from fusion
                cout << "Sequence #[" << y <<"]:["<< i*15 << "] = " << outputArray[y][i] << endl;
            }
            cout << endl;
            y++;
            delay(1000);
        }
    }

    if (uinput == 2) // Maximum
    {
        while(1)
        {
            cout << "Maximum Values" << endl;
            fusion.maxFusion(rangerArray);
            for (int i = 0; i < 13; i++)
            {
                outputArray[y][i] = (fusion.getArray())[i]; // Populates the output Array with all 13 values from fusion
                cout << "Sequence #[" << y <<"]:["<< i*15 << "] = " << outputArray[y][i] << endl;
            }
            cout << endl;
            y++;
            delay(1000);
        }
    }

    return 0;
}

