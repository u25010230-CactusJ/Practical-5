#include "IncidentContext.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include "IIncidentObserver.h"
#include <iostream>
#include <algorithm>

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
    if (observer) {
        observers.push_back(observer);
    }
}

void IncidentContext::detach(IIncidentObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void IncidentContext::notifyObservers() {
    for (size_t i = 0; i < observers.size(); ++i) {
        if (observers[i]) {
            observers[i]->onStateChange(this);
        }
    }
}

void IncidentContext::setState(IncidentState* state) {
    if (currentState != state) {
        delete currentState;
        currentState = state;
        std::cout << "[IncidentContext] Incident " << incidentId 
                  << " transitioned to state: " << getStateName() << std::endl;
        
        // Notify all attached observers when state updates
        notifyObservers();
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