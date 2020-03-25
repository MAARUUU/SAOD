#pragma once
#include <iostream>
#include <cmath>


const int M_PI = 3.14;

struct point {
    double x;
    double y;
};


double getDist(const point& A, const point& B); //// ‘ункци€, вычисл€юща€ рассто€ние между точками A и B по теореме ѕифагора
double getTriangleArea(const point& A, const point& B, const point& C); // ‘ункци€, вычисл€юща€ площадь треугольника ABC по формуле √ерона
bool isSquare(const point& A, const point& B, const point& C, const point& D); // ‘ункци€, определ€юща€, €вл€ютс€ ли точки A, B, C и D вершинами
                                                                                                                            //квадрата
double getAzimuth(const point& A, const point& B);
bool inSquare(const point& P, const point& A, const point& B, const point& C, const point& D); // ‘ункци€, определ€юща€, лежит ли точка P внутри квадрата ABCD
std::ostream& operator << (std::ostream& s, const point& p); //// ‘ункци€, определ€юща€, лежит ли точка P внутри квадрата ABCD