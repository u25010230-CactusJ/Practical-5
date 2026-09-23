#ifndef IMEDIATOR_H
#define IMEDIATOR_H

class Colleague;

class IMediator
{
    public:
        virtual void notify(Colleague* sender) = 0;
        virtual ~IMediator() = default;
};

#endif; /*IMEDIATOR_H*/