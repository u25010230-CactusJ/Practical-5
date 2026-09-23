#ifndef SECURITYSERVICE_H
#define SECURITYSERVICE_H

#include "Colleague.h"
#include <string>

class IMediator;

class SecurityService : public Colleague
{
    private:
        std::string event;
        std::string payload;

    public:
        SecurityService(IMediator* mediator);

        virtual std::string getEvent() override;
        virtual std::string getPayload() override;
        virtual void handlEvent(std::string payload) override;

        void dispatchTeam(std::string location);
        void lockdownArea(std::string location);

        ~SecurityService() override;
};

#endif /*SECURITYSERVICE_H*/