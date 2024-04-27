#pragma once

#include <vector>
#include "../commands/command.hpp"
#include "../editor/editor.hpp"

class Invoker{
public:
    Invoker(Editor& editor);

    void on_button_one();
    void on_button_two();
    void on_button_three();
    void on_button_four();

    void button_one_listener(Command* command);
    void button_two_listener(Command* command);
    void button_three_listener(Command* command);
    void button_four_listener(Command* command);

    void undo();
    void redo();

    std::string getText() const;
    size_t getPos() const;

private:
    void onNewCommand(Command* command);

private:
    Editor& _currentEditor;
    size_t _currentCommand;

    Command* button_1;
    Command* button_2;
    Command* button_3;
    Command* button_4;

    std::vector<Command*> commandHistroy;
};