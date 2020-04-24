// 2. motorcycle类设计（虚基类）【问题描述】
// 声名一个基类vehicle,有私有成员maxspeed和weight，公有成员run()和stop(),以及构造和析构函数。
// 从vehicle派生bicycle和motorcar, bicycle有私有成员height， motorcar有私有成员seatnum,以及各自的构造函数和析构函数。
// 从bicycle和motorcar派生出motorcycle，观察虚基类对继承的影响。
// 定义一个motorcycle的对象，分别调用run()和stop(),观察构造/析构函数的调用情况。
// 注意：构造函数和析构函数中均为cout语句，说明哪个构造/析构函数被调用。
// 该题重点和难点在于构造函数的设计，需考虑怎么给基类及最远基类传递参数。
#include  "iostream"
using  namespace  std;
class vehicle
{
    public:
        vehicle(int m, int n);
        vehicle();
        ~vehicle();
        void run();
        void stop();
    private:
        int maxspeed;
        int weight;

};
vehicle::vehicle()
{

}
vehicle::vehicle(int m,int n)
{
    maxspeed=m;
    weight=n;
    cout<<"vehicle constructor called. "<<"maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
}
vehicle::~vehicle()
{
    cout<<"vehicle destructor called. "<<"maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
}
void vehicle::run()
{
    cout<<"vehicle run"<<endl;
}
void vehicle::stop()
{
    cout<<"vehicle stop"<<endl;
}
class bicycle :virtual public vehicle
{
    public:
        bicycle();
        bicycle(int m);
        ~bicycle();
    private:
        int height;

};
bicycle::bicycle()
{

}
bicycle::bicycle(int m)
{
    height=m;
    cout<<"bicycle constructor called. "<<"height:"<<height<<endl;
}
bicycle::~bicycle()
{
    cout<<"bicycle destructor called. "<<"height:"<<height<<endl;
}
class motorcar :virtual public vehicle
{
    public:
        motorcar(int n);
        motorcar();
        ~motorcar();
    private:
        int seatnum;
};
motorcar::motorcar()
{

}
motorcar::motorcar(int n)
{
    seatnum=n;
    cout<<"motorcar constructor called. "<<"setnum:"<<seatnum<<endl;
}
motorcar::~motorcar()
{
    cout<<"motorcar destructor called. "<<"setnum:"<<seatnum<<endl;
}
class motorcycle :public bicycle,public motorcar
{
    public:
        motorcycle();
        motorcycle(int a,int b,int c,int d);
        ~motorcycle();
        void run();
        void stop();
        
};
motorcycle::motorcycle()
{}
motorcycle::motorcycle(int a,int b,int c,int d):vehicle(c,d),bicycle(a),motorcar(b)
{
    cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
    cout<<"motorcycle destructor called"<<endl;
}
void motorcycle::run()
{
    vehicle::run();
}
void motorcycle::stop()
{
    vehicle::stop();
}
int  main(int  argc,  char  *argv[])
{
        motorcycle  m(1,  2,  3,  4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
        m.run();
        m.stop();
        system("pause");
        return  0;
}