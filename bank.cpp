// 有个银行需要开发一个用户管理程序，功能要求如下：
// 1、记录用户的账号、姓名、性别、年龄、现有存款
// 2、可以动态管理用户的存款
// (1)当用户存钱时将金额添加到现有存款内
// (2)当用户取钱时，从现有账户中扣除
// (3)  如果取钱金额超过现有存款，则拒绝取钱操作。
// (4) 如果录入为100.897元，即为无效输入，应该拒绝操作。原因：录入的数据是以“元”为单位，金额的最小单位是分。请同学们考虑一下
//   如果能有效应对这类问题。请根据给定的main函数设计一个Account类实现上述功能。
#include  <iostream>
#include  <iomanip>
using  namespace  std;
//请在此处补充Account类的定义
double xiaoshu(double x)      //判断输入金额是否合法
{
    if(x*100-(int)(x*100)!=0)
    return 1;
    else
    {
        return 0;
    }
    
}
class  Account
{
    public: void init(string a,string b,string c,int d,double e);
            void printmoney();
            void deposit(double x);
            void withdraw(double y);
    private:string card;
            string name;
            string sex;
            int year;
            double money;
};
void Account::init(string a,string b,string c,int d,double e)
{
    int z;
    card=a;
    name=b;
    sex=c;
    year=d;
    if(xiaoshu(e))
    {
        cout<<"您输入的金额不合法"<<endl;
        money=0;
    }
    else
    {
        money=e;
    }
    


}
void Account::printmoney()
{
    cout<<fixed<<setprecision(2)<<name<<"的存款为"<<money<<endl;
}
void Account::deposit(double x)
{
    if( xiaoshu(x))

    {
        cout<<"您输入的金额不合法"<<endl;
    }
    else
   
        money=money+x;
    
}
void Account:: withdraw(double y)
{
    if( xiaoshu(y))
    {
        cout<<"您输入的金额不合法"<<endl;
    }
    else if (money-y<0)
    {
        cout<<"您的存款金额不足"<<endl;
    }
    else
    {
        money=money-y;
    }   
}
int  main()
{
        Account  tom;
        tom.init("32020320011001876X", "Tom  Black",  "男",  19,  2000.89);
        tom.printmoney();//输出：Tom  Black的存款为2000.89
        tom.deposit(89.471);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的存款为2000.89
        tom.deposit(10000);
        tom.printmoney();//输出：Tom  Black的存款为12000.89
        tom.withdraw(10001);
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        tom.withdraw(10000.123);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        tom.withdraw(10000.9);//输出：您的存款金额不足
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        Account  jerry;
        jerry.init("320203200910116569",  "Jerry  Black",  "女",  11,  100.956);//输出：您输入的金额不合法
        jerry.printmoney();//输出：Jerry  Black的存款为0.00
        system("pause");
        return 0;
}
