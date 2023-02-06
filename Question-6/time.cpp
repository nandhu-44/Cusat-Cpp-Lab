#include <iostream>

class Time
{
private:
    int hours, minutes, seconds;

public:
    Time();
    Time(int s);
    void setTime(int h, int m, int s);
    void printTime(void);
    friend Time operator+(const Time &t1, const Time &t2);
};

Time::Time()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(int s)
{
    hours = s / 3600;
    minutes = (s % 3600) / 60;
    seconds = (s % 3600) % 60;
}

void Time::setTime(int h, int m, int s)
{
    seconds = s;
    minutes = seconds / 60 + m;
    seconds = seconds % 60;
    hours = minutes / 60 + h;
    minutes = minutes % 60;
}

void Time::printTime(void)
{
    std::cout  << hours << "H " << minutes << "M " << seconds << "S " << std::endl;
}

Time operator+(const Time &t1, const Time &t2)
{
    Time t3;
    t3.seconds = t1.seconds + t2.seconds;
    t3.minutes = t3.seconds / 60 + t1.minutes + t2.minutes;
    t3.seconds = t3.seconds % 60;
    t3.hours = t3.minutes / 60 + t1.hours + t2.hours;
    t3.minutes = t3.minutes % 60;
    return t3;
}

int main()
{
    Time t1, t2, t3;
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std::cout << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Set Time (Time1 & Time2)" << std::endl;
        std::cout << "2. Add Time (Sum)" << std::endl;
        std::cout << "3. Show Time (All)" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            int h, m, s;
            std::cout << "-----Time 1-----" << std::endl;
            std::cout << "Enter hours: ";
            std::cin >> h;
            std::cout << "Enter minutes: ";
            std::cin >> m;
            std::cout << "Enter seconds: ";
            std::cin >> s;
            t1.setTime(h, m, s);
            std::cout << std::endl;
            std::cout << "-----Time 2-----" << std::endl;
            std::cout << "Enter hours: ";
            std::cin >> h;
            std::cout << "Enter minutes: ";
            std::cin >> m;
            std::cout << "Enter seconds: ";
            std::cin >> s;
            t2.setTime(h, m, s);
            break;
        case 2:
            t3 = t1 + t2;
            std::cout << "The sum of Time 1 and Time 2 is : ";
            t3.printTime();
            break;
        case 3:
            std::cout << "Time 1 is : ";
            t1.printTime();
            std::cout << "Time 2 is : ";
            t2.printTime();
            std::cout << "The sum is : ";
            t3.printTime();
            break;
        case 4:
            std ::cout << "Thank you for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice!" << std::endl;
        }
        std::cout << std::endl;
    }
}
