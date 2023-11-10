//
// Created by LEGION on 2021/10/4.
//
#include "UserTask.h"

PID_Regulator_t userPidRegulator = {
        .kp = 60,
        .ki = 0,
        .kd = 0,
        .componentKpMax = 10000,
        .componentKiMax = 0,
        .componentKdMax = 0,
        .outputMax = 10000 //2006电机输出电流上限，可以调小，勿调大
};

MOTOR_INIT_t userMotorInit = {
        .speedPIDp = &userPidRegulator,
        .anglePIDp = nullptr,
        ._motorID = MOTOR_ID_1,
        .reductionRatio = 36.0f,
        .ctrlType = POSITION_Double,
};

Motor UserMotor(MOTOR_ID_5,&userMotorInit);

/*定义舵机ClawServo*/
//SERVO_INIT_T Claw_Servo_Init ={
//        .servoType = POSITION_180,    //舵机类型：180°舵机（舵机类型自行搜索）
//        .servoID = SERVO_ID_2,		 //舵机ID：由SERVO_ID_1，接线如下图所示
//        .firstAngle = 90,              //开机角度：舵机初次上电时转到的角度
//        .angleLimit_Min = 0,          //最小角度：舵机可以转到的最小角度
//        .angleLimit_Max = 180         //最大角度：舵机可以转到的最大角度
//};

//Servo ClawServo(&Claw_Servo_Init);

/***
 * 在这里放入xxx.stop()即可使舵机,电机在遥控器急停挡位断电
 */
void UserStop(){
    UserMotor.Stop();
    //ClawServo.stop();
}

/***
 * 在这里写入初始化内容
 */
void UserInit(){

}

/***
 * 用户自定义任务主循环
 */
void UserHandle(){
    UserMotor.Handle();
    //ClawServo.Handle();
}