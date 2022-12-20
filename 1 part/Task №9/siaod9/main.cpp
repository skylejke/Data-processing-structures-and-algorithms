#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <iomanip>
using namespace std;

struct Patient {
    Patient() {

    }
    Patient(int card_number, int chronic_disease_code, string surname_of_the_doctor) {
        this->card_number = card_number;
        this->chronic_disease_code = chronic_disease_code;
        this->surname_of_the_doctor = surname_of_the_doctor;
    }
    int card_number=0; //ключ
    int chronic_disease_code=0;
    string surname_of_the_doctor = "-";
};

void Fill(Patient* table, long int size) {
    //Фамилии врачей
    string surnames[7] = { "Демин","Шмаков","Черняков", "Ботоев", "Хоров", "Леухин", "Чернышов" };
    for (int i = 0; i < size; i++) {
        table[i].card_number = 10+rand() % 90;
        table[i].chronic_disease_code = rand() % 10;
        table[i].surname_of_the_doctor = surnames[rand() % 7];
    }
}

void Print(Patient* table, long int size) {
    cout << endl << setw(20) << "  " << "Таблица пациетов поликлиники" << setw(25) << "  " << endl << endl;
    cout << "Номер карточки " << setw(5) << " " << "Код хронического заболевания " << setw(5) << " " << "Фамилия лечащего врача" << endl << endl;
    for (long int i = 0; i < size; i++) {
        cout << setw(5) << " "<<table[i].card_number << setw(25) << " " << table[i].chronic_disease_code << setw(25) << " " << table[i].surname_of_the_doctor << endl;
    }
}

void PrintOne(Patient obj) {
    if (obj.card_number == 0) {
        cout << setw(25) << "  " << "Запись не найдена" << setw(25) << "  " << endl << endl;
    }
    else {
        cout << setw(25) << "  " << "Запись найдена" << setw(25) << "  " << endl << endl;
        cout << "Номер карточки " << setw(5) << " " << "Код хронического заболевания " << setw(5) << " " << "Фамилия лечащего врача" << endl << endl;
        cout << setw(5) << " " << obj.card_number << setw(25) << " " << obj.chronic_disease_code << setw(25) << " " << obj.surname_of_the_doctor << endl;
    }
}

Patient FindLineal(int key, Patient* table, long int size) {
    Patient nullpatient;
    for (int i = 0; i < size; i++) {
        if (table[i].card_number == key) {
            return table[i];
        }
    }
    return nullpatient;
}

Patient FindWithBarier(int key, Patient* table, long int size) {
    table[size].card_number = key;
    int i = 0;
    while (table[i].card_number != key) {
        i++;
    }
    return table[i];

}

Patient interpolationSearch(int key, Patient* table, int size) {
    Patient nullpatient;
    //объявляем необходимые локальные переменные
    //изначально устанавливаем нижний индекс на начало массива, а верний на конец массива
    int low = 0;
    int high = size - 1;
    int mid;
    //цикл интерполирующего поиска
    while (table[low].card_number < key && table[high].card_number >= key) {
        //интерполирующий поиск производит оценку новой области поиска
        //по расстоянию между ключом поиска и текущим значение элемента
        mid = low + ((key - table[low].card_number) * (high - low)) / (table[high].card_number - table[low].card_number);
        //если значение в ячейке с индексом mid меньше, то смещаем нижнюю границу
        if (table[mid].card_number < key)
            low = mid + 1;
        //в случае, если значение больше, то смещаем верхнюю границу
        else if (table[mid].card_number > key)
            high = mid - 1;
        //если равны, то возвращаем индекс
        else
            return table[mid];
    }
    //если цикл while не вернул индекс искомого значения,
    //то проверяем не находится ли оно в ячейке массива с индексом low,
    //иначе возвращаем -1 (значение не найдено)
    if (table[low].card_number == key)
        return table[low];
    else
        return nullpatient;
}

int main() {
    system("chcp 1251 > null");
    long int size; cout << "Кол-во записей в таблице: "; cin >> size;
    Patient* table=new Patient[size];
    Fill(table,size);
    Print(table, size);
    cout << endl;
    int num; cout << "Какой вариант поиска ключа нужно использовать" << endl;
    cout << "1 - Линейный поиск (метод грубой силы)" << endl;
    cout << "2 - Поиск с барьером" << endl;
    cout << "3 - Интерполяционный поиск" << endl << endl;
    cin >> num;
    int key; 
    switch (num) {
    case 1:{
        cout << endl << "Ключ (номер карточки): "; cin >> key; cout << endl;
        PrintOne(FindLineal(key, table, size));
        break;
    }
    case 2: {
        cout << endl << "Ключ (номер карточки): "; cin >> key; cout << endl;
        PrintOne(FindWithBarier(key, table, size));
        break;
    }
    case 3: {
        cout << endl << "Ключ (номер карточки): "; cin >> key; cout << endl;
        PrintOne(interpolationSearch(key, table, size));
        break;
    }
    default: {
        cout << "Нет такого номера варианта поиска ключа" << endl;
        break;
    }
    }
    return 0;
}

