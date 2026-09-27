#include "DispatchUnitsCommand.h"
#include "SecurityService.h"
#include "IncidentContext.h"

DispatchUnitsCommand::DispatchUnitsCommand(SecurityService* security, IncidentContext* incident)
    : security(security), incident(incident), executed(false)
{}

void DispatchUnitsCommand::execute()
{
    if(this->security == nullptr || this->incident == nullptr)
    {
        this->executed = false;
        return;
    }

    if(!this->incident->dispatch())
    {
        this->executed = false;
        return;
    }

    this->security->dispatchTeam(this->incident->getLocation());
    this->executed = true;
}

void DispatchUnitsCommand::undo()
{
    if(!this->executed) return;

    if(this->security != nullptr && this->incident != nullptr)
    {
        this->security->cancelDispatch(this->incident->getLocation());
        this->incident->restoreState();
    }

    this->executed = false;
}
