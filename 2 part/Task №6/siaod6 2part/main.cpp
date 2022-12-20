#include "Graph.h"

int inputMenu(int& number);

int main() {
    system("chcp 1251 > null");
    int menu;
    int n;
    cout << "Создание графа...";
    cout << endl << "Введите кол-во элементов в графе >> ";
    cin >> n;
    Graph graph(n);
    while (true) {
        inputMenu(menu);
        if (menu == 0) {
            graph.graphClear();
            cout << "Задание не выбрано... Выход из программы" << endl;
            break;
        }
        switch (menu) {
        case 1: {
            cout << "-------------------------------------------------------------------------" << endl;
            int first, second, weight;
            cout << "Введите номер первой вершины, второй и расстояние между ними >> ";
            cin >> first;
            cin >> second;
            cin >> weight;
            if (graph.add(first, second, weight) == false) {
                cout << "Error..." << endl;
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 2: {
            cout << "-------------------------------------------------------------------------" << endl;
            graph.printGraph();
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 3: {
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Текущий размер графа = " << graph.graphSize() << endl;
            int size; 
            cout << "Введите новый размер графа >> ";
            cin >> size;
            graph.graphResize(size);
            cout << "Новый размер графа =  " << graph.graphSize() << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 4: {
            cout << "-------------------------------------------------------------------------" << endl;
            graph.printChains();
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        default: {
            break;
        }
        }
    }
   
    return 0;
}

int inputMenu(int& number) {
    cout << "Введите номер задания" << endl;
    cout << "1) Добавить элемент в граф" << endl;
    cout << "2) Вывести граф" << endl;
    cout << "3) Увеличить размер графа" << endl;
    cout << "4) Вывести все цепочки в графе" << endl;
    cout << "-----------------" << endl;
    cout << "0) Выход из программы" << endl;
    while (1) {
        cout << "Введите число от 0 до 4: ";
        if ((cin >> number).good() && (number >= 0) && (number <= 4)) {
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

//Тестовые данные

//1
//1 2 8
//1
//1 3 4
//1
//2 4 6
//1
//2 5 3
//1
//3 2 3
//1
//3 4 2
//1
//3 6 10
//1
//4 5 3
//1
//4 6 1
//1
//5 6 4