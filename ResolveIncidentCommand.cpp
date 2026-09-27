#include "ResolveIncidentCommand.h"
#include "IncidentContext.h"

ResolveIncidentCommand::ResolveIncidentCommand(IncidentContext* incident)
    : incident(incident), executed(false)
{}

bool ResolveIncidentCommand::execute()
{
    if(this->incident == nullptr)
    {
        this->executed = false;
        return false;
    }

    if(this->incident->resolve())
    {
        this->executed = true;
        return true;
    }

    this->executed = false;
    return false;
}

bool ResolveIncidentCommand::undo()
{
    if(!this->executed || this->incident == nullptr)
    {
        return false;
    }

    if(this->incident->restoreState())
    {
        this->executed = false;
        return true;
    }

    return false;
}
