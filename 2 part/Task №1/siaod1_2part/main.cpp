#include <iostream>
#include <string>
using namespace std;

string convert_to_bin(unsigned int num) {
	unsigned int t = 0x80000000;
	string result = "";
	if (num == 0) {
		return "0";
	}
	while (t > 0) {
		if (t & num) {
			result += "1";
		}
		else {
			result += "0";
		}
		t /= 2;
	}
	return result;
}

int inputMenu(int& number) {
	cout << "Введите номер задания" << endl;
	cout << "1) Установить заданные биты в значение 1(3-ий, 11 - ый, 5 - ый)" << endl;
	cout << "2) Обнулить заданные биты(Четыре младших бита)" << endl;
	cout << "3) Умножить значение целочисленной переменной на множитель(128)" << endl;
	cout << "4) Разделить значение целочисленной переменной на множитель(128)" << endl;
	cout << "5) Установить n-ый бит в 1, используя маску (вар 2)" << endl;
	while (1) {
		cout << "Введите число от 0 до 5: ";
		if ((cin >> number).good() && (number >= 0) && (number <= 5)) {
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

int inputNum(int& number) {
	while (1) {
		cout << "Введите исходное число: ";
		if ((cin >> number).good() && (number >= 0)) {
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

void third(int& numb, int& digit) {
	numb = numb << digit;
}

void fourth(int& numb, int& digit) {
	numb = numb >> digit;
}

void fifth(int& numb, unsigned int& mask, int& n) {
	mask = mask >> n;
	numb = numb | mask;
}

int main() {
	system("chcp 1251 > null");
	int menu, number, digit = 7;
	while (true) {
		inputMenu(menu);
		if (menu == 0) {
			cout << "Задание не выбрано\nВыход из программы..." << endl;
			break;
		}
		switch (menu) {
		case 1: {
			cout << "Выбрано 1-ое задание" << endl;
			inputNum(number);
			unsigned int mask = 2088;
			cout << "\n.................................................\n";
			cout << "number:" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec: " << dec << number;
			cout << "\n.................................................\n";
			cout << "mask:" << endl << "hex: " << mask << endl << "bin: " << convert_to_bin(mask) << endl << "dec: " << dec << mask;
			cout << "\n.................................................\n";
			cout << "result:" << endl << "hex: " << hex << (number | mask) << endl << "bin: " << convert_to_bin(number | mask) << endl << "dec: " << dec << (number | mask);
			cout << "\n.................................................\n";
			cout << endl;
			break;
		}
		case 2: {
			cout << "Выбрано 2-ое задание" << endl;
			inputNum(number);
			unsigned int mask = 0xFFFFFFF0;
			cout << "\n.................................................\n";
			cout << "number:" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec: " << dec << number;
			cout << "\n.................................................\n";
			cout << "mask:" << endl << "hex: " << hex << mask << endl << "bin: " << convert_to_bin(mask) << endl << "dec: " << dec << mask;
			cout << "\n.................................................\n";
			cout << "result:" << endl << "hex: " << hex << (number & mask) << endl << "bin: " << convert_to_bin(number & mask) << endl << "dec : " << dec << (number & mask);
			cout << "\n.................................................\n";
			cout << endl;
			break;
		}
		case 3: {
			cout << "Выбрано 3-ое задание" << endl;
			inputNum(number);
			cout << "\n.................................................\n";
			cout << "number before" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec: " << dec << number;
			third(number, digit);
			cout << "\n.................................................\n";
			cout << "number after" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec: " << dec << number;
			cout << "\n.................................................\n";
			cout << endl;
			break;
		}
		case 4: {
			cout << "Выбрано 4-ое задание" << endl;
			inputNum(number);
			cout << "\n.................................................\n";
			cout << "number before" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec : " << dec << number;
			fourth(number, digit);
			cout << "\n.................................................\n";
			cout << "number after" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec: " << dec << number;
			cout << "\n.................................................\n";
			cout << endl;
			break;
		}
		case 5: {
			cout << "Выбрано 5-ое задание" << endl;
			inputNum(number);
			int n;
			cout << "Введите n: ";
			cin >> n;
			unsigned int mask;
			mask = 0x80000000;
			cout << "\n.................................................\n";
			cout << "number before" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec: " << dec << number;
			fifth(number, mask, n);
			cout << "\n.................................................\n";
			cout << "number after" << endl << "hex: " << hex << number << endl << "bin: " << convert_to_bin(number) << endl << "dec: " << dec << number;
			cout << "\n.................................................\n";
			cout << endl;
			break;
		}
		default: {
			cout << "Задание не выбрано\nВыход из программы..." << endl;
			break;
			return 0;
		}
		}
		return 0;
	}
}