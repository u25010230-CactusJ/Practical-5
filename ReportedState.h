#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include "IncidentState.h"

class IncidentContext;

class ReportedState : public IncidentState {
public:
    std::string getName() override;
    bool handleDispatch(IncidentContext& context) override;
    bool handleResolve(IncidentContext& context) override;
    bool previousState(IncidentContext& context) override;
};

#endif // REPORTEDSTATE_H