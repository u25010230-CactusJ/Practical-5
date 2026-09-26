#include "LegacyPAAdapter.h"
#include "LegacyPagingSystem.h"
#include <iostream>

using namespace std;

LegacyPAAdapter::LegacyPAAdapter(IMediator* med) : ModernNotifier(med) {
    legacySystem = new LegacyPagingSystem();
}

LegacyPAAdapter::~LegacyPAAdapter() {
    delete legacySystem;
    legacySystem = nullptr;
}

int LegacyPAAdapter::parseZoneToCode(const string& zone) {
    if (zone == "Science Block") return 101;
    if (zone == "Main Library") return 202;
    return 999; // Default general zone
}

void LegacyPAAdapter::sendAlert(const string& zone, const string& message) {
    int code = parseZoneToCode(zone);
    string formattedMsg = "[EMERGENCY ALERT]: " + message;
    legacySystem->executeAudioPage(code, formattedMsg.c_str());
}