#include "OperatorControlPanel.h"
#include <iostream>

void OperatorControlPanel::submitAndExecute(ICommand* command)
{
    if(command == nullptr)
    {
        std::cout << "[Operator] ERROR: Cannot execute a null command." << std::endl;
        return;
    }

    if(command->execute())
    {
        history.push(command);
        std::cout << "[Operator] Command executed successfully."<< std::endl;
    }
    else
    {
        std::cout << "[Operator] Command failed. " << "It will not be added to history." << std::endl;
        delete command;
    }
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

        history.pop();
        return;
    }

    if(command->undo())
    {
        std::cout << "[Operator] Last command undone successfully." << std::endl;

        history.pop();
        delete command;
    }
    else
    {
        std::cout << "[Operator] Unable to undo the last command." << std::endl;
    }
}

OperatorControlPanel::~OperatorControlPanel()
{
    while(!history.empty())
    {
        ICommand* command = history.top();

        if(command != nullptr)
        {
            delete command;
        }

        history.pop();
    }
}
