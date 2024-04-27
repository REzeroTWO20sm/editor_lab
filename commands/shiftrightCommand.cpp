#include "shiftrightCommand.hpp"

ShiftrightCommand::ShiftrightCommand(Editor &editor)
    : _currentEditor(editor)
    , _beforeCurrent{}
{}

void ShiftrightCommand::execute()
{
    _beforeCurrent = _currentEditor.get_pos();
    _currentEditor.shiftRight();
}

void ShiftrightCommand::undo()
{
    _currentEditor.set_cursor(_beforeCurrent);
}

Command* ShiftrightCommand::clone() const
{
    return new ShiftrightCommand(*this);
}