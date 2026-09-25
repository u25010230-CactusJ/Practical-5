#ifndef INCIDENTCONTEXT_H
#define INCIDENTCONTEXT_H

#include <string>
#include <vector>

class IncidentState;
class IIncidentObserver; // Observer interface forward declaration

class IncidentContext {
private:
    std::string incidentId;
    std::string location;
    IncidentState* currentState;
    std::vector<IIncidentObserver*> observers; // List of registered observers

public:
    IncidentContext(std::string id, std::string loc);
    ~IncidentContext(); // Destructor cleans up currentState

    // Observer Pattern interface methods
    void attach(IIncidentObserver* observer);
    void detach(IIncidentObserver* observer);
    void notifyObservers();

    // State Pattern interface methods
    void setState(IncidentState* state);
    std::string getId() const;
    std::string getLocation() const;
    std::string getStateName() const;

    void dispatch();
    void resolve();
};

#endif // INCIDENTCONTEXT_H