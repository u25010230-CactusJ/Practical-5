#ifndef LOCKBUILDCOMMAND_H
#define LOCKBUILDCOMMAND_H

#include "ICommand.h"
#include <string>

class AccessControlService;

class LockBuildingCommand : public ICommand
{
    private:
        AccessControlService* accessControl;
        std::string location;
        bool isLocked;
        
    public:
        LockBuildingCommand(AccessControlService* accessControl, std::string location);

        virtual bool execute() override;
        virtual bool undo() override;

        ~LockBuildingCommand() override = default;
};

#endif /*LOCKBUILDCOMMAND_H*/