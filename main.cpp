#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <random>
#include "generator.h"
#include <string>

#include "radar.h"
#include "ranger.h"
#include "sonar.h"
#include "laser.h"

using namespace std;

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


int main( int argc, char ** argv )
{
    int uinput; // user input for ints
    cout << "Program started" << endl;
    Laser laser1;
    Radar radar1;
    Sonar sonar1;
    cout << "Rangers created" << endl;

    //////////////////////////////////////////////
    /******* LASER FIXED PARAMETERS PRINT *******/
    //////////////////////////////////////////////

    cout << "*****LASER*****" << endl;
    cout << "Fixed Parameters" << endl;
    cout << "Model: " << laser1.getModel() << endl;
    cout << "Field of View (FOV): " << laser1.getFOV() << "degrees" << endl;
    cout << "Scan range: " << laser1.getMinDistance() << "m - " << laser1.getMaxDistance() << "m" << endl << endl;

    //////////////////////////////////////////
    /******* LASER SETTING PARAMETERS *******/
    //////////////////////////////////////////

    cout << "Setting non-fixed parameters" << endl;


    /**** PORT SET ****/

    cout << "Default Port: " << laser1.getPortDir() << laser1.getPortNumber() << endl;
    cout << "Set Port Number (0,1,2) " << laser1.getPortDir();
    cin >> uinput;

    if (laser1.setPORT(uinput) == 0) // checks setPort method was successful (returns 1)
    {
        cout << "Unable to set port - incorrect value entered. Reverting to default: " << laser1.getPortNumber() << endl;
        port0Taken = true;
    }
    cout << "Port set to: " << laser1.getPortDir() << laser1.getPortNumber() << endl << endl;
    switch (uinput)
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


    /**** BAUD SET ****/

    cout << "Default Baud: " << laser1.getBaud() << endl;
    cout << "Set Baud (38400 or 115200): ";
    cin >> uinput;

    if (laser1.setBaud(uinput) == 0) // checks setPort method was successful (returns 1)
    {
        cout << "Unable to set Baud - incorrect value entered. Reverting to default: " << laser1.getBaud() << endl;
    }
    cout << "Baud set to: " << laser1.getBaud() << endl << endl;


    /**** ANGULAR RESOLUTION SET ****/

    cout << "Default Angular Resolution (AngRes): " << laser1.getAngularResolution() << endl;
    cout << "Set AngRes (15 or 30) degrees: ";
    cin >> uinput;

    if (laser1.setAngularResolution(uinput) == 0) // checks setPort method was successful (returns 1)
    {
        cout << "Unable to set AngRes - incorrect value entered. Reverting to default: " << laser1.getAngularResolution() << endl;
    }
    cout << "AngRes set to: " << laser1.getAngularResolution() << endl << endl;


    /**** LASER ALL PARAMETERS PRINT ****/

    cout << "----- FINAL SET VALUES -----" << endl;
    cout << "Model: " << laser1.getModel() << endl;
    cout << "Baud: " << laser1.getBaud() << endl;
    cout << "Port: " << laser1.getPortDir() << laser1.getPortNumber() << endl;
    cout << "FOV: " << laser1.getFOV() << endl;
    cout << "AngRes: " << laser1.getAngularResolution() << endl;
    cout << "Min Distance: " << laser1.getMinDistance() << endl;
    cout << "Max Distance: " << laser1.getMaxDistance() << endl;
    cout << endl;


    //////////////////////////////////////////////
    /******* RADAR FIXED PARAMETERS PRINT *******/
    //////////////////////////////////////////////

    cout << "*****RADAR*****" << endl;
    cout << "Fixed Parameters" << endl;
    cout << "Model: " << radar1.getModel() << endl;
    cout << "Scan range: " << radar1.getMinDistance() << "m - " << radar1.getMaxDistance() << "m" << endl << endl;


    //////////////////////////////////////////
    /******* RADAR SETTING PARAMETERS *******/
    //////////////////////////////////////////

    cout << "Setting non-fixed parameters" << endl;


    /**** PORT SET ****/

    cout << "Default Port: " << radar1.getPortDir() << radar1.getPortNumber() << endl;
    cout << "Set Port Number (0,1,2) " << radar1.getPortDir();
    cin >> uinput;

    if (uinput != laser1.getPortNumber()) // checks if the port entered clashes with the laser sensor port
    {
        if (radar1.setPORT(uinput) == 0) // checks setPort method was successful (returns 1)
        {
            cout << "Unable to set port - incorrect value entered. Choosing next available port." << endl;

        }
        else // success
        {
            cout << "Port set to: " << radar1.getPortNumber() << endl;
        }
    }
    else //clashes
    {
        cout << "Port unavailable. Choosing next available port. " << endl;
        if (radar1.setPORT(nextPort()) == 1) // gets next free port, sends it to be set, then checks it was successful
        {
            cout << "Port set to: " << radar1.getPortNumber() << endl;
        }
    }


    /**** FOV SET ****/

    cout << "Default FOV: " << radar1.getFOV() << endl;
    cout << "Set FOV (20 or 40) degrees: ";
    cin >> uinput;

    if (radar1.setFOV(uinput) == 0) // checks setPort method was successful (returns 1)
    {
        cout << "Unable to set FOV - incorrect value entered. Reverting to default: " << radar1.getFOV() << endl;
    }
    cout << "FOV set to: " << radar1.getFOV() << endl << endl;

    return 0;
}

