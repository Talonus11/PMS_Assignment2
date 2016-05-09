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
    /**
     * @brief
     * returns the type of sensor: 0 = Laser, 1 = Radar, 2 = Sonar
     * @return
     */
    int getSensorType();

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
    /**
     * @brief
     * returns -1. This method does not serve a purpose for laser, as it does not have an angular resolution. The method exists to allow for agnostic code only.
     * @return
     */
    int setFOV(int);

private:

    //Sensor Variables
    string model; /**< Model Name */
    unsigned int baud; /**< Baud Rate */
    unsigned int portNumber; /**< Number of the Port */
    string portDir; /**< Directory of the Port */
    unsigned int FOV; /**< Field of View */
    unsigned int angRes; /**< Angular Resolution */
    double maxDistance; /**< Maximum Distance */
    double minDistance; /**< Minimum Distance */
    bool portSet; /**< Has the port been set? */
    double scanValues[13]; /**< Array of scanned values */
    int sensorType = 0; /**< Identifies the sensor as Laser */


    //Sensor Variable Options
    const int FOV_ = 180;
    const string MODEL_ = "UTM-XXL";
    const double MIN_DISTANCE_ = 0.2;
    const double MAX_DISTANCE_ = 8.0;
    const string PORT_STRING_ = "USB: /dev/ttyACM";
    const int port0_ = 0;
    const int port1_ = 1;
    const int port2_ = 2;
    const int baud0_ = 38400;
    const int baud1_ = 115200;
    const double ang_res0_ = 15;
    const double ang_res1_ = 30;

};

#endif // LASER_H
