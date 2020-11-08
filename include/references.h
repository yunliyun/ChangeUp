//define all motor ports constant variables here
/*drivetrain motor ports*/
#define FLMotorPort 1
#define FRMotorPort 10
#define BLMotorPort 19
#define BRMotorPort 16
/*claw motor ports*/
#define ClawLMotorPort 7
#define ClawRMotorPort 3
/*roller motor ports*/
#define RollerUMotorPort 13
#define RollerLMotorPort 14


//define all sensor ports constant variables here
/**
#define GyroPort 1
**/

 //declare global motor object variables here
 /*drivetrain motor variables*/
extern pros::Motor FLMotor;
extern pros::Motor FRMotor;
extern pros::Motor BLMotor;
extern pros::Motor BRMotor;
 /*claw motor variables*/
extern pros::Motor ClawLMotor;
extern pros::Motor ClawRMotor;
/*roller motor variables*/
extern pros::Motor RollerUMotor;
extern pros::Motor RollerLMotor;

 //declare global controller object variable here
extern pros::Controller master;
extern pros::Controller partner;

//declare global sensor object variables here
/**
extern pros::ADIGyro gyro;
**/

//declare global variables that map controller joysticks for drivetrain variables
extern int LeftControl;
extern int RightControl;
extern int power;
extern int turn;

//declare drive train function prototype
/*drive train task thread function prototype*/
void DriveTrain_fn(void* param);
/*drive train functions*/
void Drive(double, int);
void DriveTarget(double, int);

void Rotate(double, int);
void RotateTarget(double, int);

bool AtDistanceDriveGoal(int);

//declare roller upper task thread function prototype
void RollerUpper_fn(void* param);
/*roller upper functions*/
void RollerUpper(double, int);
void RollerUpperTarget(double, int);

bool AtDistanceRollerUpperGoal(int);

//declare roller lower task thread function prototype
void RollerLower_fn(void* param);
/*roller lower functions*/
void RollerLower(double, int);
void RollerLowerTarget(double, int);

bool AtDistanceRollerLowerGoal(int);

//declare claw task thread function prototype
void Claw_fn(void* param);
/*claw functions*/
void Claw(double, int);
void ClawTarget(double, int);

bool AtDistanceClawGoal(int);


//declare functions for antonomous.cpp
/* function for basic auton*/
void basic();
/* function for blue alliance side close to goal zone*/
void Bluebasic();
/* function for red alliance side close to goal zone*/
void Redbasic();
/* function for skill autonomous*/
void SkillsAuton();

/* variables and functions for auton selector */
extern int autonselector;
extern const char *titles[4];
extern void (*scripts[4])();

void LCDScriptExecute();
