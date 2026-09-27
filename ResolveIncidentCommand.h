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

        virtual bool execute() override;
        virtual bool undo() override;

        ~ResolveIncidentCommand() override = default;
};

#endif /* RESOLVEINCIDENTCOMMAND_H */
