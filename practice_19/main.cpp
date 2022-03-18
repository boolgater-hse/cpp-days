#include <iostream>
#include <filesystem>
#include <fstream>

class AccessDeniedException : public std::exception
{
};

class IOError : public std::exception
{
};

bool have_write_permissions(const std::string& path)
{
    FILE* fp = fopen(path.c_str(), "w");
    if (fp == nullptr)
    {
        if (errno == EACCES)
        {
            return false;
        }
    }
    return true;
}

bool file_exists(const std::string& path)
{
    std::fstream file;
    file.open(path, std::fstream::in);

    return file.is_open();
}

bool is_path_valid(const std::string& path)
{
    std::filesystem::path temp(path);

    return is_regular_file(temp) || is_directory(temp);
}

void append_to_file(const std::string& path, const std::string& str_to_append)
{
    if (!is_path_valid(path))
    {
        throw std::invalid_argument("Path is not valid");
    }
    if (!file_exists(path))
    {
        throw std::invalid_argument("File does not exist");
    }
    if (!have_write_permissions(path))
    {
        throw AccessDeniedException();
    }
    bool io_failed = false;

    std::ofstream out;
    out.open(path);
    out << str_to_append;
    if (!out)
    {
        io_failed = true;
    }

    if (io_failed)
    {
        throw IOError();
    }
}

int main()
{
    append_to_file("./tt/b.txt", "bay");
    return 0;
}
