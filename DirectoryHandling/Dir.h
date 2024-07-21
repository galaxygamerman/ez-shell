#pragma once

void getCWD(void);
// Outputs the current working directory into the terminal

void chDir(const std::filesystem::path& path);
// Changes the current working directory to the given path

void lsDir(const std::filesystem::path& path);
// Outputs the contents of the given directory to the terminal

void mkDir(const std::filesystem::path& path);
// Creates a directory in the given path

bool rmDir(const std::filesystem::path& path);
// Removes the directory in the given path
