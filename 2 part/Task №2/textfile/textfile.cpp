#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int inputMenu(int& number) {
    cout << "Введите номер задания" << endl;
    cout << "1) Cоздание текстового файла кодировки ASCII, содержащего десятичные числа по несколько чисел на строке" << endl;
    cout << "2) Вывод содержимого текстового файла" << endl;
    cout << "3) Добавление новой строки в конец файла" << endl;
    cout << "4) Прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение" << endl;
    cout << "5) Определить количество чисел в файле" << endl;
    cout << "6) Создать новый файл из значений исходного, умножив каждое число на сумму первого и последнего чисел исходного файла" << endl;
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

void CreateAndFillFile(string fileName) {
    ofstream fout;
    fout.open(fileName, ios::out);
    int lines = rand() % 10 + 1;
    for (int i = 0; i < lines; i++) {
        int countNumbers = rand() % 6 + 1;
        for (int j = 0; j < countNumbers; j++) {
            fout << rand() % 20 + 1 << " ";
        }
        if (i < lines - 1) {
            fout << endl;
        }
    }
    if (fout.good()) {
        fout.close();
    }
    else {
        return;
    }
}

void PrintFile(string fileName) {
    ifstream fin;
    fin.open(fileName, ios::in);
    if (fin.is_open()) {
        cout << "Содержимое файла " << fileName << ":" << "\n";
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            cout << line << endl;
        }
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
    }
    if (fin.good()) {
        fin.close();
    }
    else {
        return;
    }
}

void AppendLine(string fileName, string line) {
    ofstream fout;
    fout.open(fileName, ios::app);
    fout << endl << line;
    if (fout.good()) {
        fout.close();
    }
    else {
        return;
    }
}

int GetNumber(string fileName) {
    int resultNumber = 0;
    ifstream fin;
    fin.open(fileName, ios::in);
    if (fin.is_open()) {
        int numberIndex;
        cout << "Номер искомого числа, начиная с 0: ";
        cin >> numberIndex;
        for (int i = 0; i <= numberIndex; i++) {
            fin >> resultNumber;
        }
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
    }
    if (fin.good()) {
        fin.close();
    }
    else {
        return -1;
    }
    return resultNumber;
}

int CountNumbers(string fileName){
    int n, count = 0;
    ifstream fin;
    fin.open(fileName, ios::in);
    if (fin.is_open()) {
        while (fin >> n) {
            count++;
        }
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
        return -1;
    }
    if (fin.good()) {
        fin.close();
    }
    return count;
}

void AdditionalTask(string fileName) {
    ifstream fin;
    fin.open(fileName, ios::in);
    if (fin.is_open()) {
        int temp, n, i = 0, size = CountNumbers(fileName);
        int* numbers = new int[size];
        while (fin >> n) {
            numbers[i] = n;
            i++;
        }
        fin.close();
        int multiplier = numbers[0] + numbers[size-1];
        ofstream fout;
        fout.open("new_file.txt", ios::out);
        fin.open(fileName, ios::in);
        while (fin >> temp) {
            fout << temp * multiplier << " ";
        }
        if (fin.good() && fout.good()){
            fout.close();
            fin.close();
        }
        else {
            return;
        }
    }
    else {
        cout << "Файла с таким именем не существует" << endl;
    }
    fin.close();
}

int main() {
    system("chcp 1251 > null");
    int menu;
    string fileName;
    while (true) {
        inputMenu(menu);
        if (menu == 0) {
            cout << "Задание не выбрано\nВыход из программы..." << endl;
            break;
        }
        cout << endl;
        switch (menu) {
        case 1: {
            cout << "Введите имя файла: ";
            cin >> fileName;
            cin.ignore();
            cin.clear();
            CreateAndFillFile(fileName);
            break;
        }
        case 2: {
            cout << "Введите имя файла: ";
            cin >> fileName;
            cin.ignore();
            cin.clear();
            PrintFile(fileName);
            cout<< endl;
            break;
        }
        case 3: {
            cout << "Введите имя файла: ";
            cin >> fileName;
            cin.ignore();
            cin.clear();
            string lineToAppend;
            cout << "Введите строку, которую хотите добавить: ";
            cin.get();
            getline(cin, lineToAppend);
            AppendLine(fileName, lineToAppend);
            break;
        }
        case 4: {
            cout << "Введите имя файла: ";
            cin >> fileName;
            cin.ignore();
            cin.clear();
            int result = GetNumber(fileName);
            if (result == -1) {
                cout << "Число не может быть найдено" << endl << endl;
            }
            else {
                cout << "Число под требуемым индексом: " << result << endl << endl;
            }
            break;
        }
        case 5: {
            cout << "Введите имя файла: ";
            cin >> fileName;
            cin.ignore();
            cin.clear();
            int count = CountNumbers(fileName);
            if (count == -1) {
                cout << endl;
            }
            else {
                cout << "Количество чисел в файле: " << count << endl << endl;
            }
            break;
        }
        case 6: {
            cout << "Введите имя файла: ";
            cin >> fileName;
            cin.ignore();
            cin.clear();
            AdditionalTask(fileName);
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