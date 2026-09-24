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

std::string LockBuildingCommand::getLocation()
{
    return this->location;
}

void LockBuildingCommand::setLocation(std::string location)
{
    this->location = location;
}

AccessControlService* LockBuildingCommand::getReceiver()
{
    return this->accessControl;
}

void LockBuildingCommand::setReceiver(AccessControlService* accessControl)
{
    this->accessControl = accessControl;
}
