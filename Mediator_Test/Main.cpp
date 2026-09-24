#include "CampusMediator.h"
#include "SecurityService.h"
#include "AccessControlService.h"
#include "MedicalService.h"
//#include "ModernNotifier.h"

#include <iostream>

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "      CampusGuard Mediator Test" << std::endl;
    std::cout << "========================================" << std::endl;

    CampusMediator mediator;

    SecurityService security(&mediator);
    AccessControlService accessControl(&mediator);
    MedicalService medical(&mediator);
    //ModernNotifier notifier(&mediator);

    mediator.registerColleague(&security);
    mediator.registerColleague(&accessControl);
    mediator.registerColleague(&medical);
    //mediator.registerColleague(&notifier);

    std::cout << "\n--- Test 1: Security dispatches team ---" << std::endl;
    security.dispatchTeam("Science Building");

    std::cout << "\n--- Test 2: Medical request ---" << std::endl;
    medical.requestMedicalAssistance("Library");

    std::cout << "\n--- Test 3: Security locks down area ---" << std::endl;
    security.lockdownArea("Engineering Building");

    std::cout << "\n--- Test 4: Unknown event ---" << std::endl;
    security.handleEvent("UNKNOWN_EVENT","Unknown Location");

    std::cout << "\n--- Test 5: Deregister MedicalService ---" << std::endl;
    mediator.deregisterColleague(&medical);
    security.dispatchTeam("Student Centre");

    std::cout << "\n--- Test 6: Deregister remaining colleagues ---" << std::endl;
    mediator.deregisterColleague(&security);
    mediator.deregisterColleague(&accessControl);
    //mediator.deregisterColleague(&notifier);

    security.dispatchTeam("Empty Campus");

    std::cout << "\n========================================" << std::endl;
    std::cout << "       Mediator Tests Complete" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
