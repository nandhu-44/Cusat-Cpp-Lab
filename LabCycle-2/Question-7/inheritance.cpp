#include <iostream>

class Alpha
{
    int a;

public:
    Alpha();
    Alpha(int);
    void showA();
};

class Beta 
{
    int b;

public:
    Beta();
    Beta(int);
    void showB();
};

class Gamma : public Alpha, public Beta
{
    int c;

public:
    Gamma();
    Gamma(int, int, int);
    void showC();
};

Alpha::Alpha()
{
    a = 0;
}

Alpha::Alpha(int a)
{
   this->a = a;
   std::cout << "Alpha has been assigned!" << std::endl;   
}

void Alpha::showA()
{
    std::cout << "a = " << a << std::endl;
}

Beta::Beta()
{
    b = 0;
}

Beta::Beta(int b)
{
    this->b = b;
    std::cout << "Beta has been assigned!" << std::endl;
}

void Beta::showB()
{
    std::cout << "b = " << b << std::endl;
}

Gamma::Gamma()
{
    c = 0;
}

Gamma::Gamma(int a, int b, int c) : Alpha(a), Beta(b)
{
    this->c = c;
    std::cout << "Gamma has been assigned!" << std::endl;
}

void Gamma::showC()
{
    std::cout << "c = " << c << std::endl;
}

int main()
{
    int a,b,c;
    Gamma g;
    std::cout << std::endl;
    bool continueLoop = true, assigned = false;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Assign values" << std::endl;
        std::cout << "2. Display values" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the integer value of a: ";
            std::cin >> a;
            std::cout << "Enter the integer value of b: ";
            std::cin >> b;
            std::cout << "Enter the integer value of c: ";
            std::cin >> c;
            std::cout << std::endl;
            g = Gamma(a, b, c);
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                g.showA();
                g.showB();
                g.showC();
            }
            else
            {
                std::cout << "Values not assigned yet!" << std::endl;
            }
            break;
        case 3:
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

