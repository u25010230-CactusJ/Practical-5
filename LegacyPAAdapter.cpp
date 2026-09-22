#include "LegacyPAAdapter.h"
#include "LegacyPagingSystem.h"
#include <iostream>

using namespace std;

LegacyPAAdapter::LegacyPAAdapter() : legacySystem( new LegacyPagingSystem()) {}
LegacyPAAdapter::~LegacyPAAadapter()
{
delete legacySystem;
legacySystem = 0;
}

int LegacyPAAdapter::parseZoneToCode( const string& zone) {
if ( zone == "Science Block") return 101;
if ( zone == "Main Library") return 202;
return 999; // default general zone
}

void LegacyPAAdapter::sendAlert( const string& zone, const string& message) {
int code = parseZoneToCode(zone);
string formattedMsg = "[EMERGENCY ALERT]: " + message;
legacySystem->executedAudioPage(code, formattedMsg.c_str());
}
