#include "ft_sed.hpp"

FtSed::FtSed(std::string filename, std::string s1, std::string s2)
    : _filename(filename), _s1(s1), _s2(s2)
{
}

FtSed::~FtSed()
{
}

bool FtSed::replace()
{
    // try to openn
    std::ifstream inFile(_filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: Cannot open file " << _filename << std::endl;
        return false;
    }

    // creat the outputt
    std::ofstream outFile((_filename + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Cannot create output file" << std::endl;
        inFile.close();
        return false;
    }

    // Readinggg
    std::string content;
    std::string line;
    while (std::getline(inFile, line))
    {
        content += line;
        if (!inFile.eof())
            content += "\n";
    }

    if (!_s1.empty())
    {
        size_t pos = 0;
        while ((pos = content.find(_s1, pos)) != std::string::npos)
        {
            content = content.substr(0, pos) + _s2 + content.substr(pos + _s1.length());
            pos += _s2.length();
        }
    }

    // Writng to outputt fle
    outFile << content;

    inFile.close();
    outFile.close();

    return true;
}