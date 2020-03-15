#include <iostream>
#include<string.h> 
using namespace std;
int main()
{
	int i, j, count=0,k=26;
	char a[10], b[10];
	cin >> a;
	cin >> b;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] >= 65 && a[i] <= 90)
		{
			a[i] = a[i] + 32;
		}
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] >= 65 && b[i] <= 90)
		{
			b[i] = b[i] + 32;
		}
	}
	for (i = 0; a[i]!='\0'; i++)
	{
		for (j = 0; b[j] != '\0'; j++)
		{
			if (a[i] >= b[j])
				count = a[i] - b[j];
			else
				count = b[j] - a[i];
			if (k >= count)
				k = count;
		}
	}
	cout << k;
	return 0;
	
}
