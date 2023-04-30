#include <iostream>

class Student
{
protected:
    int rollNumber;

public:
    void setNumber(int);
    int getNumber(void);
};

class Test : public Student
{
protected:
    int marks1, marks2;

public:
    void setMarks(int, int);
    int getMarks1(void);
    int getMarks2(void);
};

class Arts
{
protected:
    int artsMark;

public:
    void setArtsMark(int);
    int getArtsMark(void);
};

class Result : public Test, public Arts
{
    int total;

public:
    void setTotal(int);
    void display(void);
};

void Student ::setNumber(int r)
{
    rollNumber = r;
}

int Student ::getNumber(void)
{
    return rollNumber;
}

void Test ::setMarks(int m1, int m2)
{
    marks1 = m1;
    marks2 = m2;
}

int Test ::getMarks1(void)
{
    return marks1;
}

int Test ::getMarks2(void)
{
    return marks2;
}

void Arts ::setArtsMark(int m)
{
    artsMark = m;
}

int Arts ::getArtsMark(void)
{
    return artsMark;
}

void Result ::setTotal(int t)
{
    total = t;
}

void Result ::display(void)
{
    std::cout << "Roll Number: " << getNumber() << std::endl;
    std::cout << "Marks 1: " << getMarks1() << std::endl;
    std::cout << "Marks 2: " << getMarks2() << std::endl;
    std::cout << "Arts Marks: " << getArtsMark() << std::endl;
    std::cout << "Total Marks: " << total << std::endl;
}

int main()
{
    bool continueLoop = true, assigned = false;
    Result result;
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
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
            int rollNumber, marks1, marks2, artsMark;
            std::cout << "Enter Roll Number: ";
            std::cin >> rollNumber;
            std::cout << "Enter Marks 1: ";
            std::cin >> marks1;
            std::cout << "Enter Marks 2: ";
            std::cin >> marks2;
            std::cout << "Enter Arts Marks: ";
            std::cin >> artsMark;
            result.setNumber(rollNumber);
            result.setMarks(marks1, marks2);
            result.setArtsMark(artsMark);
            result.setTotal(marks1 + marks2 + artsMark);
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                result.display();
            }
            else
            {
                std::cout << "Please enter details first!" << std::endl;
            }
            break;
        case 3:
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