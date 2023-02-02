#include <iostream>
#include <string>

class Strings
{
private:
    std::string str;

public:
    Strings()
    {
        str = "";
    }
    Strings(std::string s)
    {
        str = s;
        
    }
    void getData(std::string s)
    {
        str = s;
    }
    void print()
    {
        std::cout << str << std::endl;
    }
    friend Strings concatenate(Strings, Strings);
    friend void compare(Strings, Strings);
    void getLength()
    {
        std::cout << str.length() << std::endl;
    }
};

Strings concatenate(Strings s1, Strings s2)
{
    Strings s3;
    s3.str = s1.str + s2.str;
    return s3;
}

void compare(Strings s1, Strings s2)
{
    if (s1.str == s2.str)
    {
        std::cout << "The given two strings are equal." << std::endl;
    }
    else
    {
        std::cout << "The given two strings are not equal." << std::endl;
    }
}

int main()
{
    Strings s1, s2, s3;
    std::string str1, str2;
    std::cout << std::endl;
    std::cout << "Enter the first string: ";
    getline(std::cin, str1);
    s1.getData(str1);
    std::cout << std::endl;
    std::cout << "Enter the second string: ";
    getline(std::cin, str2);
    s2.getData(str2);
    std::cout << std::endl;
    s3 = concatenate(s1, s2);
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std::cout << "____Main Menu____" << std::endl;
        std::cout << "1. Compare the two strings" << std::endl;
        std::cout << "2. Print the concatenated string" << std::endl;
        std::cout << "3. Print the length of the strings" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
        case 1:
            compare(s1, s2);
            break;
        case 2:
            s3.print();
            break;
        case 3:
            std::cout << "Length of the first string: ";
            s1.getLength();
            std::cout << "Length of the second string: ";
            s2.getLength();
            break;
        case 4:
            std::cout << "Thank you for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        std::cout << std::endl;
    }
}