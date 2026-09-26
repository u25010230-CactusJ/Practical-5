#ifndef LEGACY_PA_ADAPTER_H
#define LEGACY_PA_ADAPTER_H

#include "ModernNotifier.h"
#include <string>

class LegacyPagingSystem;

// Adapter: Adapts LegacyPagingSystem to conform to ModernNotifier
class LegacyPAAdapter : public ModernNotifier {
private:
    LegacyPagingSystem* legacySystem;
    int parseZoneToCode(const std::string& zone);

public:
    explicit LegacyPAAdapter(IMediator* med = nullptr);
    ~LegacyPAAdapter() override;

    void sendAlert(const std::string& zone, const std::string& message) override;
};

#endif