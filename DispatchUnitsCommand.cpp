#include "DispatchUnitsCommand.h"
#include "SecurityService.h"
#include "IncidentContext.h"

DispatchUnitsCommand::DispatchUnitsCommand(SecurityService* security, IncidentContext* incident)
    : security(security), incident(incident), executed(false)
{}

void DispatchUnitsCommand::execute()
{
    this->incident->dispatch();
    this->security->dispatchTeam(this->incident->getLocation());
    this->executed = true;
}

void DispatchUnitsCommand::undo()
{
    if(this->executed)
    {
        this->security->cancelDispatch(this->incident->getLocation());
        this->executed = false;
    }
}
