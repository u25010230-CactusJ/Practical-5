#include "AccessControlService.h"
#include "IMediator.h"
#include <iostream>

AccessControlService::AccessControlService(IMediator* mediator)
    : Colleague(mediator)
{}

void AccessControlService::restrictDoors(std::string location)
{
    std::cout << "[Access Control] Restricting doors at " << location << std::endl;
}

void AccessControlService::unlockEmergencyExits(std::string location)
{
    std::cout << "[Access Control] Unlocking emergency exits at " << location << std::endl;
}

void AccessControlService::handleEvent(const std::string& event, const std::string& payload)
{
    if(event == "TEAM_DISPATCHED")
    {
        restrictDoors(payload);
    }
    else if(event == "AREA_LOCKDOWN")
    {
        restrictDoors(payload);
    }
}
