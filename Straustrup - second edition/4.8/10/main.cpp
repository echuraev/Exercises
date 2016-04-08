#include <iostream>

template<typename T>
void reverse2D(T **arr, const int rowNum, const int colNum)
{
    int rows = (rowNum%2) ? rowNum/2 + 1 : rowNum/2;
    for (int i(0); i < rows/2; ++i)
    {
        for (int j(0); j < colNum; ++j)
        {
            T tmp = arr[i][j];
            arr[i][j] = arr[rowNum - (i + 1)][colNum - (j + 1)];
            arr[rowNum - (i + 1)][colNum - (j + 1)] = tmp;
        }
    }
}

template<typename T>
void print(T **arr, const int rowNum, const int colNum)
{
    for (int i (0); i < rowNum; ++i)
    {
        for (int j(0); j < colNum; ++j)
        {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int rowNum = 4;
    const int colNum = 5;
    int **a = new int * [rowNum];
    for (int i(0); i < rowNum; ++i)
    {
        a[i] = new int [colNum];
        for (int j(0); j < colNum; ++j)
        {
            a[i][j] = i*colNum + j + 1;
        }
    }
    print<int>(a, rowNum, colNum);
    std::cout << std::endl;

    reverse2D<int>(a, rowNum, colNum);
    print<int>(a, rowNum, colNum);
    return 0;
}
