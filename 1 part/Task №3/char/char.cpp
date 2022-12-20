#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int len = 1024;
bool check89(int a) { // проверка наличия цифр 8 или 9 в числе
	bool check = true;
	while (a != 0) {
		if (a % 10 == 9 or a % 10 == 8) {
			check = false;
			break;
		}
		else {
			a = a / 10;
		}
	}
	return check;
}
int OctalToDecimal(int n) { // функция перевода из восьмеричной в десятичную систему счисления
		int p = 0, decimal = 0, r;
	while (n > 0) {
		r = n % 10;
		n = n / 10;
		decimal = decimal + r * pow(8, p);
		++p;
	}
	return decimal;
}
void proposal_processing(char s[], vector<int>& numbers) { // обработка предложения и добавление чисел в массив
		int num = 0;
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			num = (num * 10) + (s[i] - '0');
		}
		else {
			if (num > 0) {
				numbers.push_back(num);
				num = 0;
			}
		}
	}
	if (num > 0) {
		numbers.push_back(num);
	}
}
void array_processing_and_output(vector<int>& numbers) { // обработка и вывод массива
	int j = 0, k = 0;
	for (int i = 0; i < (int)numbers.size(); i++) {
		if (check89(numbers[i])) {
			numbers[j] = OctalToDecimal(numbers[i]);
			j++;
			k++;
		}
	}
	cout << "Массив из чисел восьмеричного кода, элеменеты которого предварительно переведены в десятичную систему счисления : " << endl;
		for (int i = 0; i < k; i++) {
			cout << "numbers[" << i << "] = " << numbers[i] << endl;
		}
}
int main() {
	setlocale(LC_ALL, "rus");
	char s[len] = { '\0' };
	cout << "Введите предложение" << endl;
	cin.getline(s, len);
	vector<int>n;
	proposal_processing(s, n);
	array_processing_and_output(n);
	return 0;
}
