#include <iostream>
#include <vector>
using namespace std;
int max_size = 100;

struct Airport {
    char destination[30]; //Пункт назначения
    int flight_num; //Номер рейса
    char departure_day[10]; //День вылета
    int departure_time; //Время вылета
    int arrival_time; //Время прибытия
    int free_seats; // Кол-во свободных мест
    int delay; // Информация о задержке вылета в часах
};

void inputOneRecord(Airport& r) {
    cout << "----Вставка инфорармации по рейсу----" << endl;
    cout << "Пункт назначения: "; cin >> r.destination;
    cout << "Номер рейса: "; cin >> r.flight_num;
    cout << "День вылета: "; cin >> r.departure_day;
    cout << "Время вылета: "; cin >> r.departure_time;
    cout << "Время прибытия: "; cin >> r.arrival_time;
    cout << "Кол-во свободных мест: "; cin >> r.free_seats;
    cout << "Информация о задержке вылета в часах: "; cin >> r.delay;
    cout << "-------------------------------------" << endl;
}

void outputOneRecord(Airport r) {
    cout << "Пункт назначения: "; cout << r.destination << endl;
    cout << "Номер рейса: "; cout << r.flight_num << endl;
    cout << "День вылета: "; cout << r.departure_day << endl;
    cout << "Время вылета: "; cout << r.departure_time << endl;
    cout << "Время прибытия: "; cout << r.arrival_time << endl;
    cout << "Кол-во свободных мест: "; cout << r.free_seats << endl;
    cout << "Информация о задержке вылета в часах: "; cout << r.delay << endl;
}

void insertRecord(vector<Airport>&r, int i) {
    inputOneRecord(r[i]);
}

void outBoard(vector<Airport>& r, int i) {
    outputOneRecord(r[i]);
}

void insertRecordBeforeMax(vector<Airport>& r, int n, Airport newelement) {
    int max = 0;
    Airport temp, sdvig;
    for (int i = 0; i < n; i++) {
        if (r[i].flight_num > max) {
            max = r[i].flight_num;
        }
    }
    for (int i = 0; i < n; i++) {
        if (r[i].flight_num == max) {
            temp = r[i];
            r[i] = newelement;
            for (int j = i + 1; j < n + 1; j++) {
                sdvig = r[j];
                r[j] = temp;
                temp = sdvig;
                i++;
            }
        }
    }
}

void deleteLeft(vector<Airport>& r, vector<Airport>& ar, int n, int time) {
    int j = 0, k = 0, x;
    for (int i = 0; i < n; i++) {
        if (time - r[i].departure_time >= 0) {
            ar[j] = r[i];
            j++;
        }
        else {
            r[k] = r[i];
            k++;
        }
    }
    cout << "Желаете вывести таблицу?" << endl
        << "1-Архивная таблица" << endl
        << "2-Изменное табло" << endl
        << "Другое значение - выход" << endl;
    cin >> x;
    switch (x)
    {
    case 1: {
        cout << endl << "----Архивная таблица------" << endl;
        for (int i = 0; i < j; i++) {
            cout << "----Информация по рейсу №" << i + 1 << "----" << endl;
            outBoard(ar, i);
            cout << "--------------------------------" << endl;
        }
        break;
    }
    case 2: {
        for (int i = 0; i < k; i++) {
            cout << "----Информация по рейсу №" << i + 1 << "----" << endl;
            outBoard(r, i);
            cout << "--------------------------------" << endl;
        }
        break;
    }
    default: {
        break;
    }
    }
}

void outputReady(int time, vector<Airport>& r, int n) {
    for (int i = 0; i < n; i++) {
        if (r[i].departure_time - time == 2) {
            cout << "----Рейс №" << i + 1 << " готов к вылету по расписанию----" << endl;
            outputOneRecord(r[i]);
            cout << "------------------------------------------------" << endl;
        }
        else {
            cout << "Нет рейсов, которые готовы вылететь." << endl;
        }
    }
}

void outputGivenDestination(char s[], int n, vector<Airport>& r) {
    for (int i = 0; i < n; i++) {
        if (strcmp(r[i].destination, s) == 0) {
            cout << "----Рейс №" << i + 1 << " вылетает в заданный пункт назначения----" << endl;
            outputOneRecord(r[i]);
            cout << "------------------------------------------------" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n, y;
    cout << "Введите количеcтво рейсов: "; cin >> n;
    vector<Airport> info(max_size);
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            insertRecord(info, i);
        }
    }
    else {
        cout << "n должно быть больше нуля";
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        cout << "----Информация по рейсу №" << i + 1 << "----" << endl;
        outBoard(info, i);
        cout << "--------------------------------" << endl;
    }
    povtor: // метка для goto
    cout << "Введите номер задачи:" << endl
        << "1)Вставить информацию по новому рейсу в таблицу перед рейсом с большим номером." << endl
        << "2)Удалить информацию о вылетевшем рейсе и сохранить ее в архивной таблице." << endl
        << "3)Вывести рейсы, готовые к вылету по расписанию (за 2 часа до времени вылета)." << endl
        << "4)Сформировать список номеров рейсов, вылетающих в заданный пункт назначения." << endl;
    cout << "Номер: "; cin >> y;
    switch (y) {
    case 1: {
        Airport newflight;
        cout << "Введите информацию по новому рейсу" << endl;
        inputOneRecord(newflight);
        insertRecordBeforeMax(info, n, newflight);
        cout << endl << "-----Новое табло-----" << endl;
        for (int i = 0; i < n + 1; i++) {
            cout << "----Информация по рейсу №" << i + 1 << "----" << endl;
            outBoard(info, i);
            cout << "--------------------------------" << endl;
        }
        int q;
        cout << "Продолжить? 1 - да 0 - нет: ";
        cin >> q;
        if (q == 1) {
            goto povtor; //152 строка в main
        }
        else {
            exit(0);
        }
        break;
    }
    case 2: {
        int current_time;
        cout << "Введите текущее время (в часах): "; cin >> current_time;
        vector<Airport> archive(max_size);
        deleteLeft(info, archive, n, current_time);
        int q;
        cout << "Продолжить? 1 - да 0 - нет: ";
        cin >> q;
        if (q == 1) {
            goto povtor; //152 строка в main
        }
        else {
            exit(0);
        }
        break;
    }
    case 3: {
        int current_time;
        cout << "Введите текущее время (в часах): "; cin >> current_time;
        outputReady(current_time, info, n);
        int q;
        cout << "Продолжить? 1 - да 0 - нет: ";
        cin >> q;
        if (q == 1) {
            goto povtor; //152 строка в main
        }
        else {
            exit(0);
        }
        break;
    }
    case 4: {
        char given_destination[30];
        cout << "Введите пункт назначения: "; cin >> given_destination;
        outputGivenDestination(given_destination, n, info);
        int q;
        cout << "Продолжить? 1 - да 0 - нет: ";
        cin >> q;
        if (q == 1) {
            goto povtor; //152 строка в main
        }
        else {
            exit(0);
        }
        break;
    }
    default: {
        cout << "Нет такой задачи, соответсвующей введенному вами номером" << endl;
        int q;
        cout << "Продолжить? 1 - да 0 - нет: ";
        cin >> q;
        if (q == 1) {
            goto povtor; //152 строка в main
        }
        else {
            exit(0);
        }
        break;
    }
    }
    return 0;
}