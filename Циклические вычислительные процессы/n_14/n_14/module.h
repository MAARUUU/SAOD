#pragma once
#include<cmath>

float f(float a, float x, float b, float c); //�������� ��  ������� + �������

float if_f(float a, float b, float c, float x); // ������� �� �������������� ��������
                                                //���� �����������, �� ������� ��������� �������������� ��������

void calculation(float a, float b, float c, float x_b, float x_e, float dx); // ������� + ������ � ����

void output(float x_b, float x_e, float dx, float a, float b, float c); //����� ������ �� �����
void file_output(float x_b, float x_e, float dx, float a, float b, float c); // ������ ������ � ����
