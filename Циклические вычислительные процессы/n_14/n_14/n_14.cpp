#include <iostream>
#include "module.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	float a = 0, b = 0, c = 0, x_b = 0, x_e = 0, dx = 0, ans = 0;

	cout << "Введите x начальное - ";
	cin >> x_b;
	cout << "Введите x конечное - ";
	cin >> x_e;
	cout << "Введите шаг - ";
	cin >> dx;

	cout << "Введите a - ";  
	cin >> a;
	cout << "Введите b - ";  
	cin >> b;
	cout << "Введите c - ";  
	cin >> c;

	output(x_b, x_e, dx, a, b, c); // вывод данных на экран
	file_output(x_b, x_e, dx, a, b, c); // запись данных в файл
	calculation(a, b, c, x_b, x_e, dx); // расчеты + запись в файл
}
