#ifndef ICOMMAND_H
#define ICOMMAND_H

class ICommand
{
    public:
        virtual bool execute() = 0;
        virtual bool undo() = 0;
        virtual ~ICommand() = default;
};

#endif /*ICOMMAND_H*/