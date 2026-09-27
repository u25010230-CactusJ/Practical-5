#ifndef IINCIDENTOBSERVER_H
#define IINCIDENTOBSERVER_H

class IncidentContext; // Forward declaration

class IIncidentObserver {
public:
    virtual ~IIncidentObserver() {}
    virtual void onStateChange(IncidentContext* context) = 0;
};

#endif // IINCIDENTOBSERVER_H