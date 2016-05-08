#include "rangerfusion.h"
#include <iostream>

using namespace std;

RangerFusion::RangerFusion()
{
}

double* RangerFusion::minFusion(Ranger* rangerArray[3])
{

}

double* RangerFusion::avgFusion(Ranger* rangerArray[3])
{
    for (int i = 0; i < 3; i++)
    {
        rangerArray[i]->genArray();
    }

    double outputArray[13];
    for (int i = 0; i < 13; i++)
    {
        int numVals = 0;
        double val1 = 0;
        double val2 = 0;
        double val3 = 0;
        cout << "DEBUG: Laser value [" << i << "] = " << (rangerArray[0]->getArray())[i] << endl;
        cout << "DEBUG: Radar value [" << i << "] = " << (rangerArray[1]->getArray())[i] << endl;
        cout << "DEBUG: Sonar value [" << i << "] = " << (rangerArray[2]->getArray())[i] << endl;
        if (((rangerArray[0]->getArray())[i]) /* If it's not null */ && !(rangerArray[0]->disregard((rangerArray[0]->getArray())[i]))) // And if it's not disregarded as min or max
        {
            val1 = (rangerArray[0]->getArray())[i];
            cout << "DEBUG: Laser set to " << (rangerArray[0]->getArray())[i] << endl;
            numVals++;
        }
        if (((rangerArray[1]->getArray())[i]) /* If it's not null */ && !(rangerArray[1]->disregard((rangerArray[1]->getArray())[i]))) // And if it's not disregarded as min or max
        {
            if (numVals == 0)
                val1 = (rangerArray[1]->getArray())[i];
            else if (numVals == 1)
                val2 = (rangerArray[1]->getArray())[i];
            cout << "DEBUG: Radar set to " << (rangerArray[1]->getArray())[i] << endl;
            numVals++;
        }
        if (((rangerArray[2]->getArray())[i]) /* If it's not null */ && !(rangerArray[2]->disregard((rangerArray[2]->getArray())[i]))) // And if it's not disregarded as min or max
        {
            if (numVals == 0)
                val1 = (rangerArray[2]->getArray())[i];
            else if (numVals == 1)
                val2 = (rangerArray[2]->getArray())[i];
            else if (numVals == 2)
                val3 = (rangerArray[2]->getArray())[i];
            cout << "DEBUG: Sonar set to " << (rangerArray[2]->getArray())[i] << endl;
            numVals++;
        }
        cout << "DEBUG: val1 = " << val1 << endl;
        cout << "DEBUG: val2 = " << val2 << endl;
        cout << "DEBUG: val3 = " << val3 << endl;
        cout << "DEBUG: numVals = " << numVals << endl;

        if (numVals == 0)
            outputArray[i] = 0;
        if (numVals == 1)
            outputArray[i] = val1;
        if (numVals == 2)
            outputArray[i] = ((val1 + val2)/2);
        if (numVals == 3)
            outputArray[i] = ((val1 + val2 + val3)/3);
        cout << "DEBUG: mean set to: " << outputArray[i] << endl;
        cout << endl;
    }
}

double* RangerFusion::maxFusion(Ranger* rangerArray[3])
{

}

