#include <iostream>

#include <vector>

#include <math.h>

#include <algorithm>

#include <fstream>

using namespace std;

double c(vector <double> x, vector <double> y)

{

for (int i=0; i<x.size(); ++i)

x[i] *= y[i];

double sum = 0;

for (int i=0; i<x.size(); ++i)

sum += x[i];

return sum;

}

double o(vector <double> x, vector <double> y)

{

double r = c(x, y);

for (int i=0; i<y.size(); ++i)

y[i] = pow(y[i], 2);

double su = 0;

for (int i=0; i<y.size(); ++i)

su += y[i];

return (r/su);

}

int main()

{

ifstream g("input.txt");

ofstream h("output.txt");

int n = 3;

double e = pow(10, -5);

h << "e = " << e << endl;

h << endl << "=========================================" << endl << endl;

vector <vector <double> > a(n, vector <double> (n));

for (int i=0; i<n; ++i)

for (int j=0; j<n; ++j)

g >> a[i][j];

int k = 1;

vector <double> b;

for (int i=0; i<n; ++i)

b.push_back(1);

vector <double> t;

for (int i=0; i<n; ++i)

t.push_back(c(a[i], b));

double l1, l2, m;

l1 = o(t, b);

b = t;

t.clear();

for (int u=0;;++u)

{

for (int i=0; i<n; ++i)

t.push_back(c(a[i], b));

l2 = o(t, b);

h << l2 << endl;

m = fabs(l2 - l1)/fabs(l1);

if (m < e)

break;

l1 = l2;

b = t;

t.clear();

++k;

}

h << endl << "=========================================" << endl << endl;

h << "Kol-vo iter: " << k;

return 0;

}