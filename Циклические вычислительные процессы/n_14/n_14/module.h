#pragma once
#include<cmath>

float f(float a, float x, float b, float c); //проверка на  условия + расчеты

float if_f(float a, float b, float c, float x); // условие на действительное значение
                                                //Если срабатывает, то функция принимает действительное значение

void calculation(float a, float b, float c, float x_b, float x_e, float dx); // расчеты + запись в файл

void output(float x_b, float x_e, float dx, float a, float b, float c); //вывод данных на экран
void file_output(float x_b, float x_e, float dx, float a, float b, float c); // запись данных в файл
