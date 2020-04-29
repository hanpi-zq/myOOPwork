// WEEK10 第十一章 流类库与输入输出（编程题） 编程题
// 2. 二进制文件的读写 【问题描述】请编写一个程序，实现如下功能
// 1、定义结构体student, 包括stu_id,score 2个变量。其中stu_id是一个short型变量，score为short型变量。
// 2、从键盘输入学生个数n及n个学生的数据，存储在new创建的数组a中
// 3、使用write函数，以二进制形式，将a数组中存放的n个学生一次写入out.txt文件中（不要使用循环）
// 4、使用read函数，以二进制形式，使用循环方式，从out.txt中每次读出一个学生信息，存储于new创建的数组b中
// 5、使用write函数，以文本形式，将b数组中存放的n个学生一次写入out.txt文件中，要求添加到文件末尾（不要使用循环）
// 【输入形式】
// 输入第一行是整数，表示有n个学生
// 输入第2到n+1行是学生信息，每行表示一个学生的stu_id,score
// 【输出形式】
// 输出文件名：out.txt，其中包括2次输出信息
// 【输入范例】
// 2
// 1011 90
// 1012 68
// 【输出范例】
// 无
#include  <iostream>
#include <fstream>
using  namespace  std;
struct student
    {
        short stu_id;
        short score;

    } ;
int main()
{
    int n;
    cin>>n;
    student a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].stu_id>>a[i].score;
    }
   ofstream tfile ("out.txt",ios::binary);
   tfile.write((char *)&a,sizeof(&a));
   tfile.close();
   student *b =new student [n];
   ifstream myfile ("out.txt",ios_base::binary|ios_base::in);
   for(int i=0;i<n;i++)
   {
    myfile.read((char *)(b+i),sizeof(student));
   }
   ofstream pfile ("out.txt",ios_base::app);
   tfile.write((char *)b,n);
   pfile.close();
}