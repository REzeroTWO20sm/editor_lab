#include "backspaceCommand.hpp"

BackspaceCommand::BackspaceCommand(Editor &editor)
    : _currentEditor(editor)
    , _prevBuffer{}
    , _beforeCurrent{}
{}

void BackspaceCommand::execute()
{
    _prevBuffer = _currentEditor.get_text();
    _beforeCurrent = _currentEditor.get_pos();
    _currentEditor.backspace();
}

void BackspaceCommand::undo()
{
    _currentEditor.set_text(_prevBuffer);
    _currentEditor.set_cursor(_beforeCurrent);
}

Command* BackspaceCommand::clone() const
{
    return new BackspaceCommand(*this);
}