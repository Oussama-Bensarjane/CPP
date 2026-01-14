#include "ft_sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./ft_sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    FtSed sed(argv[1], argv[2], argv[3]);
    if (!sed.replace())
        return 1;

    return 0;
}