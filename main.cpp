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


int main( int argc, char ** argv )
{
    double dinput; // user input for doubles
    int uinput; // user input for ints
    cout << "Program started" << endl;
    Laser laser1;
    Radar radar1;
    Sonar sonar1;
    cout << "Rangers created" << endl;

    /******* LASER FIXED PARAMETERS PRINT *******/
    cout << "*****LASER*****" << endl;
    cout << "Fixed Parameters" << endl;
    cout << "Model: " << laser1.getModel() << endl;
    cout << "Field of View (FOV): " << laser1.getFOV() << "degrees" << endl;
    cout << "Scan range: " << laser1.getMinDistance() << "m - " << laser1.getMaxDistance() << "m" << endl << endl;

    /******* LASER SETTING PARAMETERS *******/
    cout << "Setting non-fixed parameters" << endl;

    /*** PORT SET ***/
    cout << "Default Port: " << laser1.getPortDir() << laser1.getPortNumber() << endl;
    cout << "Set Port Number (0,1,2) " << laser1.getPortDir();
    cin >> uinput;

    if (laser1.setPORT(uinput) == 0)
    {
        cout << "Unable to set port - incorrect value entered. Reverting to default: " << laser1.getPortNumber() << endl;
    }
    cout << "Port set to: " << laser1.getPortDir() << laser1.getPortNumber() << endl;




    return 0;
}

