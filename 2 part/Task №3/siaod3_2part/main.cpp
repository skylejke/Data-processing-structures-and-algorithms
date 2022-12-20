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
    cout << "������� ����� �������" << endl;
    cout << "1) ��������� ������ �� ����� � �������� ������� � �������" << endl;
    cout << "2) ������� ������ �� ������� ��� �������� �������� ����� � �������������� �� �����." << endl;
    cout << "3) ����� ������ � ����� �� �������� ����� (����� ���� � ���-�������, �������� ����� ������ � ���� ������ � �����, ��������� ������ ������ � ������ �� �� ������)" << endl;
    cout << "4) �������� ������ �� ������� ����� (1 000 000 �������)" << endl;
    cout << "5) ��������� testBinF" << endl;
    cout << "6) ��������� testHeshT" << endl;
    cout << "7) ����� ���-�������" << endl;
    cout << "0) �����" << endl;
    while (1) {
        cout << "������� ����� �� 0 �� 7: ";
        if ((cin >> number).good() && (number >= 0) && (number <= 7)) {
            return number;
        }
        if (cin.fail()) {
            cin.clear();
            cout << endl << "�������� ����, ���������." << endl << endl;
        }
        else {
            cout << endl << "����� ��� ����������� ��������� ��������. ��������� ����." << endl << endl;
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
            cout << "������� �� �������\n����� �� ���������..." << endl;
            break;
        }
        switch (menu) {
        case 1: {
            int index;
            cout << "������� ����� ������ (-1 ��� ���� �������): ";
            cin >> index;
            InsertBinHash(hashtable, bin_file_name, index);
            hashtable.print();
            cout << "-----------------------" << endl << endl;
            break;
        }
        case 2: {
            int key;
            cout << "������� ����: ";
            cin >> key;
            DeleteByKeyHash(hashtable, bin_file_name, key);
            hashtable.print();
            cout << "-----------------------" << endl << endl;
            break;
        }
        case 3: {
            int key;
            cout << "������� ����: ";
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
            cout << "����� ������ ������ ������: " << search_time << " ������" << endl;
            cout << "----------------------------------" << endl;

            cout << "----------------------------------" << endl;
            start_time = clock();
            GetByKeyHash(big_hashtable, "bigfile.bin", 777777);
            end_time = clock();
            search_time = double(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "����� ������ 500 000-�� ������: " << search_time << " ������" << endl;
            cout << "----------------------------------" << endl;

            cout << "----------------------------------" << endl;
            start_time = clock();
            GetByKeyHash(big_hashtable, "bigfile.bin", 666666);
            end_time = clock();
            search_time = double(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "����� ������ 1 000 000-�� ������: " << search_time << " ������" << endl;
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
            cout << "������� �� �������\n����� �� ���������..." << endl;
            break;
        }
        }
    }
    return 0;
}
