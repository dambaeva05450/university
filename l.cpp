#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double f (double a)
{
return (-1.5*(exp(a)+sin(a)-cos(a)));
}
int main(){
double i=0;
fstream g("o1.txt");
while(i<=1)
{
g<<i<<' '<<f(i)<<endl;
i+=0.1;
}
}