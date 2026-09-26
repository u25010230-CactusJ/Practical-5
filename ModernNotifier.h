#ifndef MODERN_NOTIFIER_H
#define MODERN_NOTIFIER_H

#include <string>
#include "Colleague.h"

// Target interface expected by modern CampusGuard subsystems
class ModernNotifier : public Colleague {
public:
    explicit ModernNotifier(IMediator* med = nullptr) : Colleague(med) {}
    virtual ~ModernNotifier() = default;

    virtual void sendAlert(const std::string& zone, const std::string& message) = 0;
    virtual void cancelAlert(std::string location);
    virtual bool handleEvent(const std::string& event, const std::string& payload);
};

#endif