#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class IMediator;
#include <string>

class Colleague
{
    protected:
        IMediator* mediator;

    public:
        Colleague(IMediator* mediator);
        void changed();

        virtual std::string getEvent() = 0;
        virtual std::string getPayload() = 0;

        virtual void handleEvent(std::string payload) = 0;
        virtual ~Colleague() = default;
};

#endif /*COLLEAGUE_H*/