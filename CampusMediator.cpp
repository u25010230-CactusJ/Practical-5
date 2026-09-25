#include "CampusMediator.h"
#include "Colleague.h"
#include <iostream>

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
    if(sender == nullptr) return;

    std::string event = sender->getEvent();
    std::string payload = sender->getPayload();
    bool handled = false;

    std::cout << "[Mediator] Received event: " << event << " for " << payload << std::endl;

    for(Colleague* colleague : colleagues)
    {
        if(colleague != nullptr && colleague != sender)
        {
            if(colleague->handleEvent(event, payload))
            {
                handled = true;
            }
        }
    }

    if(!handled)
    {
        std::cout << "[Mediator] WARNING: No colleague handled event '" << event << "'" << std::endl;
    }
}
