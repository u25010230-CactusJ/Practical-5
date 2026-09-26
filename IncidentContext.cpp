#include "IncidentContext.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include "IIncidentObserver.h"
#include <iostream>

IncidentContext::IncidentContext(std::string id, std::string loc)
    : incidentId(id), location(loc) {
    currentState = new ReportedState();
    std::cout << "[IncidentContext] Registered Incident " << incidentId 
              << " at " << location << " | Initial State: " << getStateName() << std::endl;
}

IncidentContext::~IncidentContext() {
    delete currentState;
    currentState = nullptr;
}

void IncidentContext::attach(IIncidentObserver* observer) {
    notifier.attach(observer);
}

void IncidentContext::detach(IIncidentObserver* observer) {
    notifier.detach(observer);
}

void IncidentContext::setState(IncidentState* state) {
    if (currentState != state) {
        delete currentState;
        currentState = state;
        std::cout << "[IncidentContext] Incident " << incidentId 
                  << " transitioned to state: " << getStateName() << std::endl;
        
        // Notify subscribers via IncidentNotifier
        notifier.notifyObservers(this);
    }
}

std::string IncidentContext::getId() const { return incidentId; }
std::string IncidentContext::getLocation() const { return location; }

std::string IncidentContext::getStateName() const {
    return currentState ? currentState->getName() : "Unknown";
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