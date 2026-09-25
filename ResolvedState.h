#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

class IncidentContext;

class ResolvedState : public IncidentState {
public:
    std::string getName() override;
    void handleDispatch(IncidentContext& context) override;
    void handleResolve(IncidentContext& context) override;
};

#endif // RESOLVEDSTATE_H