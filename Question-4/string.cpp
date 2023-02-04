#include <iostream>
#include <cstring>

class Strings
{
private:
    char *str;
    int len;

public:
    Strings()
    {
        len = 0;
        str = new char[len + 1];
        // str[0] = '\0';
    }

    Strings(const char *s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    void display()
    {
        std::cout << str;
    }

    void getData(const char *s)
    {
        len = strlen(s);
        delete str;
        str = new char[len + 1];
        strcpy(str, s);
    }

    void concatenate(const Strings &s1, const Strings &s2)
    {
        // Strings
        len = s1.len + s2.len;
        delete str;
        str = new char[len + 1];
        strcpy(str, s1.str);
        strcat(str, s2.str);
        // return s3;
    }

    bool compare(const Strings &s2) const
    {
        return strcmp(str, s2.str) == 0;
    }

    int getLength() const
    {
        return len;
    }

    ~Strings()
    {
        delete str;
    }
};

int main()
{
    Strings s1, s2, s3;

    while (true)
    {
        int choice;
        std::cout << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "____Main Menu____" << std::endl;
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
            std::cout << "The contents of s1 >";
            s1.display();
            std::cout << std::endl;
            std::cout << "Enter string 2: ";
            std::cin >> str2;
            s2.getData(str2);
            std::cout << "The contents of s2 >";
            s2.display();
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
            exit(0);
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
