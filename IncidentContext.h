#ifndef INCIDENTCONTEXT_H
#define INCIDENTCONTEXT_H

#include <string>

class IncidentState;

class IncidentContext {
private:
    std::string incidentId;
    std::string location;
    IncidentState* currentState;

public:
    IncidentContext(std::string id, std::string loc);
    ~IncidentContext(); // Destructor to clean up currentState

    void setState(IncidentState* state);
    std::string getId() const;
    std::string getLocation() const;
    std::string getStateName() const;
    void dispatch();
    void resolve();
};

#endif // INCIDENTCONTEXT_H