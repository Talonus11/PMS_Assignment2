#ifndef SONAR_H
#define SONAR_H
#include <string>
#include "ranger.h"

using namespace std;

/**
 * @brief
 * The Sonar class is a sub-class of Ranger. It is one of 3 types of Ranger used for distance sensing.
 */
class Sonar : public Ranger
{
public:
    /**
     * @brief
     *
     */
    Sonar();

// GET Methods
    /**
     * @brief
     * Returns the model of Sonar
     * @return string
     */
    string getModel();
    /**
     * @brief
     * Returns the port directory of Sonar
     * @return string
     */
    string getPortDir();
    /**
     * @brief
     * returns the MIN_DISTANCE of Sonar
     * @return double
     */
    double getMinDistance();
    /**
     * @brief
     * returns the MAX_DISTANCE of Sonar
     * @return double
     */
    double getMaxDistance();
    /**
     * @brief
     * returns the Angular Resolution of Sonar. Since Sonar does not have an Angular Resolution, this returns -1. It is included so that the code is agnostic.
     * @return double
     */
    double getAngularResolution();
    /**
     * @brief
     * returns the FOV of Sonar
     * @return int
     */
    int getFOV();
    /**
     * @brief
     *  returns the Port Number of Sonar
     * @return int
     */
    int getPortNumber();
    /**
     * @brief
     * returns the Baud Rate of Sonar
     * @return int
     */
    int getBaud();
    /**
     * @brief
     * returns the generated array of normally distributed values, representing a distance scan performed by Sonar
     * @return double
     */
    double* getArray();

// SET Methods
    /**
     * @brief
     * sets the portNumber to the parameter taken in. As the Rangers are initialised in the order Laser > Radar > Sonar, this method also ensures that Sonar's portNumber does not clash with Laser or Radar.
     * Lastly, this method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setPORT(int);
    /**
     * @brief
     * sets the Baud to the parameter taken in, as long as that value is sane. This method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setBaud(int);

    /**
     * @brief
     * generates an array of size 13, populating it with values taken from Generator's normal distribution generator. This is saved into the array scanValues in Sonar.
     */
    void genArray();
    /**
     * @brief
     * compares the parameter taken in against the MIN_DISTANCE and MAX_DISTANCE properties of Sonar. If the parameter "check" is equal to either, returns "true" to signify that the value should be disregarded. This is called in RangerFusion
     * @param check
     * @return bool
     */
    bool disregard(double check);

private:

    //Sensor Variables
    string model; /**< Test Model */
    unsigned int baud; /**< TODO */
    unsigned int portNumber; /**< TODO */
    string portDir; /**< TODO */
    unsigned int FOV; /**< TODO */
    double maxDistance; /**< TODO */
    double minDistance; /**< TODO */
    bool portSet; /**< TODO */
    double scanValues[13]; /**< TODO */


    //Sensor Variable Options
    const int FOV_ = 90; /**< TODO */
    const string MODEL_ = "SONX-001"; /**< TODO */
    const double MIN_DISTANCE_ = 0.2; /**< TODO */
    const double MAX_DISTANCE_ = 4.0; /**< TODO */
    const string PORT_STRING_ = "USB: /dev/ttyACM"; /**< TODO */
    const int port0_ = 0; /**< TODO */
    const int port1_ = 1; /**< TODO */
    const int port2_ = 2; /**< TODO */
    const int baud0_ = 38400; /**< TODO */
    const int baud1_ = 115200; /**< TODO */
};

#endif // SONAR_H
