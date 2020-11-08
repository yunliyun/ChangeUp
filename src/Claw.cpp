#include "main.h"

//set claw motor goal flag
bool AtDistanceClawGoal(int threshold) {
  return (abs((int)(ClawLMotor.get_position()-ClawLMotor.get_target_position())) < threshold);
}


//set claw target, but does not wait for them to reach their target
void Claw(double distance, int speed){
    ClawLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    ClawRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    ClawLMotor.move_relative(distance, speed);
    ClawRMotor.move_relative(distance, speed);
}

//set claw target, and wait for them to reach their target
void ClawTarget(double distance, int speed){
    Claw(distance, speed);
    do {
      pros::delay(20);
    } while (!AtDistanceClawGoal(5));
    pros::delay(20);
}

//thread for all claw controls
void Claw_fn(void* param) {

  ClawLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  ClawRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

  while (true) {

    if (master.get_digital(DIGITAL_L1)) {
      //max 12000
      ClawLMotor.move_voltage(7000);
      ClawRMotor.move_voltage(7000);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_L2)) {
      //max -12000
      ClawLMotor.move_voltage(-7000);
      ClawRMotor.move_voltage(-7000);
      //pros::delay(20);
    }
    else {
      ClawLMotor.move_voltage(0);
      ClawRMotor.move_voltage(0);
      //pros::delay(20);
    }

  }
}
