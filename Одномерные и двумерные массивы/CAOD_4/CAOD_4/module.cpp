#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "module.h"

using namespace std;


typedef struct tag_point
{
	int x;
	int y;
} Point;

Point* fiSet;
Point* seSet;

int Q(int ax, int ay, int bx, int by, int atx, int aty)
{
	return atx * (by - ay) + aty * (ax - bx) + ay * bx - ax * by;
}

int Check(int aAx, int aAy, int aBx, int aBy, int aCx, int aCy, int aPx, int aPy)
{
	int q1 = Q(aAx, aAy, aBx, aBy, aPx, aPy);
	int q2 = Q(aBx, aBy, aCx, aCy, aPx, aPy);
	int q3 = Q(aCx, aCy, aAx, aAy, aPx, aPy);
	if (((q1 >= 0) && (q2 >= 0) && (q3 >= 0)) || ((q1 < 0) && (q2 < 0) && (q3 < 0))) return 1; else return 0;
}


void calculate()
{
	int n, m, i, j, k, x, y, g, l;

	cout << "1 mnogestvo -  " << endl;
	scanf_s("%d", &n); //n - число точек в первом 
	cout << "2 mnogestvo -  " << endl;
	scanf_s("%d", &m); //m - число точек во втором множестве

	fiSet = (Point*)malloc(sizeof(Point) * n);
	seSet = (Point*)malloc(sizeof(Point) * m);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		fiSet[i].x = x;
		cout << " " << endl;
		fiSet[i].y = y;
	}
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;

	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		seSet[i].x = x;
		cout << " " << endl;
		seSet[i].y = y;
	}
	cout << " " << endl;
	cout << " " << endl;

	Point p[3];
	int iHavePoints = -1;

	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			for (k = j + 1; k < n; ++k)
			{
				g = 0;

				for (l = 0; l < m; l++)
					g += Check(fiSet[i].x, fiSet[i].y,
						fiSet[j].x, fiSet[j].y,
						fiSet[k].x, fiSet[k].y,
						seSet[l].x, seSet[l].y);

				if (g > iHavePoints)
				{
					iHavePoints = g;
					p[0].x = fiSet[i].x; p[0].y = fiSet[i].y;
					p[1].x = fiSet[j].x; p[1].y = fiSet[j].y;
					p[2].x = fiSet[k].x; p[2].y = fiSet[k].y;
				}
			}

	//Выводим три искомые точки
	printf("%d %d\n", p[0].x, p[0].y);
	printf("%d %d\n", p[1].x, p[1].y);
	printf("%d %d\n", p[2].x, p[2].y);

	free(fiSet);
	free(seSet);

	return;
}


