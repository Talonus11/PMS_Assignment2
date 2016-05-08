#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include "ranger.h"


class RangerFusion
{
public:
    RangerFusion();
    double* minFusion(Ranger* rangerArray[3]);
    double* avgFusion(Ranger* rangerArray[3]);
    double* maxFusion(Ranger* rangerArray[3]);
};

#endif // RANGERFUSION_H
