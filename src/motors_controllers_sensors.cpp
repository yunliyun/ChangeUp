#include "main.h"

//define all motors here
/**pros::Motor::Motor_object ( const std::uint8_t port,
                     const pros::motor_gearset_e_t gearset,
                     const bool reverse,
                     const pros::motor_encoder_units_e_t encoder_units );
**/
/*drivetrain motors*/
pros::Motor FLMotor(FLMotorPort, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor FRMotor(FRMotorPort, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BLMotor(BLMotorPort, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BRMotor(BRMotorPort, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
/*claw motors*/
pros::Motor ClawLMotor(ClawLMotorPort, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor ClawRMotor(ClawRMotorPort, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
/*roller motors*/
pros::Motor RollerUMotor(RollerUMotorPort, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor RollerLMotor(RollerLMotorPort, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

//define all controllers here
/**
pros::Controller::Controller ( pros::controller_id_e_t id )

id 	-> The ID of the controller (e.g. the master or partner controller)
Must be one of E_CONTROLLER_MASTER or E_CONTROLLER_PARTNER
**/
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

//define all sensors here
/**
pros::ADIGyro::ADIGyro ( std::uint8_t port,
                         double multiplier = 1 )

port 	The ADI port number (from 1-8, ‘a’-‘h’, ‘A’-‘H’) to initialize as a gyro
multiplier 	A scalar value that will be mutliplied by the gyro heading value
**/
//pros::ADIGyro gyro(GyroPort);
