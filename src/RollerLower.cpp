#include "main.h"

//set roller lower motor goal flag
bool AtDistanceRollerLowerGoal(int threshold) {
  return (abs((int)(RollerLMotor.get_position()-RollerLMotor.get_target_position())) < threshold);
}

//set roller lower target, but does not wait for them to reach their target
void RollerLower(double distance, int speed){
    RollerLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    RollerLMotor.move_relative(distance, speed);
}

//set roller lower target, and wait for them to reach their target
void RollerLowerTarget(double distance, int speed){
    RollerLower(distance, speed);
    do {
      pros::delay(20);
    } while (!AtDistanceRollerLowerGoal(5));
    pros::delay(20);
}

//thread for all roller lower controls
void RollerLower_fn(void* param) {

  RollerLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {

    if (master.get_digital(DIGITAL_R1)) {
      //max 12000
      RollerLMotor.move_voltage(7000);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_R2)) {
      //max -12000
      RollerLMotor.move_voltage(-5000);
      //pros::delay(20);
    }
    else {
      RollerLMotor.move_voltage(0);
      //pros::delay(20);
    }

  }

}
