#pragma once

#include <string>

class Editor{
public:
    Editor();

    void type(const char& letter);
    void backspace();
    void shiftLeft();
    void shiftRight();

    std::string get_text() const;
    size_t get_pos() const;

    void set_text(const std::string& string);
    void set_cursor(size_t pos);
    
private:
    std::string _buffer;
    size_t _pos;
};