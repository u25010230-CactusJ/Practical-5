#ifndef ACTIVESTATE_H
#define ACTIVESTATE_H

#include "IncidentState.h"

class IncidentContext;

class ActiveState : public IncidentState {
public:
    std::string getName() override;
    void handleDispatch(IncidentContext& context) override;
    void handleResolve(IncidentContext& context) override;
};

#endif // ACTIVESTATE_H