// WEEK9 第八章 多态性（编程题）程序片段编程题 1. 运算符重载-成员函数（复数类） 【问题描述】
// 请定义一个复数类，将+/-运算符重载为成员函数，实现复数与复数的加减及复数与浮点数的加减。
// 请根据给定的main函数，设计Complex类。
// 【样例输出】
// a+b=4+3i
// a-b=2+5i
// a+100=103+4i
// a-2.5=0.5+4i
#include  <iostream>
using  namespace  std;
class Complex
{
private:
    double real;
    double magic;
public:
    Complex(double a=0.0 , double b=0.0);
    ~Complex();
    void print();
    Complex operator-(Complex c);
    Complex operator+(Complex c1);
    Complex operator+(int c2);
    Complex operator-(double c3);
};

Complex::Complex(double a,double b)
{
    real=a;
    magic=b;
}

Complex::~Complex()
{
}
Complex Complex::operator-(Complex c)
{
    return Complex(real-c.real,magic-c.magic);
}
Complex Complex::operator+(Complex c1)
{
    return Complex(real+c1.real,magic+c1.magic);
}
Complex Complex::operator+(int c2)
{
    return Complex(real+c2,magic);
}
Complex Complex::operator-(double c3)
{
    return Complex(real-c3,magic);
}
void Complex::print()
{
    cout<<real<<"+"<<magic<<"i";
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
        system("pause");
        return  0;
}
