#include "ResolveIncidentCommand.h"
#include "IncidentContext.h"

ResolveIncidentCommand::ResolveIncidentCommand(IncidentContext* incident)
    : incident(incident), executed(false)
{}

void ResolveIncidentCommand::execute()
{
    if(incident == nullptr)
    {
        return;
    }

    if(incident->resolve())
    {
        executed = true;
    }
    else
    {
        executed = false;
    }
}

void ResolveIncidentCommand::undo()
{
    if(!executed || incident == nullptr)
    {
        return;
    }

    if(incident->restoreState())
    {
        executed = false;
    }
}
