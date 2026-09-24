#include <iostrem>
#include "ModernNotifier.h"

using namespace std;

void ModernNotifier::cancelAlert(string location)
{
cout << "[Notifier] Cancelling alert for " << location << endl;
}

bool ModernNotifier::handleEvent(const string& event, const string& payload)
{
if(event == "TEAM_DISPATCHED")
{sendAlert(payload, "Security team dispatched.")
return true;
}

else if(event == "AREA_LOCKDOWN")
{sendAlert(payload, "Area lockdown in effect.")
return true;
}

else if(event == "MEDICAL_REQUESTED")
{sendAlert(payload, "Medical assistance requested.")
return true;
}

else 
{
cout << "[Notifier] Unsupported event:" << event << endl;
return false;

}
}