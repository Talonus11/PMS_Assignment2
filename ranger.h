#ifndef RANGER_H
#define RANGER_H

#include <string>

using namespace std;


class Ranger
{
public:
    Ranger();

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
};

#endif // RANGER_H
