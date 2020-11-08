#include "main.h"

//Returns true/false as to whether the drive wheels have reached their position goal set by driveForDistance
bool AtDistanceDriveGoal(int threshold) {
  return (abs((int)(FLMotor.get_position()-FLMotor.get_target_position())) < threshold);
}

//set drive target, but does not wait for them to reach their target
void Drive(double distance, int speed) {
  FLMotor.move_relative(distance, speed);
  BLMotor.move_relative(distance, speed);
  FRMotor.move_relative(distance, speed);
  BRMotor.move_relative(distance, speed);
}

//set drive target, and wait for them to reach their target
void DriveTarget(double distance, int speed) {
  Drive(distance, speed);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}

//turn to target position, but does not wait for them to reach their target
void Rotate(double distance, int speed) {
  FLMotor.move_relative(distance, speed);
  BLMotor.move_relative(distance, speed);
  FRMotor.move_relative(-distance, speed);
  BRMotor.move_relative(-distance, speed);
}

//turn to target position, and wait for them to reach their target
void RotateTarget(double distance, int speed) {
  Rotate(distance, speed);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}

//thread for all drive train controls
void DriveTrain_fn(void* param) {
  /** - tank drive variables -
  int LeftControl = master.get_analog(ANALOG_LEFT_Y);
  int RightControl = master.get_analog(ANALOG_RIGHT_Y);
  **/

  /** - arcade drive variables -**/
  //int power = master.get_analog(ANALOG_LEFT_Y); //left joystick Y drive straight
  int power = master.get_analog(ANALOG_RIGHT_Y); //right joystick Y drive straight
  int turn = master.get_analog(ANALOG_RIGHT_X);
  int LeftControl = power + turn;
  int RightControl = power - turn;

  while (true){

    /** - tank drive -
    //get joysticks position value and maps them to a variable
    LeftControl = master.get_analog(ANALOG_LEFT_Y);
    RightControl = master.get_analog(ANALOG_RIGHT_Y);

    FLMotor.move(LeftControl);
    BLMotor.move(LeftControl);
    FRMotor.move(RightControl);
    BRMotor.move(RightControl);
    pros::delay(2);
    **/

    /* arcade drive*/
    //power = master.get_analog(ANALOG_LEFT_Y); //left joystick Y drive straight
    power = master.get_analog(ANALOG_RIGHT_Y); //right joystick Y drive straight
    turn = master.get_analog(ANALOG_RIGHT_X);
    LeftControl = power + turn;
    RightControl = power - turn;
    FLMotor.move(LeftControl);
    BLMotor.move(LeftControl);
    FRMotor.move(RightControl);
    BRMotor.move(RightControl);
    pros::delay(2);

  }
}
