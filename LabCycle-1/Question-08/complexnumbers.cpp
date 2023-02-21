#include <iostream>

class Complex
{
    int real, imag;

public:
    Complex() {}
    Complex(int i);
    Complex(int r, int i);
    Complex operator+(Complex &c2);
    void setData(void);
    void display(void);
};

Complex::Complex(int i)
{
    real = i;
    imag = i;
}

Complex::Complex(int r, int i)
{
    real = r;
    imag = i;
}

Complex Complex::operator+(Complex &c2)
{
    Complex c3;
    c3.real = real + c2.real;
    c3.imag = imag + c2.imag;
    return c3;
}

void Complex::setData(void)
{
    std::cout << "Enter real part: ";
    std::cin >> real;
    std::cout << "Enter imaginary part: ";
    std::cin >> imag;
}

void Complex::display(void)
{
    const std::string sign = imag > 0 ? " + " : " - ";
    if (imag == 0)
    {
        std::cout << real << std::endl;
    }
    else if (imag == 1)
    {
        std::cout << real << sign << "i" << std::endl;
    }
    else
    {
        std::cout << real << sign << std::abs(imag) << "i" << std::endl;
    }
}

int main()
{
    int m, n;
    Complex c1, c2;
    Complex c3;
    bool continueLoop = true, assigned = false;
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Enter complex numbers" << std::endl;
        std::cout << "2. Add complex numbers" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "-----Complex Number 1-----" << std::endl;
            c1.setData();
            std::cout << std::endl;
            std::cout << "-----Complex Number 2-----" << std::endl;
            c2.setData();
            assigned = true;
            break;
        case 2:
            if (!assigned)
            {
                std::cout << "Please enter the complex numbers first." << std::endl;
                break;
            }
            c3 = c1 + c2;
            std::cout << "The sum of the complex numbers is : ";
            c3.display();
            std::cout << std::endl;
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