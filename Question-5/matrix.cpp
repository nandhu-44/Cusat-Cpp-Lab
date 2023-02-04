#include <iostream>
#include <tuple>

class Matrix
{
    int **mat;
    int row, col;

public:
    Matrix(int r, int c);
    void printMatrix(void);
    void setData(void);
    int setElement(int r, int c, int val);
    int getElement(int r, int c);
    std::tuple<int, int> getDimensions(void);
    ~Matrix();
};
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

void Matrix::printMatrix(void)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::setData(void)
{
    for (int i = 0; i < row; i++)
    {
        std::cout << "-----Row " << i + 1 << "----- " << std::endl;
        for (int j = 0; j < col; j++)
        {
            std::cout << "Enter element at [" << i + 1 << "," << j + 1 << "] : ";
            std::cin >> mat[i][j];
        }
        std::cout << std::endl;
    }
}

int Matrix::setElement(int r, int c, int val)
{
    mat[r][c] = val;
    return 0;
}

int Matrix::getElement(int r, int c)
{
    return mat[r][c];
}

std::tuple<int, int> Matrix::getDimensions(void)
{
    return std::make_tuple(row, col);
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
    int row, col;
    std::cout << "Enter number of rows: ";
    std::cin >> row;
    std::cout << "Enter number of columns: ";
    std::cin >> col;
    Matrix m(row, col);
    bool continueLoop = true;
    while (continueLoop)
    {
        int choice;
        int r, c, val;
        std::cout << std::endl;
        std::cout << "_____Main Menu_____ " << std::endl;
        std::cout << "1. Set Data" << std::endl;
        std::cout << "2. Print Matrix" << std::endl;
        std::cout << "3. Set Element" << std::endl;
        std::cout << "4. Get Element" << std::endl;
        std::cout << "5. Get Dimensions" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            m.setData();
            break;
        case 2:
            m.printMatrix();
            break;
        case 3:
            std::cout << "Enter row: ";
            std::cin >> r;
            std::cout << "Enter column: ";
            std::cin >> c;
            std::cout << "Enter value: ";
            std::cin >> val;
            m.setElement(r - 1, c - 1, val);
            break;
        case 4:
            std::cout << "Enter row: ";
            std::cin >> r;
            std::cout << "Enter column: ";
            std::cin >> c;
            std::cout << "Element at [" << r << "," << c << "] is " << m.getElement(r - 1, c - 1) << std::endl;
            break;
        case 5:
            std::cout << "Dimensions of matrix are " << std::get<0>(m.getDimensions()) << "x" << std::get<1>(m.getDimensions()) << std::endl;
            break;
        case 6:
            std::cout << "Thsnk you for using the program." << std::endl;
            continueLoop = false;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
}