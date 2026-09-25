#include "ResolvedState.h"
#include "IncidentContext.h"
#include <iostream>

std::string ResolvedState::getName() {
    return "Resolved";
}

void ResolvedState::handleDispatch(IncidentContext& context) {
    std::cout << "[ResolvedState] [INVALID ACTION] Incident is already resolved. Cannot re-dispatch." << std::endl;
}

void ResolvedState::handleResolve(IncidentContext& context) {
    std::cout << "[ResolvedState] Incident is already marked as Resolved." << std::endl;
}