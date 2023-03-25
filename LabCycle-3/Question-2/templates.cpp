#include <iostream>

template <typename T>
class Calculator
{
private:
    T num1, num2;

public:
    Calculator()
    {
        num1 = 0;
        num2 = 0;
    }

    Calculator(T n1, T n2)
    {
        num1 = n1;
        num2 = n2;
    }

    T add()
    {
        return num1 + num2;
    }

    T subtract()
    {
        return num1 - num2;
    }

    T multiply()
    {
        return num1 * num2;
    }

    T divide()
    {
        if (num2 == 0)
        {
            return 0;
        }
        return num1 / num2;
    }
};

int main()
{
    Calculator<float> calc;
    bool continueLoop = true, assigned = false;
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu----" << std::endl;
        std::cout << "1. Assign values" << std::endl;
        std::cout << "2. Add" << std::endl;
        std::cout << "3. Subtract" << std::endl;
        std::cout << "4. Multiply" << std::endl;
        std::cout << "5. Divide" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            float n[2];
            for (int i = 0; i < 2; i++)
            {
                std::cout << "Enter number " << i + 1 << " : ";
                std::cin >> n[i];
            }
            calc = Calculator<float>(n[0], n[1]);
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                std::cout << "Sum : " << calc.add() << std::endl;
            }
            else
            {
                std::cout << "Values have not been assigned!" << std::endl;
            }
            break;
        case 3:
            if (assigned)
            {
                std::cout << "Difference : " << calc.subtract() << std::endl;
            }
            else
            {
                std::cout << "Values have not been assigned!" << std::endl;
            }
            break;
        case 4:
            if (assigned)
            {
                std::cout << "Product : " << calc.multiply() << std::endl;
            }
            else
            {
                std::cout << "Values have not been assigned!" << std::endl;
            }
            break;
        case 5:
            if (assigned)
            {
                if (calc.divide() != 0)
                {
                    std::cout << "Quotient : " << calc.divide() << std::endl;
                }
                else
                {
                    std::cout << "Division by zero is not possible!" << std::endl;
                }
            }
            else
            {
                std::cout << "Values have not been assigned!" << std::endl;
            }
            break;
        case 6:
            std::cout << "Thank you for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice!" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
}
