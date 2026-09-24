#include "MedicalService.h"
#include "IMediator.h"
#include <iostream>

MedicalService::MedicalService(IMediator* mediator)
    : Colleague(mediator)
{}

void MedicalService::prepareResponse(std::string location)
{
    std::cout << "[Medical] Preparing medical response for " << location << std::endl;
}

void MedicalService::handleEvent(const std::string& event, const std::string& payload)
{
    if(event == "TEAM_DISPATCHED")
    {
        prepareResponse(payload);
    }
}
