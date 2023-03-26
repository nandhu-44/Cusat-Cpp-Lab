#include <iostream>

class Shape
{
protected:
    float area;

public:
    virtual void getData() = 0;
    virtual void displayArea() = 0;
};

class Square : public Shape
{
    int side;

public:
    void getData()
    {
        std::cout << "Enter the side of the square : ";
        std::cin >> side;
    }
    void displayArea()
    {
        std::cout << "Area of the square : " << side * side << std::endl;
    }
};

class Rectangle : public Shape
{
    int length;
    int breadth;

public:
    void getData()
    {
        std::cout << "Enter the length of the rectangle : ";
        std::cin >> length;
        std::cout << "Enter the breadth of the rectangle : ";
        std::cin >> breadth;
    }
    void displayArea()
    {
        std::cout << "Area of the rectangle : " << length * breadth << std::endl;
    }
};

class Circle : public Shape
{
    int radius;

public:
    void getData()
    {
        std::cout << "Enter the radius of the circle : ";
        std::cin >> radius;
    }
    void displayArea()
    {
        std::cout << "Area of the circle : " << 3.14 * radius * radius << std::endl;
    }
};

class Ellipse : public Shape
{
    int majorAxis;
    int minorAxis;

public:
    void getData()
    {
        std::cout << "Enter the length of major axis of the ellipse : ";
        std::cin >> majorAxis;
        std::cout << "Enter the length of minor axis of the ellipse : ";
        std::cin >> minorAxis;
    }
    void displayArea()
    {
        std::cout << "Area of the ellipse : " << 3.14 * majorAxis * minorAxis << std::endl;
    }
};

int main()
{
    Shape *s;
    bool continueLoop = true;
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu----" << std::endl;
        std::cout << "1. Find area of Square" << std::endl;
        std::cout << "2. Find area of Rectangle" << std::endl;
        std::cout << "3. Find area of Circle" << std::endl;
        std::cout << "4. Find area of Ellipse" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            s = new Square;
            s->getData();
            s->displayArea();
            break;
        case 2:
            s = new Rectangle;
            s->getData();
            s->displayArea();
            break;
        case 3:
            s = new Circle;
            s->getData();
            s->displayArea();
            break;
        case 4:
            s = new Ellipse;
            s->getData();
            s->displayArea();
            break;
        case 5:
            std::cout << "Thank you for the using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice!" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
}
