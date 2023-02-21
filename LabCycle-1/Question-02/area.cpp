#include <iostream>
#include <cmath>

int area(int side)
{
    return side * side;
}

int area(int length, int breadth)
{
    return length * breadth;
}

float area(float radius)
{
    return 3.14 * radius * radius;
}

float area(int side1, int side2, int side3)
{
    float s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

float area(float base1, float base2, float height)
{
    return ((base1 + base2) / 2) * height;
}
bool checkValidTriangle(int side1, int side2, int side3)
{
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std::cout << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Area of Square" << std::endl;
        std::cout << "2. Area of Rectangle" << std::endl;
        std::cout << "3. Area of Circle" << std::endl;
        std::cout << "4. Area of Triangle" << std::endl;
        std::cout << "5. Area of Trapezium" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        switch (choice)
        {
        case 1:
            int side;
            std::cout << std::endl;
            std::cout << "Enter the side of the square: ";
            std::cin >> side;
            std::cout << "The area of the square is " << area(side) << std::endl;
            break;
        case 2:
            int length, breadth;
            std::cout << std::endl;
            std::cout << "Enter the length of the rectangle: ";
            std::cin >> length;
            std::cout << "Enter the breadth of the rectangle: ";
            std::cin >> breadth;
            std::cout << "The area of the rectangle is " << area(length, breadth) << std::endl;
            break;
        case 3:
            float radius;
            std::cout << std::endl;
            std::cout << "Enter the radius of the circle: ";
            std::cin >> radius;
            std::cout << "The area of the circle is " << area(radius) << std::endl;
            break;
        case 4:
            int side1, side2, side3;
            float areaOfTriangle;
            bool isValid;
            std::cout << std::endl;
            std::cout << "Enter the first side of the triangle: ";
            std::cin >> side1;
            std::cout << "Enter the second side of the triangle: ";
            std::cin >> side2;
            std::cout << "Enter the third side of the triangle: ";
            std::cin >> side3;
            areaOfTriangle = area(side1, side2, side3);
            isValid = checkValidTriangle(side1, side2, side3) && areaOfTriangle > 0;
            isValid ? std::cout << "The area of the triangle is " << areaOfTriangle << std::endl : std::cout << "The triangle is not valid!" << std::endl;
            break;
        case 5:
            float base1, base2, height;
            std::cout << std::endl;
            std::cout << "Enter the first base of the trapezium: ";
            std::cin >> base1;
            std::cout << "Enter the second base of the trapezium: ";
            std::cin >> base2;
            std::cout << "Enter the height of the trapezium: ";
            std::cin >> height;
            std::cout << "The area of the trapezium is " << area(base1, base2, height) << std::endl;
            break;
        case 6:
            std::cout << std::endl;
            std::cout << "Thank you for using the program." << std::endl;
            std::cout << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << std::endl;
            std::cout << "Please provide a valid choice!" << std::endl;
            std::cout << std::endl;
            break;
        }
    }
    return 0;
}