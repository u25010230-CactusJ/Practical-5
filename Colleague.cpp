#include "Colleague.h"
#include "IMediator.h"

Colleague::Colleague(IMediator* mediator)
    : mediator(mediator)
{}

void Colleague::changed()
{
    this->mediator->notify(this);
}
