#include <iostream>
using namespace std;
int Buy(int a,int b)
{
	int a1, a2, b1, b2;
	a1 = a / 2;
	a2 = a % 2;
	b1 = b / 3;
	b2 = b % 3;
	if (a == 1 && b == 2)
		return 0;
	else
		return a1 + b1 + Buy(a1 + b1 + a2, a1 + b1 + b2);

	
}
int main()
{
	int money , n;
	cin >> money;
	n = money+Buy(money,money);
	cout << n;
	
}