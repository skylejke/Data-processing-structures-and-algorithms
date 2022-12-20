#include <iostream>
using namespace std;

template<typename T>
class List {
public:
	void f(List<T>& list, int k) {
		Node* temp1;
		Node* temp2;
		int c = 0;
		for (Node* i = head; i->pNext != nullptr; i = i->pNext) {
			if (c == k - 1) {
				temp1 = i;
			}
			if (c == list.GetSize() - 1) {
				temp2 = i;
			}
			c++;
		}
		temp2->pNext = head;
		head = temp1->pNext;
		temp1->pNext = nullptr;
	}
	List(); //конструктор
	~List(); //деструктор
	void pop_front(); //удаление первого элемента в списке
	void push_back(T data); //добавление элемента в конец списка
	void clear(); // очистить список
	int GetSize() { return size; } // получить количество елементов в списке
	T& operator[](const int index); // перегруженный оператор [] 
	void push_front(T data); //добавление элемента в начало списка
	void insert(T data, int index); //добавление элемента в список по указанному индексу
	void removeAt(int index); //удаление элемента в списке по указанному индексу
	void pop_back(); //удаление последнего элемента в списке
	void complete_list(List<T>& list, int size, int n); //заполнение списка
	void print_list(List<T>& list, int n); //вывод списка

private:
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int	size;
	Node<T>* head;
};




template<typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::clear() {
	while (size) {
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index){
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::pop_back() {
	removeAt(size - 1);
}

template<typename T>
void List<T>::complete_list(List<T>& list, int size, int n){
	T data;
	cout << "Ввод списка №" << n << ": ";
	for (int i = 0; i < size; i++) {
		cin >> data;
		list.push_back(data);
	}
}

template<typename T>
void List<T>::print_list(List<T>& list, int n) {
	cout << "Список №"<< n <<": ";
	for (int i = 0; i < list.GetSize(); i++) {
		cout << list[i] <<" ";
	}
	cout << endl;
}

template<typename T>
void push_back_before_list2_last(List<T>& list1, List<T>& list2) {
	list1.push_back(list2[list2.GetSize() - 1]);
}

template<typename T>
bool compare(List<T>& list1, List<T>& list2) {
	for (int i = 0; i < list1.GetSize(); i++) {
		if (list1[i] != list2[i]) {
			return false;
			break;
		}
	}
	return true;
}

template<typename T>
void delete_numbers(List<T>& list) {
	for (int i = 0; i < list.GetSize(); i++) {
		if (isdigit(list[i])) {
			list.removeAt(i);
		}
	}
}



int main() {
	setlocale(LC_ALL, "ru");
	int size, n=0;
	cout << "Введите размер списков: ";
	cin >> size;
	List<char> list1;
	List<char> list2;
	list1.complete_list(list1, size, 1);
	list1.print_list(list1, 1);
	list1.complete_list(list2, size, 2);
	list1.print_list(list2, 2);
	cout << "Введите номер задачи: " << endl;
	cout << "1) Проверка списков на равенство." << endl;
	cout << "2) Вставка в список №1 последнего элемента списка №2." << endl;
	cout << "3) Удаление из списка №2, узлов, содержащие цифровые значения." << endl;
	cin >> n;
	switch (n) {
	case 1: {
		if (compare(list1, list2)) {
			cout << "Списки равны" << endl;
		}
		else {
			cout << "Списки не равны" << endl;
		}
		break;
	}
	case 2: {
		push_back_before_list2_last(list1, list2);
		cout << endl << "Внесены изменения в список №1" << endl;
		list1.print_list(list1, 1);
		break;
	}
	case 3: {
		delete_numbers(list2);
		cout << endl << "Внесены изменения в список №2" << endl;
		list2.print_list(list2, 2);
		break;
	}
	default: {
		break;
	}
	}
	return 0;
}