#ifndef LASER_H
#define LASER_H
#include <string>
#include "ranger.h"

using namespace std;

/**
 * @brief
 * The Laser class is a sub-class of Ranger. It is one of 3 types of Ranger used for distance sensing.
 */
class Laser : public Ranger
{
public:
    /**
     * @brief
     *
     */
    Laser();

// GET Methods
    /**
     * @brief
     * returns the model of Laser
     * @return string
     */
    string getModel();
    /**
     * @brief
     * returns the port directory of Laser
     * @return string
     */
    string getPortDir();
    /**
     * @brief
     * returns the MIN_DISTANCE of Laser
     * @return double
     */
    double getMinDistance();
    /**
     * @brief
     * returns the MAX_DISTANCE of Laser
     * @return double
     */
    double getMaxDistance();
    /**
     * @brief
     * returns the Angular Resolution of Laser
     * @return double
     */
    double getAngularResolution();
    /**
     * @brief
     * returns the FOV (Field of View) of Laser
     * @return int
     */
    int getFOV();
    /**
     * @brief
     * returns the Port Number of Laser
     * @return int
     */
    int getPortNumber();
    /**
     * @brief
     * returns the Baud Rate of Laser
     * @return int
     */
    int getBaud();
    /**
     * @brief
     * returns the generated array of normally distributed values, representing a distance scan performed by Laser
     * @return double
     */
    double* getArray();

// SET Methods
    /**
     * @brief
     * sets the Baud to the parameter taken in, as long as that value is sane. This method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setBaud(int);
    /**
     * @brief
     * sets the Angular Resolution to the parameter taken in, as long as that value is sane. This method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setAngularResolution(int);
    /**
     * @brief
     * sets the portNumber to the parameter taken in. This method also returns a 1 if successful, or a 0 if unsuccessful.
     * @param int
     * @return int
     */
    int setPORT(int);

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
    string model; /**< TODO */
    unsigned int baud; /**< TODO */
    unsigned int portNumber; /**< TODO */
    string portDir; /**< TODO */
    unsigned int FOV; /**< TODO */
    unsigned int angRes; /**< TODO */
    double maxDistance; /**< TODO */
    double minDistance; /**< TODO */
    bool portSet; /**< TODO */
    double scanValues[13]; /**< TODO */


    //Sensor Variable Options
    const int FOV_ = 180; /**< TODO */
    const string MODEL_ = "UTM-XXL"; /**< TODO */
    const double MIN_DISTANCE_ = 0.2; /**< TODO */
    const double MAX_DISTANCE_ = 8.0; /**< TODO */
    const string PORT_STRING_ = "USB: /dev/ttyACM"; /**< TODO */
    const int port0_ = 0; /**< TODO */
    const int port1_ = 1; /**< TODO */
    const int port2_ = 2; /**< TODO */
    const int baud0_ = 38400; /**< TODO */
    const int baud1_ = 115200; /**< TODO */
    const double ang_res0_ = 15; /**< TODO */
    const double ang_res1_ = 30; /**< TODO */

    int a_size = 0; /**< TODO */
};

#endif // LASER_H
