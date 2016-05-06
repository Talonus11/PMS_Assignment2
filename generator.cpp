#include "generator.h"
#include <random>
#include <ctime>

using namespace std;

Generator::Generator()
{
}

double Generator::normalGenerator(double mean, double stdDev, double max)
{
    double randomVal;
    static default_random_engine generator(time(0));
    normal_distribution<double> distribution(mean,stdDev);
    randomVal = distribution(generator);
    if (randomVal < 0.2) // clips values below 0.2 to minDistance
    {
        randomVal = 0.2;
    }
    if (randomVal > max) // clips values above max to max, where max is passed in as an argument
    {
        randomVal = max;
    }
    return randomVal;
}
