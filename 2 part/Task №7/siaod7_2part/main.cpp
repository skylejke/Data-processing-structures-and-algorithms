//Дано прямоугольное поле размером n*m клеток.
//Можно совершать шаги длиной в одну клетку 
//вправо, вниз или по диагонали вправо вниз.
//В каждой клетке записано некоторое
//натуральное число.Необходимо попасть из
//верхней левой клетки в правую нижнюю.
//Вес маршрута вычисляется как сумма чисел со
//всех посещенных клеток.Необходимо найти
//маршрут с минимальным весом.


#include <iostream>
using namespace std;

void fillmatrix(int** matrix, int n, int m) {
	int choice;
	cout << "How would you like to fill in the matrix?" << endl << "1 - Random number generator" << endl << "2 - From the keyboard" << endl;
	cout << ">> ";  cin >> choice;
	switch (choice) {
	case 1: {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matrix[i][j] = rand() % 100;
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << "Enter " << i + 1 << j + 1 << " matrix element >> ";
				cin >> matrix[i][j];
			}
		}
		break;
	}
	}
}

void showmatrix(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

int minCost(int** matrix, int n, int m) {

	// for 1st column
	for (int i = 1; i < n; i++) {
		matrix[i][0] += matrix[i - 1][0];
	}

	// for 1st row
	for (int j = 1; j < m; j++) {
		matrix[0][j] += matrix[0][j - 1];
	}

	// for rest of the 2d matrix
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
		}
	}

	// returning the value in last cell
	return matrix[n - 1][m - 1];
}

int main() {
	system("chcp 1251 > null");
	int n, m;
	cout << "n >> ";
	cin >> n;
	cout << "m >> ";
	cin >> m;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
	fillmatrix(matrix, n, m);
	cout << "--------------------------" << endl;
	cout << "Matrix: " << endl;
	showmatrix(matrix, n, m);
	cout << "--------------------------" << endl;
	cout << "Minimum cost from (0,0) to (n,m) is " << minCost(matrix, n, m) << endl;
	cout << "--------------------------" << endl;
	return 0;
}
