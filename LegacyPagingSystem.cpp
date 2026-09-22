#include "LegacyPagingSystem.h"
#include <iostream>

using namespace std;

void LegacyPagingSystem::executeAudioPage( int zoneCode, const char* rawText) {
    cout << "[Legacy PA Hardware] Broadcasting Code " << zoneCode
    << " -> \"" << rawText << "\"\n";
}
