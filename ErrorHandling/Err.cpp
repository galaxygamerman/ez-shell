#include <iostream>
#include <string>
#include "Err.h"

void printError(std::string label, error_t __e) {
    std::cerr << label << ": ";
    switch (__e) {
    case USAGE_ERROR:
        std::cout << '\r';
        print_help();
        break;
    case CMD_ERROR:
        std::cout << "That is not a command";
        break;
    case NO_PATH_MKDIR_ERROR:
        std::cout << "Path was not specified. mkdir unsuccessful.";
        break;
    case NO_PATH_CWD:
        std::cout << "Path was not specified. Set to Current Working Directory.";
        break;
    case DIR_NOT_EXISTANT:
        std::cout << "Directory does not exist at specified path.";
        break;
    case NOT_DIR_ERROR:
        std::cout << "Specified path is not a directory.";
        break;
    case DIR_EXISTS_ERROR:
        std::cout << "Directory already exists at specified path.";
        break;
    case INVALID_DIR_NAME_ERROR:
        std::cout << "Invalid directory name. Directory name must follow rules of your OS.";
        break;
    case MKDIR_FAILED:
        std::cout << "Can't make directory. Check permissions.";
        break;
    case RMDIR_FAILED:
        std::cout << "Can't delete directory. Check permissions.";
        break;
    case RMDIR_ITEM_FAILED:
        std::cout << "Can't delete item in directory. Check permissions.";
        break;
    default:
        std::cout << "Something unexpected has happened."
            << "Please report this to the developer.";
    }
    std::cout << std::endl;
}
void print_help(void) {
    std::cout << "ez - Easy File System Tool\n\n"
        << "Usage : ez <command> [<path>]\n\n"
        << "Available commands :\n\n"
        << "cwd\t\tPrint the current working directory\n"
        << "cd\t\tChange the current working directory\n"
        << "ls\t\tList files and directories in the current working directory\n"
        << "mkdir\t\tCreate a new directory\n"
        << "rm\t\tRemove a file or directory\n"
        << "help\t\tDisplay this help message\n\n"
        << "Options :\n\n"
        << "<path>\t\tSpecify a path for the command(e.g.ez mkdir mydir)\n\n"
        << "Examples :\n\n"
        << "\tez cwd\t\t# Print the current working directory\n"
        << "\tez cd mydir\t# Change to the 'mydir' directory\n"
        << "\tez ls\t\t# List files and directories in the current directory\n"
        << "\tez mkdir mydir\t# Create a new directory named 'mydir'\n"
        << "\tez rm myfile\t# Remove the file 'myfile'\n"
        << "\tez rm mydir\t# Remove the directory 'mydir' and its contents\n"
        << "\tez help\t\t# Display this help message\n\n"
        << "\tNote : Use ez help <command> for more information about a specific command.\n";
}