#ifndef DEMOSCENARIO_H
#define DEMOSCENARIO_H

#include "EmergencyFacade.h"
#include "IncidentContext.h"
#include "DispatchUnitsCommand.h"
#include "LockBuildingCommand.h"
#include "BroadcastAlertCommand.h"
#include "ResolveIncidentCommand.h"

#include <iostream>
#include <string>

using namespace std;

class DemoScenario
{
    private:
        void displayMenu();
        void reportIncident(EmergencyFacade& facade, IncidentContext*& incident);
        void dispatchSecurity(EmergencyFacade& facade,IncidentContext* incident);
        void requestMedical(EmergencyFacade& facade,IncidentContext* incident);
        void lockBuilding(EmergencyFacade& facade,IncidentContext* incident);
        void broadcastAlert(EmergencyFacade& facade,IncidentContext* incident);
        void resolveIncident(EmergencyFacade& facade,IncidentContext* incident);
        void undoLastAction(EmergencyFacade& facade);
        void showIncidentStatus(IncidentContext* incident);
    
    public:
        void runDemoScenario();
};

#endif /*DEMOSCENARIO_H*/