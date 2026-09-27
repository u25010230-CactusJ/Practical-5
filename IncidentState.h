#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include <string>

class IncidentContext;

class IncidentState {
public:
    virtual ~IncidentState() {}
    virtual std::string getName() = 0;
    virtual bool handleDispatch(IncidentContext& context) = 0;
    virtual bool handleResolve(IncidentContext& context) = 0;
    virtual bool previousState(IncidentContext& context) = 0;
};

#endif // INCIDENTSTATE_H