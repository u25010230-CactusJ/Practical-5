#ifndef INCIDENTCONTEXT_H
#define INCIDENTCONTEXT_H

#include <string>
#include "IncidentNotifier.h" // Delegate observer management to IncidentNotifier

class IncidentState;
class IIncidentObserver;

class IncidentContext {
private:
    std::string incidentId;
    std::string location;
    IncidentState* currentState;
    IncidentNotifier notifier; // Component handling observer operations

public:
    IncidentContext(std::string id, std::string loc);
    ~IncidentContext();

    // Delegate Observer management to the internal IncidentNotifier
    void attach(IIncidentObserver* observer);
    void detach(IIncidentObserver* observer);

    // State Pattern methods
    void setState(IncidentState* state);
    std::string getId() const;
    std::string getLocation() const;
    std::string getStateName() const;

    void dispatch();
    void resolve();
};

#endif // INCIDENTCONTEXT_H