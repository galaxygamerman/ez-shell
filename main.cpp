#include <iostream>
#include <string>
#include <filesystem>
#include "DirectoryHandling/Dir.h"
#include "ErrorHandling/Err.h"
#include "Commands.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printError("Usage Error", USAGE_ERROR);
        return 1;
    }

    command_struct command_list[] = {
        {"cwd", GET_CWD},
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

    std::filesystem::path path;
    try {
        if (argc < 3 && choice == MAKE_DIRECTORY) throw NO_PATH_MKDIR_ERROR;
        if (argc < 3) throw NO_PATH_CWD;
        path = argv[2];
    }
    catch (const error_t& e) {
        printError("Omission", e);
        if (choice == MAKE_DIRECTORY) return 1;
        path = ".";
    }
    switch (choice) {
    case GET_CWD:
        getCWD();
        break;
    case CHANGE_DIRECTORY:
        chDir(path);
        break;
    case LOOK_DIRECTORY:
        lsDir(path);
        break;
    case MAKE_DIRECTORY:
        mkDir(path);
        break;
    case REMOVE_DIRECTORY:
        rmDir(path);
        break;
    case HELP:
        print_help();
        break;
    default:
        printError("Invalid command", CMD_ERROR);
        return 1;
    }
    return 0;
}