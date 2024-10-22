#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int K, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, K, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, K, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, const int K, int rowNo)
{
    PrintRow(a, rowNo, K, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, K, rowNo + 1);
    else
        cout << endl;
}

// Функція для пошуку максимального елемента у стовпці
void findMaxInColumn(int** a, const int rowCount, int j, int i, int& max)
{
    if (i >= rowCount)
        return;

    if (a[i][j] > max)
        max = a[i][j];

    findMaxInColumn(a, rowCount, j, i + 1, max);
}

// Рекурсивна функція для пошуку найменшого з максимальних елементів у непарних стовпцях
void findMinOfMaxInOddColumns(int** a, const int rowCount, const int colCount, int j = 1, int minOfMax = INT_MAX)
{
    if (j >= colCount) // Базовий випадок
    {
        cout << "Найменший з максимальних елементів по непарних стовпцях: " << minOfMax << endl;
        return;
    }

    int max = a[0][j]; // Початкове значення для пошуку максимального елемента в стовпці
    findMaxInColumn(a, rowCount, j, 0, max); // Знаходимо максимум у стовпці

    if (max < minOfMax)
        minOfMax = max; // Оновлюємо мінімальний максимум

    findMinOfMaxInOddColumns(a, rowCount, colCount, j + 2, minOfMax); // Переходимо до наступного непарного стовпця
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned>(time(nullptr)));

    int Low = -34;
    int High = 26;
    int rowCount;
    int colCount;

    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);
    PrintRows(a, rowCount, colCount, 0);

    findMinOfMaxInOddColumns(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
