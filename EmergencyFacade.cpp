#include "EmergencyFacade.h"
#include "IncidentContext.h"
#include "LockBuildingCommand.h"
#include "BroadcastAlertCommand.h"
#include "DispatchUnitsCommand.h"
#include <iostream>

using namespace std;

EmergencyFacade::EmergencyFacade()
: security(&mediator), accessControl(&mediator){
    mediator.registerServices(&security, &accessControl, &paAdapter);
}

CampusMediator& EmergencyFacade::getMediator(){
    return mediator;
}

void EmergencyFacade::executeFullCampusEvacuationWorkflow( IncidentContxt& incident, const string& reason) {
cout << "\n=======================================================\n";
cout << "[FACADE WORKFLOW] Initiating Campus Evacuation Protocol\n";
cout << "=======================================================\n";
// Step 1: Lock perimeter doors via command invoker
    auto lockCmd = make_shared<LockBuildingCommand>(&accessControl, incident.getLocation());
    invoker.submitAndExecute(lockCmd);

    // Step 2: Send audio warnings via the legacy PA adapter
    auto alertCmd = make_shared<BroadcastAlertCommand>(
        &paAdapter, incident.getLocation(), "EVACUATE IMMEDIATELY: " + reason);
    invoker.submitAndExecute(alertCmd);

    // Step 3: Dispatch units (triggers mediator auto-coordination)
    auto dispatchCmd = make_shared<DispatchUnitsCommand>(&security, &incident);
    invoker.submitAndExecute(dispatchCmd);

    cout << "=======================================================\n\n";
}

void EmergencyFacade::cancelLastAction() {
    cout << "\n[FACADE OPERATOR ROLLBACK] Undoing previous step...\n";
    invoker.undoLastAction();
}