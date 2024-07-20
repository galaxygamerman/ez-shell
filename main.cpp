#include <iostream>
#include <string>
#include "DirectoryHandling/Dir.h"
#include "ErrorHandling/Err.h"

enum command {
    CHANGE_DIRECTORY = 0,
    LOOK_DIRECTORY = 1,
    MAKE_DIRECTORY = 2,
    REMOVE_DIRECTORY = 3,
    HELP = 4,
};
typedef struct {
    std::string name;
    enum command cmd;
} command_struct;

int main(int argc, char** argv) {
    if (argc < 2) {
        printError("Usage Error", USAGE_ERROR);
        return 1;
    }

    command_struct command_list[] = {
        {"cd", CHANGE_DIRECTORY},
        {"ls", LOOK_DIRECTORY},
        {"mkdir", MAKE_DIRECTORY},
        {"rmdir", REMOVE_DIRECTORY},
        {"help", HELP},
    };

    int choice;
    for (int i = 0; i < (sizeof(command_list) / sizeof(command_struct)); i++) {
        std::string arg(argv[1]);
        if (arg.compare(command_list[i].name) == 0)
            choice = i;
    }

    switch (choice) {
    case CHANGE_DIRECTORY:
        chDir();
        break;
    case LOOK_DIRECTORY:
        lsDir();
        break;
    case MAKE_DIRECTORY:
        mkDir();
        break;
    case REMOVE_DIRECTORY:
        rmDir();
        break;
    case HELP:
        print_help();
        break;
    default:
        printError("Invalid arguments", ARG_ERROR);
        return 1;
    }

    return 0;
}