#ifndef FT_SED_HPP
# define FT_SED_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <sys/stat.h>

class FtSed
{
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

public:
    FtSed(std::string filename, std::string s1, std::string s2);
    ~FtSed();
    
    bool replace();
};

#endif