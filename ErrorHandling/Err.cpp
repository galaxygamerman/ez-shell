#include <iostream>
#include <string>
#include "Err.h"

void printError(std::string label, error_t __e) {
    std::cerr << label << ": " << __e << std::endl;
    // Additional plans exist to add an if-else structure under here
}