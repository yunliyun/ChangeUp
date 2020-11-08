#include "main.h"

//set roller upper motor goal flag
bool AtDistanceRollerUpperGoal(int threshold) {
  return (abs((int)(RollerUMotor.get_position()-RollerUMotor.get_target_position())) < threshold);
}

//set roller upper target, but does not wait for them to reach their target
void RollerUpper(double distance, int speed){
    RollerUMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    RollerUMotor.move_relative(distance, speed);
}

//set roller upper target, and wait for them to reach their target
void RollerUpperTarget(double distance, int speed){
    RollerUpper(distance, speed);
    do {
      pros::delay(20);
    } while (!AtDistanceRollerUpperGoal(5));
    pros::delay(20);
}

//thread for all roller upper controls
void RollerUpper_fn(void* param) {

  RollerUMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {

    if (master.get_digital(DIGITAL_R1)) {
      //max 12000
      RollerUMotor.move_voltage(7000);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_R2)) {
      //max -12000
      RollerUMotor.move_voltage(-5000);
      //pros::delay(20);
    }
    else {
      RollerUMotor.move_voltage(0);
      //pros::delay(20);
    }

  }

}
