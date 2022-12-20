#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

void randomFill(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printarr(int* arr, int size) {
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort_po_ubblv(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void insertSort(int* arr, int n) {
    long long int counter = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
}

void shellSort(int* num, int size)
{
    long long int counter = 0;
    int increment = 3;    // начальное приращение сортировки
    while (increment > 0)  // пока существует приращение
    {
        for (int i = 0; i < size; i++)  // для всех элементов массива
        {
            int j = i;          // сохраняем индекс и элемент
            int temp = num[i];
            // просматриваем остальные элементы массива, отстоящие от j-ого
            // на величину приращения
            while ((j >= increment) && (num[j - increment] > temp))
            {  // пока отстоящий элемент больше текущего
                num[j] = num[j - increment]; // перемещаем его на текущую позицию
                j = j - increment;       // переходим к следующему отстоящему элементу
            }
            num[j] = temp; // на выявленное место помещаем сохранённый элемент
        }
        if (increment > 1) {      // делим приращение на 2
            increment = increment / 2;
        }
        else if (increment == 1) { // последний проход завершён,
            break;  // выходим из цикла
        }
    }
}
 
void Merge(int* A, int first, int last)
{
    int middle, start, final, j;
    int* mas = new int[last+1];
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final])))
        {
            mas[j] = A[start];
            start++;
        }
        else
        {
            mas[j] = A[final];
            final++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++) {
        A[j] = mas[j];
    }
    delete[]mas;
};

//рекурсивная процедура сортировки
void MergeSort(int* A, int first, int last)
{
    if (first < last)
    {
        MergeSort(A, first, (first + last) / 2); //сортировка левой части
        MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
        Merge(A, first, last); //слияние двух частей
    }
}

int main() {
    srand(time_t(NULL));
    setlocale(LC_ALL, "rus");
    int num; cout << "Номер сортировки: " << endl;
    cout << "1 - Алгоритм простой сортировки (Простой вставки)" << endl;
    cout << "2 - Алгоритм усовершенствованной сортировки (Шелла со смещениями Д. Кнута.)" << endl;
    cout << "3 - Быстрый алгоритм сортировки (Cлияние)" << endl;
    cin >> num;
    switch (num) {
    case 1: {
        int size; cout << "Размер массива: "; cin >> size;
        int* arr = new int[size];
        randomFill(arr, size);
        printarr(arr, size);
        long double start_time = clock();
        insertSort(arr, size);
        cout << "Сработан алгоритм сортировки" << endl;
        printarr(arr, size);
        long double end_time = clock();
        long double search_time = end_time - start_time;
        cout << "Время выполнения сортировки: " << fixed << setprecision(3) << search_time / 1000 << endl;
        delete[]arr;
        break;
    }
    case 2: {
        int size; cout << "Размер массива: "; cin >> size;
        int* arr = new int[size];
        randomFill(arr, size);
        printarr(arr, size);
        long double start_time = clock();
        shellSort(arr, size);
        cout << "Сработан алгоритм сортировки" << endl;
        printarr(arr, size);
        long double end_time = clock();
        long double search_time = end_time - start_time;
        cout << "Время выполнения сортировки: " << fixed << setprecision(3) << search_time / 1000 << endl;
        delete[]arr;
        break;
    }
    case 3: {
        int size; cout << "Размер массива: "; cin >> size;
        int* arr = new int[size];
        randomFill(arr, size);
        printarr(arr, size);
        long double start_time = clock();
        MergeSort(arr, 0, size-1);
        cout << "Сработан алгоритм сортировки" << endl;
        printarr(arr, size);
        long double end_time = clock();
        long double search_time = end_time - start_time;
        cout << "Время выполнения сортировки: " << fixed << setprecision(3) << search_time / 1000 << endl;
        delete[]arr;
        break;
    }
    default: {
        break;
    }
    }
    return 0;
}
