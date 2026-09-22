#ifndef EMERGENCY_FACADE_H
#define EMERGENCY_FACADE_H

#include "CampusMediator.h"
#include "SecurityService.h"
#include "AccessControlService.h"
#include "LegacyPAAdapter.h"
#include "OperatorControlPanel.h"
#include <string>

using namespace std;

class IncidentContext;

//facade

class EmergencyFacade {
private:
CampusMediator mediator;
SecurityService security;
AccessControlService accessControl;
LegacyPAAdapter paAdapter;
OperatorControlPanel invoker;

public:
EmergencyFacade();
CampusMediator& getMediator();

void executeFullCampusEvacuationWorkflow(IncidentContext& incident, const string& reason);
void cancelLastAction();
};
#endif