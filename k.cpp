
#include <iostream>

#include <math.h>

#include <algorithm>

#include <vector>

#include <iomanip>

#include <fstream>

using namespace std;

double f(double x, double y)

{

return (y-3*cos(x));

}

int main()

{

double n, a, b, h, hf, x, y, yi, k1, k2, k3, k4;

ofstream g("o.txt");


g << "metod eilera" << endl << endl;

x = 0;

y = 0;

g << setw(3) << x << setw(12) << y << endl;

a = 0;

b = 1;

n = 10;

h = (b-a)/n;

for (int i=0; i<n; ++i)

{

yi = y + h * f(x, y);

y = yi;

x += h;

g << setw(3) << x << setw(12) << y << endl;

}


g << endl << "eiler-koshi" << endl << endl;

x = 0;

y = 0;

g << setw(3) << x << setw(12) << y << endl;

for (int i=0; i<n; ++i)

{

yi = y + h * f(x + h/2, y + (h/2) * f(x, y));

y = yi;

x += h;

g << setw(3) << x << setw(12) << y << endl;

}


g << endl << "rungekutta" << endl << endl;

x = 0;

y = 0;

g << setw(3) << x << setw(12) << y << endl;

for (int i=0; i<n; ++i)

{

k1 = f(x, y);

k2 = f(x + (h/2), y + ((h * k1)/2));

k3 = f(x + (h/2), y + ((h * k2)/2));

k4 = f(x + h, y + (h * k3));

yi = y + ((h/6) * (k1 + 2 * k2 + 2 * k3 + k4));

y = yi;

x += h;

g << setw(3) << x << setw(12) << y << endl;

}

return 0;

}