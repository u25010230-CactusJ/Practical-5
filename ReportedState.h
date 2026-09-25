#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

#include "IncidentState.h"

class IncidentContext;

class ReportedState : public IncidentState {
public:
    std::string getName() override;
    void handleDispatch(IncidentContext& context) override;
    void handleResolve(IncidentContext& context) override;
};

#endif // REPORTEDSTATE_H