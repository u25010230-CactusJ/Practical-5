#ifndef SECURITYSERVICE_H
#define SECURITYSERVICE_H

#include "Colleague.h"
#include <string>

class IMediator;

class SecurityService : public Colleague
{
    public:
        SecurityService(IMediator* mediator);

        virtual void handleEvent(const std::string& payload) override;

        void dispatchTeam(std::string location);
        void lockdownArea(std::string location);

        ~SecurityService() override;
};

#endif /*SECURITYSERVICE_H*/