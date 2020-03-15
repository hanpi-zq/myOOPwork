#include <iostream>
using namespace std;
int main()
{
	int i, k, j, b[8][8], m=0,flag=0;
	char a[8];
	cin >> a;
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			b[i][j]=1; 
		}
	}	
	for (i = 0; i < 8; i++)
	{
		if (a[i] == '*')
			k = i;
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 1; j < 8; j++)
		{
			if (a[i] == j+48)
			{
				for (m = 0; m < 8; m++)
				{
					b[i][m] = 0;
					b[m][j-1] = 0;
					if (i - m >= 0 && j - m - 1>=0)
					{
						b[i - m][j - m-1] = 0;
					} 
					if (i - m>=0 && j + m - 1<8)
					{
						b[i - m][j + m - 1] = 0;	
					}
					if (i + m<8&&j - m - 1>=0)
					{
						b[i + m][j - m - 1] = 0;
					}
					if (i + m<8&&j + m - 1<8)
					{
						b[i + m][j + m - 1] = 0;
					}
				}
			}

		}

	}
	for (i = 0; i < 8; i++)
	{
		if (b[k][i] != 0)
		{
			cout << i+1<< endl;
			flag++;
		}
	}
	if(flag==0)
		cout << "No Answer" << endl;
	return 0;
}


