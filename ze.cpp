#include <iostream>

#include <math.h>

#include <fstream>

#include <vector>

#include <algorithm>

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

double maxn(vector <double> x, vector <double> y)

{

for (int i=0; i<x.size(); ++i)

x[i] = fabs(x[i] - y[i]);

return (*max_element(x.begin(), x.end()));

}

int main()

{

ifstream g("input.txt");

ofstream h("output.txt");

double e = 0.0001;

int n = 4;

vector <vector <double> > a(n, vector <double> (n));

vector <double> b(n);

double xi, yi, zi;

for (int i=0; i<n; ++i)
{

for (int j=0; j<n; ++j)

g >> a[i][j];

g >> b[i];
}
for (int i=0; i<n; ++i)

{

double t = a[i][i];

for (int j=0; j<n; ++j)

{

a[i][j] /= t;

a[i][j] *= -1;

}

b[i] /= t;

}

for (int i=0; i<n; ++i)

a[i][i] = 0;

vector <double> v = b;

vector <double> k = b;

for (int u=0;;++u)

{

for (int i=0; i<n; ++i)

{

b[i] = (c(a[i], b) + v[i]);

}

if (maxn(b, k) < e)

break;

for (int i=0; i<n; ++i)

h << b[i] << ' ';

h << endl;

k = b;

}




return 0;

}