#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void add_to_contacts(const Contact& contact);
        void display_contacts(void);
        int is_empty(void);
        void display_contact(int index);
    private:
        Contact _contacts[8];
        int _size;
        int _index;
};
#endif