#include <iostream>
#include <cstring>

class Strings
{
private:
    char *str;
    int len;

public:
    Strings();
    Strings(const char *s);
    void display();
    void getData(const char *s);
    void concatenate(const Strings &s1, const Strings &s2);
    bool compare(const Strings &s2) const;
    int getLength();
    ~Strings();
};

Strings::Strings()
{
    len = 0;
    str = new char[len + 1];
}

Strings::Strings(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}

void Strings::display()
{
    std::cout << str;
}

void Strings::getData(const char *s)
{
    len = strlen(s);
    delete str;
    str = new char[len + 1];
    strcpy(str, s);
}

void Strings::concatenate(const Strings &s1, const Strings &s2)
{
    len = s1.len + s2.len;
    delete str;
    int i = s2.str[0] == ' ' ? 1 : 2;
    str = new char[len + i];
    strcpy(str, s1.str);
    if (i > 1)
        strcat(str, " ");
    strcat(str, s2.str);
}

bool Strings::compare(const Strings &s2) const
{
    return strcmp(str, s2.str) == 0;
}

int Strings::getLength()
{
    return len;
}

Strings::~Strings()
{
    delete str;
}

int main()
{
    Strings s1, s2, s3;
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std::cout << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Concatenate" << std::endl;
        std::cout << "2. Compare" << std::endl;
        std::cout << "3. Get Length" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
        {
            char str1[50];
            char str2[50];
            std::cout << "Enter string 1: ";
            std::cin >> str1;
            s1.getData(str1);
            std::cout << std::endl;
            std::cout << "Enter string 2: ";
            std::cin >> str2;
            s2.getData(str2);
            std::cout << std::endl;
            s3.concatenate(s1, s2);
            std::cout << "Concatenated string: ";
            s3.display();
            std::cout << std::endl;
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            char str1[50];
            char str2[50];
            std::cout << "Enter string 1: ";
            std::cin >> str1;
            s1.getData(str1);
            std::cout << "Enter string 2: ";
            std::cin >> str2;
            s2.getData(str2);
            if (s1.compare(s2))
            {
                std::cout << "Strings are equal." << std::endl;
            }
            else
            {
                std::cout << "Strings are not equal." << std::endl;
            }
            std::cout << std::endl;
            break;
        }
        case 3:
        {
            char str1[50];
            std::cout << "Enter string: ";
            std::cin >> str1;
            s1.getData(str1);
            int length = s1.getLength();
            std::cout << "Length of string: " << length << std::endl;
            std::cout << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Thank you for using the program." << std::endl;
            std::cout << std::endl;
            continueLoop = false;
            break;
        }
        default:
        {
            std::cout << "Please provide a valid choice!" << std::endl;
            std::cout << std::endl;
            break;
        }
        }
    }
    return 0;
}
