#ifndef RANGER_H
#define RANGER_H

#include <string>

using namespace std;


class Ranger
{
public:
    Ranger();

// GET Methods
    virtual string getModel(void) = 0;
    virtual string getPortDir(void) = 0;
    virtual double getMinDistance(void) = 0;
    virtual double getMaxDistance(void) = 0;
    virtual double getAngularResolution(void) = 0;
    virtual int getFOV(void) = 0;
    virtual int getPortNumber(void) = 0;
    virtual int getBaud(void) = 0;
    virtual double* getArray(void) = 0;
    virtual bool disregard(double check) = 0;
    virtual void genArray(void) = 0;
};

#endif // RANGER_H
