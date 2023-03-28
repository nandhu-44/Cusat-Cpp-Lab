#include <iostream>
#include <cstdlib>
#include <ctime>

class AbstractBase
{
    static int objects;

public:
    AbstractBase()
    {
        objects++;
    }
    static int getObjects()
    {
        return objects;
    }
};

int AbstractBase::objects = 0;

class SubBase : virtual public AbstractBase
{
    float area;

public:
    virtual void getData() = 0;
    virtual void displayArea() = 0;
};

class Square : public SubBase
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

class Rectangle : public SubBase
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

int generateRandomNumber()
{
    srand(time(0));
    return rand() % 10 + 1;
}

int main()
{
    int randomNumber = generateRandomNumber();
    SubBase *s;
    SubBase *obj[randomNumber];
    for (int i = 0; i < randomNumber; i++)
    {
        obj[i] = new Square;
    }
    bool continueLoop = true;
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Calculate the no of objects created" << std::endl;
        std::cout << "2. Calculate the area of a square" << std::endl;
        std::cout << "3. Calculate the area of a rectangle" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "No of objects created : " << AbstractBase::getObjects() << std::endl;
            break;
        case 2:
            s = new Square;
            s->getData();
            s->displayArea();
            break;
        case 3:
            s = new Rectangle;
            s->getData();
            s->displayArea();
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
