#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void non_empty_input(std::string *var, std::string message)
{
    do{
        std::cout << message;
        std::getline(std::cin , *var);
        std::cout << std::endl;
        if((*var).empty())
        {
            std::cout << "The programm does not accepts empty inputs, try again." << std::endl;
        }
    } while((*var).empty());
}

Contact handle_add()
{
    std::string fn;
    std::string ln;
    std::string nick;
    std::string phone_num;
    std::string dark_sec;

    std::cout << "please enter the following fields:" << std::endl;
    non_empty_input(&fn, "first name:");
    non_empty_input(&ln, "last name:");
    non_empty_input(&nick, "nickname:");
    non_empty_input(&phone_num, "phone number:");
    non_empty_input(&dark_sec, "darkest secret:");
    return (Contact(fn,ln,nick,phone_num, dark_sec));
}

int is_all_num(const std::string& str)
{
    for(size_t i = 0; i < str.size(); i++)
    {
        if(!std::isdigit(str[i]))
            return(0);
    }
    return (1);
}

void handle_search( PhoneBook& pb)
{
    std::string index;
    pb.display_contacts();
    do{
        std::cout << "Enter the index you want to search on (to exit enter q): ";
        std::getline(std::cin, index);
        if(std::cin.eof() || index == "q")
            break;
        if(pb.is_empty())
        {
            std::cout<< "empty phone book. exiting the search..." << std::endl;
            break;    
        }
        else if(!is_all_num(index))
            std::cout<< "Index must be a number (positive)" << std::endl;
        else if(index[0] > '7' || index[0] < '0' || index.size() > 1)
            std::cout<< "Wrong index: please enter a number between 0 and 7" << std::endl;
        else 
            pb.display_contact(index[0] - '0');
    }while(true);
}

int main()
{
    PhoneBook pb;
    std::string mode;
    std::cout << "_________________________________________________" << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to the crappy awesome phonebook software" << std::endl;
    std::cout << "In this progeamm you can add contacts and perform a search on them :D." << std::endl;
    std::cout << "_________________________________________________" << std::endl;
    std::cout << std::endl;
    std::cout << "The accepted commands are (ADD, SEARCH, and EXIT)" << std::endl;
    do{
        std::cout <<"$";
        std::getline(std::cin, mode);
        if(mode == "ADD")
        {
            pb.add_to_contacts(handle_add());
        }
        if(mode == "SEARCH")
        {
            handle_search(pb);
        }
        if(mode == "EXIT")
        {
            break;
        }
    }while(!std::cin.eof());
}