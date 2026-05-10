#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}

Contact::Contact(
    std::string& first_name,
    std::string& last_name,
    std::string& nickname,
    std::string& phone_number,
    std::string& darkest_secet
): 
_first_name(first_name), 
_last_name(last_name), 
_nickname(nickname), 
_phone_number(phone_number), 
_darkest_secet(darkest_secet)
{
}

Contact::~Contact()
{
}

std::string Contact::get_first_name()
{
    return this->_first_name;
}
std::string Contact::get_last_name()
{
    return this->_last_name;
}
std::string Contact::get_nickname()
{
    return this->_nickname;
}
std::string Contact::get_phone_number()
{
    return this->_phone_number;
}
std::string Contact::get_darkest_secet()
{
    return this->_darkest_secet;
}
