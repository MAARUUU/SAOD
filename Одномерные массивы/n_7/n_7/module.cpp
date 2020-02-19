#include <iostream>
#include<iomanip>
#include<fstream>
#include "module.h"


using namespace std;


// �����, ������� ���������  ���.������
void dinamic_array(int n, int *array) 
{
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
}

// �����, ������� ������� ���.������� �� ����� + � ����
void print_dinamic_array(int n,int *array)
{
	ofstream fout("File.txt"); 
	fout << fixed << setprecision(3);
	cout << "�������� ������: " << endl;
	fout << "�������� ������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << "    ";
		fout << array[i] << "    ";
	}
	fout <<"   "<< endl;
	fout.close();
}


// �����, ������� ���������� ������� ������ ������������� �������� ������� + ������ � ����
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
	fout << "����� ������������� �������� - "<<maxI<< endl;
	fout << "   " << endl;
	fout.close();
	return maxI;
}

// �����, ������� ��������� ������������ ��������� �������, ������������� ����� ������ � ������ �������� ����������
// + ������ � ����
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
			
	fout << "������������ ��������� �������, ������������� ����� ������ � ������ �������� ���������� -  " << multiply<< endl;
	fout << "   " << endl;
	fout.close();
	return multiply;
}

// �����, ����������� ������ ����� �������, ����� � ������ ��� �������� ������������� ��������,
// �������� � �������� ��������, � �� ������ �������� ~��������, �������� � ������ ��������
// + ������ � ����
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
	cout << "���������� ������: " << endl;
	fout << "���������� ������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << array1[i] << "   ";
		fout << array1[i] << "   ";
	}
	fout << "   " << endl;
	fout.close();
}



// �����, ������� ��������� ������
void static_array(int o, float array[20])
{
	for (int i = 0; i < o; i++)
	{
		cin >> array[i];
	}
}

// �����, ������� ������� ������ �� ����� + ������ � ����
void print_static_array(int o, float array[20])
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);
	fout << " ------------------------------------------------" << endl;
	fout << "   " << endl;
	cout << "�������� ������: " << endl;
	fout << "�������� ������: " << endl;
	for (int i = 0; i < o; i++)
	{
		cout << array[i] << "    ";
		fout << array[i] << "    ";
	}
	fout << "   " << endl;
	fout.close();
}

// �����, ������� ������� ���������� ��������� �������, ������ 0
// ������ � ����
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
	cout << "���������� ��������� �������, ������ 0 -  ";
	fout << "���������� ��������� �������, ������ 0 -  " << k;
	fout << "   " << endl;
	fout.close();
	return k;
}


// �����, ������� ������� ����� ��������� �������, ������������� ����� ������������ ��������
// + ������ � ����
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
	cout << "����� ��������� �������, ������������� ����� ������������ �������� - ";
	fout << "����� ��������� �������, ������������� ����� ������������ �������� - "<<sum<<endl;
	fout << "   " << endl;
	fout.close();
	return sum;
}

// �����, ������� ����������� �������� ������� �� ����������� ������� ��������� + ������ � ����
void transform_static_array(int o, float array[20])
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);

	float temp;
	cout << "���������� ������: " << endl;
	fout << "���������� ������: " << endl;
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

