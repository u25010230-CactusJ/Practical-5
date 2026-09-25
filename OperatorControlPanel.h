#ifndef OPERATORCONTROLPANEL_H
#define OPERATORCONTROLPANEL_H

#include "ICommand.h"
#include <stack>

class OperatorControlPanel
{
    private:
        std::stack<ICommand*> history;

    public:
        void submitAndExecute(ICommand* command);
        void undoLastAction();

        ~OperatorControlPanel() = default;
};

#endif /*OPERATORCONTROLPANEL_H*/
