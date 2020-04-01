// 2. 编写CStudent类，并建立对象数组，分析对象的创建与释放过程中构造函数与析构函数的调用
// 【问题描述】// 编写CStudent类，并建立对象数组，分析对象的创建与释放过程中构造函数与析构函数的调用。
// 具体要求：
// 1、CStudent类包括两个私有成员：姓名和年龄
// 2、CStudent类具有一个静态数据成员count，在对象被创建时自动加1，在对象被释放时自动减1
// 3、在构造函数中输出"*** is contructing", 在析构函数中输出“*** is destructing”
// 4、请根据main函数分析其他功能，并完成CStudent类的设计
// 5、请分析块作用域的对象创建与释放的原因
#include <iostream>
#include <string>
using  namespace  std;

class  CStudent
{
    public:
        void printname()
        {
            
            if(name=="")
                cout<<"name:noname"<<endl;
            else
                cout<<"name:"<<name<<endl;
        }
        CStudent(string a,int b)
        {
            name=a;
            year=b;
            count++;
            if(name=="")
                cout<<"noname is contructing"<<endl;
            else
                cout<<name<<" is contructing"<<endl;
        }
        CStudent()
        {
            name="";
            year=0;
            count++;
            if(name=="")
                cout<<"noname is contructing"<<endl;
             else
                cout<<name<<" is contructing"<<endl;
        }
        ~CStudent()
        {
            count--;
            if(name=="")
                cout<<"noname is destructing"<<endl;
             else
                cout<<name<<" is destructing"<<endl;   

        }
        static int  getcount()
        {
            return count;
        }
    private:
        string name;
        int year;
        static int count;
        
};
    int CStudent::count=0;


int  main()
{
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuB[5];
                stuB[4].printname();
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        {
                CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)};
                for  (int  i  =  0;  i  <  2;  i++)
                {
                        stuA[i].printname();
                }
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        }
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl;
        system("pause");
        return  0;
}