#include "CampusMediator.h"
#include "Colleague.h"

void CampusMediator::registerColleague(Colleague* newCol)
{
    if(newCol == nullptr) return;

    for(auto col : this->colleagues)
    {
        if(col == newCol) return; // already exists
    }

    this->colleagues.push_back(newCol);
}

void CampusMediator::deregisterColleague(Colleague* newCol)
{
    if(newCol == nullptr) return;

    std::vector<Colleague*>::iterator it = this->colleagues.begin();
    while(it != colleagues.end())
    {
        if(*it == newCol)
        {
            this->colleagues.erase(it);
            return;
        }

        it++;
    }
}

void CampusMediator::notify(Colleague* sender)
{
    //string event = sender->getEvent();
    std::string payload = sender->getPayload();

    for(auto col : this->colleagues)
    {
        if(col != sender)
        {
            col->handlEvent(payload);
        }
    }
}

CampusMediator::~CampusMediator()
{
    std::vector<Colleague*>::iterator it = this->colleagues.begin();
    while(it != colleagues.end())
    {
        this->colleagues.erase(it);
    }
}
