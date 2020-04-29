// WEEK10 第十一章 流类库与输入输出（编程题）// 编程题
// 1. 请编程一个程序，实现文件的拷贝
// 【问题描述】请编写一个程序，实现如下功能
// a.txt文件中已经预先存储了一组数据，以空格分隔，数据的个数不确定。
// 从a.txt文件中读取数据，并将从小到大排序后的数据输出到b.txt文件
// b.txt文件中数据以空格分隔// 【输入形式】
// 输入文件名：a.txt
// 【输出形式】
// 输出文件名：b.txt
#include  <iostream>
#include <fstream>
using  namespace  std;
int main()
{
    double c[50];
    ifstream myfile("a.txt");
    int len=0;
    while(!myfile.eof())
    {
        myfile>>c[len];
        ++len;
    }
    ofstream outfile("b.txt");
    
    // for(int i=0;i<len;i++)
    // {
    //     myfile>>c[i];
    // }
    for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len - i; j++)
        {
            if (c[j] > c[j + 1])
			{
				//交换
				double buffer = c[j];
				c[j] = c[j + 1];
				c[j + 1] = buffer;
			}

        }
    }
    for(int i=0;i<len;i++)
    {
        outfile<<c[i]<<" ";
    }
    //  for(int i=0;i<len-1;i++)
    //  {
    //      cout<<c[i]<<" ";
    //  }
    // system("pause");
}
//     for(int i=0;i<len;i++)
//     {
//         cout<<c[i]<<" ";
//     }
//     system("pause");
// }