// 1. 请设计一个程序实现图书库存的管理（动态数组类）
// 【问题描述】 请设计一个程序实现图书库存的管理。请根据给定的main函数及程序输出，完成设计。具体要求如下。
// 一、请设计一个Book类：
// 1、包括私有成员：
//     unsigned int m_ID;//编号
//     string m_Name;//书名
//     string m_Introductio//简介
//     string m_Author;//作者
//     string m_Date;//日期
//     unsigned int m_Page;//页数
// 2、设计所有成员变量的getter和setter函数，关于getter和setter，我们在多文件视频课程中已经进行了介绍，同学们也可以百度了解。
// 3、设计构造与析构函数，不要求输出信息，但各位同学可以自己输出并分析各个对象的创建与删除的情况：
// Book();//将m_ID初始化为0，表示这个一个未赋值对象
//     virtual ~Book();//无具体的工作
//     Book(const Book& other);//实现所有成员变量的拷贝
// 二、请设计一个Store类,这是一个动态数组类，用于实现图书的管理：
// 1、包括私有成员：
//     Book *m_pBook;//指向利用new操作动态创建的Book数组
//     unsigned int m_Count;//表示库存中图书的数量
// 2、设计m_Count成员变量的getter和setter函数。
// 3、设计构造与析构函数
//    1） Store();
//    将 m_Count置为0，m_pBook置为空指针;并输出"Store default constructor called!"
//    2）Store(int n);
//    将m_Count置为n;利用new创建大小为n的数组，令m_pBook指向数组;并输出"Store constructor with (int n) called!";
//    3）virtual ~Store();
//    将m_Count置为0;判断如果m_pBook不为空指针，释放m_pBook指向空间;并输出"Store destructor called!";
//    4）Store(const Store& other);
//    实现对象数组的深拷贝，并输出"Store copy constructor called!";
// 4、设计入库操作
//    入库操作的主要功能是在数组中添加一本新书。
//    函数声明为：void in(Book &b)
//    注意因为入库了一本新书，所以需要增加一个存储空间。提示：可以通过新申请一个空间，并将原有数据拷贝进新空间，同时将新增的书放在数组最后一个元素，再释放原有空间，
//从而实现数组大小的动态调整。
// 5、设计出库操作
//    出库操作的主要功能是根据指定的书名，在数组中删除这本书。
//    函数声明为：void out(string name)
//    注意因为删除了一本书，所以需要减少一个存储空间。提示：可以通过新申请一个空间，并将未被删除的部分拷贝进新空间，再释放原有空间，从而实现数组大小的动态调整。
// 6、根据ID查找图书
//    要求根据给定的ID查找图书，如果找到，则返回一个Book对象，Book对象中存储了对应书本的信息；如果找不到，则返回一个Book对象，Book对象的m_ID为0，表示未被初始化。
//    函数声明为：Book findbyID(int ID)
//  7、根据name查找图书
//    要求根据给定的书名查找图书，如果找到，则返回一个Book对象，Book对象中存储了对应书本的信息；如果找不到，则返回一个Book对象，Book对象的m_ID为0，表示未被初始化。
//    函数声明为：Book findbyName(string name)
// 8、设计一个函数打印所有的图书的信息
//    函数声明为：void printList()
#include <iostream>
using  namespace  std;
class  Book
{
public:
    void SetID(int n);
    void SetName(string n);
    void SetAuthor(string n);
    void SetIntroduction(string n);                                                      //请在此处补充Book类的定义
    void SetDate(string n);
    void SetPage(int n);
    Book(const Book& b);
    int GetID();
    string GetAuthor();
    string GetName();
    string GetDate();
    Book();
    ~Book();
private:
    unsigned int m_ID;//编号
    string m_Name;//书名
    string m_Introductio;//简介
    string m_Author;//作者
    string m_Date;//日期
     int m_Page;//页数

};
void Book::SetPage(int n)
{
    m_Page = n;
}
void Book::SetID(int n)
{
    m_ID = n;
}
void Book::SetName(string n)
{
    m_Name = n;
}                                                     //请在此处补充Book类的成员函数实现
void Book::SetAuthor(string n)
{
    m_Author = n;
}
void Book::SetIntroduction(string n)
{
    m_Introductio = n;
}
void Book::SetDate(string n)
{
    m_Date = n;
}
int Book::GetID()
{
    return m_ID;
}
string Book::GetName()
{
    return m_Name;
}
string Book::GetAuthor()
{
    return m_Author;
}
string Book::GetDate()
{
    return m_Date;
}
Book::Book()
{
    m_ID = 0;
    m_Page = 0;
}
Book::Book(const Book& b)
{
    m_ID = b.m_ID;//编号
    m_Name = b.m_Name;//书名
    m_Introductio = b.m_Introductio;//简介
    m_Author = b.m_Author;//作者
    m_Date = b.m_Date;//日期
    m_Page = b.m_Page;
}
Book::~Book()
{

}
class  Store
{
public:
    void in(Book& b);
    void out(string name);
    Book findbyID(int ID);
    Book findbyName(string name);
    void printList();
    int  GetCount();
    void GetID();
    Store();
    Store(int n);
    virtual ~Store();
    Store(const Store& other);
private:
    Book* m_pBook;
    int m_Count;
    Book* book1;                                                        //请在此处补充Store类的定义

};
Store::Store()
{
    m_Count = 0;
    m_pBook = 0;
    book1 = 0;
    cout << "Store default constructor called!" << endl;
}
Store::Store(int n)
{
    m_Count = n;
    m_pBook = new Book[n];
    book1 = 0;
    cout << "Store constructor with (int n) called!" << endl;
}
Store::~Store()
{
    m_Count = 0;
    book1 = 0;
    if (m_pBook != nullptr)
        delete[] m_pBook;
    cout << "Store destructor called!" << endl;

}
Store::Store(const Store& p)
{
    m_pBook = p.m_pBook;
    m_Count = p.m_Count;
    book1 = p.book1;
}
int Store::GetCount()
{
    return m_Count;
}
void Store::in(Book& b)
{
    int i=0;
    book1 = new Book[m_Count + 1];
    for ( i = 0; i < m_Count; i++)
    {
        book1[i] = m_pBook[i];
    }
    book1[i] = b;
    m_pBook = book1;
    m_Count = m_Count + 1;
}
void Store::out(string name)
{

    int i = 0;
    book1 = new Book[m_Count - 1];
    for ( i = 0; i < m_Count - 1; i++)
    {
        if (m_pBook[i].GetName() == name)
        {
            book1[i] = m_pBook[i +1];
        }
        else
        {
            book1[i] = m_pBook[i];
        }
    }
    m_pBook = book1;
    m_Count = m_Count - 1;


}
Book Store::findbyID(int ID)
{
    Book book2;
    for (int i = 0; i < m_Count; i++)
    {
        if (m_pBook[i].GetID() == ID)
        {
            return m_pBook[i];
            break;
        }

    }
    return book2;
}                                                    //请在此处补充Store类的成员函数实现
Book Store::findbyName(string name)
{
    
    Book book1;
    for (int i = 0; i < m_Count; i++)
    {
        if (m_pBook[i].GetName() == name)
        {
            return m_pBook[i];
            break;
        }
    }
    return book1;
}
void Store::printList()
{
    cout<<"There are totally "<< m_Count <<" Books:"<<endl;
    for (int i = 0; i < m_Count; i++)
    {
        if (m_pBook[i].GetID() != 0)
            cout << "ID=" << m_pBook[i].GetID() << "; " << "Name:" << m_pBook[i].GetName() << "; " << "Author:" << m_pBook[i].GetAuthor() << "; " << "Date:" << m_pBook[i].GetDate() << "; " << endl;
    }
}
int  main()
{
    Store  s;
    Book  b1, b2, b3;
    b1.SetID(1);
    b1.SetName("C++  语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout << "第一本书入库" << endl;
    s.in(b1);
    cout << "第二本书入库" << endl;
    s.in(b2);
    cout << "第三本书入库" << endl;
    s.in(b3);
    cout << "现有库存书籍数量：" << s.GetCount() << endl;
    cout << "查找并出库图书：离散数学" << endl;
    Book  tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
    {
        s.out("离散数学");
        cout << "离散数学  已成功出库" << endl;
    }
    else
        cout << "没有找到name为离散数学的书" << endl;
    cout << "现有库存书籍数量：" << s.GetCount() << endl;

    cout << "查找图书  ID：3" << endl;
    tmpbook = s.findbyID(3);
    if (tmpbook.GetID() != 0)
        cout << "找到ID为" << 3 << "的书，书名：" << tmpbook.GetName() << endl;
    else
        cout << "没有找到ID为" << 3 << "的书" << endl;

    cout << "查找图书  name：离散数学" << endl;
    tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
        cout << "找到name为离散数学的书，ID：" << tmpbook.GetID() << endl;
    else
        cout << "没有找到name为离散数学的书" << endl;

    cout << "输出所有库存图书的信息" << endl;
    s.printList();
    cout << "程序运行结束" << endl;
    system("pause");
    return  0;
}