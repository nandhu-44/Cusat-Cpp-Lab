#include <iostream>
#include <iomanip>

class Matrix
{
    int row, col;
    int **mat;

public:
    Matrix();
    Matrix(int, int);
    void getMatrix();
    void displayMatrix();
    int operator+(const Matrix &);
    int operator*(const Matrix &);
    ~Matrix();
};

Matrix::Matrix()
{
    row = 0;
    col = 0;
    mat = NULL;
}

Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    mat = new int *[row];
    for (int i = 0; i < row; i++)
    {
        mat[i] = new int[col];
    }
}

void Matrix::getMatrix()
{
    for (int i = 0; i < row; i++)
    {
        std::cout << "-----Row " << i + 1 << "-----" << std::endl;
        for (int j = 0; j < col; j++)
        {
            std::cout << "Enter the element at [" << i + 1 << "," << j + 1 << "] : ";
            std::cin >> mat[i][j];
        }
    }
}

void Matrix::displayMatrix()
{
    int width = 3;
    std::cout << std::endl;
    for (int i = 0; i < row; i++)
    {
        std::cout << "│";
        for (int j = 0; j < col; j++)
        {
            std::cout << std::setw(width) << mat[i][j] << " ";
        }
        std::cout << std::setw(width) << "│" << std::endl;
    }
    std::cout << std::endl;
}

int Matrix::operator+(const Matrix &m)
{
    if (row == m.row && col == m.col)
    {
        std::cout << std::endl;
        Matrix temp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        temp.displayMatrix();
        return 0;
    }
    else
    {
        return 1;
    }
}

int Matrix::operator*(const Matrix &m)
{
    if (col == m.row)
    {
        std::cout << std::endl;
        Matrix temp(row, m.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < m.col; j++)
            {
                temp.mat[i][j] = 0;
                for (int k = 0; k < col; k++)
                {
                    temp.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        temp.displayMatrix();
        return 0;
    }
    else
    {
        return 1;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    int r, c;
    std::cout << std::endl;
    std::cout << "-----Matrix 1-----" << std::endl;
    std::cout << "Enter the number of rows : ";
    std::cin >> r;
    std::cout << "Enter the number of columns : ";
    std::cin >> c;
    Matrix m1(r, c);
    std::cout << std::endl;
    std::cout << "-----Matrix 2-----" << std::endl;
    std::cout << "Enter the number of rows : ";
    std::cin >> r;
    std::cout << "Enter the number of columns : ";
    std::cin >> c;
    Matrix m2(r, c);
    std::cout << std::endl;
    bool continueLoop = true, assigned = false;
    while (continueLoop)
    {
        int choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Enter the elements of the matrices" << std::endl;
        std::cout << "2. Display the matrices" << std::endl;
        std::cout << "3. Add the matrices" << std::endl;
        std::cout << "4. Multiply the matrices" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "-----Matrix 1-----" << std::endl;
            m1.getMatrix();
            std::cout << std::endl;
            std::cout << "-----Matrix 2-----" << std::endl;
            m2.getMatrix();
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                std::cout << "-----Matrix 1-----" << std::endl;
                m1.displayMatrix();
                std::cout << std::endl;
                std::cout << "-----Matrix 2-----" << std::endl;
                m2.displayMatrix();
            }
            else
            {
                std::cout << "The matrices have not been assigned!" << std::endl;
            }
            break;
        case 3:
            if (assigned)
            {
                std::cout << "-----Sum-----";
                if (m1 + m2)
                {
                    std::cout << "\r" << std::flush;
                    std::cout << "The matrices cannot be added." << std::endl;
                }
            }
            else
            {
                std::cout << "The matrices have not been assigned!" << std::endl;
            }
            break;
        case 4:
            if (assigned)
            {
                std::cout << "-----Product-----";
                if (m1 * m2)
                {
                    std::cout << "\r" << std::flush;
                    std::cout << "The matrices cannot be multiplied." << std::endl;
                }
            }
            else
            {
                std::cout << "The matrices have not been assigned!" << std::endl;
            }
            break;
        case 5:
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
