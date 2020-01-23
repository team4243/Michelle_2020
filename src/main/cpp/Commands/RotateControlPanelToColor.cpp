// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Commands/RotateControlPanelToColor.h"
#include "Subsystems/ControlPanelRotator.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RotateControlPanelToColor::RotateControlPanelToColor(): frc::Command() {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RotateControlPanelToColor::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RotateControlPanelToColor::Execute() {
    cpr.motorOnFast();   
}

// Make this return true when this Command no longer needs to run execute()
bool RotateControlPanelToColor::IsFinished() {
    if (colorSensorInterface.ColorMatchesColorFromFMS())
        return true;
    else
        return false;        
}

// Called once after isFinished returns true
void RotateControlPanelToColor::End() {
    cpr.motorStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateControlPanelToColor::Interrupted() {
    cpr.motorStop();
}
