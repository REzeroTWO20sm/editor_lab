#include <iostream>

#include "invoker.hpp"
#include "../commands/emptyCommand.hpp"

Invoker::Invoker(Editor& editor) 
    : _currentEditor(editor)
    , _currentCommand{}
    , button_1(new EmptyCommand)
    , button_2(new EmptyCommand)
    , button_3(new EmptyCommand)
    , button_4(new EmptyCommand)
    , commandHistroy{}
{}

void Invoker::onNewCommand(Command* command){
    if(_currentCommand == commandHistroy.size()){
        command->execute();
    }
    else{
        commandHistroy.erase(commandHistroy.begin()+_currentCommand, commandHistroy.end());
        command->execute();
    }
    _currentCommand++;
    commandHistroy.push_back(command->clone());
}

void Invoker::on_button_one()
{
    onNewCommand(button_1);
}

void Invoker::on_button_two()
{
    onNewCommand(button_2);
}

void Invoker::on_button_three()
{
   onNewCommand(button_3);
}

void Invoker::on_button_four()
{
    onNewCommand(button_4);
}

void Invoker::button_one_listener(Command* command)
{
    button_1 = command;
}

void Invoker::button_two_listener(Command* command)
{
    button_2 = command;
}

void Invoker::button_three_listener(Command* command)
{
    button_3 = command;
}

void Invoker::button_four_listener(Command* command)
{
    button_4 = command;
}

void Invoker::undo()
{
    if(_currentCommand != 0){
        commandHistroy[--_currentCommand]->undo();
    }
}

void Invoker::redo()
{
    if(_currentCommand != commandHistroy.size()){
        commandHistroy[_currentCommand]->execute();
        _currentCommand++;
    }
}

std::string Invoker::getText() const {
    return _currentEditor.get_text();
}

size_t Invoker::getPos() const
{
    return _currentEditor.get_pos();
}