#include <iostream>
#include <string>
#include <cstdlib>

class Student
{
private:
    std::string name;
    int rollNo;
    int marksCpp;
    int marksPython;
    int marksJava;

public:
    void input(void);
    void calcGrade(int, int, int);
    void display(void);
};
int checkRange(int);

void Student::input(void)
{
    std::string name_;
    int rollNo_, marksCpp_, marksPython_, marksJava_;
    std::cout << "Enter the name of the student: ";
    std::cin >> name_;
    name = name_;
    std::cout << "Enter the roll no of the student: ";
    std::cin >> rollNo_;
    rollNo = rollNo_;
    std::cout << "Enter the marks in C++ out of 100: ";
    std::cin >> marksCpp_;
    marksCpp = checkRange(marksCpp_);
    std::cout << "Enter the marks in Python out of 100: ";
    std::cin >> marksPython_;
    marksPython = checkRange(marksPython_);
    std::cout << "Enter the marks in Java out of 100: ";
    std::cin >> marksJava_;
    marksJava = checkRange(marksJava_);
}

int checkRange(int marks)
{
    int errorCount = 0;
    while (errorCount < 5)
    {
        if (marks < 0 || marks > 100)
        {
            std::cout << "Enter the marks in the range of 0 to 100: ";
            std::cin >> marks;
            errorCount++;
        }
        else
        {
            return marks;
        }
    }
    std::cout << "You have entered the marks in the wrong range for 5 times. Please try again later." << std::endl;
    exit(1);
}

void Student::calcGrade(int a, int b, int c)
{
    int total = a + b + c;
    float percentage = total / 3;
    if (percentage >= 90)
    {
        std::cout << "The grade of the student is A" << std::endl;
    }
    else if (percentage >= 80)
    {
        std::cout << "The grade of the student is B" << std::endl;
    }
    else if (percentage >= 70)
    {
        std::cout << "The grade of the student is C" << std::endl;
    }
    else if (percentage >= 60)
    {
        std::cout << "The grade of the student is D" << std::endl;
    }
    else if (percentage >= 40)
    {
        std::cout << "The grade of the student is E" << std::endl;
    }
    else
    {
        std::cout << "The grade of the student is F" << std::endl;
    }
}

void Student::display(void)
{
    std::cout << std::endl;
    std::cout << "The name of student is " << name << std::endl;
    std::cout << "The roll number of the student is " << rollNo << std::endl;
    std::cout << "The marks in C++ is " << marksCpp << std::endl;
    std::cout << "The marks in Python is " << marksPython << std::endl;
    std::cout << "The marks in Java is " << marksJava << std::endl;
    calcGrade(marksCpp, marksPython, marksJava);
    std::cout << std::endl;
}

int main()
{
    int studentCount;
    std::cout << "Enter the number of students: ";
    std::cin >> studentCount;
    std::cout << std::endl;
    Student student[studentCount];
    for (int i = 0; i < studentCount; i++)
    {
        std::cout << "Enter the details of student " << i + 1 << std::endl;
        student[i].input();
        std::cout << std::endl;
    }
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std::cout << "_____Main Menu_____ " << std::endl;
        std::cout << "1. Display the details of all the students" << std::endl;
        std::cout << "2. Display the details of a particular student" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < studentCount; i++)
            {
                student[i].display();
            }
            break;
        case 2:
            int studentNo;
            std::cout << "Enter the student number: ";
            std::cin >> studentNo;
            std::cout << std::endl;
            if (studentNo < 1 || studentNo > studentCount)
            {
                std::cout << "Enter the correct student number!" << std::endl;
                break;
            }
            student[studentNo - 1].display();
            break;
        case 3:
            std::cout << std::endl;
            std::cout << "Thank You for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Please provide a valid choice!" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
}
