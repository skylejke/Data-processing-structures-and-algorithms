#include <iostream>
#include <vector>
#include <cstring>
#include <clocale>
#include <conio.h>
using namespace std;
int asd(int a) { // Проверка четное или нечетное количество чисел
    int c, i = 0;
    while (a != 0) {
        i++;
        a = a / 10;
    }
    c = i % 2;
    return c;
}
void Fill_array(int arr[], int size, int n) //Заполнение массива
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            cout << "Число не может быть меньше 0, для данного элемента будет выбрано значение 0" << endl;
            arr[i] = 0;
        }
    }
}
void Show_array(int arr[], int size) // Вывод всех элементов массива
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void count(int arr[], const int size, int newelement) { // вставка нового элемента в массив перед элементом, у которого четное количество цифр 
    int d = 0, c;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            if (asd(arr[i]) == 0) {
                c = arr[i];
                arr[i] = newelement;
                for (int j = i + 1; j < size - 1; j++) {
                    d = arr[j];
                    arr[j] = c;
                    c = d;
                    i++;
                }
            }
        }
    }
}
void delete_even(int arr[], int size) { //Удаление всех четных чисел массива.
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = -1;
        }
    }
}
void maxoneven(int arr[], int size) { // поиск максимального числа среди элементов массива, расположенных на четных местах.
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }
    cout << "Максимальное число среди элементов массива, расположенных на четных местах: " << max << endl;
}
int main()
{
    setlocale(LC_ALL, "rus");
    const int size = 5;
    int arr1[size] = { 0 }, n;
    cout << "Введите количество обрабатываемых элементов массивa: ";
    cin >> n;
    if (n > 0 && n <= size) {
        cout << "Введите " << n << " чисел " << endl;
        Fill_array(arr1, size, n);
    }
    else {
        cout << "n должно быть больше нуля";
        exit(0);
    }
    cout << "Исходный массив:" << endl;
    Show_array(arr1, size);
    cout << endl;
    int y;
    cout << "Введите номер задачи: " << endl;
    cout << "1 - Вставить новый элемент в массив перед элементом, у которого четное количество цифр. " << endl;
    cout << "2 - Удалить все четные числа массива." << endl;
    cout << "3 - Найти максимальное число среди элементов массива, расположенных на четных местах." << endl;
    cin >> y;
    switch (y) {
    case(1):
    {
        const int newsize = size + 1;
        int arr2[newsize] = { 0 };
        for (int i = 0; i < size; i++) {
            arr2[i] = arr1[i];
        }
        int newelement;
        cout << "Введите элемент, который желаете вставить перед элементом, у которого четное количество цифр: ";
        cin >> newelement;
        count(arr2, newsize, newelement);
        cout << "Новый массив: " << endl;
        Show_array(arr2, newsize);
        break;
    }
    case(2):
    {
        delete_even(arr1, size);
        cout << "Новый массив: " << endl;
        Show_array(arr1, size);
        break;
    }
    case(3):
    {
        maxoneven(arr1, size);
        break;
    }
    }
    return 0;
}