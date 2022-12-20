#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "Product.h"
#include "binfile.h"
#include "hashtable.h"
#include "hashfile.h"

using namespace std;

int inputMenu(int& number) {
    cout << "Введите номер задания" << endl;
    cout << "1) Прочитать запись из файла и вставить элемент в таблицу" << endl;
    cout << "2) Удалить запись из таблицы при заданном значении ключа и соответственно из файла." << endl;
    cout << "3) Найти запись в файле по значению ключа (найти ключ в хеш-таблице, получить номер записи с этим ключом в файле, выполнить прямой доступ к записи по ее номеру)" << endl;
    cout << "4) Тестовый прогон на большом файле (1 000 000 записей)" << endl;
    cout << "5) Запустить testBinF" << endl;
    cout << "6) Запустить testHeshT" << endl;
    cout << "7) Вывод хэш-таблицы" << endl;
    cout << "0) Выход" << endl;
    while (1) {
        cout << "Введите число от 0 до 7: ";
        if ((cin >> number).good() && (number >= 0) && (number <= 7)) {
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
    HashTable hashtable;
    int menu;
    string bin_file_name = "file.bin";
    while (true) {
        inputMenu(menu);
        if (menu == 0) {
            cout << "Задание не выбрано\nВыход из программы..." << endl;
            break;
        }
        switch (menu) {
        case 1: {
            int index;
            cout << "Введите номер записи (-1 для всех записей): ";
            cin >> index;
            InsertBinHash(hashtable, bin_file_name, index);
            hashtable.print();
            cout << "-----------------------" << endl << endl;
            break;
        }
        case 2: {
            int key;
            cout << "Введите ключ: ";
            cin >> key;
            DeleteByKeyHash(hashtable, bin_file_name, key);
            hashtable.print();
            cout << "-----------------------" << endl << endl;
            break;
        }
        case 3: {
            int key;
            cout << "Введите ключ: ";
            cin >> key;
            GetByKeyHash(hashtable, bin_file_name, key);
            cout << "-----------------------" << endl << endl;
            break;
        }
        case 4: {
            //ConvertTextToBin("bigfile.bin", "bigfile.txt");

            //OutputBinFile("bigfile.bin"); 

            double  search_time;
            clock_t start_time, end_time;
            HashTable big_hashtable;
            InsertBinHash(big_hashtable, "bigfile.bin");

            cout << "----------------------------------" << endl;
            start_time = clock();
            GetByKeyHash(big_hashtable, "bigfile.bin", 343434);
            end_time = clock();
            search_time = double(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "Время чтения первой записи: " << search_time << " секунд" << endl;
            cout << "----------------------------------" << endl;

            cout << "----------------------------------" << endl;
            start_time = clock();
            GetByKeyHash(big_hashtable, "bigfile.bin", 777777);
            end_time = clock();
            search_time = double(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "Время чтения 500 000-ой записи: " << search_time << " секунд" << endl;
            cout << "----------------------------------" << endl;

            cout << "----------------------------------" << endl;
            start_time = clock();
            GetByKeyHash(big_hashtable, "bigfile.bin", 666666);
            end_time = clock();
            search_time = double(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "Время чтения 1 000 000-ой записи: " << search_time << " секунд" << endl;
            cout << "----------------------------------" << endl;
            break;
        }
        case 5: {
            testBinF();
            break;
        }
        case 6: {
            testHeshT();
            break;
        }
        case 7: {
            hashtable.print();
        }
        default: {
            cout << "Задание не выбрано\nВыход из программы..." << endl;
            break;
        }
        }
    }
    return 0;
}
