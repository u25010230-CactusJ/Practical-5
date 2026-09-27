#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "IncidentState.h"

class IncidentContext;

class ActiveState : public IncidentState {
public:
    std::string getName() override;
    bool handleDispatch(IncidentContext& context) override;
    bool handleResolve(IncidentContext& context) override;
    bool previousState(IncidentContext& context) override;
};

#endif // ACTIVESTATE_H