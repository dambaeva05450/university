
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const double e = 0.00001;
double f1(double x, double y)

{

return (1-sin(2*y));;

}

double f2(double x, double y)

{

return 0.5-cos(x-0.5);

}
int main(){
	fstream g("p1.txt");
double xi = 1.4;
double yi = -0.2;
double xi1=f1(xi,yi);
double yi1=f2(xi,yi);

while(max(fabs(yi1-yi),fabs(xi1-xi))>e)
{
g<<xi<<' '<<yi<<"\n";
	yi=yi1;
	xi=xi1;
	xi1=f1(xi,yi);
	yi1=f2(xi,yi);

	}
g<<xi1<<' '<<yi1<<"\n";
}