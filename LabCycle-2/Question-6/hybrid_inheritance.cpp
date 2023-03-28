#include <iostream>

class Student
{
protected:
    int rollNumber;

public:
    void getNumber(int);
    void putNumber(void);
};

class Test : virtual public Student
{
protected:
    float mark1, mark2;

public:
    void getMarks(float, float);
    void putMarks(void);
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void getScore(float);
    void putScore(void);
};

class Result : public Test, public Sports
{
private:
    float total;

public:
    void display(void);
};

void Student::getNumber(int a)
{
    rollNumber = a;
}

void Student::putNumber(void)
{
    std::cout << "Roll Number = " << rollNumber << std::endl;
}

void Test::getMarks(float x, float y)
{
    mark1 = x;
    mark2 = y;
}

void Test::putMarks(void)
{
    std::cout << "Mark1 = " << mark1 << std::endl;
    std::cout << "Mark2 = " << mark2 << std::endl;
}

void Sports::getScore(float s)
{
    score = s;
}

void Sports::putScore(void)
{
    std::cout << "Score = " << score << std::endl;
}

void Result::display(void)
{
    total = mark1 + mark2 + score;
    putNumber();
    putMarks();
    putScore();
    std::cout << "Total Score = " << total << std::endl;
}

int main()
{
    Result r1;
    bool continueLoop = true, assigned = false;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Enter Details" << std::endl;
        std::cout << "2. Display Details" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            int rollNumber;
            float mark1, mark2, score;
            std::cout << "Enter Roll Number: ";
            std::cin >> rollNumber;
            std::cout << "Enter Mark 1: ";
            std::cin >> mark1;
            std::cout << "Enter Mark 2: ";
            std::cin >> mark2;
            std::cout << "Enter Score: ";
            std::cin >> score;
            r1.getNumber(rollNumber);
            r1.getMarks(mark1, mark2);
            r1.getScore(score);
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                r1.display();
            }
            else
            {
                std::cout << "Please enter the details first!" << std::endl;
            }
            break;
        case 3:
            std::cout << "Thank you for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice." << std::endl;
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}
