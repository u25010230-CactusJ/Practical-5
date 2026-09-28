#include "EmergencyFacade.h"
#include "IncidentContext.h"
#include "LockBuildingCommand.h"
#include "BroadcastAlertCommand.h"
#include "DispatchUnitsCommand.h"
#include <iostream>

using namespace std;

EmergencyFacade::EmergencyFacade()
    : security(&mediator), accessControl(&mediator), medical(&mediator), paAdapter(&mediator) {
    // CampusMediator acts as the concrete observer/mediator.
    // Individual services hold references to the mediator via their Colleague constructors.
    mediator.registerColleague(&security);
    mediator.registerColleague(&accessControl);
    mediator.registerColleague(&medical);
    mediator.registerColleague(&paAdapter);
}

CampusMediator& EmergencyFacade::getMediator() {
    return mediator;
}

void EmergencyFacade::executeFullCampusEvacuationWorkflow(IncidentContext& incident, const string& reason) {
    cout << "\n=======================================================\n";
    cout << "[FACADE WORKFLOW] Initiating Campus Evacuation Protocol\n";
    cout << "=======================================================\n";

    cout << "[Facade] Step 1: Dispatching security response.\n";
    ICommand* dispatchCmd = new DispatchUnitsCommand(&security, &incident);
    invoker.submitAndExecute(dispatchCmd);

    cout << "[Facade] Step 2: Preparing medical response.\n";
    medical.prepareResponse(incident.getLocation());

    cout << "[Facade] Step 3: Restricting building access.\n";
    ICommand* lockCmd = new LockBuildingCommand(&accessControl, incident.getLocation());
    invoker.submitAndExecute(lockCmd);

    cout << "[Facade] Step 4: Broadcasting evacuation alert.\n";
    ICommand* alertCmd = new BroadcastAlertCommand(&paAdapter, incident.getLocation(), "EVACUATE IMMEDIATELY: " + reason);
    invoker.submitAndExecute(alertCmd);

    cout << "[Facade] Campus evacuation workflow completed.\n";
    cout << "=======================================================\n\n";
}

void EmergencyFacade::cancelLastAction() {
    cout << "\n[FACADE OPERATOR ROLLBACK] Undoing previous step...\n";
    invoker.undoLastAction();
}

// this is for the interactive main
SecurityService& EmergencyFacade::getSecurity()
{
    return security;
}

AccessControlService& EmergencyFacade::getAccessControl()
{
    return accessControl;
}

MedicalService& EmergencyFacade::getMedical()
{
    return medical;
}

LegacyPAAdapter& EmergencyFacade::getNotifier()
{
    return paAdapter;
}

OperatorControlPanel& EmergencyFacade::getControlPanel()
{
    return invoker;
}