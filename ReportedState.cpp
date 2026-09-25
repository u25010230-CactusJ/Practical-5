#include "ReportedState.h"
#include "ActiveState.h"
#include "IncidentContext.h"
#include <iostream>

std::string ReportedState::getName() {
    return "Reported";
}

void ReportedState::handleDispatch(IncidentContext& context) {
    std::cout << "[ReportedState] Dispatching units to location: " << context.getLocation() 
              << " for Incident " << context.getId() << "..." << std::endl;
    // Transition state from Reported -> Active
    context.setState(new ActiveState());
}

void ReportedState::handleResolve(IncidentContext& context) {
    std::cout << "[ReportedState] [INVALID ACTION] Cannot directly resolve Incident " << context.getId() 
              << " at " << context.getLocation() << " from Reported state! Dispatch responders first." << std::endl;
}