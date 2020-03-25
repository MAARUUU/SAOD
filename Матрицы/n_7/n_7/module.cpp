#include <iostream>
#include<iomanip>
#include<fstream>
#include "module.h"


using namespace std;

void dinamic_matrica(int **Arr, int n)
{
	ofstream fout("File.txt");
	fout << fixed << setprecision(3);
	cout << "Матрица: " << endl;
	fout << "Матрица: " << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			Arr[i][j] =  rand() % 11 - 3;
			cout << setw(6) << Arr[i][j] << ' ';
			fout << setw(6) << Arr[i][j] << ' ';
		}
		cout << endl;
		fout << endl;
	}
	cout << '\n';
	fout << "   " << endl;
	fout.close();
}

  void match_element(int **Arr, int n)
  {
	ofstream fout("File.txt", ios::app);
	fout << fixed << setprecision(3);

	int count=0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Arr[i][j] == Arr[j][i])
			{
				count++;
			}
			if (count == n)
			{
				cout << " \n " << i + 1 << " строка совпадает с " << i + 1 << " столбцом " << endl;
				fout << " \n " << i + 1 << " строка совпадает с " << i + 1 << " столбцом " << endl;
				k++;
			}
		}
		count = 0;
	}
	if (k == 0)
		cout << "\n\n Нет совпадающих строк и столбцов" << endl;
	    fout << "\n\n Нет совпадающих строк и столбцов" << endl;
	fout << "   " << endl;
	fout.close();
  }

  void sum_negative_element(int **Arr, int n)
  {
	  ofstream fout("File.txt", ios::app);
	  fout << fixed << setprecision(3);

	  int count,result = 0;
	  for (int i = 0; i < n; i++)
	  {
		  for (int j = 0; j < n; j++)
		  {
			  if (Arr[i][j] < 0)
			  {
				  for (count = 0; count < n; count++)
				  {
					  result += Arr[i][count];
				  }
				  cout << "\n Сумма элементов на " << i + 1 << " строке равна " << result << endl;
				  fout << "\n Сумма элементов на " << i + 1 << " строке равна " << result << endl;
				  j = n;
				  result = 0;
			  }
		  }
	  }
	  fout << "   " << endl;
	  fout.close();
  }


  void static_matrica(int (x)[][4])
  {
	  ofstream fout("File.txt", ios::app);
	  fout << fixed << setprecision(3);
	  fout << "---------------------------------- " << endl;

	  cout << "Матрица: " << endl;
	  fout << "Матрица: " << endl;
	  for (int i = 0; i < 4; ++i)
	  {
		  for (int j = 0; j < 4; ++j)
		  {
			  cout << setw(6) << x[i][j] << ' ';
			  fout << setw(6) << x[i][j] << ' ';
		  }
		  cout << endl;
		  fout << endl;
	  }
	  cout << '\n';
	  fout << "   " << endl;
	  fout.close();
  }


  void transform_matrica(int(x)[][4], int &step)
  {
	  ofstream fout("File.txt", ios::app);
	  fout << fixed << setprecision(3);

	  int cur[12], shift[12];
	  int edge,i,j,q=0;

	  fout << "   " << endl;
	  fout << "Количество шагов поворота - " << step<<endl;
	  fout << "   " << endl;

	  for (int i = 0; i < 4 / 2; i++) //слои
	  {
		  edge = 4 - 1 - i;

		  //снять слой      
		  int  c = 0;
		  for (int j = q; j < edge; j++)
		  {
			  cur[c] = x[q][j];
			  c++;
		  }
		  for (int i = q; i < edge; i++)
		  {
			  cur[c] = x[i][edge];
			  c++;
		  }
		  for (int j = edge; j >= q; j--)
		  {
			  cur[c] = x[edge][j];
			  c++;
		  }
		  for (int i = edge - 1; i > q; i--)
		  {
			  cur[c] = x[i][q];
			  c++;
		  }
		  //переставить
		  for (int i = 0; i < 4 * (4 - 2 * q - 1); i++)
			  shift[(i + step) % (4 * (4 - 2 * q - 1))] = cur[i];

		  //одеть слой       
		  c = 0;
		  for (int j = q; j < edge; j++)
		  {
			  x[q][j] = shift[c];
			  c++;
		  }
		  for (int i = q; i < edge; i++)
		  {
			  x[i][edge] = shift[c];
			  c++;
		  }
		  for (int j = edge; j >= q; j--)
		  {
			  x[edge][j] = shift[c];
			  c++;
		  }
		  for (int i = edge - 1; i > q; i--)
		  {
			  x[i][q] = shift[c];
			  c++;
		  }
	  }

      //Результат
	  cout << "Полученная матрица: " << endl;
	  fout << "Полученная Матрица: " << endl;
	  for (int i = 0; i < 4; ++i)
	  {
		  for (int j = 0; j < 4; ++j)
		  {
			  cout << setw(6) << x[i][j] << ' ';
			  fout << setw(6) << x[i][j] << ' ';
		  }
		  cout << endl;
		  fout << endl;
	  }
	  cout << '\n';
	  fout << "   " << endl;
	  fout.close();
  }
