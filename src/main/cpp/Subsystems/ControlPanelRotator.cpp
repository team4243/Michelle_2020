// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include <unistd.h>   // sleep

#include "Subsystems/ControlPanelRotator.h"
#include "Commands/RotateControlPanelToColor.h"
#include "Subsystems/ColorSensorInterface.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

ControlPanelRotator::ControlPanelRotator() : frc::Subsystem("ControlPanelRotator") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
  
    controlPanelMotorController.reset(new frc::PWMTalonSRX(0));
    AddChild("ControlPanelMotorController", std::static_pointer_cast<frc::PWMTalonSRX>(controlPanelMotorController));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void ControlPanelRotator::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new RotateControlPanelToColor());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ControlPanelRotator::Periodic() {
    // Put code here to be run every loop

}

void ControlPanelRotator::motorOnFast()
{
    controlPanelMotorController->Set(1.0);
}

void ControlPanelRotator::motorOnSlow()
{
    controlPanelMotorController->Set(0.1);
}

void ControlPanelRotator::motorStop()
{
    controlPanelMotorController->StopMotor();
}


bool ControlPanelRotator::SpinToColor(int numRotations, std::string color)
{
    ColorSensorInterface colorSensor;
    bool colorFound = false;
    std::chrono::milliseconds timespan(5000);   // 5 seconds 
    double sensorConfidenceLevel = 50.0;
    int spinCount = 0;

    std::string initColor = colorSensor.GetColorFromSensor(sensorConfidenceLevel);

    int loopCnt = 0;
    int maxLoopCnt = 100;
    motorOnFast();
    while ((spinCount < numRotations) && (loopCnt < maxLoopCnt))
    {
        loopCnt++;
        std::string currentColor = colorSensor.GetColorFromSensor(sensorConfidenceLevel);
        if (currentColor.compare(initColor) == 0)
            spinCount++;
        if ((spinCount == numRotations) || (loopCnt == maxLoopCnt))
            motorStop();
    }

    if (spinCount == numRotations)
    {
        loopCnt = 0;
        motorOnSlow();
        while ((!colorFound) && (loopCnt < maxLoopCnt))
        {
            std::string currentColor = colorSensor.GetColorFromSensor(sensorConfidenceLevel);
            if (currentColor.compare(color) == 0)
            {
                motorStop();
                colorFound = true;
                std::this_thread::sleep_for(timespan);
            }
        }
        
    }
    else
    {
        printf("\nControlPanelRotator: Failed to rotate %d times", numRotations);
    }
    
    return colorFound;
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

