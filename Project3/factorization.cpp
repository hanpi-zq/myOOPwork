#include  <iostream>
#include  <cmath>
using  namespace  std;

//�ж��Ƿ�Ϊ����
int  isPrime(long  num)
{
	int a, i;
	a =int(sqrt(num));
	for (i = 2; i <= a; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;

}//���������طֽ⣬
void  factorization(long n, long a[], int &m)
{  
	int i;
	while (n > 1)
	{
		for (i = 2; i <=n; i++)
		{
			if (n % i == 0)
			{
				a[m] = i;
				m++;
				n = n / i;
				break;
			}
		}
	}
		


}

int  main()
{
	long  n;
	long  factor[100];
	int  numofFactor = 0;
	cin >> n;
	factorization(n, factor, numofFactor);
	for (int i = 0; i < numofFactor; i++)
	{
		cout << factor[i] << "  ";
	}
	cout << endl;
	return  0;
}
