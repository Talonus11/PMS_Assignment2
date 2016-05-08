#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include "ranger.h"


class RangerFusion
{
public:
    RangerFusion();
    void minFusion(Ranger* rangerArray[3]);
    void avgFusion(Ranger* rangerArray[3]);
    void maxFusion(Ranger* rangerArray[3]);
    double* getArray();

private:
    double fusedArray[13];
};

#endif // RANGERFUSION_H
