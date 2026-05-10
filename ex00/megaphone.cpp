#include <iostream>
#include <string>
#include <cctype>

int main (int argc, char *argv[])
{
    int i;
    std::string output;

    i = 1;
    output = "";
    if(argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        while(argv[i])
        {
            output = output + argv[i];
            i++;
        }
        for (size_t j = 0; j < output.size(); j++)
            output[j] = std::toupper(output[j]);
        std::cout << output << std::endl;
    }
    return (0);
}