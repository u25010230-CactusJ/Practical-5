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

std::string BroadcastAlertCommand::getLocation()
{
    return this->location;
}

void BroadcastAlertCommand::setLocation(std::string location)
{
    this->location = location;
}

std::string BroadcastAlertCommand::getMSG()
{
    return this->msg;
}

void BroadcastAlertCommand::setMSG(std::string msg)
{
    this->msg = msg;
}

ModernNotifier* BroadcastAlertCommand::getReceiver()
{
    return this->notifier;
}

void BroadcastAlertCommand::setReceiver(ModernNotifier* notifier)
{
    this->notifier = notifier;
}
