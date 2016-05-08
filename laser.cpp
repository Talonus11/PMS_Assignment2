#include "laser.h"
#include <iostream>
#include <cstdio>
#include "generator.h"

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
    portSet = false;
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

double* Laser::getArray()
{
    return scanValues;
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

void Laser::genArray()
{
    Generator myGen;
    double mean = 6.0;
    double stdDev = 5.0;
    if (angRes == ang_res0_) //If angular resolution is 15, generate array of 13 values populating all
    {
        for (int i = 0; i < 13; i++)
        {
            scanValues[i] = myGen.normalGenerator(mean,stdDev,maxDistance);
        }
    }
    if (angRes == ang_res1_) //If angular resolution is 30, generate array of 13 values populating only even slots
    {
        for (int i = 0; i < 13; i++)
        {
            if (i % 2 == 0)
            {
                scanValues[i] = myGen.normalGenerator(mean,stdDev,maxDistance);
            }
            if (i % 2 == 1)
            {
                scanValues[i] = NULL;
            }

        }
    }
}

bool Laser::disregard(double check) // checks if the value is clipped, and therefore should be disregarded
{
    if ((check == maxDistance) || (check == minDistance))
    {
        return true;
    }
    else return false;
}
