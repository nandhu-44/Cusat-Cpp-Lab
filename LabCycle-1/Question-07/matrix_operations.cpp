#include <iostream>

class Matrix
{
    int **mat;
    int row, col;

public:
    Matrix(int r, int c);
    void printMatrix(void);
    void setData(void);
    friend void matrix_add(const Matrix &m1, const Matrix &m2);
    friend void matrix_mult(const Matrix &m1, const Matrix &m2);
    void matrix_transpose(void);
    void matrix_trace(void);
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

void matrix_add(const Matrix &m1, const Matrix &m2)
{
    if (m1.row != m2.row || m1.col != m2.col)
    {
        std::cout << "Matrix addition not possible!" << std::endl;
    }
    Matrix m3(m1.row, m1.col);
    for (int i = 0; i < m1.row; i++)
    {
        for (int j = 0; j < m1.col; j++)
        {
            m3.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
        }
    }
    std::cout << "The sum of the matrices is  => " << std::endl;
    m3.printMatrix();
}

void matrix_mult(const Matrix &m1, const Matrix &m2)
{
    if (m1.row != m2.row || m1.col != m2.col)
    {
        std::cout << "Matrix multiplication not possible!" << std::endl;
    }
    Matrix m3(m1.row, m1.col);
    for (int i = 0; i < m1.row; i++)
    {
        for (int j = 0; j < m1.col; j++)
        {
            m3.mat[i][j] = m1.mat[i][j] * m2.mat[i][j];
        }
    }
    std::cout << "The product of the matrices is  => " << std::endl;
    m3.printMatrix();
}

void Matrix::matrix_transpose(void)
{
    Matrix m3(col, row);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            m3.mat[i][j] = mat[j][i];
        }
    }
    std::cout << "The transpose of the matrix is => " << std::endl;
    m3.printMatrix();
}

void Matrix::matrix_trace(void)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        sum += mat[i][i];
    }
    std::cout << "The trace of the matrix is => " << sum << std::endl;
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
    std::cout << "Enter the number of rows: ";
    std::cin >> r;
    std::cout << "Enter the number of columns: ";
    std::cin >> c;
    std::cout << std::endl;
    Matrix m1(r, c), m2(r, c), m3(r, c);
    bool continueLoop = true;
    std::cout << "-----Matrix 1-----" << std::endl;
    m1.setData();
    std::cout << std::endl;
    std::cout << "-----Matrix 2-----" << std::endl;
    m2.setData();
    std::cout << std::endl;
    while (continueLoop)
    {
        int choice, n;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "-----Main Menu-----" << std::endl;
        std::cout << "1. Add Matrix" << std::endl;
        std::cout << "2. Multiply Matrix" << std::endl;
        std::cout << "3. Transpose of a Matrix" << std::endl;
        std::cout << "4. Trace of a Matrix" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            matrix_add(m1, m2);
            break;
        case 2:
            matrix_mult(m1, m2);
            break;
        case 3:
            std::cout << "Enter which matrix to transpose (1 or 2) : ";
            std::cin >> n;
            if (n == 1)
            {
                m1.matrix_transpose();
            }
            else if (n == 2)
            {
                m2.matrix_transpose();
            }
            else
            {
                std::cout << "Invalid number! Try again later." << std::endl;
            }
            break;
        case 4:
            if (r != c)
            {
                std::cout << "Trace is only possible for square matrices!! " << std::endl;
                break;
            }
            std::cout << "Enter which matrix to trace (1 or 2) : ";
            std::cin >> n;
            if (n == 1)
            {
                m1.matrix_trace();
            }
            else if (n == 2)
            {
                m2.matrix_trace();
            }
            else
            {
                std::cout << "Invalid number! Try again later." << std::endl;
            }
            break;
        case 5:
            std::cout << "Thank you for using our program." << std::endl;
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