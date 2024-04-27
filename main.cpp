#include <iostream>

#include "invoker/invoker.hpp"
#include "commands/backspaceCommand.hpp"
#include "commands/shiftleftCommand.hpp"
#include "commands/shiftrightCommand.hpp"
#include "commands/typeCommand.hpp"
#include "editor/editor.hpp"

int main(){
    Editor editor;
    
    Invoker invoker(editor);
    
    invoker.button_one_listener(new TypeCommand(editor, 'b'));
    invoker.button_two_listener(new TypeCommand(editor, 'r'));
    invoker.button_three_listener(new BackspaceCommand(editor));
    invoker.button_four_listener(new ShiftleftCommand(editor));

    invoker.on_button_one();
    invoker.on_button_one();
    invoker.on_button_one();
    invoker.on_button_two();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rrro 4

    invoker.undo();
    invoker.undo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rr 2

    invoker.redo();
    invoker.redo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rrro 4


    invoker.on_button_three();
    invoker.on_button_three();
    invoker.on_button_three();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;// r 1

    invoker.undo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rr 2
    
    invoker.undo();
    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rrr 3

    invoker.on_button_four();
    invoker.on_button_four();
    invoker.on_button_four();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rrr 0

    invoker.undo();
    invoker.undo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rrr 2

    invoker.redo();
    
    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rrr 1

    invoker.redo();
    invoker.redo();
    invoker.redo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//rrr 0

    invoker.on_button_two();
    invoker.on_button_two();
    invoker.on_button_two();
    invoker.on_button_two();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//oooorrr 4

    invoker.undo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//ooorrr 3

    invoker.redo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//oooorrr 4

    invoker.button_three_listener(new TypeCommand(editor, 'o'));

    invoker.on_button_three();
    invoker.on_button_three();
    invoker.on_button_three();
    invoker.on_button_three();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//oooobbbbrrr 8

    invoker.undo();
    invoker.undo();
    invoker.undo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//oooobrrr 5

    invoker.redo();
    invoker.redo();
    invoker.redo();

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;//oooobbbbrrr 8

    invoker.button_three_listener(new BackspaceCommand(editor));
    invoker.button_four_listener(new ShiftrightCommand(editor));

    int txt_count = invoker.getText().length();
    for(int i=0; i<txt_count;i++){
        invoker.on_button_four();
        invoker.on_button_three();
    }
    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;

    invoker.button_one_listener(new TypeCommand(editor, 'z'));
    invoker.button_two_listener(new TypeCommand(editor, 'e'));
    invoker.button_three_listener(new TypeCommand(editor, 'r'));
    invoker.button_four_listener(new TypeCommand(editor, 'o'));

    for(int i=0;i<4;i++){
        invoker.on_button_one();
        invoker.on_button_two();
        invoker.on_button_three();
        invoker.on_button_four();
        invoker.button_four_listener(new TypeCommand(editor, ' '));
        invoker.on_button_four();
        invoker.button_four_listener(new TypeCommand(editor, 'o'));
    }

    std::cout <<  "Text and pos: " << invoker.getText() << ", " << invoker.getPos() << std::endl;
}