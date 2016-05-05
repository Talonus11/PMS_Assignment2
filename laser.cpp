#include "laser.h"
#include <iostream>
#include <cstdio>

Laser::Laser()
{
    model = MODEL_;
    baud = baud0_;
    portNumber = port0_;
    portDir = PORT_STRING_;
    FOV = FOV_;
    angRes = ang_res0_;
    maxDistance = MAX_DISTANCE_;
    minDistance = MIN_DISTANCE_;
}

// GET Methods

string Laser::getModel()
{
    return model;
}

string Laser::getPortDir()
{
    return portDir;
}

int Laser::getPortNumber()
{
    return portNumber;
}

double Laser::getMaxDistance()
{
    return maxDistance;
}

double Laser::getMinDistance()
{
    return minDistance;
}

double Laser::getAngularResolution()
{
    return angRes;
}

int Laser::getFOV()
{
    return FOV;
}

int Laser::getBaud()
{
    return baud;
}

int Laser::getArraySize()
{
    return a_size;
}

// SET Methods

//void Laser::setAngularResolution(double x)
//{
//    if (x == 0.5 || x == 1.0)
//        angularResolution = x;
//    else
//        printf("Error: Angular Resolution must be either 0.5 or 1.0.\n");
//}

int Laser::setPORT(int input)
{
    if (input == port0_)
    {
        portNumber = port0_;
        return 1;
    }
    else if (input == port1_)
    {
        portNumber = port1_;
        return 1;
    }
    else if (input == port2_)
    {
        portNumber = port2_;
        return 1;
    }
    else return 0;
}

//void Laser::setBaud(int x)
//{
//        if (x == 38400 || x == 115200)
//        baud = x;
//    else
//        printf("Error: Baud Rate must be either 38400 or 115200\n");
//}

// Other Methods
void Laser::calcArraySize()
{
    a_size = FOV/angRes;
}
