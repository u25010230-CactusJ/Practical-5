#include "BroadcastAlertCommand.h"
#include "ModernNotifier.h"

BroadcastAlertCommand::BroadcastAlertCommand(ModernNotifier* notifier, std::string location, std::string msg)
    : notifier(notifier), location(location), msg(msg)
{}

bool BroadcastAlertCommand::execute()
{
    if(this->notifier == nullptr)
    {
        return false;
    }

    this->notifier->sendAlert(this->location, this->msg);
    return true;
}

bool BroadcastAlertCommand::undo()
{
    if(this->notifier == nullptr)
    {
        return false;
    }

    this->notifier->cancelAlert(this->location);
    return true;
}
