#include "LockBuildingCommand.h"
#include "AccessControlService.h"

LockBuildingCommand::LockBuildingCommand(AccessControlService* accessControl, std::string location)
    : accessControl(accessControl), location(location), isLocked(false)
{}

void LockBuildingCommand::execute()
{
    accessControl->restrictDoors(this->location);
    this->isLocked = true;
}

void LockBuildingCommand::undo()
{
    if(this->isLocked)
    {
        accessControl->unlockEmergencyExits(this->location);
        this->isLocked = false;
    }
}
