// задача 6
// написать функцию умножения двух чисел, используя только операцию сложения

#include "pch.h"
#include <iostream>
#include<iomanip>
#include<fstream>


using namespace std;

int mul(int n, int  m)
{
	if (m == 0)
		return 0;

	return (n + mul(n, m - 1));
}

int vvod(int n)
{
	cout << " введите число " << endl;
	cin >> n;
	return n;
}

void print(int n, int  m)
{
	cout << n << "*" << m << "=" << mul(n, m) << endl;
}

void file(int n, int  m)
{
	ofstream fout("File.txt", ios::app);

	fout << "n= " << n << endl << "m=  " << m << endl;
	fout << "n*m= " << mul(n, m) << endl;
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0, m = 0;
	n = vvod(n);
	m = vvod(m);
	print(n, m);
	file(n, m);
	system("pause");
}


