#include <iostream>
#include<iomanip>
#include<fstream>
#include "module.h"


using namespace std;


// метод, который заполняет  дин.массив
void dinamic_array(int n, int *array) 
{
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
}

// метод, который выводит дим.массива на экран + в файл
void print_dinamic_array(int n,int *array)
{
	ofstream fout("File.txt"); 
	fout << fixed << setprecision(3);
	cout << "Исходный массив: " << endl;
	fout << "Исходный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << "    ";
		fout << array[i] << "    ";
	}
	fout <<"   "<< endl;
	fout.close();
}


// метод, который занимается поиском номера максимального элемента массива + запись в файл
int max_dinamic_array(int n, int *array)
{
	int maxI;
	int max = array[0];
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);
	for (int i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			 maxI = i;
		}
	}
	fout << "   " << endl;
	fout << "Номер максимального элемента - "<<maxI<< endl;
	fout << "   " << endl;
	fout.close();
	return maxI;
}

// метод, который вычислять произведение элементов массива, расположенных между первым и вторым нулевыми элементами
// + запись в файл
int multiply_dinamic_array(int n, int *array)
{
	int multiply = 1;
	
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);

	for (int i = 0; i < n; i++)
		if (array[i] == 0 && i < n)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (array[j] == 0)
				{
					break;

				}
				multiply = multiply * array[j];
			}
			break;
			}
			
	fout << "Произведение элементов массива, расположенных между первым и вторым нулевыми элементами -  " << multiply<< endl;
	fout << "   " << endl;
	fout.close();
	return multiply;
}

// метод, преобразует массив таким образом, чтобы в первой его половине располагались элементы,
// стоявшие в нечетных позициях, а во второй половине ~элементы, стоявшие в четных позициях
// + запись в файл
void transform_dinamic_array(int n, int *array)
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3); 

	int *array1= new int[n];

	int count = 0;
	for (int i = 1; i < n; i++)
	{
		if ((i - 1) % 2 == 0)
		{
			array1[count] = array[i];
			count++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if ((i - 1) % 2 != 0)
		{
			array1[count] = array[i];
			count++;
		}
	}
	cout << "Полученный массив: " << endl;
	fout << "Полученный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << array1[i] << "   ";
		fout << array1[i] << "   ";
	}
	fout << "   " << endl;
	fout.close();
}



// метод, который заполняет массив
void static_array(int o, float array[20])
{
	for (int i = 0; i < o; i++)
	{
		cin >> array[i];
	}
}

// метод, который выводит массив на экран + запись в файл
void print_static_array(int o, float array[20])
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);
	fout << " ------------------------------------------------" << endl;
	fout << "   " << endl;
	cout << "Исходный массив: " << endl;
	fout << "Исходный массив: " << endl;
	for (int i = 0; i < o; i++)
	{
		cout << array[i] << "    ";
		fout << array[i] << "    ";
	}
	fout << "   " << endl;
	fout.close();
}

// метод, который находит количество элементов массива, равных 0
// запись в файл
int number_zero_static_array(int o, float array[20])
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);

	int k = 0;
	for (int i = 0; i < o; i++)
	{
		if (array[i] == 0) k++;
	}
	cout << "   " << endl;
	fout << "   " << endl;
	cout << "Количество элементов массива, равных 0 -  ";
	fout << "Количество элементов массива, равных 0 -  " << k;
	fout << "   " << endl;
	fout.close();
	return k;
}


// метод, который находит сумму элементов массива, расположенных после минимального элемента
// + запись в файл
float sum_static_array(int o, float array[20])
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);
	
	float min = array[0];
	float minIndex = 0;
	float sum = 0;
	for (int i = 0; i < o; i++)
	{
		if (min > array[i])
		{
			min = array[i];
			minIndex = i;
		}
	}
	for (int i = minIndex + 1; i < o; i++)
	{
		sum += array[i];
	}
	fout << "   " << endl;
	cout << "Сумма элементов массива, расположенных после минимального элемента - ";
	fout << "Сумма элементов массива, расположенных после минимального элемента - "<<sum<<endl;
	fout << "   " << endl;
	fout.close();
	return sum;
}

// метод, который располагает элементы массива по возрастанию модулей элементов + запись в файл
void transform_static_array(int o, float array[20])
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);

	float temp;
	cout << "Полученный массив: " << endl;
	fout << "Полученный массив: " << endl;
	for (int i = 0; i < o; i++)
	{
		for (int j = 0; j <= o - i; j++)
		{
			if (abs(array[j]) > abs(array[j + 1]))
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < o; i++)
	{
		cout << array[i] << " ";
		fout << array[i] << " ";
	}
	fout << "   " << endl;
	fout.close();
}

