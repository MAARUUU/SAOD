#include <iostream>
#include<iomanip>
#include<fstream>
#include "module.h"


using namespace std;


//проверка на  условия + расчеты
float f(float a, float x, float b, float c) 
{
	if ((x+c < 0) && (a != 0))
	{
		return (((-1)*a* pow(x, 3)) - b);
	}
	else  if ((x + c > 0) && (a == 0)) 
	    {
			return ((x - a) / (x - c));
		}
		else 
	    {
			return ((x / c) + (c / x));
		}
}



// условие на действительное значение
// Если срабатывает, то функция принимает действительное значение
// Иначе целые
float if_f(float a, float b, float c, float x) 
{
	int a1 = 0, b1 = 0, c1 = 0;
	a1 = trunc(a);
	b1 = trunc(b);
	c1 = trunc(c);

	if ((a1 ^ b1) | (a1 ^ c1))
	{
		return f(a, x, c, b);
	}
	else
	{
		return f(a1, x, c1, b1);
	}

}


// расчеты + запись в файл
//считается до 3-го знака
void calculation(float a, float b, float c, float x_b, float x_e, float dx) 
{
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);
	do
	{
		float ans = if_f(a, b, c, x_b);
		cout << setw(3) << x_b << setw(9) << ans << endl;  
		fout << setw(3) << x_b << setw(9) << ans << endl;
		x_b += dx;
	} while (x_b < x_e);

}


// вывод данных на экран
void output(float x_b, float x_e, float dx, float a, float b, float c)
{
	int k = 7;
	system("cls");
	cout << fixed << setprecision(3);
	cout << "X-начальное " << "  " << " X-конечное " << "  " << " шаг dx " << "  " << " A " << setw(8) << " B " << setw(8) << " C " << endl;
	cout << setw(8) << x_b << setw(13) << x_e << setw(13) << dx << setw(9) << a << setw(8) << b << setw(8) << c << endl;
	cout << endl << setw(2) << "X" << setw(k) << "F" << endl;

}


// запись данных в файл
void file_output(float x_b, float x_e, float dx, float a, float b, float c)
{
	int k = 7;
	ofstream fout("File.txt");
	fout << fixed << setprecision(3);
	fout << "X-начальное " << "  " << " X-конечное " << "  " << " шаг dx " << "  " << " A " << setw(8) << " B " << setw(8) << " C " << endl;
	fout << setw(8) << x_b << setw(13) << x_e << setw(13) << dx << setw(9) << a << setw(8) << b << setw(8) << c << endl;
	fout << endl << setw(2) << "X" << setw(k) << "F" << endl;
	fout.close();
}