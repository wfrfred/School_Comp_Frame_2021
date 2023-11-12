//
// Created by wfrfred on 2023/11/12.
//

#include "RoboticArm.h"

RoboticArm::RoboticArm() {
    memset(command, 0, sizeof(char) * 256);
    sprintf(command, "#255PMOD4!");
    HAL_UART_Transmit(&huart6, (uint8_t *) command, strlen(command), 1000);
}

void RoboticArm::stop() {
    sprintf(command, "#255dPDST!");
    HAL_UART_Transmit(&huart6, (uint8_t *) command, strlen(command), 1000);
}

void RoboticArm::setTargetAngles(const float angles[5]) {
    for (int i = 0; i < 5; ++i) {
        targetAngles[i] = (uint32_t) std::round(((2000.f / 180.f) * angles[i] + 500));
    }
}

void RoboticArm::setClawServo(uint8_t isOpen) {
    clawServoAngle = isOpen ? 1500 : 500;
}

void RoboticArm::handle() {
    sprintf(command, "{#001P%04dT0000!#002P%04dT0000!#003P%04dT0000!#004P%04dT0000!#005P%04dT0000!#006P%04dT0000!}",
            (int) targetAngles[0], (int) targetAngles[1], (int) targetAngles[2], (int) targetAngles[3],
            (int) targetAngles[4], (int) clawServoAngle);
    HAL_UART_Transmit(&huart6, (uint8_t *) command, strlen(command), 1000);
}