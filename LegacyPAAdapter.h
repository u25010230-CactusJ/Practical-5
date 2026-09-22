#ifndef LEGACY_PA_ADAPTER_H
#define LEGACY_PA_ADAPTER_H

#include "ModernNotifier.h"
#include <memory>
using namespace std;

class LegacyPagingSystem; // why?

// adapter 
class LegacyPAAdapter : public ModernNotifier {
private:
LegacyPagingSystem* legacySystem;
int parseZoneToCode(const string& zone);

public:
LegacyPAAdapter();
~LegacyPAAdapter() override;

void sendALert( const string& zone, const string& message) override;
};

#endif