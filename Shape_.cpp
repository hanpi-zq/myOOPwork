// 1. Shape Circle Rectangle类的设计，继承与派生
// 【问题描述】: 编写一个Shape类并派生出Circle类和Rectangle类，观察运行机制。
// shape类有以下成员
// 1）私有成员m_ID
// 2）公有getter和setter
// 3）计算面积函数getArea()，返回0;
// 4）构造与析构函数
// Circle类从shape类继承，并派生以下成员
// 1）私有成员r
// 2）公有getter和setter
// 3）计算面积函数getArea()，返回计算面积;
// 4）构造与析构函数
// Rectangle类从shape类继承，并派生以下成员
// 1）私有成员h,w
// 2）公有getter和setter
// 3）计算面积函数getArea()，返回计算面积;
// 4）构造与析构函数
#include  <iostream>
using  namespace  std;
const  int  pi=3.14159;
class Shape                         //shape类的定义
{
    public:
        Shape(int n);
        ~Shape();
        void SetID(int m);
        int  GetID();
        int getArea();
    private:
        int m_ID;

};
Shape::Shape(int m)
{
    m_ID=m;
    cout<<"Shape constructor called:"<<m_ID<<endl;
}
Shape::~Shape()
{
    cout<<"Shape destructor called:"<<m_ID<<endl;
}
void Shape::SetID(int i)
{
    m_ID=i;
}
int Shape::GetID()
{
    return m_ID;
}
int Shape::getArea()
{
    return 0;
}
class Circle :public Shape                       //circle类的定义
{
    public:
        Circle(int m,int n);
        ~Circle();
        void SetR(int i);
        int  GetR();
        double getArea();
    private:
        int r;
       
};
Circle::Circle(int m,int n):Shape(n)
{
    r=m;
    cout<<"Circle constructor called:"<<Shape::GetID()<<endl;
}
Circle::~Circle()
{
    cout<<"Circle destructor called:"<<Shape::GetID()<<endl;
}
void Circle::SetR(int i)
{
    r=i;
}
int Circle::GetR()
{
    return r;
}
double Circle::getArea()
{
    return pi*r*r;
}
class Rectangle : public Shape                    //Rectangle类的定义
{
    public:
        Rectangle (int m,int n,int p);
        ~Rectangle();
        void Set(int i,int j);
        int  Geth();
        int  Getw();
        double getArea();
    private:
        int h;
        int w;

};
Rectangle::Rectangle(int m,int n,int p):Shape(p)
{
    h=m;
    w=n;
    cout<<"Rectangle constructor called:"<<Shape::GetID()<<endl;
}
Rectangle::~Rectangle()
{
    cout<<"Rectangle destructor called:"<<Shape::GetID()<<endl;
}
void Rectangle::Set(int i,int j)
{
    h=i;
    w=j;
}
int Rectangle::Geth()
{
    return h;
}
int Rectangle::Getw()
{
    return w;
}

double Rectangle::getArea()
{
    return h*w;
}
int  main()
{
        Shape  s(1);                //1表示ID
        Circle  c(4,2);             //4表示半径，2表示ID
        Rectangle  r(4,  5,3);      //4和5表示长和宽，3表示ID
        cout<<"Shape的面积"<<s.getArea()<<endl;
        cout<<"Circle的面积"<<c.getArea()<<endl;
        cout<<"Rectangle的面积"<<r.getArea()<<endl;
        system("pause");
        return 0;
}