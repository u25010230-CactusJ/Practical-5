#include "IncidentNotifier.h"
#include "IIncidentObserver.h"
#include <algorithm>
#include <iostream>

IncidentNotifier::IncidentNotifier() {}

IncidentNotifier::~IncidentNotifier() {
    observers.clear();
}

void IncidentNotifier::attach(IIncidentObserver* observer) {
    if (observer) {
        observers.push_back(observer);
    }
}

void IncidentNotifier::detach(IIncidentObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void IncidentNotifier::notifyObservers(IncidentContext* context) {
    for (size_t i = 0; i < observers.size(); ++i) {
        if (observers[i]) {
            observers[i]->onStateChange(context);
        }
    }
}