#include <string>
#include <filesystem>
#include "Commands.h"
#include "../ErrorHandling/Err.h"

command_struct command_list[] = {
    {"cwd", GET_CWD},
    {"cd", CHANGE_DIRECTORY},
    {"ls", LOOK_DIRECTORY},
    {"mkdir", MAKE_DIRECTORY},
    {"rmdir", REMOVE_DIRECTORY},
    {"help", HELP},
};

int parseCommand(char* __arg) {
    for (int i = 0; i < (sizeof(command_list) / sizeof(command_struct)); i++) {
        std::string arg(__arg);
        if (arg.compare(command_list[i].name) == 0)
            return i;
    }
    return -1;
}

std::filesystem::path parsePath(int& choice, int& __arg1, char* __arg2[]) {
    try {
        if (__arg1 < 3 && choice == MAKE_DIRECTORY) throw NO_PATH_MKDIR_ERROR;
        if (__arg1 < 3) throw NO_PATH_CWD;
        return __arg2[2];
    }
    catch (const error_t& e) {
        printError("Omission", e);
        if (e == NO_PATH_MKDIR_ERROR) return "tempDir";
        return ".";
    }
}