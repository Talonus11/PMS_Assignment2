#include "generator.h"
#include <random>
#include <ctime>

using namespace std;

Generator::Generator()
{
    default_random_engine name(time(0));

}

double Generator::normalGenerator(double mean, double stdDev)
{
    static default_random_engine generator(time(0));
    normal_distribution<double> distribution(mean,stdDev);
    return distribution(generator);
}

//    std::random_device rd;
//    std::mt19937 gen(rd());

//    // values near the mean are the most likely
//    // standard deviation affects the dispersion of generated values from the mean
//    std::normal_distribution<> d(mean,stdDev);

//    std::map<int, int> hist;
//    for(int n=0; n<10000; ++n) {
//        ++hist[std::round(d(gen))];
//    }
//    for(auto p : hist) {
//        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
//                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
//    }
