#include <iostream>
using namespace std;
void fillmatrix(int **matrix, int n, int m) {
	int y;
	cout << "Как вы желаете заполнить матрицу?" << endl << "1 - Датчиком случайных чисел" << endl << "2 - C клавиатуры" << endl;
	cin >> y;
	switch (y) {
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
				cout << "Введите " << i + 1 << j + 1 << " элемент матрицы: ";
				cin >> matrix[i][j];
			}
		}
		break;
	}
	}
}
void showmatrix(int **matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}
void matrix_multiplication(int **matrix1, int **matrix2, int n, int m) {
	int** newmatrix=new int*[n];
	for (int i = 0; i < n; i++) {
		newmatrix[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			newmatrix[i][j] = 0;
			for (int k = 0; k < m; k++)
				newmatrix[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}
	showmatrix(newmatrix, n, m);
}
int main()
{
	setlocale(LC_ALL, "rus");
	int n1, m1, n2, m2;
	cout << "Операция умножения двух матриц выполнима только в том случае, если число столбцов в первом сомножителе равно числу строк во втором!" << endl;
	cout << "Введите количество строк в матрице 1: ";
	cin >> n1;
	cout << "Введите количество столбцов в матрице 1: ";
	cin >> m1;
	if (n1 <= 0 or m1 <= 0) {
		cout << "Количество строк и столбцов > 0";
		return 1;
	}
	int** matrix1 = new int*[n1];
	for (int i = 0; i < n1; i++) {
		matrix1[i] = new int[m1];
	}
	fillmatrix(matrix1, n1, m1);
	cout << "Матрица 1: " << endl;
	showmatrix(matrix1, n1, m1);
	cout << "Введите количество строк в матрице 2: ";
	cin >> n2;
	cout << "Введите количество столбцов в матрице 2: ";
	cin >> m2;
	if (n2 <= 0 or m2 <= 0) {
		cout << "Количество строк и столбцов > 0";
		return 1;
	}
	int** matrix2 = new int* [n2];
	for (int i = 0; i < n2; i++) {
		matrix2[i] = new int[m2];
	}
	fillmatrix(matrix2, n2, m2);
	cout << "Матрица 2: " << endl;
	showmatrix(matrix2, n2, m2);
	if (m1 != n2){
		cout << "Умножение невозможно, потому что число столбцов в первом сомножителе не равно числу строк во втором!";
		return 0;
	}
	else {
		cout << "Результат произведения матрицы 1 на матрицу 2: " << endl;
		matrix_multiplication(matrix1, matrix2, n1, m2);
	}
	return 0;
}