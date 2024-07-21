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

extern command_struct command_list[];
// Global list with list of all commands

int parseCommand(char* __arg);
// Reads commandline arguments to select the appropriate command

std::filesystem::path parsePath(int& choice, int& __arg1, char* __arg2[]);
// Reads commandline arguments to return path for selected command