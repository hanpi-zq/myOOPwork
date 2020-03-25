// 2. 友员函数：请定义Boat和Car两个类，并定义两者的一个友员函数totalweight(),计算两个类的对象的重量和。
// 【问题描述】:定义Boat和Car两个类，两者都有私有成员weight属性，定义两者的一个友员函数totalweight(),计算两个类的对象的重量和。
// 请根据给定的main函数和totalweight()函数的定义，完善Boat和Car两个类。
#include  <iostream>
using  namespace  std;
class Boat
    {
        public:
            Boat(int x=0);
            int weight;
     };
Boat::Boat(int x)
{
    weight=x;
}
class Car
    {
        public:
            Car(int y=0);
            friend int  totalweight(Boat&  b,Car&  c);
        private:
            int weight;
    };
Car::Car(int y)
{
    weight=y;
}
int  totalweight(Boat&  b,Car&  c)
{
    return  b.weight+c.weight;
}
int  main()
{
    Boat  b(100);
    Car  c(200);
    cout<<totalweight(  b,  c)<<endl;
    system("pause");
    return  0;
}