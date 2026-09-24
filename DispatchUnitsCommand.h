#ifndef DISPATCHUNITSCOMMAND_H
#define DISPATCHUNITSCOMMAND_H

#include "ICommand.h"
#include <string>

class SecurityService;
class IncidentContext;

class DispatchUnitsCommand : public ICommand
{
    private:
        SecurityService* security;
        IncidentContext* incident;
        bool executed;
        
    public:
        DispatchUnitsCommand(SecurityService* security, IncidentContext* incident);

        virtual void execute() override;
        virtual void undo() override;

        ~DispatchUnitsCommand() override = default;
};

#endif /*DISPATCHUNITSCOMMAND_H*/