#include <iostream>
#include <chrono>
#include "Product.h"
#include "binfile.h"
#include "bintree.h"
#include "AVLtree.h"
using namespace std;

int inputMenu(int& number);
int rotations();

int main() {
    system("chcp 1251 > null");
    int menu;
    BinaryTree bintree;
    AVLtree avltree;
    while (true) {
        inputMenu(menu);
        if (menu == 0) {
            cout << "Задание не выбрано... Выход из программы" << endl;
            break;
        }
        switch (menu) {
        case 1: {
            cout << "-------------------------------------------------------------------------" << endl;
            ConvertTextToBin("file.bin", "file.txt");
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 2: {
            cout << "-------------------------------------------------------------------------" << endl;
            OutputBinFile("file.bin");
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 3: {
            cout << "-------------------------------------------------------------------------" << endl;
            if (bintree.createTree("file.bin")) {
                cout << "Tree has been created" << endl;
            }
            else {
                cout << "Error..." << endl;
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 4: {
            cout << "-------------------------------------------------------------------------" << endl;
            Product pr;
            cout << "Название продукта: "; cin >> pr.name; cin.ignore(); cin.clear();
            cout << "Код продукта: "; cin >> pr.code; cin.ignore(); cin.clear();
            cout << "Производитель продукта: "; cin >> pr.manufacturer; cin.ignore(); cin.clear();
            cout << "Цена продукта: "; cin >> pr.price; cin.ignore(); cin.clear();
            cout << "Страна-производитель продукта: "; cin >> pr.country; cin.ignore(); cin.clear();
            bintree.addNode(pr, 10);
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 5: {
            cout << "-------------------------------------------------------------------------" << endl;
            int key, index=-1;
            cout << "Key: "; cin >> key; cin.ignore(); cin.clear();
            index = bintree.findNode(key);
            cout << "Index: " << index << endl;
            printRecord(DirectAccess("file.bin", index));
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 6: {
            cout << "-------------------------------------------------------------------------" << endl;
            int key;
            cout << "Key: "; cin >> key; cin.ignore(); cin.clear();
            if (bintree.removeNode(key)) {
                cout << "Node has been deleted" << endl;
            }
            else {
                cout << "Error..." << endl;
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 7: {
            cout << "-------------------------------------------------------------------------" << endl;
            bintree.printTree();
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 8: {
            cout << "-------------------------------------------------------------------------" << endl;
            if (avltree.createAVLTree("file.bin")) {
                cout << "Tree has been created" << endl;
            }
            else {
                cout << "Error..." << endl;
            }
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 9: {
            cout << "-------------------------------------------------------------------------" << endl;
            Product pr;
            cout << "Название продукта: "; cin >> pr.name; cin.ignore(); cin.clear();
            cout << "Код продукта: "; cin >> pr.code; cin.ignore(); cin.clear();
            cout << "Производитель продукта: "; cin >> pr.manufacturer; cin.ignore(); cin.clear();
            cout << "Цена продукта: "; cin >> pr.price; cin.ignore(); cin.clear();
            cout << "Страна-производитель продукта: "; cin >> pr.country; cin.ignore(); cin.clear();
            avltree.head = avltree.addNode(avltree.head, pr, 10);
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 10: {
            cout << "-------------------------------------------------------------------------" << endl;
            int key, index=-1;
            cout << "Key: "; cin >> key; cin.ignore(); cin.clear();
            index = avltree.findNode(key);
            cout << "Index: " << index << endl;
            printRecord(DirectAccess("file.bin", index));
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 11: {
            cout << "-------------------------------------------------------------------------" << endl;
            int key;
            cout << "Ключ: "; cin >> key; cin.ignore(); cin.clear();
            avltree.head = avltree.removeNode(avltree.head, key);
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 12: {
            cout << "-------------------------------------------------------------------------" << endl;
            avltree.printTree();
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        case 13: {
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Количество поворотов при построении СДП по большому файлу: "<< rotations() << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            break;
        }
        default: {
            break;
        }
        }
    }
}

int inputMenu(int& number) {
    cout << "Введите номер задания" << endl;
    cout << "--- Управление бинарным файлом ---" << endl;
    cout << "1) Создать бинарный файл из текстового" << endl;
    cout << "2) Вывести данные бинарного файла" << endl;

    cout << "--- Бинарное дерево поиска ---" << endl;
    cout << "3) Построить дерево по бинарному файлу" << endl;
    cout << "4) Добавить элемент в дерево" << endl;
    cout << "5) Поиск по ключу в дереве" << endl;
    cout << "6) Удалить элемент из дерева" << endl;
    cout << "7) Вывод дерева" << endl;

    cout << "--- AVL дерево ---" << endl;
    cout << "8) Построить дерево по бинарному файлу" << endl;
    cout << "9) Добавить элемент в дерево" << endl;
    cout << "10) Поиск по ключу в дереве" << endl;
    cout << "11) Удалить элемент из дерева" << endl;
    cout << "12) Вывод дерева" << endl;
    cout << "13) Определить кол-во поворотов при построении СДП" << endl;

    cout << "-----------------" << endl;
    cout << "0) Выход из программы" << endl;
    while (1) {
        cout << "Введите число от 0 до 13: ";
        if ((cin >> number).good() && (number >= 0) && (number <= 13)) {
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

int rotations() {
    AVLtree tree;
    if (tree.createAVLTree("bigfile.bin")) {
        cout << "Tree has been created" << endl;
    }
    else {
        cout << "Error..." << endl;
    }
    return tree.rotations;
}

//Apple
//101111
//Apple_Factory
//5
//Egypt
