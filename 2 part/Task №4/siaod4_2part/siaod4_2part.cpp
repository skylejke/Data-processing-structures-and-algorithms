#include <iostream>
#include "BinaryTree.h"
using namespace std;

int inputMenu(int& number) {
    cout << "Введите номер задания" << endl;
    cout << "1) Создать идеально сбалансированное бинарное дерево из n узлов." << endl;
    cout << "2) Отобразить дерево на экране, повернув его против часовой стрелки" << endl;
    cout << "3) Используя рекурсивный алгоритм определить количество уровней в дереве" << endl;
    cout << "4) Вернуть узел с максимальным значением, обходя дерево в ширину. " << endl;
    cout << "5) Определить максимальное и минимальное значения" << endl;
    cout << "6) Удалить дерево" << endl;
    cout << "0) Выход из программы" << endl;
    while (1) {
        cout << "Введите число от 0 до 6: ";
        if ((cin >> number).good() && (number >= 0) && (number <= 6)) {
            return number;
        }
        if (cin.fail()) {
            cin.clear();
            cout << endl << "Неверный ввод, повторите." << endl << endl;
        }
        else {
            cout << endl << "Число вне допустимого диапазона значений. Повторите ввод." << endl << endl;
        }
        cin.ignore(100, '\n');
    }
}

int main() {
    system("chcp 1251 > null");
    int menu;
    point* p = 0;
    int n = -1;
    while (true) {
        inputMenu(menu);
        if (menu == 0) {
            cout << "Задание не выбрано\nВыход из программы..." << endl;
            break;
        }
        switch (menu) {
        case 1: {
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Введите количество элементов дерева: ";
            cin >> n;
            p = BuildTree(n, p);
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 2: {
            cout << "-------------------------------------------------------------------------" << endl;
            if (p) {
                PrintTree(p, n);
            }
            else {
                cout << "Дерево не создано\n";
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 3: {
            cout << "-------------------------------------------------------------------------" << endl;
            if (p) {
                cout << "Количество уровней в дереве = " << TreeHeight(p) << endl;
            }
            else {
                cout << "Дерево не создано\n";
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 4: {
            cout << "-------------------------------------------------------------------------" << endl;
            if (p) {
                breadthFirst(p);
            }
            else {
                cout << "Дерево не создано\n";
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 5: {
            cout << "-------------------------------------------------------------------------" << endl;
            if (p) {
                cout << "Максимальное значение = " << MaxValue(p) << endl;
                cout << endl;
                cout << "Минимальное значение = " << MinValue(p) << endl;
            }
            else {
                cout << "Дерево не создано\n";
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 6: {
            DeleteTree(p);
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Дерево удалено" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        default: {
            cout << "Задание не выбрано\nВыход из программы..." << endl;
            break;
        }
        }
    }
    return 0;
}
