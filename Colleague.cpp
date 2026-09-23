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
