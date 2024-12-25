#include <cmath>
#include <iostream>
using namespace std;

double f(double t, double y) {
    return t * y;
}

void Euler_Method(double t0, double y0, double T, int N, double* t, double* y) {
    double h = (T - t0) / N;

    t[0] = t0;
    y[0] = y0;

    for (int i = 0; i < N; ++i) 
    {
        y[i + 1] = y[i] + h * f(t[i], y[i]);
        t[i + 1] = t[i] + h;
    }
}

int main() {
    double t0 = 0.0;
    double y0 = 1.0;
    double T = 2.0;
    const int N = 100;

    double t[N + 1];
    double y[N + 1];

    Euler_Method(t0, y0, T, N, t, y);

    for (int i = 0; i <= N; ++i) {
        cout << "t[" << i << "] = " << t[i] << ", y[" << i << "] = " << y[i] << endl;
    }

    return 0;
}