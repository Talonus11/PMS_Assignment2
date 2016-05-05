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

int Laser::setAngularResolution(int input)
{
    if (input == ang_res0_)
    {
        angRes = ang_res0_;
        return 1;
    }
    else if (input == ang_res1_)
    {
        angRes = ang_res1_;
        return 1;
    }
    else return 0;
}

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

int Laser::setBaud(int input)
{
    if (input == baud0_)
    {
        baud = baud0_;
        return 1;
    }
    else if (input == baud1_)
    {
        baud = baud1_;
        return 1;
    }
    else return 0;
}

// Other Methods
void Laser::calcArraySize()
{
    a_size = FOV/angRes;
}
