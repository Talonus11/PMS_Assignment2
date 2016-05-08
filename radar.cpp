#include "radar.h"
#include <iostream>
#include <cstdio>
#include "generator.h"

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
    angRes = FOV;
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

double Radar::getAngularResolution()
{
    return -1.0;
}

double* Radar::getArray()
{
    return scanValues;
}

// SET Methods

int Radar::setFOV(int input)
{
    if (input == FOV1_)
    {
        FOV = FOV1_;
        return 1;
    }
    else if (input == FOV2_)
    {
        FOV = FOV2_;
        return 1;
    }
    else return 0;
}

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


int Radar::setBaud(int input)
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

double* Radar::genArray()
{
    Generator myGen;
    double mean = 6.0;
    double stdDev = 5.0;
    double outputArray[13];
    if (FOV == FOV1_) //If FOV is 20, generate array of 13 values populating only array slot 6 with a generated value
    {
        for (int i = 0; i < 13; i++)
        {
            if (i == 6)
            {
                outputArray[i] = myGen.normalGenerator(mean,stdDev,maxDistance);
            }
            else
            {
                outputArray[i] = NULL;
            }
        }
    }
    if (FOV == FOV2_) //If FOV is 40, generate array of 13 values populating only array slots 5, 6 and 7 with the same value
    {
        for (int i = 0; i < 13; i++)
        {
            if (i == 7)
            {
                outputArray[5] = myGen.normalGenerator(mean,stdDev,maxDistance);
                outputArray[6] = myGen.normalGenerator(mean,stdDev,maxDistance);
                outputArray[7] = myGen.normalGenerator(mean,stdDev,maxDistance);
            }
            else
            {
                outputArray[i] = NULL;
            }
        }
    }

    for (int i = 0; i < 13; i++)
    {
        cout << "DEBUG: generated array [" << i << "] = " << outputArray[i] << endl;
    }
}
