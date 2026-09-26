#include "EmergencyFacade.h"
#include "IncidentContext.h"
#include "LockBuildingCommand.h"
#include "BroadcastAlertCommand.h"
#include "DispatchUnitsCommand.h"
#include <iostream>

using namespace std;

EmergencyFacade::EmergencyFacade()
    : security(&mediator), accessControl(&mediator), paAdapter(&mediator) {
    
    // Register colleague services using your mediator's registerColleague method
    mediator.registerColleague(&security);
    mediator.registerColleague(&accessControl);
    mediator.registerColleague(&paAdapter);
}

CampusMediator& EmergencyFacade::getMediator() {
    return mediator;
}

void EmergencyFacade::executeFullCampusEvacuationWorkflow(IncidentContext& incident, const string& reason) {
    cout << "\n=======================================================\n";
    cout << "[FACADE WORKFLOW] Initiating Campus Evacuation Protocol\n";
    cout << "=======================================================\n";

    // Step 1: Lock perimeter doors via command invoker using raw pointers
    ICommand* lockCmd = new LockBuildingCommand(&accessControl, incident.getLocation());
    invoker.submitAndExecute(lockCmd);

    // Step 2: Send audio warnings via the legacy PA adapter using raw pointers
    ICommand* alertCmd = new BroadcastAlertCommand(
        &paAdapter, incident.getLocation(), "EVACUATE IMMEDIATELY: " + reason);
    invoker.submitAndExecute(alertCmd);

    // Step 3: Dispatch units using raw pointers
    ICommand* dispatchCmd = new DispatchUnitsCommand(&security, &incident);
    invoker.submitAndExecute(dispatchCmd);

    cout << "=======================================================\n\n";
}

void EmergencyFacade::cancelLastAction() {
    cout << "\n[FACADE OPERATOR ROLLBACK] Undoing previous step...\n";
    invoker.undoLastAction();
}