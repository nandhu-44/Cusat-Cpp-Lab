#include <iostream>

class Vector
{
    int i, j, k;

public:
    Vector();
    Vector(int, int, int);
    friend int operator*(Vector &, Vector &);
    friend std::istream &operator>>(std::istream &, Vector &);
    friend std::ostream &operator<<(std::ostream &, Vector &);
};

Vector::Vector()
{
    i = 0;
    j = 0;
    k = 0;
}

Vector::Vector(int a, int b, int c)
{
    i = a;
    j = b;
    k = c;
}

int operator*(Vector &v1, Vector &v2)
{
    return v1.i * v2.i + v1.j * v2.j + v1.k * v2.k;
}

std::istream &operator>>(std::istream &input, Vector &v)
{
    std::cout << "Enter the value of i: ";
    std::cin >> v.i;
    std::cout << "Enter the value of j: ";
    std::cin >> v.j;
    std::cout << "Enter the value of k: ";
    std::cin >> v.k;
    return input;
}

std::ostream &operator<<(std::ostream &output, Vector &v)
{
    std::string outputStr;
    outputStr = std::to_string(v.i) + "i ";
    outputStr += (v.j >= 0 ? "+ " : "- ") + std::to_string(std::abs(v.j)) + "j ";
    outputStr += (v.k >= 0 ? "+ " : "- ") + std::to_string(std::abs(v.k)) + "k";
    output << outputStr;
    return output;
}

int main()
{
    Vector v1, v2;
    bool continueLoop = true, assigned = false;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Enter the values of the vectors" << std::endl;
        std::cout << "2. Display the vectors" << std::endl;
        std::cout << "3. Display the dot product" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "-----Vector 1-----" << std::endl;
            std::cin >> v1;
            std::cout << "-----Vector 2-----" << std::endl;
            std::cin >> v2;
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                std::cout << "Vector 1 : " << v1 << std::endl;
                std::cout << "Vector 2 : " << v2 << std::endl;
            }
            else
            {
                std::cout << "The vectors have not been assigned any values!" << std::endl;
            }
            break;
        case 3:
            if (assigned)
            {
                std::cout << "The dot product of the vectors is: " << v1 * v2 << std::endl;
            }
            else
            {
                std::cout << "The vectors have not been assigned any values!" << std::endl;
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