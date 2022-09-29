// NOTE: This code require Cpp standard set to C++20 in order to compile

#include <iostream>
#include <format>
#define ROW 3
#define COLUMN 3

void printMatrix(int &row, int &column, int matrix[ROW][COLUMN])
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
        {
            std::cout << matrix[r][c] << " ";
        }
        std::cout << "\n";
    }
}

void inputMatrix(int &row, int &column, int matrix[ROW][COLUMN], std::string matrixName)
{
    std::cout << std::format("===== Matriks {} =====\n", matrixName);
    std::cout << "Masukkan jumlah baris = ";
    std::cin >> row;
    std::cout << "Masukkan jumlah kolom = ";
    std::cin >> column;
    std::cout << "\n";

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
        {
            std::cout << std::format("Masukkan elemen matriks {} baris ke {} kolom {} : ", matrixName, r+1, c+1);
            std::cin >> matrix[r][c];
        }
    }
}

int main()
{
    int firstMatrix[ROW][COLUMN];
    int secondMatrix[ROW][COLUMN];
    int resultMatrix[ROW][COLUMN];
    int rowFirst = 0;
    int columnFirst = 0;
    int rowSecond = 0;
    int columnSecond = 0;

    inputMatrix(rowFirst, columnFirst, firstMatrix, "A");

    std::cout << "\n";

    printMatrix(rowFirst, columnFirst, firstMatrix);

    std::cout << "\n";

    inputMatrix(rowSecond, columnSecond, secondMatrix, "B");

    std::cout << "\n";

    printMatrix(rowSecond, columnSecond, secondMatrix);

    std::cout << "\n";

    if (rowFirst != columnSecond)
    {
        std::cout << "Matriks tidak sesuai";
    }

    else
    {
        for (int row = 0; row < rowFirst; row++)
        {
            for (int col = 0; col < columnSecond; col++)
            {
                resultMatrix[row][col] = 0;

                for (int store = 0; store < rowSecond; store++)
                {
                    resultMatrix[row][col] += firstMatrix[row][store] * secondMatrix[store][col];
                }
                std::cout << resultMatrix[row][col] << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}