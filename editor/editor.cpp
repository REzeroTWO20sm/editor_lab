#include "editor.hpp"

Editor::Editor() : _buffer{}, _pos{}
{}

void Editor::type(const char &letter){
    _buffer.insert(_buffer.begin()+ _pos, letter);
    ++_pos;
}

void Editor::backspace(){
    if(_pos != 0){
        _buffer.erase(_buffer.begin()+(--_pos));
    }
}

std::string Editor::get_text() const{
    return _buffer;
}

void Editor::shiftLeft(){
    if(_pos == 0){
        _pos = _pos;
    }
    else{
        --_pos;
    }
}

void Editor::shiftRight(){
    if(_pos == _buffer.size()){
        _pos = _pos;
    }
    else{
        ++_pos;
    }
}

size_t Editor::get_pos() const
{
    return _pos;
}

void Editor::set_text(const std::string& str){
    _buffer = str;
    if(_pos > str.size()){
        _pos = str.size();
    }
}

void Editor::set_cursor(size_t size){
    if(size > _buffer.size()){
        _pos = _buffer.size();
    }
    else{
        _pos = size;
    }
}