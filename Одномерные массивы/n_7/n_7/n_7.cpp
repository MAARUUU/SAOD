#include <iostream>
#include "module.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размерность массива: ";
	cin >> n; // размер массива
	int *ptrarray = new int[n]; // выделение памяти для дим.массива

	dinamic_array(n, ptrarray);
	cout << "   " << endl;
	print_dinamic_array(n, ptrarray);
	cout << "   " << endl;
    int f=max_dinamic_array(n,ptrarray);
	cout << "   " << endl;
	cout << "Номер максимального элемента - " << f << endl;;
	cout << "   " << endl;
	int m = multiply_dinamic_array(n, ptrarray);
	cout << "Произведение элементов массива - " << m << endl;;
	cout << "   " << endl;
	transform_dinamic_array(n, ptrarray);
	cout << "   " << endl;
	delete[] ptrarray; // высвобождение памяти дим.массива

	cout << "-------------------------------------------" << endl;

	int o;
	cout << "Введите размерность массива: ";
	cin >> o; // размер массива
	float array[20];

	cout << "   " << endl;
	static_array(o, array);
	cout << "   " << endl;
	print_static_array(o, array);
	cout << "   " << endl;
	int h = number_zero_static_array(o, array);
	cout << h << endl;
	cout << "   " << endl;
	float ss = sum_static_array(o, array);
	cout << ss << endl;
	cout << "   " << endl;
	transform_static_array(o, array);
	cout << "   " << endl;

	system("pause");
	return 0;
}

