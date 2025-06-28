/********************************************************************
 * File: MPU6050_YAW_Goytaborgs.h
 * Description: A lightweight C++ abstraction library for reading 
 *              yaw angles from the MPU6050 sensor. It is built on 
 *              top of the "MPU6050_6Axis_MotionApps20.h" and 
 *              "I2Cdev.h" libraries, which are also available in 
 *              the Goytaborgs team's libraries repository.
 *              
 *              This abstraction provides access exclusively to 
 *              the yaw value, as it is the most commonly used 
 *              orientation parameter in robots equipped with the 
 *              MPU6050.
 * 
 * Dependencies:
 *  - Arduino.h
 *  - I2Cdev.h
 *  - MPU6050_6Axis_MotionApps20.h
 * 
 * Created by: Heverton Souza - June 4, 2025
********************************************************************/

#ifndef MPU6050_YAW_GOYTABORGS_H
#define MPU6050_YAW_GOYTABORGS_H

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

/* ----- Functions ----- */

/**
 * @brief Initializes the I2C connection and calibrates the MPU6050.
 * 
 * This function should be called once in the setup() routine to start 
 * communication with the MPU6050 sensor and load the DMP firmware.
 * 
 * @param None
 * @return None
 */
void MPU6050_Config();

/**
 * @brief Reads the current yaw value from the MPU6050 DMP.
 * 
 * Should be called periodically in the main loop to update the `yaw` 
 * variable with the latest value from the sensor.
 * 
 * @param None
 * @return None
 */
void MPU6050_Read();


/**
 * @brief Recalibrates the yaw angle to zero.
 * 
 * This function resets the internal yaw reference, treating the current 
 * orientation as 0 degrees. Useful for realigning the robot at runtime.
 * 
 * @param None
 * @return None
 */
void MPU6050_Boot();

/**
 * @brief Externally accessible yaw angle.
 * 
 * This variable holds the most recently read yaw value from the MPU6050, 
 * in degrees. It should be accessed after calling MPU6050_Read().
 */
extern float yaw;

#endif
