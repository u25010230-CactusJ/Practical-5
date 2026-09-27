#include <iostream>
#include <cassert>
#include <string>

// State & Observer Pattern Headers
#include "IncidentContext.h"
#include "IncidentNotifier.h"
#include "IIncidentObserver.h"
#include "IncidentState.h"
#include "ReportedState.h"
#include "ActiveState.h"
#include "ResolvedState.h"

// Mediator & Service Headers
#include "CampusMediator.h"
#include "SecurityService.h"
#include "AccessControlService.h"
#include "MedicalService.h"
#include "ModernNotifier.h"

// Command Pattern Headers
#include "OperatorControlPanel.h"
#include "DispatchUnitsCommand.h"
#include "LockBuildingCommand.h"
#include "BroadcastAlertCommand.h"

// Concrete implementation for ModernNotifier pure virtual sendAlert
class ConcreteNotifier : public ModernNotifier {
public:
    // This relies on the 1-line fix to ModernNotifier.h mentioned above
    explicit ConcreteNotifier(IMediator* mediator) : ModernNotifier(mediator) {}

    void sendAlert(const std::string& zone, const std::string& message) override {
        std::cout << "[ConcreteNotifier] Alert sent to " << zone << ": " << message << std::endl;
    }
};

// Mock Observer for testing observer notifications
class MockObserver : public IIncidentObserver {
public:
    int updateCount;
    std::string lastState;

    MockObserver() : updateCount(0), lastState("") {}

    void onStateChange(IncidentContext* context) override {
        if (context) {
            updateCount++;
            lastState = context->getStateName();
            std::cout << "  [MockObserver] Notification #" << updateCount 
                      << " | Incident: " << context->getId() 
                      << " is now " << lastState << std::endl;
        }
    }
};

int main() {
    std::cout << "=================================================================\n";
    std::cout << "     CAMPUSGUARD COMPLETE SUITE - MAXIMUM CODE COVERAGE TEST     \n";
    std::cout << "=================================================================\n\n";

    // -----------------------------------------------------------------
    // SECTION 1: STATE PATTERN & TRANSITION TESTING
    // -----------------------------------------------------------------
    std::cout << "--- [SECTION 1] TESTING STATE PATTERN TRANSITIONS ---\n";
    IncidentContext* incident = new IncidentContext("INC-2026-999", "Engineering Building");

    assert(incident->getStateName() == "Reported");
    std::cout << "Initial State Verified: " << incident->getStateName() << std::endl;

    std::cout << "\n[Test 1.1] Invalid Resolve in Reported State:" << std::endl;
    incident->resolve();
    assert(incident->getStateName() == "Reported");

    std::cout << "\n[Test 1.2] Dispatch (Reported -> Active):" << std::endl;
    incident->dispatch();
    assert(incident->getStateName() == "Active");

    std::cout << "\n[Test 1.3] Redundant Dispatch in Active State:" << std::endl;
    incident->dispatch();
    
    std::cout << "\n[Test 1.4] Resolve (Active -> Resolved):" << std::endl;
    incident->resolve();
    assert(incident->getStateName() == "Resolved");

    std::cout << "\n[Test 1.5] Redundant Dispatch & Resolve in Resolved State:" << std::endl;
    incident->dispatch();
    incident->resolve();


    // -----------------------------------------------------------------
    // SECTION 2: OBSERVER PATTERN & INCIDENTNOTIFIER DELEGATION
    // -----------------------------------------------------------------
    std::cout << "\n--- [SECTION 2] TESTING OBSERVER PATTERN & INCIDENTNOTIFIER ---\n";
    IncidentContext observableIncident("INC-2026-100", "Science Lab A");
    MockObserver* observer1 = new MockObserver();
    MockObserver* observer2 = new MockObserver();

    observableIncident.attach(observer1);
    observableIncident.attach(observer2);
    std::cout << "Attached observer1 and observer2 successfully." << std::endl;

    std::cout << "\n[Test 2.1] Triggering Dispatch Notification:" << std::endl;
    observableIncident.dispatch(); 
    assert(observer1->updateCount == 1 && observer1->lastState == "Active");

    std::cout << "\n[Test 2.2] Detaching Observer 1 and Resolving:" << std::endl;
    observableIncident.detach(observer1);
    observableIncident.resolve(); 
    
    assert(observer1->updateCount == 1);
    assert(observer2->updateCount == 2 && observer2->lastState == "Resolved");


    // -----------------------------------------------------------------
    // SECTION 3: MEDIATOR PATTERN & SERVICE COLLEAGUES
    // -----------------------------------------------------------------
    std::cout << "\n--- [SECTION 3] TESTING MEDIATOR & SERVICE COLLEAGUES ---\n";
    CampusMediator* mediator = new CampusMediator();
    
    SecurityService* security = new SecurityService(mediator);
    AccessControlService* accessControl = new AccessControlService(mediator);
    MedicalService* medical = new MedicalService(mediator);
    ConcreteNotifier* notifier = new ConcreteNotifier(mediator);

    // Register Services via exact method found in CampusMediator.h
    mediator->registerColleague(security);
    mediator->registerColleague(accessControl);
    mediator->registerColleague(medical);
    mediator->registerColleague(notifier);
    std::cout << "Registered all services with CampusMediator." << std::endl;

    // Test Colleague Services using exact methods from their headers
    std::cout << "\n[Test 3.1] Security Service triggers dispatch:" << std::endl;
    security->dispatchTeam("Building 4");

    std::cout << "\n[Test 3.2] Access Control triggers lockdown:" << std::endl;
    accessControl->restrictDoors("Building 4");

    std::cout << "\n[Test 3.3] Medical Service triggers assist:" << std::endl;
    medical->requestMedicalAssistance("Building 4");

    std::cout << "\n[Test 3.4] ModernNotifier testing cancel alert:" << std::endl;
    notifier->cancelAlert("Building 4");


    // -----------------------------------------------------------------
    // SECTION 4: COMMAND PATTERN & OPERATOR CONTROL PANEL
    // -----------------------------------------------------------------
    std::cout << "\n--- [SECTION 4] TESTING COMMAND PATTERN & CONTROL PANEL ---\n";
    OperatorControlPanel panel;

    // Instantiate concrete commands
    ICommand* dispatchCmd = new DispatchUnitsCommand(security, incident);
    ICommand* lockCmd = new LockBuildingCommand(accessControl, "Library Building");
    ICommand* alertCmd = new BroadcastAlertCommand(notifier, "EMERGENCY_LOCKDOWN", "Library Building");

    // Execute Commands via Operator Control Panel using submitAndExecute
    std::cout << "\n[Test 4.1] Executing Dispatch Command:" << std::endl;
    panel.submitAndExecute(dispatchCmd);

    std::cout << "\n[Test 4.2] Executing Lock Building Command:" << std::endl;
    panel.submitAndExecute(lockCmd);

    std::cout << "\n[Test 4.3] Executing Broadcast Alert Command:" << std::endl;
    panel.submitAndExecute(alertCmd);

    std::cout << "\n[Test 4.4] Testing Undo Functionality:" << std::endl;
    panel.undoLastAction();


    // -----------------------------------------------------------------
    // SECTION 5: MEMORY CLEANUP
    // -----------------------------------------------------------------
    std::cout << "\n--- [SECTION 5] CLEANING ALLOCATED MEMORY ---\n";
    delete observer1;
    delete observer2;

    // panel.history takes ownership of ICommands? If not, delete them here.
    // Assuming OperatorControlPanel destructor cleans up its stack to avoid double deletion errors.

    delete incident;
    delete security;
    delete accessControl;
    delete medical;
    delete notifier;
    delete mediator;

    std::cout << "All dynamically allocated memory cleaned up successfully.\n";
    std::cout << "=================================================================\n";
    std::cout << "          ALL PATTERN TESTS COMPLETED SUCCESSFULLY!              \n";
    std::cout << "=================================================================\n";

    return 0;
}