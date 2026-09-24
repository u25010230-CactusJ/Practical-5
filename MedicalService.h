#ifndef MEDICALSERVICE_H
#define MEDICALSERVICE_H

#include "Colleague.h"
#include <string>

class IMediator;

class MedicalService : public Colleague
{
    public:
        explicit MedicalService(IMediator* mediator);

        void prepareResponse(std::string location);
        void handleEvent(const std::string& event, const std::string& payload) override;

        ~MedicalService() override = default;
};

#endif /* MEDICALSERVICE_H */
