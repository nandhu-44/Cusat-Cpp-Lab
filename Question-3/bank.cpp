#include <iostream>
#include <string>

class Bank
{
private:
    static int count;
    std::string customer_name;
    std::string account_type;
    int account_no;
    float balance_amount;

public:
    void new_account(void);
    void deposit(float);
    void withdraw(float);
    void balance_enquiry(void);
    void account_statement(void);
    int get_count(void);
};

int Bank::count = 0;

void Bank::new_account()
{
    count++;
    std::string cust_name, acc_type;
    int acc_no;
    float balance;
    int error_count = 0;
    std::cout << std::endl;
    std::cout << "Enter the name of customer " << count << ": ";
    std::cin >> cust_name;
    customer_name = cust_name;
    std::cout << "Enter your account type (S for Savings, F for fixed deposit account): ";
    std::cin >> acc_type;
    while (acc_type != "S" && acc_type != "F")
    {
        if (error_count < 2)
        {
            std::cout << "Invalid account type" << std::endl;
            std::cout << "Enter your account type (S for Savings, F for fixed deposit account): ";
            std::cin >> acc_type;
            error_count++;
        }
        else
        {
            std::cout << "You have entered an invalid account type 3 times. Please try again later." << std::endl;
            exit(0);
        }
    }
    account_type = (acc_type == "S"  || acc_type == "s") ? "Savings" : "Fixed Deposit";
    std::cout << "Your account number is: " << count << std::endl;
    account_no = count;
    std::cout << "Enter the amount of money you want to deposit (Min is ₹500) : ";
    std::cin >> balance;
    while (balance < 500)
    {
        if (error_count < 2)
        {
            std::cout << "You need to deposit at least ₹500" << std::endl;
            std::cout << "Enter the amount of money you want to deposit : ";
            std::cin >> balance;
            error_count++;
        }
        else
        {
            std::cout << "You have entered an invalid amount 3 times. Please try again later." << std::endl;
            exit(0);
        }
    }
    balance_amount = balance;
    std::cout << "Your account has been created successfully." << std::endl;
}

void Bank::deposit(float amount)
{
    balance_amount += amount;
}

void Bank::withdraw(float amount)
{
    if (balance_amount < amount)
    {
        std::cout << "You don't have enough money in your account." << std::endl;
    }
    else if (amount < 500)
    {
        std::cout << "You need to withdraw at least ₹500" << std::endl;
    }
    else if (balance_amount - amount < 500)
    {
        std::cout << "You can't withdraw this amount. You need to keep at least ₹500 in your account." << std::endl;
    }
    else
    {
        balance_amount -= amount;
    }
}

void Bank::balance_enquiry()
{
    std::cout << "Your balance is ₹" << balance_amount << std::endl;
}

void Bank::account_statement()
{
    std::cout << std::endl;
    std::cout << "Account Statement" << std::endl;
    std::cout << "Customer Name: " << customer_name << std::endl;
    std::cout << "Account Type: " << account_type << std::endl;
    std::cout << "Account Number: " << account_no << std::endl;
    std::cout << "Balance Amount: ₹" << balance_amount << std::endl;
}

int Bank::get_count()
{
    return count;
}

int main()
{
    int n;
    std::cout << "Enter the number of customers: ";
    std::cin >> n;
    Bank b[n];
    for (int i = 0; i < n; i++)
    {
        b[i].new_account();
    }
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        std::cout << std::endl;
        std::cout << "_____Main Menu_____ " << std::endl;
        std::cout << "1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Balance Enquiry" << std::endl;
        std::cout << "4. Account Statement" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        int acc_no;
        float amount;
        switch (choice)
        {
        case 1:
            std::cout << "Enter your account number: ";
            std::cin >> acc_no;
            if (acc_no > n || acc_no < 1)
            {
                std::cout << "Invalid account number" << std::endl;
                break;
            }
            else
            {
                std::cout << "Enter the amount you want to deposit: ";
                std::cin >> amount;
                b[acc_no - 1].deposit(amount);
                break;
            }
        case 2:
            std::cout << "Enter your account number: ";
            std::cin >> acc_no;
            if (acc_no > n || acc_no < 1)
            {
                std::cout << "Invalid account number" << std::endl;
                break;
            }
            else
            {
                std::cout << "Enter the amount you want to withdraw: ";
                std::cin >> amount;
                b[acc_no - 1].withdraw(amount);
                break;
            }
        case 3:
            std::cout << "Enter your account number: ";
            std::cin >> acc_no;
            if (acc_no > n || acc_no < 1)
            {
                std::cout << "Invalid account number" << std::endl;
                break;
            }
            else
            {
                b[acc_no - 1].balance_enquiry();
                break;
            }
        case 4:
            std::cout << "Enter your account number: ";
            std::cin >> acc_no;
            if (acc_no > n || acc_no < 1)
            {
                std::cout << "Invalid account number" << std::endl;
                break;
            }
            else
            {
                b[acc_no - 1].account_statement();
                break;
            }
        case 5:
            std::cout << "Thank you for using our services." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}