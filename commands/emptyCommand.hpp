#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class EmptyCommand : public Command{
public:
    EmptyCommand();
    void execute() override;
    void undo() override;
    Command* clone() const override;
};