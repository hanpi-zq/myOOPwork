// 1. clock类派生类设计
// 【问题描述】
// 请基于clock基类的设计及给定的main函数，完成派生类watchDerived的设计。
// 需要补充的函数包括：
// 1、默认构造函数：watchDerived() 
// 2、构造函数：watchDerived(int h, int m, int s)
// 3、请成员变量清零：void setzero()
// 4、前置、后置++运算符重载
// 5、<<运算符重载（以友元函数方式重载）
// 【样例输入】
// 11 59 50
// 【样例输出】
// watch constructor called
// watchDerived constructor called
// watch constructor called
// watchDerived constructor called
// watch copy constructor called
// watchDerived copy constructor called
// watchDerived destructor called
// watch destructor called
// s1: 11:59:59
// s2: 0:0:0
// s1: 0:0:1
// s2: 0:0:1
// s1: 0:0:0

#include <iostream>
using namespace std;
class watch
{
public:
    watch()
    {
        m_hour = 0;
        m_min = 0;
        m_sec = 0;
        cout << "watch default constructor called" << endl;        
    }
    watch(int h, int m, int s)
    {
        m_hour = h;
        m_min = m;
        m_sec = s;
        cout << "watch constructor called" << endl;
    }

    //注意保护成员在以公有继承方式被继承时，在派生类中依然是保护成员，即可以在派生类内访问，但是不能在类外访问。
protected:
    int m_hour; //小时
    int m_min;  //分钟
    int m_sec;  //秒钟
};

//派生类watchDerived的设计
class watchDerived : public watch
{
    //请补充派生类watchDerived的设计
    public:
    watchDerived(int h, int m, int s):watch( h, m, s )
    {
        m_hour = h;
        m_min = m;
        m_sec = s;

        cout<<"watchDerived constructor called"<<endl;
    }
    watchDerived():watch()
    {
        m_hour = 0;
        m_min = 0;
        m_sec = 0;
        cout<<"watchDerived constructor called"<<endl;
        
    }
    watchDerived(watchDerived &w):watch(w)
    {
        m_hour=w.m_hour;
        m_min=w.m_min;
        m_sec=w.m_sec;
        
    }
    ~watchDerived()
    {
        
    }
    void setzero()
    {
        m_hour=0;
        m_min=0;
        m_sec=0;
    }
    watchDerived  operator++()
    {
        if(++m_sec==60)
        {
            m_sec=0;
            m_min=m_min+1;
            if(m_min==60)
            {
                m_min=0;
                m_hour=m_hour+1;
                if(m_hour==12)
                {
                    m_hour=0;
                }
            }
        }
        return *this;
    }
    watchDerived operator++(int)
    {
        watchDerived w2=*this;
        ++(*this);
        return w2;

    }
    friend ostream &operator<<(ostream &, const watchDerived &);
    friend istream &operator>>(istream &,  watchDerived &);
    
};


//请完善派生类watchDerived中<<运算符的重载函数
ostream &operator<<(ostream &out, const watchDerived &s)
{
    out<<s.m_hour<<":"<<s.m_min<<":"<<s.m_sec;
    return out;

}
istream &operator>>(istream & in,  watchDerived &s)
{
    in>> s.m_hour >> s.m_min >> s.m_sec;
    return in;
}

int main()
{
    watchDerived s1, s2(11, 59, 59);

    s1 = s2++;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    s1.setzero();
    s2.setzero();

    s1 = ++s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cin>>s1;
    cout << "s1: " << ++s1 << endl;
    system("pause");
    return 0;
}