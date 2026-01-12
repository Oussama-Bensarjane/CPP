#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
    std::string type;

public:
    std::string& getType(std::string type) const;
    std::string setType(std::string &type);


    Weapon();
    ~Weapon();
};



#endif