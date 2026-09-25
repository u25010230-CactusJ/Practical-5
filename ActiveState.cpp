#include "ActiveState.h"
#include "ResolvedState.h"
#include "IncidentContext.h"
#include <iostream>

std::string ActiveState::getName() {
    return "Active";
}

void ActiveState::handleDispatch(IncidentContext& context) {
    std::cout << "[ActiveState] Responders are already actively dispatched at " << context.getLocation() << "." << std::endl;
}

void ActiveState::handleResolve(IncidentContext& context) {
    std::cout << "[ActiveState] Incident at " << context.getLocation() << " has been contained and resolved." << std::endl;
    // Transition state from Active -> Resolved
    context.setState(new ResolvedState());
}