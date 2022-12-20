#include <iostream>
#include <vector>
using namespace std;
//Ввод элементов
void Fill(vector<vector<int>>& points1, vector<vector<int>>& points2)
{
    for (int i = 0; i < points1.size(); i++)
    {
        points1[i].resize(2);
        cout << "Введи координаты [" << i + 1 << "] точки первого множества >> ";
        cin >> points1[i][0] >> points1[i][1];
    }

    for (int i = 0; i < points2.size(); i++)
    {
        points2[i].resize(2);
        cout << "Введи координаты [" << i + 1 << "] точки второго множества >> ";
        cin >> points2[i][0] >> points2[i][1];
    }
}
//Вывод 
void Print(vector<vector<int>>& points1, vector<vector<int>>& points2)
{
    cout << "\nМножество 1" << endl;
    for (int i = 0; i < points1.size(); i++)
    {
        cout << "[" << i + 1 << "]: " << points1[i][0] << ";" << points1[i][1] << endl;
    }
    cout << endl;

    cout << "Множество 2" << endl;
    for (int i = 0; i < points2.size(); i++)
    {
        cout << "[" << i + 1 << "]: " << points2[i][0] << ";" << points2[i][1] << endl;
    }
    cout << endl;
}
//Проверка принадлежности точки к треугольнику
bool Belong(int x1, int y1, int x2, int y2, int x3, int y3, int x0, int y0)
{
    int res1 = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int res2 = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int res3 = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);

    if ((res1 >= 0 && res2 >= 0 && res3 >= 0) || (res1 <= 0 && res2 <= 0 && res3 <= 0)) return true;
    else return false;
}


int main()
{
    setlocale(LC_ALL, "rus");

    vector<vector<int>> points1;
    vector<vector<int>> points2;
    int size1, size2;
    cout << "Количество точек первого множества >> ";
    cin >> size1;
    points1.resize(size1);

    cout << "Количество точек второго множества >> ";
    cin >> size2;
    points2.resize(size2);


    Fill(points1, points2);
    Print(points1, points2);
    cout << endl;

}