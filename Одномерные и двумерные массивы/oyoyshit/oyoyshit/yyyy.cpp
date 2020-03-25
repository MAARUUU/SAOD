#include "yyyy.h"
#include <iostream>
#include <cmath>


using namespace std;


std::ostream& operator << (std::ostream& s, const point& p)
{
    s << '(' << p.x << "; " << p.y << ')';
    return s;
}

double getDist(const point& A, const point& B) {
    return hypot(A.x - B.x, A.y - B.y);
}

double getTriangleArea(const point& A, const point& B, const point& C) {
    double a = getDist(A, B);
    double b = getDist(B, C);
    double c = getDist(A, C);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


bool isSquare(const point& A, const point& B, const point& C, const point& D) {
    bool result = true;
    double P[6] = { getDist(A, B), getDist(A, C), getDist(A, D), getDist(B, C), getDist(B, D), getDist(C, D) };
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (P[i] > P[j]) {
                double temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }
    for (int i = 5; i >= 0; i--) {
        P[i] /= P[0];
    }
    for (int i = 0; i < 4; i++) {
        result *= (fabs(P[i] - 1.0) < 1e-12);
    }
    for (int i = 4; i < 6; i++) {
        result *= (fabs(P[i] - sqrt(2)) < 1e-12);
    }
    return result;
}

// ‘ункци€, вычисл€юща€ угол между отрезком AB и осью OX
double getAzimuth(const point& A, const point& B) {
    return fmod(atan2(B.y - A.y, B.x - A.x) + 2 * M_PI, 2 * M_PI);
}


bool inSquare(const point& P, const point& A, const point& B, const point& C, const point& D) {
    
    point verteces[4] = { A, B, C, D };
    for (int i = 1; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (getAzimuth(verteces[0], verteces[i]) > getAzimuth(verteces[0], verteces[j])) {
                point temp = verteces[i];
                verteces[i] = verteces[j];
                verteces[j] = temp;
            }
        }
    }
    double S1 = getTriangleArea(verteces[0], verteces[1], P);
    double S2 = getTriangleArea(verteces[1], verteces[2], P);
    double S3 = getTriangleArea(verteces[2], verteces[3], P);
    double S4 = getTriangleArea(verteces[0], verteces[3], P);
    double S = 2 * getTriangleArea(A, B, C);
    return fabs(S - S1 - S2 - S3 - S4) < 1e-10;
}
