//
// Created by wfrfred on 2023/11/12.
//

#ifndef RM_FRAME_C_ROBOTICARM_H
#define RM_FRAME_C_ROBOTICARM_H

#include "Device.h"

class RoboticArm{
    char command[256];
    uint32_t clawServoAngle{0};
    uint32_t targetAngles[5]{0};
public:
    void init();
    void setTargetAngles(const float angles[5]);
    void setClawServo(uint8_t isOpen);
    void stop();
    void handle();
};

#endif //RM_FRAME_C_ROBOTICARM_H
