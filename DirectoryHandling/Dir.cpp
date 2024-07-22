#include <iostream>
#include <filesystem>
#include "Dir.h"
#include "../ErrorHandling/Err.h"

void getCWD(void) {
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
}
void chDir(const std::filesystem::path& path) {
    std::filesystem::current_path(path);
    std::cout << "Switched to: " << std::filesystem::current_path() << std::endl;
}
void lsDir(const std::filesystem::path& path) {
    if (!std::filesystem::exists(path)) {
        printError("lsDir", DIR_NOT_EXISTANT);
        return;
    }

    if (!std::filesystem::is_directory(path)) {
        printError("lsDir", NOT_DIR_ERROR);
        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::cout << entry.path().filename().string();
        if (std::filesystem::is_directory(entry.status())) {
            std::cout << "/";
        }
        std::cout << std::endl;
    }
}
void mkDir(const std::filesystem::path& path) {
    if (std::filesystem::exists(path)) {
        printError("mkdir", DIR_EXISTS_ERROR);
        return;
    }

    if (path.filename().string().empty()) {
        printError("mkdir", INVALID_DIR_NAME_ERROR);
        return;
    }

    try {
        std::filesystem::create_directory(path);
    }
    catch (const std::filesystem::filesystem_error& e) {
        printError("mkdir", MKDIR_FAILED);
        return;
    }

    std::cout << "Directory created successfully: " << path.string() << std::endl;
}
bool rmDir(const std::filesystem::path& path) {
    if (!std::filesystem::exists(path)) {
        printError("rmdir", DIR_NOT_EXISTANT);
        return false;
    }

    if (!std::filesystem::is_directory(path)) {
        printError("rmdir", NOT_DIR_ERROR);
        return false;
    }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (std::filesystem::is_directory(entry.status())) {
            if (!rmDir(entry.path())) {
                return false;
            }
        } else {
            if (!std::filesystem::remove(entry.path())) {
                printError("rmdir", RMDIR_ITEM_FAILED);
                return false;
            }
        }
    }

    if (!std::filesystem::remove(path)) {
        printError("rmdir", MKDIR_FAILED);
        return false;
    }

    std::cout << "Directory deleted successfully: " << path.string() << std::endl;
    return true;
}