#include "MedicalService.h"
#include "IMediator.h"
#include <iostream>

MedicalService::MedicalService(IMediator* mediator)
    : Colleague(mediator)
{}

void MedicalService::requestMedicalAssistance(std::string location)
{
    std::cout << "[Medical] Medical assistance requested at " << location << std::endl;

    this->event = "MEDICAL_REQUESTED";
    this->payload = location;

    changed();
}

void MedicalService::prepareResponse(std::string location)
{
    std::cout << "[Medical] Preparing medical response for " << location << std::endl;
}

bool MedicalService::handleEvent(const std::string& event, const std::string& payload)
{
    if(event == "TEAM_DISPATCHED")
    {
        prepareResponse(payload);
        return true;
    }
    return false;
}
