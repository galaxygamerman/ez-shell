#pragma once

void getCWD(void);
void chDir(const std::filesystem::path& path);
void lsDir(const std::filesystem::path& path);
void mkDir(const std::filesystem::path& path);
bool rmDir(const std::filesystem::path& path);
void print_help(void);