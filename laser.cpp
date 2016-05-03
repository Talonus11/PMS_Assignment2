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

//void Laser::setPORT(int x)
//{
//    switch (x)
//    {
//        case 0:
//            PORT = "USB: /dev/ttyACM0";
//            break;
//        case 1:
//            PORT = "USB: /dev/ttyACM1";
//            break;
//        case 2:
//            PORT = "USB: /dev/ttyACM2";
//            break;
//        default:
//            printf("Error: Port Number must be either 0, 1 or 2.\n");
//    }
//}

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
