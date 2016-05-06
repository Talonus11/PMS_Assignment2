#ifndef SONAR_H
#define SONAR_H
#include <string>
#include "ranger.h"

using namespace std;

class Sonar : public Ranger
{
public:
    Sonar();

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
    void setPORT(int);

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


    //Sensor Variable Options
    const int FOV_ = 90;
    const string MODEL_ = "SONX-001";
    const double MIN_DISTANCE_ = 0.2;
    const double MAX_DISTANCE_ = 4.0;
    const string PORT_STRING_ = "USB: /dev/ttyACM";
    const int port0_ = 0;
    const int port1_ = 1;
    const int port2_ = 2;
    const int baud0_ = 38400;
    const int baud1_ = 115200;

    int a_size = 0;
};

#endif // SONAR_H
