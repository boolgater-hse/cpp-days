#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

size_t lineCounter = 1;
bool showEnds = false;
bool showTabs = false;
bool showNumberNonemptyLines = false;
bool showNumberAllLines = false;
bool showNotation = false;
bool suppressLine = false;

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
    std::string buffer;
    while (getline(std::cin, buffer))
    {
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

    std::string versionText = "cat 0.02\n"
                              "Update: now we are using Boost\n";

    po::options_description desc("Generic options");
    desc.add_options()
            ("help", "equivalent to -vET")
            ("version", "output version information and exit")
            ("show-all,A", "equivalent to -vET")
            ("number-nonblank,b", "number nonempty output lines, overrides -n")
            (",e", "equivalent to -vE")
            ("show-ends,E", "display $ at end of each line")
            ("number,n", "number all output lines")
            ("squeeze-blank,s", "suppress repeated empty (\\n only) output lines")
            (",t", "equivalent to -vT")
            ("show-tabs,T", "display TAB characters as ^I")
            (",u", "(ignored)")
            ("show-nonprinting,v", "use ^ and M- notation, except for LFD and TAB");

    po::parsed_options parsed = po::command_line_parser(argc, argv).options(desc).allow_unregistered().run();
    std::vector <po::basic_option <char>> items = parsed.options;
    for (auto& item: items)
    {
        if (item.unregistered)
        {
            if (item.string_key[0] == '-')
            {
                std::cout << "cat: unknown option -- " << item.string_key.substr(1) << '\n' <<
                          "Try 'cat --help' or get out of my swamp\n";

                return 0;
            }
            else
            {
                std::cout << "cat: unknown option -- " << item.original_tokens.at(0).substr(2) << '\n' <<
                          "Try 'cat --help' or get out of my swamp\n";

                return 0;
            }
        }
    }

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        std::cout << helpText;
        return 0;
    }
    if (vm.count("version"))
    {
        std::cout << versionText;
        return 0;
    }
    if (vm.count("show-all"))
    {
        showNotation = true;
        showEnds = true;
        showTabs = true;
    }
    if (vm.count("number-nonblank"))
    {
        if (showNumberAllLines)
        {
            showNumberAllLines = false;
        }
        showNumberNonemptyLines = true;
    }
    if (vm.count("show-ends"))
    {
        showEnds = true;
    }
    if (vm.count("number"))
    {
        showNumberAllLines = true;
    }
    if (vm.count("squeeze-blank"))
    {
        suppressLine = true;
    }
    if (vm.count("show-tabs"))
    {
        showTabs = true;
    }
    if (vm.count("show-nonprinting"))
    {
        showNotation = true;
    }

    for (auto& item: items)
    {
        if (item.string_key.empty())
        {
            if (item.original_tokens.at(0) == "-")
            {
                infiniteInput();
            }
            else
            {
                std::fstream file;
                file.open(item.original_tokens.at(0), std::fstream::in);
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
    }

    return 0;
}
