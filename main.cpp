#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

  #include <windows.h>

  inline void delay( unsigned long ms )
    {
        Sleep( ms );
    }

#else  /* presume POSIX */

  #include <unistd.h>

  inline void delay( unsigned long ms )
    {
        usleep( ms * 1000 );
    }

#endif



// NormalGenerator function - Returns a single value that is within a normal distribution with a mean and std deviation as set by parameters passed as arguments

double normalGenerator(double mean, double stdDev)
{
    default_random_engine generator(time(0));
    normal_distribution<double> distribution(mean,stdDev);

    return distribution(generator);
}


int main( int argc, char ** argv )
{
    printf("Code running successfully\n");

    double distArray [101];

    default_random_engine generator(time(0));
    normal_distribution<double> distribution(6.0,5.0);

    for (int i = 0; i < 101; i++)
    {
        cout << "#" << i << "= " << distribution(generator) << endl;
    }






    return 0;
}

