#include "pch.h"
#include <iostream>
#include "Baag.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");

	Baag n(3,4,"Blue");

	Baag m;
	m.set_book(5);
	int f = m.get_book();
	cout <<"Количество книг - "<< f << endl;
	m.set_color("Green");
	cout <<"Цвет сумки - "<< m.get_color() << endl;
	m.set_pen(2);
	cout << "Количество письменных принадлежностей - "<<m.get_pen() << endl;
    
	system("pause");
}

