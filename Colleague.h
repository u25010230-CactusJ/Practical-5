#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class IMediator;
#include <string>

class Colleague
{
    protected:
        IMediator* mediator;

    public:
        explicit Colleague(IMediator* mediator);
        virtual void changed();

        virtual std::string getEvent() const = 0;
        virtual std::string getPayload() const = 0;

        virtual void handleEvent(const std::string& payload) = 0;
        virtual ~Colleague() = default;
};

#endif /*COLLEAGUE_H*/