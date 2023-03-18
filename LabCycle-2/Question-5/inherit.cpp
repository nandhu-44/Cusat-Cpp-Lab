#include <iostream>

class Base1
{
    int x;

public:
    Base1()
    {
        x = 0;
    }
    Base1(int x)
    {
        this->x = x;
    }
    int getX()
    {
        return x;
    }
    void setX(int x)
    {
        this->x = x;
    }
};

class Base2
{
    int y;

public:
    Base2()
    {
        y = 0;
    }
    Base2(int y)
    {
        this->y = y;
    }
    int getY()
    {
        return y;
    }
    void setY(int y)
    {
        this->y = y;
    }
};

class MultipleInherited1 : virtual public Base1, virtual public Base2
{
    int i;

public:
    MultipleInherited1()
    {
        i = 0;
    }
    MultipleInherited1(int i)
    {
        this->i = i;
    }
    int getI()
    {
        return i;
    }
};

class MultipleInherited2 : virtual public Base1, virtual public Base2
{
    int j;

public:
    MultipleInherited2()
    {
        j = 0;
    }
    MultipleInherited2(int j)
    {
        this->j = j;
    }
    int getJ()
    {
        return j;
    }
};

class MultiLevelInherited1 : public MultipleInherited1
{
    int a;

public:
    MultiLevelInherited1(int p, int q = 0) : MultipleInherited1(q)
    {
        a = p;
    }
    int getA()
    {
        return a;
    }
};

class MultiLevelInherited2 : public MultipleInherited2
{
    int b;

public:
    MultiLevelInherited2(int q, int r = 0) : MultipleInherited2(r)
    {
        b = q;
    }
    int getB()
    {
        return b;
    }
};

class Derived : public MultiLevelInherited1, public MultiLevelInherited2
{
    int c;

public:
    Derived(int p, int q, int r, int s, int t) : MultiLevelInherited1(r, p), MultiLevelInherited2(s, q)
    {
        c = t;
    }
    int getC()
    {
        return c;
    }
};

std::string color(std::string text, std::string color = "white")
{
    std::string colors[] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};
    std::string colorCodes[] = {"30", "31", "32", "33", "34", "35", "36", "37"};
    std::string colorCode = "0";
    for (int i = 0; i < 8; i++)
    {
        if (color == colors[i])
        {
            colorCode = colorCodes[i];
            break;
        }
    }
    return "\033[1;" + colorCode + "m" + text + "\033[0m";
}

int main()
{
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        int x, y, i, j, a, b, c;
        std::cout << color("--------------------------------------------------", "yellow") << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Create multiple inheritance objects" << std::endl;
        std::cout << "2. Create multilevel inheritance objects" << std::endl;
        std::cout << "3. Create Hybrid(both) inheritance objects" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << color("--------------------------------------------------", "yellow") << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter the value of x (" + color("Class-Base1", "green") + ") : ";
            std::cin >> x;
            std::cout << "Enter the value of y (" + color("Class-Base2", "green") + ") : ";
            std::cin >> y;
            std::cout << "Enter the value of i (" + color("Class-MultipleInherited1", "red") + ") : ";
            std::cin >> i;
            std::cout << "Enter the value of j (" + color("Class-MultipleInherited2", "red") + ") : ";
            std::cin >> j;
            MultipleInherited1 obj1(i);
            MultipleInherited2 obj2(j);
            obj1.setX(x);
            obj2.setY(y);
            std::cout << std::endl;
            std::cout << color("--------------------------------------------------", "cyan") << std::endl;
            std::cout << std::endl;
            std::cout << "-----Multiple Inheritance-----" << std::endl;
            std::cout << "The value of x (" + color("Class-Base1", "green") + ") is : " << obj1.getX() << std::endl;
            std::cout << "The value of y (" + color("Class-Base2", "green") + ") is : " << obj2.getY() << std::endl;
            std::cout << "The value of i (" + color("Class-MultipleInherited1", "red") + ") is : " << obj1.getI() << std::endl;
            std::cout << "The value of j (" + color("Class-MultipleInherited2", "red") + ") is : " << obj2.getJ() << std::endl;
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Enter the value of i (" + color("Class-MultipleInherited1", "red") + ") : ";
            std::cin >> i;
            std::cout << "Enter the value of j (" + color("Class-MultipleInherited2", "red") + ") : ";
            std::cin >> j;
            std::cout << "Enter the value of a (" + color("Class-MultiLevelInherited1", "blue") + ") : ";
            std::cin >> a;
            std::cout << "Enter the value of b (" + color("Class-MultiLevelInherited2", "blue") + ") : ";
            std::cin >> b;
            MultiLevelInherited1 obj3(a, i);
            MultiLevelInherited2 obj4(b, j);
            std::cout << std::endl;
            std::cout << color("--------------------------------------------------", "cyan") << std::endl;
            std::cout << std::endl;
            std::cout << "-----Multi Level Inheritance-----" << std::endl;
            std::cout << "The value of i (" + color("Class-MultpleInherited1", "red") + ") is : " << obj3.getI() << std::endl;
            std::cout << "The value of j (" + color("Class-MultipleInherited2", "red") + ") is : " << obj4.getJ() << std::endl;
            std::cout << "The value of a (" + color("Class-MultiLevelInherited1", "blue") + ") is : " << obj3.getA() << std::endl;
            std::cout << "The value of b (" + color("Class-MultiLevelInherited2", "blue") + ") is : " << obj4.getB() << std::endl;
            std::cout << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Enter the value of x (" + color("Class-Base1", "green") + ") : ";
            std::cin >> x;
            std::cout << "Enter the value of y (" + color("Class-Base2", "green") + ") : ";
            std::cin >> y;
            std::cout << "Enter the value of i (" + color("Class-MultipleInherited1", "red") + ") : ";
            std::cin >> i;
            std::cout << "Enter the value of j (" + color("Class-MultipleInherited2", "red") + ") : ";
            std::cin >> j;
            std::cout << "Enter the value of a (" + color("Class-MultiLevelInherited1", "blue") + ") : ";
            std::cin >> a;
            std::cout << "Enter the value of b (" + color("Class-MultiLevelInherited2", "blue") + ") : ";
            std::cin >> b;
            std::cout << "Enter the value of c (" + color("Class-Derived", "magenta") + ") : ";
            std::cin >> c;
            Derived obj5(i, j, a, b, c);
            obj5.setX(x);
            obj5.setY(y);
            std::cout << std::endl;
            std::cout << color("--------------------------------------------------", "cyan") << std::endl;
            std::cout << std::endl;
            std::cout << "-----Hybrid Inheritance-----" << std::endl;
            std::cout << "The value of x (" + color("Class-Base1", "green") + ") is : " << obj5.getX() << std::endl;
            std::cout << "The value of y (" + color("Class-Base2", "green") + ") is : " << obj5.getY() << std::endl;
            std::cout << "The value of i (" + color("Class-MultipleInherited1", "red") + ") is : " << obj5.getI() << std::endl;
            std::cout << "The value of j (" + color("Class-MultipleInherited2", "red") + ") is : " << obj5.getJ() << std::endl;
            std::cout << "The value of a (" + color("Class-MultiLevelInherited1", "blue") + ") is : " << obj5.getA() << std::endl;
            std::cout << "The value of b (" + color("Class-MultiLevelInherited2", "blue") + ") is : " << obj5.getB() << std::endl;
            std::cout << "The value of c (" + color("Class-Derived", "magenta") + ") is : " << obj5.getC() << std::endl;
            std::cout << std::endl;
            break;
        }
        case 4:
            std::cout << "Thank you for using the program." << std::endl;
            std::cout << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice!" << std::endl;
            std::cout << std::endl;
            break;
        }
    }
    return 0;
}
