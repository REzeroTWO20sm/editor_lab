#include "typeCommand.hpp"

TypeCommand::TypeCommand(Editor &editor,const char& letter)
    : _currentEditor(editor)
    , toAdd(letter)
    , _prevBuffer{}
    , _beforeCurrent{}
{}

void TypeCommand::execute()
{
    _prevBuffer = _currentEditor.get_text();
    _beforeCurrent = _currentEditor.get_pos();
    _currentEditor.type(toAdd);
}

void TypeCommand::undo()
{
    _currentEditor.set_text(_prevBuffer);
    _currentEditor.set_cursor(_beforeCurrent);
}

Command* TypeCommand::clone() const
{
    return new TypeCommand(*this);
}