// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#pragma once

#include <string>
#include "frc/commands/Subsystem.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/PWMTalonSRX.h"
#include "../../../../../.gradle/caches/transforms-2/files-2.1/12b80ce887e4d15f4aa0a512179a5386/ColorSensorV3-cpp-1.0.1-headers/rev/ColorSensorV3.h"
#include "../../../../../.gradle/caches/transforms-2/files-2.1/12b80ce887e4d15f4aa0a512179a5386/ColorSensorV3-cpp-1.0.1-headers/rev/ColorMatch.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 *
 *
 * @author ExampleAuthor
 */
class ControlPanelRotator: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<rev::ColorSensorV3> colorSensor;
	std::shared_ptr<frc::SpeedController> controlPanelMotorController;

	static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
    static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
    static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
    static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);
	rev::ColorMatch m_colorMatcher;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
ControlPanelRotator();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	std::string GetColorFromSensor(double confidence);
	bool SpinToColor(int numRotations, std::string color);

};
