#pragma once
#include <string>

enum command {
    GET_CWD = 0,
    CHANGE_DIRECTORY = 1,
    LOOK_DIRECTORY = 2,
    MAKE_DIRECTORY = 3,
    REMOVE_DIRECTORY = 4,
    HELP = 5,
};
typedef struct {
    std::string name;
    enum command cmd;
} command_struct;
