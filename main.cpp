#include <iostream>
#include <string>
#include <filesystem>
#include "DirectoryHandling/Dir.h"
#include "ErrorHandling/Err.h"
#include "Commands/Commands.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printError("Usage Error", USAGE_ERROR);
        return 1;
    }
    int choice = parseCommand(argv[1]);

    std::filesystem::path path;
    if (choice != -1) {
        path = parsePath(choice, argc, argv);
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