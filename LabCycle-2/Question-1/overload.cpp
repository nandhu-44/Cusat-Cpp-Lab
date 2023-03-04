#include <iostream>
#include <cmath>
#include <iomanip>

class Vector
{
    float i;
    float j;
    float k;
    float magnitude;

public:
    Vector();
    Vector(float, float, float);
    bool operator==(Vector);
    bool operator!=(Vector);
    bool operator<(Vector);
    bool operator>(Vector);
    bool operator<=(Vector);
    bool operator>=(Vector);
};

Vector::Vector()

{
    i = 0;
    j = 0;
    k = 0;
    magnitude = 0;
}

Vector::Vector(float i, float j, float k)
{
    this->i = i;
    this->j = j;
    this->k = k;
    magnitude = sqrt(i * i + j * j + k * k);
}

bool Vector::operator==(Vector v)
{
    return i == v.i && j == v.j && k == v.k;
}

bool Vector::operator!=(Vector v)
{
    return i != v.i || j != v.j || k != v.k;
}

bool Vector::operator<(Vector v)
{
    return magnitude < v.magnitude;
}

bool Vector::operator>(Vector v)
{
    return magnitude > v.magnitude;
}

bool Vector::operator<=(Vector v)
{
    return magnitude <= v.magnitude;
}

bool Vector::operator>=(Vector v)
{
    return magnitude >= v.magnitude;
}

int main()
{
    Vector v[2];
    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        float a, b, c;
        std::cout << "-----Vector " << i + 1 << "-----" << std::endl;
        std::cout << "Enter i component : ";
        std::cin >> a;
        std::cout << "Enter j component : ";
        std::cin >> b;
        std::cout << "Enter k component : ";
        std::cin >> c;
        v[i] = Vector(a, b, c);
        std::cout << std::endl;
    }
    std::cout << std::boolalpha;
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std ::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Check == Operator" << std::endl;
        std::cout << "2. Check != Operator" << std::endl;
        std::cout << "3. Check < Operator" << std::endl;
        std::cout << "4. Check > Operator" << std::endl;
        std::cout << "5. Check <= Operator" << std::endl;
        std::cout << "6. Check >= Operator" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "v1 == v2 : " << (v[0] == v[1]) << std::endl;
            break;
        case 2:
            std::cout << "v1 != v2 : " << (v[0] != v[1]) << std::endl;
            break;
        case 3:
            std::cout << "v1 < v2 : " << (v[0] < v[1]) << std::endl;
            break;
        case 4:
            std::cout << "v1 > v2 : " << (v[0] > v[1]) << std::endl;
            break;
        case 5:
            std::cout << "v1 <= v2 : " << (v[0] <= v[1]) << std::endl;
            break;
        case 6:
            std::cout << "v1 >= v2 : " << (v[0] >= v[1]) << std::endl;
            break;
        case 7:
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