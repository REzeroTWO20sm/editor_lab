#include "shiftleftCommand.hpp"

ShiftleftCommand::ShiftleftCommand(Editor &editor)
    : _currentEditor(editor)
    , _beforeCurrent{}
{}

void ShiftleftCommand::execute()
{
    _beforeCurrent = _currentEditor.get_pos();
    _currentEditor.shiftLeft();
}

void ShiftleftCommand::undo()
{
    _currentEditor.set_cursor(_beforeCurrent);
}

Command* ShiftleftCommand::clone() const
{
    return new ShiftleftCommand(*this);
}