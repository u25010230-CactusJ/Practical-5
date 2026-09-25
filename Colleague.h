#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class IMediator;
#include <string>

class Colleague
{
    protected:
        IMediator* mediator;
        std::string event;
        std::string payload;

    public:
        explicit Colleague(IMediator* mediator);
        virtual void changed();

        virtual std::string getEvent() const;
        virtual std::string getPayload() const;

        virtual bool handleEvent(const std::string& event, const std::string& payload) = 0;
        virtual ~Colleague() = default;
};

#endif /*COLLEAGUE_H*/