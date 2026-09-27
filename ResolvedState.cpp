#include "ResolvedState.h"
#include "IncidentContext.h"
#include <iostream>

std::string ResolvedState::getName() {
    return "Resolved";
}

bool ResolvedState::handleDispatch(IncidentContext& context) {
    std::cout << "[ResolvedState] [INVALID ACTION] Incident " << context.getId() 
              << " at " << context.getLocation() << " is already resolved. Cannot re-dispatch." << std::endl;

    return false;
}

bool ResolvedState::handleResolve(IncidentContext& context) {
    std::cout << "[ResolvedState] Incident " << context.getId() 
              << " is already marked as Resolved." << std::endl;

    return false;
}

bool ResolvedState::previousState(IncidentContext& context)
{
    std::cout << "[ResolvedState] Restoring Incident " << context.getId()
            << " from Resolved to Active." << std::endl;

    context.setState(new ActiveState());
    return true;
}