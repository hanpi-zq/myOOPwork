#include <iostream>
#include <iomanip>
using namespace std;
double Complex(double a, double b)
{
	double c;
	c = a - b;
	return c;
}
int main()
{
	int i;
	double a[4],e,d;
	for (i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	d = Complex(a[0], a[2]);
	e= Complex(a[1], a[3]);
	cout << setprecision(2) << setiosflags(ios::fixed);
	cout << d<< " "<< e;

}