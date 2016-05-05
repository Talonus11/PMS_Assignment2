#ifndef LASER_H
#define LASER_H
#include <string>
#include "ranger.h"

using namespace std;

class Laser : public Ranger
{
public:
    Laser();

// GET Methods
    string getModel();
    string getPortDir();
    double getMinDistance();
    double getMaxDistance();
    double getAngularResolution();
    int getFOV();
    int getPortNumber();
    int getBaud();
    int getArraySize();

// SET Methods
    void setBaud(int);
    void setPortNumber(int);
    void setAngularResolution(double);
    void setScanningTime(int);
    int setPORT(int);

    void calcArraySize();

private:

    //Sensor Variables
    string model;
    unsigned int baud;
    unsigned int portNumber;
    string portDir;
    unsigned int FOV;
    unsigned int angRes;
    double maxDistance;
    double minDistance;


    //Sensor Variable Options
    const int FOV_ = 180;
    const string MODEL_ = "UTM-XXL";
    const double MIN_DISTANCE_ = 0.2;
    const double MAX_DISTANCE_ = 8.0;
    const string PORT_STRING_ = "USB: /dev/ttyACM";
    const int port0_ = 0;
    const int port1_ = 1;
    const int port2_ = 2;
    const int baud0_ = 38400;
    const int baud1_ = 115200;
    const double ang_res0_ = 15;
    const double ang_res1_ = 30;

    int a_size = 0;
};

#endif // LASER_H
