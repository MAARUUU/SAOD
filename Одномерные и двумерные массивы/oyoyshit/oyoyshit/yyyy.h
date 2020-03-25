#pragma once
#include <iostream>
#include <cmath>


const int M_PI = 3.14;

struct point {
    double x;
    double y;
};


double getDist(const point& A, const point& B); //// �������, ����������� ���������� ����� ������� A � B �� ������� ��������
double getTriangleArea(const point& A, const point& B, const point& C); // �������, ����������� ������� ������������ ABC �� ������� ������
bool isSquare(const point& A, const point& B, const point& C, const point& D); // �������, ������������, �������� �� ����� A, B, C � D ���������
                                                                                                                            //��������
double getAzimuth(const point& A, const point& B);
bool inSquare(const point& P, const point& A, const point& B, const point& C, const point& D); // �������, ������������, ����� �� ����� P ������ �������� ABCD
std::ostream& operator << (std::ostream& s, const point& p); //// �������, ������������, ����� �� ����� P ������ �������� ABCD