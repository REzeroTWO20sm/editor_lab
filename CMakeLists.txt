cmake_minimum_required(VERSION 3.20)
project(commandPattern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMMANDS
    commands/command.hpp
    commands/backspaceCommand.hpp commands/backspaceCommand.cpp
    commands/shiftleftCommand.hpp commands/shiftleftCommand.cpp
    commands/shiftrightCommand.hpp commands/shiftrightCommand.cpp
    commands/typeCommand.hpp commands/typeCommand.cpp
    commands/emptyCommand.hpp commands/emptyCommand.cpp
)

set(EDITOR editor/editor.hpp editor/editor.cpp)

set(INVOKER invoker/invoker.hpp invoker/invoker.cpp)

add_executable(${PROJECT_NAME} main.cpp ${COMMANDS} ${EDITOR} ${INVOKER})