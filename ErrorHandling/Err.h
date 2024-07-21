#pragma once

typedef enum {
    USAGE_ERROR,
    CMD_ERROR,
    NO_PATH_MKDIR_ERROR,
    NO_PATH_CWD,
    DIR_NOT_EXISTANT,
    NOT_DIR_ERROR,
    DIR_EXISTS_ERROR,
    INVALID_DIR_NAME_ERROR,
    MKDIR_FAILED,
    UNKNOWN
    // Additional error codes to be added
}error_t;

void printError(std::string label, error_t __e);
// Prints all the relevant errors in accordance with their error codes

void print_help(void);
// Prints the help menu