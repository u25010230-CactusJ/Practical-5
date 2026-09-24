#ifndef ACCESSCONTROLSERVICE_H
#define ACCESSCONTROLSERVICE_H

#include "Colleague.h"
#include <string>

class IMediator;

class AccessControlService : public Colleague
{
    public:
        AccessControlService(IMediator* mediator);

        void restrictDoors(std::string location);
        void unlockEmergencyExits(std::string location);

        virtual bool handleEvent(const std::string& event, const std::string& payload) override;

        ~AccessControlService() override = default;
};

#endif /*ACCESSCONTROLSERVICE_H*/