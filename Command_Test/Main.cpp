#include "OperatorControlPanel.h"
#include "LockBuildingCommand.h"
#include "DispatchUnitsCommand.h"
// #include "BroadcastAlertCommand.h"
#include "AccessControlService.h"
#include "SecurityService.h"
#include "CampusMediator.h"
// #include "ModernNotifier.h"
// #include "IncidentContext.h"

#include <iostream>

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "       CampusGuard Command Test" << std::endl;
    std::cout << "========================================" << std::endl;

    CampusMediator mediator;

    AccessControlService accessControl(&mediator);
    SecurityService security(&mediator);
    // ModernNotifier notifier(&mediator);
    // IncidentContext incident("INC001","Science Building");

    mediator.registerColleague(&accessControl);
    mediator.registerColleague(&security);
    // mediator.registerColleague(&notifier);

    OperatorControlPanel panel;

    std::cout << "\n--- Test 1: Lock building command ---" << std::endl;
    panel.submitAndExecute(new LockBuildingCommand(&accessControl,"Science Building"));

    std::cout << "\n--- Test 2: Undo lock building command ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 3: Dispatch units command ---" << std::endl;
    // panel.submitAndExecute(new DispatchUnitsCommand(&security,&incident));

    std::cout << "\n--- Test 4: Undo dispatch units command ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 5: Broadcast alert command ---" << std::endl;
    // panel.submitAndExecute(new BroadcastAlertCommand(&notifier,"Science Building","Evacuate immediately"));

    std::cout << "\n--- Test 6: Undo broadcast alert command ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 7: Undo with empty history ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 8: Null command ---" << std::endl;
    panel.submitAndExecute(nullptr);

    std::cout << "\n--- Test 9: Multiple commands in history ---" << std::endl;
    panel.submitAndExecute(new LockBuildingCommand(&accessControl,"Library"));
    // panel.submitAndExecute(new BroadcastAlertCommand(&notifier,"Library","Emergency evacuation"));
    // panel.submitAndExecute(new DispatchUnitsCommand(&security,&incident));

    std::cout << "\n--- Test 10: Undo most recent command ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 11: Undo next command ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 12: Undo final command ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 13: Undo after all commands removed ---" << std::endl;
    panel.undoLastAction();

    std::cout << "\n--- Test 14: Null service in LockBuildingCommand ---" << std::endl;
    LockBuildingCommand* invalidLock = new LockBuildingCommand(nullptr,"Engineering Building");
    delete invalidLock;

    std::cout << "\n--- Test 15: Null service in DispatchUnitsCommand ---" << std::endl;
    // DispatchUnitsCommand* invalidDispatch = new DispatchUnitsCommand(nullptr,&incident);
    // delete invalidDispatch;

    // std::cout << "\n--- Test 16: Null incident in DispatchUnitsCommand ---" << std::endl;
    // DispatchUnitsCommand* invalidIncident = new DispatchUnitsCommand(&security,nullptr);
    // delete invalidIncident;

    std::cout << "\n========================================" << std::endl;
    std::cout << "        Command Tests Complete" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
