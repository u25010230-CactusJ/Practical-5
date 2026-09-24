#ifndef SECURITYSERVICE_H
#define SECURITYSERVICE_H

#include "Colleague.h"
#include <string>

class IMediator;

class SecurityService : public Colleague
{
    public:
        explicit SecurityService(IMediator* mediator);

        void dispatchTeam(std::string location);
        void lockdownArea(std::string location);

        virtual bool handleEvent(const std::string& event, const std::string& payload) override;

        ~SecurityService() override = default;
};

#endif /*SECURITYSERVICE_H*/