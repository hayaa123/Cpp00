#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}

Contact::Contact(
    const std::string& first_name,
    const std::string& last_name,
    const std::string& nickname,
    const std::string& phone_number,
    const std::string& darkest_secret
): 
_first_name(first_name), 
_last_name(last_name), 
_nickname(nickname), 
_phone_number(phone_number), 
_darkest_secret(darkest_secret)
{
}

Contact::~Contact()
{
}

std::string Contact::get_first_name() const
{
    return this->_first_name;
}
std::string Contact::get_last_name() const
{
    return this->_last_name;
}
std::string Contact::get_nickname() const
{
    return this->_nickname;
}
std::string Contact::get_phone_number() const
{
    return this->_phone_number;
}
std::string Contact::get_darkest_secret() const
{
    return this->_darkest_secret;
}
