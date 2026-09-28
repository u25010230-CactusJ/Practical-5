#ifndef EMERGENCY_FACADE_H
#define EMERGENCY_FACADE_H

#include "CampusMediator.h"
#include "SecurityService.h"
#include "AccessControlService.h"
#include "MedicalService.h"
#include "LegacyPAAdapter.h"
#include "OperatorControlPanel.h"
#include <string>

class IncidentContext;

// Facade: High-level entry point orchestrating campus emergency workflows
class EmergencyFacade {
private:
    CampusMediator mediator;
    SecurityService security;
    AccessControlService accessControl;
    MedicalService medical;
    LegacyPAAdapter paAdapter;
    OperatorControlPanel invoker;

public:
    EmergencyFacade();
    CampusMediator& getMediator();

    void executeFullCampusEvacuationWorkflow(IncidentContext& incident, const std::string& reason);
    void cancelLastAction();


    // this is for the interactive main
    SecurityService& getSecurity();
    AccessControlService& getAccessControl();
    MedicalService& getMedical();
    LegacyPAAdapter& getNotifier();
    OperatorControlPanel& getControlPanel();
};

#endif /*EMERGENCY_FACADE_H*/
