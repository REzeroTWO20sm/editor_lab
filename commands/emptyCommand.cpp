#include "emptyCommand.hpp"

#include <iostream>

EmptyCommand::EmptyCommand(){}

void EmptyCommand::execute(){
    std::cout << "Empty execute command" << std::endl;
}

void EmptyCommand::undo(){
    std::cout <<  "Empty undo command" << std::endl;
}

Command* EmptyCommand::clone() const{
    return new EmptyCommand(*this);
}