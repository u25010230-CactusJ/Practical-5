#include "SecurityService.h"
#include "IMediator.h"
#include <iostream>

SecurityService::SecurityService(IMediator* mediator)
    : Colleague(mediator)
{}

void SecurityService::dispatchTeam(std::string location)
{
    std::cout << "[Security] Dispatching team to " << location << std::endl;

    this->event = "TEAM_DISPATCHED";
    this->payload = location;

    changed();
}

void SecurityService::lockdownArea(std::string location)
{
    std::cout << "[Security] Lockdown requested for " << location << std::endl;

    this->event = "AREA_LOCKDOWN";
    this->payload = location;

    changed();
}

void SecurityService::handleEvent(const std::string& event, const std::string& payload)
{
    if(event == "AREA_LOCKDOWN")
    {
        dispatchTeam(payload);
    }
}