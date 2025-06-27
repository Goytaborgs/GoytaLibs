#include <MPU6050_YAW_Goytaborgs.h>


void setup() {
  MPU6050_Config();
}

void loop() {
  Serial.begin(115200);
  MPU6050_Read();
  float yaw_read = yaw; //yaw is an extern variable in library
  Serial.print("MPU yaw read: ");
  Serial.println(yaw_read);
  delay(100);
}

//If need to reset the origin anlge(0), call the MPU6050_Boot function (it takes some time to recalibrate)