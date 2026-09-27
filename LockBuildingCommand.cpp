#include "LockBuildingCommand.h"
#include "AccessControlService.h"

LockBuildingCommand::LockBuildingCommand(AccessControlService* accessControl, std::string location)
    : accessControl(accessControl), location(location), isLocked(false)
{}

bool LockBuildingCommand::execute()
{
    if(this->accessControl == nullptr)
    {
        this->isLocked = false;
        return false;
    }

    this->accessControl->restrictDoors(this->location);
    this->isLocked = true;

    return true;
}

bool LockBuildingCommand::undo()
{
    if(!this->isLocked || this->accessControl == nullptr)
    {
        return false;
    }

    this->accessControl->unlockEmergencyExits(this->location);
    this->isLocked = false;

    return true;
}
