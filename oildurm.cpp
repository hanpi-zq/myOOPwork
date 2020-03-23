//某工厂使用一种圆柱形的铁桶来运输色拉油，但是关于该油桶的容量已经模糊，现在工人们测得了油桶直径和高（由键盘输入），请帮工人们
//计算一下油桶容量和制造该油桶需要的铁皮面积。注意这个油桶是有盖的。铁皮的厚度忽略不计。请设计一个类cylinder，该类具有私有成
// r和h，r表示半径，h表示高。该类还有3个公有成员，请根据给出的代码部分，分析并设计公有函数。
#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI=3.1415926;
//请在此处完善类的设计
class cylinder
{
    public:  double init(double x,double y);
             double  getvolumn();
             double  getarea();
    private: double r,h;

};
double cylinder::init(double x, double y)
{
    r=y;
    h=x;

}
double cylinder::  getvolumn()
{
     return  PI*r*r*h;
}
double cylinder:: getarea()
{
     return  PI*r*r*2+2* PI*r*h;
}

int  main()
{
        double  d,h;
        cin>>d>>h;
        cylinder can;

        can.init(h,d/2);
        cout<<fixed<<setprecision(6);
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl;
        cout<<"铁皮的面积是"<<can.getarea()<<endl;
        system("pause");
        return 0;
}