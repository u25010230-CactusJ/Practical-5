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

        virtual void execute() override;
        virtual void undo() override;

        std::string getLocation();
        void setLocation(std::string location);
        std::string getMSG();
        void setMSG(std::string msg);

        ModernNotifier* getReceiver();
        void setReceiver(ModernNotifier* notifier);

        ~BroadcastAlertCommand() override = default;
};

#endif /*BROADCASTALERTCOMMAND_H*/