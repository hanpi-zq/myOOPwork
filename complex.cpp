// 请分析给定的代码，添加重载函数，实现复数的多种加法运算。
#include  <iostream>
#include  <iomanip>
using  namespace  std;

struct  complex
{
        double  r;
        double  i;
};
//重载函数的实现部分
complex add(complex x,complex y)
{
    complex z;
    z.r=x.r+y.r;
    z.i=x.i+y.i;
    return z;
}
complex add(complex x,double y)
{
    complex z;
    z.r=x.r+y;
    z.i=x.i;
    return z;
}
complex add(double x,complex y)
{
    complex z;
    z.r=x+y.r;
    z.i=y.i;
    return z;
}

int  main()
{
        double  num;
        complex  a,  b,  c;
        cin  >>  a.r  >>  a.i;
        cin  >>  b.r  >>  b.i;
        cin  >>  num;
        c  =  add(a,  b);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        c  =  add(a,  num);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        c  =  add(num,  b);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        system("pause");
        return 0;

}