#include "IncidentContext.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include <iostream>

IncidentContext::IncidentContext(std::string id, std::string loc)
    : incidentId(id), location(loc) {
    // Initial default state set to ReportedState
    currentState = new ReportedState();
    std::cout << "[IncidentContext] Incident created: " << incidentId 
              << " at " << location << " | Initial State: " << getStateName() << std::endl;
}

IncidentContext::~IncidentContext() {
    delete currentState;
    currentState = nullptr;
}

void IncidentContext::setState(IncidentState* state) {
    if (currentState != state) {
        delete currentState;
        currentState = state;
        std::cout << "[IncidentContext] Transitioned to state: " << getStateName() << std::endl;
    }
}

std::string IncidentContext::getId() const {
    return incidentId;
}

std::string IncidentContext::getLocation() const {
    return location;
}

std::string IncidentContext::getStateName() const {
    if (currentState) {
        return currentState->getName();
    }
    return "Unknown";
}

void IncidentContext::dispatch() {
    std::cout << "\n[IncidentContext] Dispatch requested for incident: " << incidentId << std::endl;
    if (currentState) {
        currentState->handleDispatch(*this);
    }
}

void IncidentContext::resolve() {
    std::cout << "\n[IncidentContext] Resolve requested for incident: " << incidentId << std::endl;
    if (currentState) {
        currentState->handleResolve(*this);
    }
}