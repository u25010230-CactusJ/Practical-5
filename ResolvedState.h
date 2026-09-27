#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

#include "IncidentState.h"

class IncidentContext;

class ResolvedState : public IncidentState {
public:
    std::string getName() override;
    bool handleDispatch(IncidentContext& context) override;
    bool handleResolve(IncidentContext& context) override;
    bool previousState(IncidentContext& context) override;
};

#endif // RESOLVEDSTATE_H