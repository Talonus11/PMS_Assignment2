#include "radar.h"
#include <iostream>
#include <cstdio>

Radar::Radar()
{
    model = MODEL_;
    baud = baud0_;
    portNumber = port0_;
    portDir = PORT_STRING_;
    FOV = FOV1_;
    maxDistance = MAX_DISTANCE_;
    minDistance = MIN_DISTANCE_;
    portSet = false;
}

// GET Methods

string Radar::getModel()
{
    return model;
}

string Radar::getPortDir()
{
    return portDir;
}

int Radar::getPortNumber()
{
    return portNumber;
}

double Radar::getMaxDistance()
{
    return maxDistance;
}

double Radar::getMinDistance()
{
    return minDistance;
}

int Radar::getFOV()
{
    return FOV;
}

int Radar::getBaud()
{
    return baud;
}

int Radar::getArraySize()
{
    return a_size;
}

// SET Methods

//void Radar::setAngularResolution(double x)
//{
//    if (x == 0.5 || x == 1.0)
//        angularResolution = x;
//    else
//        printf("Error: Angular Resolution must be either 0.5 or 1.0.\n");
//}

int Radar::setPORT(int input)
{

    if (input == port0_)
    {
        portNumber = port0_;
        portSet = true;
        return 1;
    }
    else if (input == port1_)
    {
        portNumber = port1_;
        portSet = true;
        return 1;
    }
    else if (input == port2_)
    {
        portNumber = port2_;
        portSet = true;
        return 1;
    }
    else return 0;
}


//void Radar::setBaud(int x)
//{
//        if (x == 38400 || x == 115200)
//        baud = x;
//    else
//        printf("Error: Baud Rate must be either 38400 or 115200\n");
//}

// Other Methods
