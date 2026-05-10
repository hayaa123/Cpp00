#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    public:
        Contact();
        Contact(
            std::string& first_name,
            std::string& last_name,
            std::string& nickname,
            std::string& phone_number,
            std::string& darkest_secet
        );
        ~Contact();
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secet();

    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secet;
};

#endif