#ifndef BROADCASTALERTCOMMAND_H
#define BROADCASTALERTCOMMAND_H

#include "ICommand.h"
#include <string>

class ModernNotifier;

class BroadcastAlertCommand : public ICommand
{
    private:
        ModernNotifier* notifier;
        std::string location;
        std::string msg;
        
    public:
        BroadcastAlertCommand(ModernNotifier* notifier, std::string location, std::string msg);

        virtual bool execute() override;
        virtual bool undo() override;

        ~BroadcastAlertCommand() override = default;
};

#endif /*BROADCASTALERTCOMMAND_H*/