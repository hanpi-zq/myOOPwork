// WEEK10 第十二章 异常处理（编程题）程序片段编程题
// 1. 继承并派生异常类【问题描述】
// 请分析main函数，从exception类继承并派生两个异常类MyException1和MyException2，要求定义what成员函数，在what函数中，要求使用typeid，返回当前类的运行时的类型。
// 请调试和分析该程序，熟练掌握关于异常捕获机制的使用。
// 【输入形式】
// 输入为一个整数，取值在1-4。
// 【输出形式】
// 输出包括两行
// 第一行为输出的异常信息
// 第二行为：Return to main()
// 【样例输入1】
// 1
// 【样例输出1】
// exception: 12MyException1
// Return to main()
//请补充合适的头文件
#include <iostream>
#include <string>
#include<stdexcept>
using  namespace  std;
//请定义异常类MyException1
class MyException1
{
private:
   string str1="12MyException1";
public:
    MyException1(/* args */);
    ~MyException1();
    string what();
};
string MyException1::what()
{
    return str1;
}
MyException1::MyException1(/* args */)
{
}

MyException1::~MyException1()
{
}

//请定义异常类MyException2
class MyException2
{
private:
    string str1="12MyException2";
public:
    MyException2(/* args */);
    ~MyException2();
    string what();
};
string MyException2::what()
{
    return str1;
}
MyException2::MyException2(/* args */)
{
}

MyException2::~MyException2()
{
}

//请定义函数divide()，对除0操作引发异常
int divide(int x,int y)
{
    if(y==0)
        throw y;
    return x/y;

}

int  main()
{
        int  id,k;
        cin>>id;
        char  a;
        string  s="hello";
          try
        {
                switch  (id)
                {
                case  1:
                        throw  MyException1();
                        break;
                case  2:
                        throw  MyException2();
                        break;
                case  3:
                        k=divide(8,0);
                        break;                                        
                case  4:
                        a=s.at(10);
                        cout<<a<<endl;
                        break;                                        
                default:
                        break;
                }
        }
        catch  (MyException1  &e)
        {
              cout  <<  "exception:  " << e.what()<<  endl;
        }
        catch  (MyException2  &e)
        {
                cout  <<  "exception:  "<<e.what()<<  endl;
        }
        catch  (int  &e)
        {
                cout  <<  "exception:  "<<e<<  endl;
        }        
        catch(exception  &e)
        {
              cout  <<  "exception:  "<<e.what()<<  endl;
        }
        cout<<"Return  to  main()"<<endl;
        system("pause");
        return  0;
}

