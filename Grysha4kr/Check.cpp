#include "Check.h"

int GetPositiveInt()
{

    while (true) {
        int value;
        try {
            if (std::cin >> value, std::cin.good() && value > 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
        catch (std::invalid_argument& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl;
        }
    }
}
std::string CheckLineS(std::ifstream& file)
{
    std::string temp_v = "";
    try
    {
        std::getline(file, temp_v);
        return temp_v;

    }
    catch (const std::exception&)
    {
        
        throw MyExcept();

    }
}
int GetChoise()
{

    while (true) {
        try {

            int value = 0;
            std::cin >> value;
            if (value == 1 || value == 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
       
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }
}
