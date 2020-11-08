#include "main.h"


void SkillsAuton(){
  Drive(75.0, 50);
do {
  pros::delay(20);
} while (!AtDistanceDriveGoal(5));
pros::delay(20);
}
