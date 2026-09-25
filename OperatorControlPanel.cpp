#include "OperatorControlPanel.h"
#include <iostream>

void OperatorControlPanel::submitAndExecute(ICommand* command)
{
    if(command == nullptr)
    {
        std::cout << "[Operator] ERROR: Cannot execute a null command." << std::endl;
        return;
    }

    command->execute();
    history.push(command);
}

void OperatorControlPanel::undoLastAction()
{
    if(history.empty())
    {
        std::cout << "[Operator] No command available to undo." << std::endl;
        return;
    }

    ICommand* command = history.top();

    if(command == nullptr)
    {
        std::cout << "[Operator] ERROR: Cannot undo a null command." << std::endl;
        return;
    }

    command->undo();
    history.pop();
}
