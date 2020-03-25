// задача 7
// Для заданной матрицы размером 8 на 8 найти такие k, что k-ая строка матрицы совпадает с k-ым столбцом.
// Найти сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент.

#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "module.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	const int n = 8;
	int **Arr = new int*[n];
	for (int i = 0; i < n; ++i)
	Arr[i] = new int[n];

	dinamic_matrica(Arr, n);
	match_element(Arr, n);
	sum_negative_element(Arr, n);
	delete[]Arr;

	cout << " ------------------------------------------------" << endl;

	// задача 14
	// Осуществить циклический сдвиг элементов квадратной матрицы размерности
	// MxN вправо на k элементов таким образом : элементы 1 - й строки сдвигаются в
	//	последний столбец сверху вниз, из него — в последнюю строку справа налево, из
	//	нее — в первый столбец снизу вверх, из него — в первую строку; для остальных
	//	элементов — аналогично
	
	int step;
	static int A[4][4] = {{1, 8, 2, 9},
						  {9, 2, 3, 1},
						  {1, 3, 3, 6},
						  {4, 7, 4, 5}};

	static_matrica(A);

	cout << "Введите количество шагов поворота - ";
	cin >> step;
	transform_matrica(A, step);

	return 0;
}