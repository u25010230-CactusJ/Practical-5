#include "ActiveState.h"
#include "ResolvedState.h"
#include "IncidentContext.h"
#include <iostream>

std::string ActiveState::getName() {
    return "Active";
}

bool ActiveState::handleDispatch(IncidentContext& context) {
    std::cout << "[ActiveState] Responders are already actively dispatched at " << context.getLocation() 
              << " for Incident " << context.getId() << "." << std::endl;

    return false;
}

bool ActiveState::handleResolve(IncidentContext& context) {
    std::cout << "[ActiveState] Incident " << context.getId() << " at " << context.getLocation() 
              << " has been contained and resolved." << std::endl;
    // Transition state from Active -> Resolved
    context.setState(new ResolvedState());
    return true;
}

bool ActiveState::previousState(IncidentContext& context)
{
    std::cout << "[ActiveState] Restoring Incident " << context.getId()
            << " from Active to Reported." << std::endl;

    context.setState(new ReportedState());
    return true;
}