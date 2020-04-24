// WEEK9 第八章 多态性（编程题） 程序片段编程题  2. 运算符重载-友元函数（复数类）【问题描述】
// 请定义一个复数类，将+/-运算符重载为友元函数，实现复数与复数的加减及复数与浮点数的加减。
// 请根据给定的main函数，设计Complex类。
// 【样例输出】
// a+b=(4)+(3i)
// a-b=(2)+(5i)
// a+100=(103)+(4i)
// a-2.5=(0.5)+(4i)
// 100+a=(103)+(4i)
// 2.5-a=(-0.5)+(-4i)
#include  <iostream>
using  namespace  std;
class Complex
{
private:
    double r;
    double i;
public:
    Complex(double a=0.0,double b=0.0);
    ~Complex();
    friend Complex operator+(Complex c1,Complex c2);
    friend Complex operator-(Complex c1,Complex c2);
    friend Complex operator+(double c1,Complex c2);
    friend Complex operator-(double c1,Complex c2);
    void print();
};

Complex::Complex(double a,double b)
{
    r=a;
    i=b;
}

Complex::~Complex()
{
}
Complex operator+(Complex c1,Complex c2)
{
    return Complex(c1.r+c2.r,c1.i+c2.i);
}
Complex operator-(Complex c1,Complex c2)
{
    return Complex(c1.r-c2.r,c1.i-c2.i);
}
Complex operator+(double c1,Complex c2)
{
    return Complex(c1+c2.r,c2.i);
}
Complex operator-(double c1,Complex c2)
{
    return Complex(c1-c2.r,-c2.i);
}
void Complex:: print()
{
    cout<<"("<<r<<")"<<"+"<<"("<<i<<"i)"<<endl;
}
int  main()
{
        Complex  a(3,4),b(1,-1),c;
        c=a+b;
        cout<<"a+b=";
        c.print();
        cout<<endl;
        c=a-b;
        cout<<"a-b=";
        c.print();
        cout<<endl;
        c=a+100;
        cout<<"a+100=";
        c.print();
        cout<<endl;
        c=a-2.5;
        cout<<"a-2.5=";
        c.print();
        cout<<endl;
        c=100+a;
        cout<<"100+a=";
        c.print();
        cout<<endl;
        c=2.5-a;
        cout<<"2.5-a=";
        c.print();
        cout<<endl;
        system("pause");
        return  0;
}