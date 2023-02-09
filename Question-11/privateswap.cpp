#include <iostream>

class Class2;
class Class1
{
    int i;

public:
    Class1() {}
    Class1(int);
    friend void swap(Class1 &, Class2 &);
    int getValue(void);
};

class Class2
{
    int j;

public:
    Class2() {}
    Class2(int);
    friend void swap(Class1 &, Class2 &);
    int getValue(void);
};

Class1::Class1(int a)
{
    i = a;
}

void swap(Class1 &c1, Class2 &c2)
{
    c1.i += c2.j;
    c2.j = c1.i - c2.j;
    c1.i -= c2.j;
}

int Class1::getValue()
{
    return i;
}

Class2::Class2(int b)
{
    j = b;
}

int Class2::getValue()
{
    return j;
}

int main()
{
    Class1 c1;
    Class2 c2;
    bool continueLoop = true, assigned = false;
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice, value;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Enter values for both classes " << std::endl;
        std::cout << "2. Swap the values of both classes " << std::endl;
        std::cout << "3. Display the values of both classes " << std::endl;
        std::cout << "4. Exit " << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "Enter an integer value for class 1: ";
            std::cin >> value;
            c1 = Class1(value);
            std::cout << "Enter an integer value for class 2: ";
            std::cin >> value;
            c2 = Class2(value);
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                swap(c1, c2);
                std::cout << "Values of both classes swapped successfully." << std::endl;
            }
            else
            {
                std::cout << "Provide values to classes first!!" << std::endl;
            }
            break;
        case 3:
            if (assigned)
            {
                std::cout << "Value of class 1: " << c1.getValue() << std::endl;
                std::cout << "Value of class 2: " << c2.getValue() << std::endl;
            }
            else
            {
                std::cout << "Provide values to classes first!!" << std::endl;
            }
            break;
        case 4:
            std::cout << "Thank you for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice!" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}