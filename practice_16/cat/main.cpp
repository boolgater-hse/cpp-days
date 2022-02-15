#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

size_t lineCounter = 1;
bool showEnds = false;
bool showTabs = false;
bool showNumberNonemptyLines = false;
bool showNumberAllLines = false;
bool showNotation = false;
bool suppressLine = false;
std::vector <std::string> files;

void applyFlags(std::string& buffer)
{
    for (long long i = buffer.size() - 1; i >= 0; --i)
    {
        if (showEnds)
        {
            if (buffer[i] == '\n')
            {
                buffer.insert(buffer.begin() + i, '$');
                continue;
            }
        }
        if (showTabs)
        {
            if (buffer[i] == '\t')
            {
                buffer[i] = '^';
                buffer.insert(buffer.begin() + i + 1, 'I');
                continue;
            }
        }
        if (showNotation)
        {
            if (buffer[i] == '\r')
            {
                buffer[i] = '^';
                buffer.insert(buffer.begin() + i + 1, 'M');
                continue;
            }
        }
    }

    if (showNumberAllLines || showNumberNonemptyLines)
    {
        std::stringstream ss;
        for (size_t i = 0; i < buffer.size(); ++i)
        {
            ss << std::setw(6) << lineCounter++ << "  ";
            buffer.insert(i, std::string(ss.str()));
            ss.str(std::string());
            while (i < buffer.size() && buffer[i] != '\n')
            {
                i++;
            }
        }
    }

    if (suppressLine)
    {
        for (size_t i = 0; i < buffer.size(); ++i)
        {
            if (buffer[i] == '\n')
            {
                i += 2;
                while (i < buffer.size() && buffer[i] == '\n')
                {
                    buffer.erase(buffer.begin() + i);
                }
            }
        }
    }
}

void infiniteInput()
{
    while (true)
    {
        std::string buffer;
        getline(std::cin, buffer);
        buffer += '\n';

        applyFlags(buffer);

        std::cout << buffer;
    }
}

int main(int argc, char* argv[])
{
    std::string helpText = "Usage: cat [OPTION]... [FILE]...\n"
                           "Concatenate FILE(s) to standard output.\n"
                           "\n"
                           "With no FILE, or when FILE is -, read standard input.\n"
                           "\n"
                           "  -A, --show-all           equivalent to -vET\n"
                           "  -b, --number-nonblank    number nonempty output lines, overrides -n\n"
                           "  -e                       equivalent to -vE\n"
                           "  -E, --show-ends          display $ at end of each line\n"
                           "  -n, --number             number all output lines\n"
                           "  -s, --squeeze-blank      suppress repeated empty (\\n only) output lines\n"
                           "  -t                       equivalent to -vT\n"
                           "  -T, --show-tabs          display TAB characters as ^I\n"
                           "  -u                       (ignored)\n"
                           "  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\n"
                           "      --help     display this help and exit\n"
                           "      --version  output version information and exit\n"
                           "\n"
                           "Examples:\n"
                           "  cat f - g  Output f's contents, then standard input, then g's contents.\n"
                           "  cat        Copy standard input to standard output.";

    std::string versionText = "cat 0.01\n"
                              "What do you want to find here? Good code solutions?\n";

    std::vector <std::string> args;
    for (int i = 0; i < argc; ++i)
    {
        args.push_back(argv[i]);
    }

    for (int i = 1; i < argc; ++i)
    {
        if (args[i][0] == '-')
        {
            if (args[i].size() == 1)
            {
                files.push_back(args[i]);
                continue;
            }

            bool status = false;

            if (args[i][1] == '-')
            {
                if (args[i] == "--help")
                {
                    std::cout << helpText;
                    return 0;
                }
                if (args[i] == "--version")
                {
                    std::cout << versionText;
                    return 0;
                }
                if (args[i] == "--show-all")
                {
                    showNotation = true;
                    showEnds = true;
                    showTabs = true;

                    status = true;
                }
                if (args[i] == "--number-nonblank")
                {
                    if (showNumberAllLines)
                    {
                        showNumberAllLines = false;
                    }
                    showNumberNonemptyLines = true;

                    status = true;
                }
                if (args[i] == "--show-ends")
                {
                    showEnds = true;

                    status = true;
                }
                if (args[i] == "--number")
                {
                    showNumberAllLines = true;

                    status = true;
                }
                if (args[i] == "--squeeze-blank")
                {
                    suppressLine = true;

                    status = true;
                }
                if (args[i] == "--show-tabs")
                {
                    showTabs = true;

                    status = true;
                }
                if (args[i] == "--show-nonprinting")
                {
                    showNotation = true;

                    status = true;
                }
                if (!status)
                {
                    std::cout << "cat: unknown option -- " << args[i].substr(2) << '\n' <<
                              "Try 'cat --help' or get out of my swamp\n";

                    return 0;
                }
            }
            else
            {
                for (char j : args[i])
                {
                    switch (j)
                    {
                        case '-':
                            continue;
                        case 'A':
                            showNotation = true;
                            showEnds = true;
                            showTabs = true;
                            break;
                        case 'b':
                            if (showNumberAllLines)
                            {
                                showNumberAllLines = false;
                            }
                            showNumberNonemptyLines = true;
                            break;
                        case 'e':
                            showNotation = true;
                            showEnds = true;
                            break;
                        case 'E':
                            showEnds = true;
                            break;
                        case 'n':
                            showNumberAllLines = true;
                            break;
                        case 's':
                            suppressLine = true;
                            break;
                        case 't':
                            showNotation = true;
                            showTabs = true;
                            break;
                        case 'T':
                            showTabs = true;
                            break;
                        case 'u':
                            // why
                            break;
                        case 'v':
                            showNotation = true;
                        default:
                            std::cout << "cat: unknown option -- " << j << '\n' <<
                                      "Try 'cat --help' or get out of my swamp\n";

                            return 0;
                    }
                }
            }
        }
        else
        {
            files.push_back(args[i]);
        }
    }

    if (files.empty())
    {
        infiniteInput();
    }
    else
    {
        for (const std::string& i: files)
        {
            if (i == "-")
            {
                infiniteInput();
            }

            std::fstream file;
            file.open(i, std::fstream::in);
            if (!file.is_open())
            {
                std::cout << "cat: No such file\n";
                continue;
            }

            std::string buffer;
            std::getline(file, buffer, '\0');

            applyFlags(buffer);

            std::cout << buffer;

            file.close();
        }
    }

    return 0;
}
