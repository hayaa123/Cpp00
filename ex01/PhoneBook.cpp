#include <string>
#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>


PhoneBook::PhoneBook()
{
    this->_index = 0;
    this->_size = 0;
}

PhoneBook::~PhoneBook()
{
}

static std::string format_field(const std::string& field)
{
    if(field.size() > 10)
    {
        return (field.substr(0, 9) + ".");
    }
    return (field);
}

void PhoneBook::add_to_contacts(const Contact& contact)
{
    if(this->_index == 8)
        this->_index = 0;
    this->_contacts[this->_index] = contact;
    this->_index +=1;
    if(this->_size < 8)
        this->_size +=1;
}

static void print_head(std::string col1, std::string col2, std::string col3, std::string col4)
{
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col1 << "|";
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col2 << "|";
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col3 << "|";
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col4 << std::endl;
}

static void print_row(int col1, std::string col2, std::string col3, std::string col4)
{
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col1 << "|";
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col2 << "|";
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col3 << "|";
    std::cout << std::setw(10)<< std::setfill(' ');
    std::cout << col4 << std::endl;
}

void PhoneBook::display_contacts(void)
{
    
    print_head("Index", "First name", "Last name", "Nickname");
    for(int i = 0; i < this->_size ; i++)
    {
        print_row(i,
                format_field(this->_contacts[i].get_first_name()),
                format_field(this->_contacts[i].get_last_name()),
                format_field(this->_contacts[i].get_nickname())
            );
    }
}
int PhoneBook::is_empty(void)
{
    return (this->_size == 0);
}

void PhoneBook::display_contact(int index)
{
    if(index >= this->_size)
    {
        std::cout<< "There is no contact informations at this index yet" << std::endl;
        return;
    }
    std::cout << this->_contacts[index].get_first_name() << std::endl;
    std::cout << this->_contacts[index].get_last_name() << std::endl;
    std::cout << this->_contacts[index].get_nickname() << std::endl;
    std::cout << this->_contacts[index].get_phone_number() << std::endl;
    std::cout << this->_contacts[index].get_darkest_secret() << std::endl;
}