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

        virtual void execute() override;
        virtual void undo() override;

        std::string getLocation();
        void setLocation(std::string location);

        AccessControlService* getReceiver();
        void setReceiver(AccessControlService* accessControl);

        ~LockBuildingCommand() override = default;
};

#endif /*LOCKBUILDCOMMAND_H*/