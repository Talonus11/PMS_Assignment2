#ifndef RADAR_H
#define RADAR_H
#include <string>
#include "ranger.h"

using namespace std;

class Radar : public Ranger
{
public:
    Radar();

// GET Methods
    string getModel();
    string getPortDir();
    double getMinDistance();
    double getMaxDistance();
    double getAngularResolution();
    int getFOV();
    int getPortNumber();
    int getBaud();
    double* getArray();

// SET Methods
    int setPORT(int);
    int setFOV(int);
    int setBaud(int);

    double* genArray();
    void calcArraySize();

private:

    //Sensor Variables
    string model;
    unsigned int baud;
    unsigned int portNumber;
    string portDir;
    unsigned int FOV;
    double maxDistance;
    double minDistance;
    bool portSet;
    int angRes;
    double scanValues[13];


    //Sensor Variable Options
    const int FOV1_ = 20;
    const int FOV2_ = 40;
    const string MODEL_ = "RAD-001";
    const double MIN_DISTANCE_ = 0.2;
    const double MAX_DISTANCE_ = 16.0;
    const string PORT_STRING_ = "USB: /dev/ttyACM";
    const int port0_ = 0;
    const int port1_ = 1;
    const int port2_ = 2;
    const int baud0_ = 38400;
    const int baud1_ = 115200;

};

#endif // RADAR_H
