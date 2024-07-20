#pragma once

typedef enum {
    USAGE_ERROR,
    ARG_ERROR,
    // Additional error codes to be added
}error_t;

void printError(std::string label, error_t __e);