#include "DemoScenario.h"

void DemoScenario::displayMenu()
{
    cout << "\n========== CAMPUSGUARD ==========" << endl;
    cout << "1. Report incident" << endl;
    cout << "2. Dispatch security" << endl;
    cout << "3. Request medical assistance" << endl;
    cout << "4. Lock down building" << endl;
    cout << "5. Broadcast emergency alert" << endl;
    cout << "6. Resolve incident" << endl;
    cout << "7. Undo last action" << endl;
    cout << "8. Show incident status" << endl;
    cout << "0. Exit" << endl;
    cout << "=================================" << endl;
}

void DemoScenario::reportIncident(EmergencyFacade& facade, IncidentContext*& incident)
{
    if(incident != nullptr)
    {
        cout << "\nAn incident is already active." << endl;
        cout << "Incident ID: " << incident->getId() << endl;
        cout << "Location: " << incident->getLocation() << endl;
        cout << "State: " << incident->getStateName() << endl;
        return;
    }

    string id;
    string location;

    cout << "\nEnter incident ID: ";
    getline(cin, id);

    cout << "Enter incident location: ";
    getline(cin, location);

    if(id.empty() || location.empty())
    {
        cout << "Incident ID and location cannot be empty." << endl;
        return;
    }

    incident = new IncidentContext(id, location);
    incident->attach(&facade.getMediator());
    cout << "[System] Incident successfully reported." << endl;
}

void DemoScenario::dispatchSecurity(EmergencyFacade& facade, IncidentContext* incident)
{
    if(incident == nullptr)
    {
        cout << "\nNo incident has been reported." << endl;
        return;
    }

    ICommand* command = new DispatchUnitsCommand(&facade.getSecurity(), incident);
    facade.getControlPanel().submitAndExecute(command);
}

void DemoScenario::requestMedical(EmergencyFacade& facade, IncidentContext* incident)
{
    if(incident == nullptr)
    {
        cout << "\nNo incident has been reported." << endl;
        return;
    }

    facade.getMedical().requestMedicalAssistance(incident->getLocation());
}

void DemoScenario::lockBuilding(EmergencyFacade& facade, IncidentContext* incident)
{
    if(incident == nullptr)
    {
        cout << "\nNo incident has been reported." << endl;
        return;
    }

    ICommand* command = new LockBuildingCommand(&facade.getAccessControl(), incident->getLocation());
    facade.getControlPanel().submitAndExecute(command);
}

void DemoScenario::broadcastAlert(EmergencyFacade& facade, IncidentContext* incident)
{
    if(incident == nullptr)
    {
        cout << "\nNo incident has been reported." << endl;
        return;
    }

    string message;

    cout << "\nEnter emergency alert message: ";
    getline(cin, message);

    if(message.empty())
    {
        cout << "Alert message cannot be empty." << endl;
        return;
    }

    ICommand* command = new BroadcastAlertCommand(&facade.getNotifier(), incident->getLocation(), message);
    facade.getControlPanel().submitAndExecute(command);
}

void DemoScenario::resolveIncident(EmergencyFacade& facade, IncidentContext* incident)
{
    if(incident == nullptr)
    {
        cout << "\nNo incident has been reported." << endl;
        return;
    }

    ICommand* command = new ResolveIncidentCommand(incident);
    facade.getControlPanel().submitAndExecute(command);
}

void DemoScenario::undoLastAction(EmergencyFacade& facade)
{
    facade.getControlPanel().undoLastAction();
}

void DemoScenario::showIncidentStatus(IncidentContext* incident)
{
    cout << "\n========== INCIDENT STATUS ==========" << endl;

    if(incident == nullptr)
    {
        cout << "No active incident." << endl;
        cout << "=====================================" << endl;
        return;
    }

    cout << "Incident ID : " << incident->getId() << endl;
    cout << "Location    : " << incident->getLocation() << endl;
    cout << "State       : " << incident->getStateName() << endl;
    cout << "=====================================" << endl;
}

void DemoScenario::runDemoScenario()
{
    EmergencyFacade facade;
    IncidentContext* incident = nullptr;
    int choice = -1;

    cout << "==================================================" << endl;
    cout << "              CAMPUSGUARD EMERGENCY SYSTEM" << endl;
    cout << "==================================================" << endl;

    while(choice != 0)
    {
        displayMenu();
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch(choice)
        {
            case 1:
                reportIncident(facade, incident);
                break;

            case 2:
                dispatchSecurity(facade, incident);
                break;

            case 3:
                requestMedical(facade, incident);
                break;

            case 4:
                lockBuilding(facade, incident);
                break;

            case 5:
                broadcastAlert(facade, incident);
                break;

            case 6:
                resolveIncident(facade, incident);
                break;

            case 7:
                undoLastAction(facade);
                break;

            case 8:
                showIncidentStatus(incident);
                break;

            case 0:
                cout << "\nExiting CampusGuard..." << endl;
                break;

            default:
                cout << "\nInvalid option. Please select a valid menu option." << endl;
                break;
        }
    }

    delete incident;

    cout << "CampusGuard shut down successfully." << endl;
}
