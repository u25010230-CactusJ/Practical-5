#ifndef INCIDENTNOTIFIER_H
#define INCIDENTNOTIFIER_H

#include <vector>

class IIncidentObserver;
class IncidentContext;

class IncidentNotifier {
private:
    std::vector<IIncidentObserver*> observers;

public:
    IncidentNotifier();
    ~IncidentNotifier();

    void attach(IIncidentObserver* observer);
    void detach(IIncidentObserver* observer);
    void notifyObservers(IncidentContext* context);
};

#endif // INCIDENTNOTIFIER_H