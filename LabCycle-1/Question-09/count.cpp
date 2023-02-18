#include <iostream>

class Test
{
    static int count;

public:
    Test();
    static void showcount(void);
};

int Test::count = 0;

Test::Test()
{
    count++;
}

void Test::showcount(void)
{
    std::cout << "The value of count is : " << count << std::endl;
}

int main()
{
    int a;
    bool continueLoop = true;
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Create new objects" << std::endl;
        std::cout << "2. Show Count" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        if (choice == 1)
        {
            int n;
            std::cout << "Enter the number of objects to create: ";
            std::cin >> n;
            Test obj[n];
            std::cout << n << " instances of the class created successfully." << std::endl;
        }
        else if (choice == 2)
        {
            Test::showcount();
        }
        else if (choice == 3)
        {
            std::cout << "Thank you for using the program." << std::endl;
            continueLoop = false;
        }
        else
        {
            std::cout << "Please provide a valid choice!" << std::endl;
        }

        std::cout << std::endl;
    }
    return 0;
}