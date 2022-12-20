#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 2; // максимальное кол-во чисел в очереди - 2

struct queue {
private:
	int array[MAX] = {};
public:
	queue() { // конструктор
		size = 0;
	}
	~queue() { // деструктор
		this->pop();
		this->pop();
	}
	void push_back(int x); // метод заноса элемента в очереди
	int pop(); // метод вытаскивания последнего элемента из очереди
	int size; // поле размера стека
};

int queue::pop() { // функция 'вытягивания' последнего элемента очереди
	if (size == 0) return 0; // проверка на размер очереди
	int data = array[0]; // запоминаем значение последнего элемента
	array[0] = array[1];
	array[1] = 0;
	size--; // уменьшаем размер очереди
	return data; // возвращаем сохраненное значение
}

void queue::push_back(int x) { // обычный занос в очереди
	array[size] = x; // присваиваем последней ячейке (по размеру) значение x
	size++; // увеличиваем размер стэка
}

int SolutionOfInfixForm(string infix, queue& mystack) {
	char operation = '\n'; // переменная, хранящяя знак операции над числами
	for (int i = 0; i < infix.size(); i++) {
		if ('0' <= infix[i] and infix[i] <= '9') {
			mystack.push_back(infix[i] - '0');
			if (mystack.size == 2) { // если кол-во чисел в очереди уже 2
			
				if (operation == '+')
					mystack.push_back(mystack.pop() + mystack.pop());
				if (operation == '-')
					mystack.push_back(mystack.pop() - mystack.pop());
				if (operation == '/')
					mystack.push_back(mystack.pop() / mystack.pop());
				if (operation == '*')
					mystack.push_back(mystack.pop() * mystack.pop());
			}
		}
		else {
			if (infix[i] != '(' and infix[i] != ')') { // проверяем на то, что не сохраняем скобки
				operation = infix[i]; // запоминаем операцию
			}
		}
	}
	return mystack.pop(); // в конце возвращаем полученное число из стека
}

int main() {
	setlocale(LC_ALL, "");
	queue mystack;
	string infix;
	cout << "Введите выражение в инфиксной форме:  ";
	cin >> infix;
	cout << "Значение выражения:  " << SolutionOfInfixForm(infix, mystack) << endl;
}
