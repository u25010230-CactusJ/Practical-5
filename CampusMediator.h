#ifndef CAMPUSMEDIATOR_H
#define CAMPUSMEDIATOR_H

#include "IMediator.h"
#include "IIncidentObserver.h"
#include <vector>

class Colleague;
class IncidentContext;

class CampusMediator : public IMediator, public IIncidentObserver
{
    private:
        std::vector<Colleague*> colleagues;

    public:
        void registerColleague(Colleague* newCol);
        void deregisterColleague(Colleague* newCol);
        virtual void notify(Colleague* sender) override;
        virtual void onStateChange(IncidentContext* context) override;        
        
        ~CampusMediator() override = default;
};

#endif /*CAMPUSMEDIATOR_H*/
