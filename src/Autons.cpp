#include "main.h"

/**auton function for RED side CLOSE to goal zone**/
void Redbasic(){
  Drive(75.0, 50);
do {
  pros::delay(20);
} while (!AtDistanceDriveGoal(5));
pros::delay(20);
}

/**auton function for BLUE side CLOSE to goal zone**/
void Bluebasic(){
  Drive(75.0, 50);
do {
  pros::delay(20);
} while (!AtDistanceDriveGoal(5));
pros::delay(20);
}

//Basic auto function - 1 cube
void basic(){
  Drive(75.0, 50);
do {
  pros::delay(20);
} while (!AtDistanceDriveGoal(5));
pros::delay(20);
}


/**varirables and functions array for auton selector**/
int autonselector = 0;
const char *titles[] = {"Redbasic", "Bluebasic", "basic", "Skills Auton"};

void (*scripts[])() = {&Redbasic, &Bluebasic, &basic, &SkillsAuton};

void LCDScriptExecute() {scripts[autonselector]();}
