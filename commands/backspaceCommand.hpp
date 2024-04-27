#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class BackspaceCommand : public Command{
public:
    BackspaceCommand(Editor& editor);
    void execute() override;
    void undo() override;
    Command* clone() const override;
private:
    Editor& _currentEditor;
    std::string _prevBuffer;
    size_t _beforeCurrent;
};