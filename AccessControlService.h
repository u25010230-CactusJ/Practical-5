#ifndef ACCESSCONTROLSERVICE_H
#define ACCESSCONTROLSERVICE_H

#include "Colleague.h"
#include <string>

class IMediator;

class AccessControlService : public Colleague
{
    private:
        std::string event;
        std::string payload;

    public:
        AccessControlService(IMediator* mediator);

        virtual std::string getEvent() override;
        virtual std::string getPayload() override;
        virtual void handleEvent(std::string payload) override;

        void restrictDoors(std::string location);
        void unlockEmergencyExits(std::string location);

        ~AccessControlService() override;
};

#endif /*ACCESSCONTROLSERVICE_H*/