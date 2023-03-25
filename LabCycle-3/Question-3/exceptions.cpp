#include <iostream>

float getQuotient(float num1, float num2)
{
    if (num2 == 0)
    {
        throw "Division by zero is not possible!";
    }
    return num1 / num2;
}

int main()
{
    float num[2];
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> num[i];
    }
    try
    {
        float quotient = getQuotient(num[0], num[1]);
        std::cout << "Quotient: " << quotient << std::endl;
    }
    catch (const char *msg)
    {
        std::cerr << msg << std::endl;
    }
}