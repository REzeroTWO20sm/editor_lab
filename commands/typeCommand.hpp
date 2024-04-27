#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class TypeCommand : public Command{
public:
    TypeCommand(Editor& editor,const char& letter);
    void execute() override;
    void undo() override;
    Command* clone() const override;
private:
    Editor& _currentEditor;
    char toAdd;
    std::string _prevBuffer;
    size_t _beforeCurrent;
};