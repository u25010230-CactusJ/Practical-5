#include "Colleague.h"
#include "IMediator.h"

Colleague::Colleague(IMediator* mediator)
    : mediator(mediator)
{}

void Colleague::changed()
{
    if(mediator != nullptr)
    {
        mediator->notify(this);
    }
}

std::string Colleague::getEvent() const
{
    return this->event;
}

std::string Colleague::getPayload() const
{
    return this->payload;
}
