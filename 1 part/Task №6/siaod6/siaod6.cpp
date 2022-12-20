#include <iostream>
using namespace std;
template<typename T>
class stack {
public:
    stack() {
        size = 0;
        top = nullptr;
    }

    int GetSize() { return size; }

    void push(int size) {
        if (size != 0) {
            Node* temp;
            temp = new Node();
            cout << "Enter element: ";
            int info; cin >> info;
            temp->data = info;
            temp->link = top;
            top = temp;
            push(size - 1);

        }
        else {
            return;
        }
    }

    void print() {
        Node* temp;
        temp = top;
        cout << "Stack: " << endl;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->link;
        }
    }

private:
    struct Node {
    public:
        Node() {};
        Node(int data, Node* link = nullptr) {
            this->data = data;
            this->link = link;
        }
        int data=0;
        Node* link = nullptr;
    };
    int	size;
    Node* top;
};

void input_arr(double* arr, int n) {
    if (n == 0) {
        cout << "Невозможно ввести элементы, т.к размер массива = 0!" << endl;
    }
    else {
        cout << "Введите элементы массива: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
}

void print_arr(double* arr, int n) {
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double average(double* arr, int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return arr[n - 1];
    }
    else {
        return ((n - 1) * average(arr, n - 1) + arr[n - 1]) / n;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int menu;
    cout << "Введите номер задачи: " << endl;
    cout << "1-Вычисление среднего значения вещественного массива из n элементов." << endl;
    cout << "2-Создание связанного стека из n элементов." << endl;
    cin >> menu;
    switch (menu) {
    case 1: {
        int size;
        cout << "Введите размер массива: ";
        cin >> size;
        double* arr = new double[size];
        if (size <= 0) {
            input_arr(arr, size);
            break;
        }
        else {
            input_arr(arr, size);
            print_arr(arr, size);
            cout << "Среднее значение массива = " << average(arr, size) << endl;;
            break;
        }
    }
    case 2: {
        int size;
        cout << "Enter stack size ";
        cin >> size;
        stack<int> stack;
        stack.push(size);
        if (size == 0) {
            cout << "Stack size = 0" << endl;
        }
        else {
            stack.print();
        }
        break;
    }
    default: {
        break;
    }
    }
    return 0;
}