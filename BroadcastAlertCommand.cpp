#include "BroadcastAlertCommand.h"
#include "ModernNotifier.h"

BroadcastAlertCommand::BroadcastAlertCommand(ModernNotifier* notifier, std::string location, std::string msg)
    : notifier(notifier), location(location), msg(msg)
{}

void BroadcastAlertCommand::execute()
{
    this->notifier->sendAlert(this->location, this->msg);
}

void BroadcastAlertCommand::undo()
{
    notifier->cancelAlert(location);
} 
