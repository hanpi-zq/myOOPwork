// WEEK9 第八章 多态性（编程题）
// 程序片段编程题
// 3. 运算符重载-综合（Point类）【问题描述】
//请定义一个Point类，将前置++和后置++运算符重载为成员函数，实现成员变量m_x和m_y的加一操作。
// 同时重载流插入运算符，实现对Point类对象的格式化输出。例如
// Point p；
// cout<<p;
// 输出结果为：// （0,0）请根据给定的main函数，设计Point类。
// 【样例输出】
// (1,3)
// (1,3)
// (3,5)
#include  <iostream>
using  namespace  std;
class Point
{
private:
    int x;
    int y;
public:
    Point(int a=0,int b=0);
    ~Point();
    Point& operator++();
    Point operator++(int);
    friend ostream & operator<<(ostream&,Point p);
};

Point::Point(int a,int b)
{
    x=a;
    y=b;
}

Point::~Point()
{
}
Point & Point::operator++()
{
    x=x+1;
    y=y+1;
    return *this;
}
Point Point::operator++(int)
{
    Point p1=*this;
    ++(*this);
    return p1;
}
ostream & operator<<(ostream&out,Point p1)
{
    out<<"("<<p1.x<<","<<p1.y<<")"<<endl;
    return out;
}
int  main()
{
        Point  a(1,3);
        cout<<a;
        cout<<a++;
        cout<<++a;
        system("pause");
        return  0;
}