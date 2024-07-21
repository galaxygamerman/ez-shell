#include <iostream>
#include <string>
#include "Err.h"

void printError(std::string label, error_t __e) {
    std::cerr << label << ": " << __e << std::endl;
    // Additional plans exist to add an if-else structure under here
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