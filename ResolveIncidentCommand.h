#ifndef RESOLVEINCIDENTCOMMAND_H
#define RESOLVEINCIDENTCOMMAND_H

#include "ICommand.h"

class IncidentContext;

class ResolveIncidentCommand : public ICommand
{
    private:
        IncidentContext* incident;
        bool executed;

    public:
        explicit ResolveIncidentCommand(IncidentContext* incident);

        void execute() override;
        void undo() override;

        ~ResolveIncidentCommand() override = default;
};

#endif /* RESOLVEINCIDENTCOMMAND_H */
