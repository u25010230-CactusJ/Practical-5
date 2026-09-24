#ifndef MEDICALSERVICE_H
#define MEDICALSERVICE_H

#include "Colleague.h"
#include <string>

class IMediator;

class MedicalService : public Colleague
{
    public:
        explicit MedicalService(IMediator* mediator);

        void MedicalService::requestMedicalAssistance(std::string location);
        void prepareResponse(std::string location);
        bool handleEvent(const std::string& event, const std::string& payload) override;

        ~MedicalService() override = default;
};

#endif /* MEDICALSERVICE_H */
