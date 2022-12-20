#include <vector>
#include <iostream>
#include <cstring>
#include <clocale>
#include <conio.h>
using namespace std;
void Fill_array(vector<int>& vector, int size, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vector[i];
        if (vector[i] < 0)
        {
            cout << "Число не может быть меньше 0, для данного элемента будет выбрано значение 0" << endl;
            vector[i] = 0;
        }
    }

}
void Show_array(vector<int>& vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " ";
    }
}
int asd(int a) {
    int c, i = 0;
    while (a != 0) {
        i++;
        a = a / 10;
    }
    c = i % 2;
    return c;
}
void count(vector<int> &vector, int size, int newelement) {
    int d = 0, c;
    for (int i = 0; i < size; i++) {
        if (vector[i]!= 0) {
            if (asd(vector[i]) == 0) {
                c = vector[i];
                vector[i] = newelement;
                for (int j = i + 1; j < size - 1; j++) {
                    d = vector[j];
                    vector[j] = c;
                    c = d;
                    i++;
                }
            }
        }
    }
}
void delete_even(vector<int>& vector, int size) {
    for (int i = 0; i < size; i++) {
        if (vector[i] % 2 == 0) {
            vector[i] = -1;
        }
    }
}
void maxoneven(vector<int>& vector, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            if (vector[i] > max) {
                max = vector[i];
            }
        }
    }
    cout << "Максимальное число среди элементов массива, расположенных на четных местах: " << max << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int size ,n ;
	cout << "Введите размер массива: ";
	cin >> size;
    if (size <= 0) {
        cout << "Размер должен быть больше нуля";
        exit(0);
    }
	vector <int> myVector(size);
	cout << "Введите количество обрабатываемых элементов массивa: ";
	cin >> n;
    if (n > 0 && n <= size) {
        cout << "Введите " << n << " чисел " << endl;
        Fill_array(myVector, size, n);
    }
    else {
        cout << "n должно быть больше нуля";
        exit(0);
    }
    cout << "Исходный массив:" << endl;
    Show_array(myVector, size);
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
        int newsize = size + 1;
        vector <int> myVector2(newsize);
        for (int i = 0; i < size; i++) {
            myVector2[i] = myVector[i];
        }
        int newelement;
        cout << "Введите элемент, который желаете вставить перед элементом, у которого четное количество цифр: ";
        cin >> newelement;
        count(myVector2, newsize, newelement);
        cout << "Новый массив: " << endl;
        Show_array(myVector2, newsize);
        break;
    }
    case(2):
    {
        delete_even(myVector,size);
        cout << "Новый массив: " << endl;
        Show_array(myVector, size);
        break;
    }
    case(3):
    {
        maxoneven(myVector,size);
        break;
    }
    } 
    return 0;
}