#include "DispatchUnitsCommand.h"
#include "SecurityService.h"
#include "IncidentContext.h"

DispatchUnitsCommand::DispatchUnitsCommand(SecurityService* security, IncidentContext* incident)
    : security(security), incident(incident), executed(false)
{}

bool DispatchUnitsCommand::execute()
{
    if(this->security == nullptr || this->incident == nullptr)
    {
        this->executed = false;
        return false;
    }

    if(!this->incident->dispatch())
    {
        this->executed = false;
        return false;
    }

    this->security->dispatchTeam(this->incident->getLocation());
    this->executed = true;

    return true;
}

bool DispatchUnitsCommand::undo()
{
    if(!this->executed)
    {
        return false;
    }

    if(this->security != nullptr && this->incident != nullptr)
    {
        this->security->cancelDispatch(this->incident->getLocation());

        if(!this->incident->restoreState())
        {
            return false;
        }

        this->executed = false;
        return true;
    }

    return false;
}
