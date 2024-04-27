#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class ShiftrightCommand : public Command{
public:
    ShiftrightCommand(Editor& editor);
    void execute() override;
    void undo() override;
    Command* clone() const override;
private:
    Editor& _currentEditor;
    size_t _beforeCurrent;
};