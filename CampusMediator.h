#ifndef CAMPUSMEDIATOR_H
#define CAMPUSMEDIATOR_H

#include "IMediator.h"
#include <vector>

class CampusMediator : public IMediator
{
    private:
        std::vector<Colleague*> colleagues;

    public:
        void registerColleague(Colleague* newCol);
        void deregisterColleague(Colleague* newCol);
        virtual void notify(Colleague* sender) override;
        
        ~CampusMediator() override = default;
};

#endif /*CAMPUSMEDIATOR_H*/