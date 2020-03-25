//Даны два множества точек на плоскости.Выбрать четыре различные точки первого множества так,
//чтобы квадрат с вершинами в этих точках накрывал все точки второго множества 

#include <iostream>
#include <cmath>
#include <fstream>
#include "yyyy.h"
#include <fstream>

using namespace std;

    int main()
    {
        setlocale(0, "");
        ofstream fout("File.txt");
        point verteces[] = { {0,0}, {10,0}, {0,10}, {10,10}, {0, 20}, {-10,-10}, {-1, 4}, {6, 4}, {6, 11}, {-1, 11} };  // массив вершин
        int vertecesCount = sizeof verteces / sizeof * verteces;  // количество вершин
        point points[] = { {2, 7}, {3, 9}, {9, 6} };     // массив точек второго множества
        int pointsCount = sizeof points / sizeof * points;   // количество этих точек
        point square[4]; // вершины квадрата
        bool foundSquare = false;  
        double area = 0; // площадь квадрата

        // Перебираем всё четвёрки вершин квадрата
        for (int i = 0; i < vertecesCount - 3; i++) {
            for (int j = i + 1; j < vertecesCount - 2; j++) {
                for (int k = j + 1; k < vertecesCount - 1; k++) {
                    for (int l = k + 1; l < vertecesCount; l++) {
                        // Если нашли вершины, образующие квадрат
                        if (isSquare(verteces[i], verteces[j], verteces[k], verteces[l])) {
                            // Вычисляем площадь этого квадрата
                            double currentArea = 2 * getTriangleArea(verteces[i], verteces[j], verteces[k]);
                            // Если эта площадь меньше текущего минимума или минимум ещё не найден
                            if (currentArea < area || !foundSquare) {
                                bool currentFind = true; // флаг, показывающий, что точки принадлежат квадрату
                                for (int z = 0; z < pointsCount && currentFind; z++) { // проверям все точки на принадлежность квадрату
                                    currentFind *= inSquare(points[z], verteces[i], verteces[j], verteces[k], verteces[l]);
                                }
                                if (currentFind) {  // Если все точки попадают в квадрат
                                    // записываем эти точки в массив
                                    square[0] = verteces[i];
                                    square[1] = verteces[j];
                                    square[2] = verteces[k];
                                    square[3] = verteces[l];
                                    foundSquare = true;
                                    // запоминаем площадь
                                    area = currentArea;
                                }
                            }
                        }
                    }
                }
            }
        }
        // если квадрат нашёлся
        if (foundSquare) {
            // выводим координаты его вершин
            fout << "Координаты вершин квадрата: ";
            for (int i = 0; i < 4; i++) {
                cout << square[i] << ",";
                fout << square[i] << ", ";
            }
        }
        else {
            cout << "Квадрат не найден.";
            fout << "Квадрат не найден.";
        }
            cout << endl;
            fout.close();
    }

