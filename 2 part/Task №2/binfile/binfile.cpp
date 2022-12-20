#include <string.h>
#include <string>
#include <iostream>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

struct Product {
    char name[20];
    char manufacturer[20];
    char country[20];
    int price;
    int code;
};
Product product;

int inputMenu(int& number) {
    cout << "Введите номер задания" << endl;
    cout << "1) Преобразование тестовых данных из текстового файла в двоичный файл" << endl;
    cout << "2) Преобразование данных из двоичного файла в текстовый" << endl;
    cout << "3) Вывод всех записей двоичного файла" << endl;
    cout << "4) Доступ к записи по ее порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле" << endl;
    cout << "5) Удаление записи с заданным значением ключа, выполнить путем замены на последнюю запись" << endl;
    cout << "6) Сформировать текстовый файл о поставках заданной страны, размещая на строке все сведения о товаре, кроме страны" << endl;
    cout << "7) Добавить новую запись о товаре в конец файла" << endl;
    cout << "0) Выход из программы" << endl;
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

void ConvertTextToBin(string bin_file_name, string txt_file_name) {
    ifstream fin(txt_file_name, ios::in);
    if (fin.is_open()) {
        ofstream fout(bin_file_name, ios::out | ios::binary);
        Product product;
        while (!fin.eof()) {
            fin >> product.name >> product.code >> product.manufacturer >> product.price >> product.country;
            fout.write((char*)&product, sizeof(Product));
        }
        fout.close();
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
    }
    fin.close();
}

void ConvertBinToText(string bin_file_name, string txt_file_name) {
    ifstream fin;
    fin.open(bin_file_name, ios::binary | ios::in);
    if (fin.is_open()) {
        ofstream fout;
        fout.open(txt_file_name, ios::out);
        Product product;
        while (fin.read((char*)&product, sizeof(Product))) {
            fout << product.name << " " << product.code << " " << product.manufacturer << " " << product.price << " " << product.country << "\n";
        }
        fout.close();
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
    }
    fin.close();
}

void OutputBinFile(string bin_file_name) {
    ifstream fin(bin_file_name, ios::in | ios::binary);
    Product product;
    if (fin.is_open()) {
        while (fin.read((char*)&product, sizeof(Product))) {
            cout << product.name << " " << product.code << " " << product.manufacturer << " " << product.price << " " << product.country << "\n";
        }
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
    }
    fin.close();
}

bool CheckIndex(string bin_file_name, int index) {
    ifstream fin;
    fin.open(bin_file_name, ios::binary | ios::in);
    Product temp;
    int count = 0;
    while (fin.read((char*)&temp, sizeof(Product))){
        count++;
    }
    fin.close();
    if (count > index) {
        return true;
    }
    else {
        return false;
    }
}

string GetProduct(string bin_file_name, int index) {
    ifstream fin;
    fin.open(bin_file_name, ios::binary | ios::in);
    string result = "";
    if (fin.is_open()) {
        if (!CheckIndex(bin_file_name, index)) {
            return "Индекс превосходит количество элементов";
        }
        Product product;
        fin.seekg(index * sizeof(Product), ios::beg);
        fin.read((char*)&product, sizeof(Product));
        result = product.name;
        result += " ";
        result += to_string(product.code);
        result += " ";
        result += product.manufacturer;
        result += " ";
        result += to_string(product.price);
        result += " ";
        result += product.country;
    }
    else {
        result = "Файла с таким именем не существует";
    }
    return result;
    fin.close();
}

void DeleteRecord(string name, int index){
    Product product;
    Product empty;
    fstream file(name, ios_base::binary | ios::in | ios::out);

    if (file.is_open()) {
        if (!CheckIndex(name, index)) {
            cout << "Индекс превышает количество записей" << endl;
            return;
        }

        file.seekg((-1) * (int)sizeof(Product), ios::end);
        file.read((char*)&product, sizeof(Product));

        file.seekg((-1) * (int)sizeof(Product), ios::end);
        file.write((char*)&empty, sizeof(Product));

        file.seekg((index) * sizeof(Product), ios::beg);
        file.write((char*)&product, sizeof(Product));
    }
    else { 
        cout << "Файла с таким именем не существует\n"; 
        return; 
    } 

    if (file.good()) {
        file.close();
    }
}

bool checkCountry(char* m1, char* m2,int size) {
    for (int i = 0; i < size; i++) {
        if (m1[i] != m2[i]) {
            return false;
        }
    }
    return true;
}

void AdditionalTask1(string bin_file_name, string new_file_name, char country[20]) {
    ifstream file(bin_file_name, ios_base::binary);
    if (!file) {
        cout << "Файла с таким именем не существует\n";
        return;
    }
    ofstream products(new_file_name, ios_base::binary);
    Product product;
    file.read((char*)&product, sizeof(Product));
    products << country << "\n";
    string temp = country;
    while (!file.eof()) {
        if (checkCountry(product.country, country, temp.size())) {
            products << product.name << " " << product.code << " " << product.manufacturer << " " << product.price << "\n";
        }
        file.read((char*)&product, sizeof(Product));
    }
    if (file.good()) {
        file.close();
    }
    if (products.good()) {
        products.close();
    }
}


void AdditionalTask2(string bin_file_name) {
    ofstream binfout;
    binfout.open(bin_file_name, ios::app | ios::binary);
    Product product;
    if (binfout.good()) {
        cout << "Название продукта: "; cin >> product.name; cin.ignore(); cin.clear();
        cout << "Код продукта: "; cin >> product.code; cin.ignore(); cin.clear();
        cout << "Производитель продукта: "; cin >> product.manufacturer; cin.ignore(); cin.clear();
        cout << "Цена продукта: "; cin >> product.price; cin.ignore(); cin.clear();
        cout << "Страна-производитель продукта: "; cin >> product.country; cin.ignore(); cin.clear();
        binfout.write((char*)&product, sizeof(Product));
        binfout.close();
    }
    else {
        cout << "Файла с таким именем не существует\n";
        return;
    }
}

int main() {
    system("chcp 1251 > null");
    string bin_file_name;
    int menu;
    while (true) {
        inputMenu(menu);
        if (menu == 0) {
            cout << "Задание не выбрано\nВыход из программы..." << endl;
            break;
        }
        cout << endl;
        switch (menu) {
        case 1: {
            cout << "Введите имя бинарного файла: ";
            cin >> bin_file_name;
            cin.ignore();
            cin.clear();
            string txt_file_name;
            cout << "Введите имя текстового файла для копирования в двоичный: ";
            cin >> txt_file_name;
            ConvertTextToBin(bin_file_name, txt_file_name);
            break;
        }
        case 2: {
            cout << "Введите имя бинарного файла: ";
            cin >> bin_file_name;
            cin.ignore();
            cin.clear();
            string txt_file_name;
            cout << "Введите имя текстового файла для копирования из двоичного: ";
            cin >> txt_file_name;
            ConvertBinToText(bin_file_name, txt_file_name);
            break;
        }
        case 3: {
            cout << "Введите имя бинарного файла: ";
            cin >> bin_file_name;
            cin.ignore();
            cin.clear();
            OutputBinFile(bin_file_name);
            break;
        }
        case 4: {
            cout << "Введите имя бинарного файла: ";
            cin >> bin_file_name;
            cin.ignore();
            cin.clear();
            int index;
            cout << "Введите индекс элемента: ";
            cin >> index;
            cout << GetProduct(bin_file_name, index) << endl;
            break;
        }
        case 5: {
            cout << "Введите имя бинарного файла: ";
            cin >> bin_file_name;
            cin.ignore();
            cin.clear();
            int index;
            cout << "Введите индекс элемента, который надо удалить: ";
            cin >> index;
            DeleteRecord(bin_file_name, index);
            break;
        }
        case 6: {
            cout << "Введите имя бинарного файла: ";
            cin >> bin_file_name;
            cin.ignore();
            cin.clear();
            char country[20]; cout << "Страна (на английском языке): ";
            cin >> country;
            cin.ignore();
            cin.clear();
            AdditionalTask1(bin_file_name, "info.bin", country);
            break;
        }
        case 7: {
            cout << "Введите имя бинарного файла: ";
            cin >> bin_file_name;
            cin.ignore();
            cin.clear();
            AdditionalTask2(bin_file_name);
            break;
        }
        default: {
            cout << "Задание не выбрано\nВыход из программы..." << endl;
            break;
        }
        }
    }
}

//Тестовые данные для 7-ого задания
//Apple
//101111
//Apple_Factory
//5
//Egypt