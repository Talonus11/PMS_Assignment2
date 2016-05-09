#ifndef RADAR_H
#define RADAR_H
#include <string>
#include "ranger.h"

using namespace std;

/**
 * @brief
 * The Radar class is a sub-class of Ranger. It is one of 3 types of Ranger used for distance sensing.
 */
class Radar : public Ranger
{
public:
    /**
     * @brief
     *
     */
    Radar();

// GET Methods
    /**
     * @brief
     * Returns the model of Radar
     * @return string
     */
    string getModel();
    /**
     * @brief
     * Returns the port directory of Radar
     * @return string
     */
    string getPortDir();
    /**
     * @brief
     * returns the MIN_DISTANCE of Radar
     * @return double
     */
    double getMinDistance();
    /**
     * @brief
     * returns the MAX_DISTANCE of Radar
     * @return double
     */
    double getMaxDistance();
    /**
     * @brief
     * returns the Angular Resolution of Radar. Since Radar does not have an Angular Resolution this returns -1. It is included so that the code is agnostic.
     * @return double
     */
    double getAngularResolution();
    /**
     * @brief
     * returns the FOV of Radar
     * @return int
     */
    int getFOV();
    /**
     * @brief
     * returns the Port Nmber of Radar
     * @return int
     */
    int getPortNumber();
    /**
     * @brief
     * returns the Baud Rate of Radar
     * @return int
     */
    int getBaud();
    /**
     * @brief
     * returns the generated array of normally distributed values, representing a distance scan performed by Radar
     * @return double
     */
    double* getArray();

// SET Methods
    /**
     * @brief
     * sets the portNumber to the parameter taken in. As the Rangers are initialised in the order Laser > Radar > Sonar, this method also ensures that Radar's portNumber does not clash with Laser.
     * Lastly, this method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setPORT(int);
    /**
     * @brief
     * sets the FOV to the parameter taken in, as long as that value is sane. This method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setFOV(int);
    /**
     * @brief
     * sets the Baud to the parameter taken in, as long as that value is sane. This method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setBaud(int);

    /**
     * @brief
     * generates an array of size 13, populating it with values taken from Generator's normal distribution generator. This is saved into the array scanValues in Radar.
     */
    void genArray();
    /**
     * @brief
     * compares the parameter taken in against the MIN_DISTANCE and MAX_DISTANCE properties of Radar. If the parameter "check" is equal to either, returns "true" to signify that the value should be disregarded. This is called in RangerFusion
     * @param check
     * @return bool
     */
    bool disregard(double check);

private:

    //Sensor Variables
    string model; /**< TODO */
    unsigned int baud; /**< TODO */
    unsigned int portNumber; /**< TODO */
    string portDir; /**< TODO */
    unsigned int FOV; /**< TODO */
    double maxDistance; /**< TODO */
    double minDistance; /**< TODO */
    bool portSet; /**< TODO */
    int angRes; /**< TODO */
    double scanValues[13]; /**< TODO */


    //Sensor Variable Options
    const int FOV1_ = 20; /**< TODO */
    const int FOV2_ = 40; /**< TODO */
    const string MODEL_ = "RAD-001"; /**< TODO */
    const double MIN_DISTANCE_ = 0.2; /**< TODO */
    const double MAX_DISTANCE_ = 16.0; /**< TODO */
    const string PORT_STRING_ = "USB: /dev/ttyACM"; /**< TODO */
    const int port0_ = 0; /**< TODO */
    const int port1_ = 1; /**< TODO */
    const int port2_ = 2; /**< TODO */
    const int baud0_ = 38400; /**< TODO */
    const int baud1_ = 115200; /**< TODO */

};

#endif // RADAR_H
