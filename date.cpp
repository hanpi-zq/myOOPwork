// 1.【问题描述】声明一个表示时间的类CTime，可以精确表示年、月、日、小时、分、秒，请计算两个日期对象之间相隔的天数。
// 要求：
// 1、包括私有成员年、月、日、小时、分、秒。
// 2、请使用构造函数实现的类的初始化工作，并判断日期和时间的有效性。年月日时分秒应该在正确的范围内。考虑闰年时候二月份的情况。
// 时间的格式是xx:xx:xx,小时不是超过23，分钟和秒不能超过59。
//     1）如果日期无效，则输出 “date error! ”  并将年、月、日、小时、分、秒置为0。
//     2）如果时间无效，则输出 “time error! ”  并将年、月、日、小时、分、秒置为0。
//     3）如果日期和时间都有效，则根据传递的参数初始化年、月、日、小时、分、秒。
//     4）构造函数的三个参数：小时、分、秒 设计为默认形成，其默认值为0。
//     5)  输出"构造函数被调用"
// 3、请设计一个拷贝构造函数，实现将参数的值全部传递给当前对象，同时输出“拷贝构造函数被调用”
// 4、请设计一个析构函数，同时输出“析构函数被调用”
// 5、设计一个成员函数  int dayDiff(CTime t) ，用于计算当前对象与形参t之间的相隔的天数，注意相隔天数为大于等于0的正整数。注意闰年的问题。
// 6、设计一个成员函数 showTime()，用于显示日期，显示格式为：2020/3/12 11:50:20
#include <iostream>
using namespace std;
int m = 0, k = 0;
int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
class CTime
{
public:
    CTime(int yyear, int mmonth, int dday, int hhour = 0, int mminute = 0, int ssecond = 0);
    CTime(CTime& p);
    int dayDiff(CTime t);
    void showTime();
    int isvalid();
    int isLearyear(int _year);
    ~CTime();
private:
    int year, month, day, hour, minute, second;
};
CTime::CTime(int yyear, int mmonth, int dday, int hhour , int mminute , int ssecond )
{
    year = yyear;
    month = mmonth;
    day = dday;
    hour = hhour;
    minute = mminute;
    second = ssecond;
    if (hour > 23 || minute > 59 || second > 59)
    {
        cout << "time error!" << endl;
        m = 1;
        year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    }
    if ((year % 4 == 0 && year % 100 != 0) || (year / 400 == 0))
    {

        if (b[month-1]<day)
        {
            k = 1;
            if (m == 0 && k == 1)
            {
                cout << "date error!" << endl;
                year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
            }
            else
            {
                cout << "date and time error!" << endl;
                year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
            }
        }
        


    }
    else
    {
        if ( a[month - 1] < day)
        {
            k = 1;
            if (m == 0 && k == 1)
            {
                cout << "date error!" << endl;
                year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
            }
            else
            {
                cout << "date and time error!" << endl;
                year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
            }
        }
    }
    
    cout << "构造函数被调用" << endl;
}
CTime::~CTime()
{
    cout << "析构函数被调用" << endl;
}
CTime::CTime(CTime& p)
{
    year = p.year;
    month = p.month;
    day = p.day;
    hour = p.hour;
    minute = p.minute;
    second = p.second;
    cout << "拷贝构造函数被调用" << endl;
}
int CTime::dayDiff(CTime t)//计算两个日期之间相隔的天数
{
    int i, days = 0;
    if (year == t.year && month == t.month)
    {
        if (day > t.day)
            days = day - t.day;
        else
            days = t.day - day;
    }
    else if(year==t.year)
        { 
            if (isLearyear(year))
            {
                if (month < t.month)
                {
                    days = days + b[month - 1] - day;
                    days = days + t.day;
                    for (i = month ; i < t.month-1; i++)
                    {
                        days = days + b[i];
                    }
                }
                else if (month == t.month)
                {
                    if (day > t.day)
                        days = day - t.day;
                    else
                        days = t.day - day;
                }
                else 
                {

                    days = days + b[t.month - 1] - t.day;
                    days = days + day;
                    for (i = t.month ; i < month-1; i++)
                    {
                        days = days + b[i];
                    }
                }
                
            }
            else
            {
                if (month < t.month)
                {
                    days = days + a[month - 1] - day;
                    days = days + t.day;
                    for (i = month ; i < t.month-1; i++)
                    {
                        days = days + a[i];
                    }
                }
                
                else
                {

                    days = days + a[t.month - 1] - t.day;
                    days = days + day;
                    for (i = t.month ; i < month-1; i++)
                    {
                        days = days + a[i];
                    }
                }
            }
        }
    else
    {
        if (t.year > year)
        {
            if (isLearyear(year))
            {
                if (month < t.month)
                {
                    days = days + b[month - 1] - day;
                    days = days + t.day;
                    for (i = month ; i < t.month-1; i++)
                    {
                        days = days + b[i];
                    }
                }
                else if (month == t.month)
                {
                    
                      days =days+ t.day - day;
                }
   
                else
                {

                    days = days + b[t.month - 1] - t.day;
                    days = days + day;
                    for (i = t.month ; i < month-1; i++)
                    {
                        days = days + b[i];
                    }
                }
            }
            else
            {
                if (month < t.month)
                {
                    days = days + a[month - 1] - day;
                    days = days + t.day;
                    for (i = month ; i < t.month-1; i++)
                    {
                        days = days + a[i];
                    }
                }
                else if (month == t.month)
                {
                   
                        days = days+t.day - day;
                }
                else
                {

                    days = days + a[t.month - 1] - t.day;
                    days = days + day;
                    for (i = t.month ; i < month-1; i++)
                    {
                        days = days + a[i];
                    }
                }
            }
            for (i = year; i < t.year; i++)
            {
                if (isLearyear(i))
                {
                    days = days + 366;
                }
                else
                    days = days + 365;
            }
        }
        if (year > t.year)
        {
            if (isLearyear(t.year))
            {
                if (month < t.month)
                {
                    days = days + b[month - 1] - day;
                    days = days + t.day;
                    for (i = month ; i < t.month-1; i++)
                    {
                        days = days + b[i];
                    }
                }
                else if (month == t.month)
                {
                    
                    days =days+ day - t.day;
                }
                else
                {

                    days = days + b[t.month - 1] - t.day;
                    days = days + day;
                    for (i = t.month ; i < month-1; i++)
                    {
                        days = days + b[i];
                    }
                }
            }
            else
            {
                if (month < t.month)
                {
                    days = days + a[month - 1] - day;
                    days = days + t.day;
                    for (i = month ; i < t.month-1; i++)
                    {
                        days = days + a[i];
                    }
                }
                else if (month == t.month)
                {

                    days = days + day - t.day;
                }
                else
                {

                    days = days + a[t.month - 1] - t.day;
                    days = days + day;
                    for (i = t.month ; i < month-1; i++)
                    {
                        days = days + a[i];
                    }
                }
            }
            for (i = t.year; i < year; i++)
            {
                if (isLearyear(i))
                {
                    days = days + 366;
                }
                else
                    days = days + 365;
            }
        }
    }
    return days;
       
    
    
}
void CTime::showTime()//输出时间
{
    cout << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << endl;
}
int CTime::isvalid()
{
    if (m == 0 && k == 0)
        return 1;
    else
    {
        return 0;
    }

}
int CTime::isLearyear(int _year)//判断是否为闰年
{
    if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
    {
        return 1;
    }
    else
        return 0;
}
int  main()
{
    int  year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime  t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime  t2(2000, 1, 1);  //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())          //如果日期和时间合法，则计算天数
    {
        int  days = 0;
        days = t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days = t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
    system("pause");
    return 0;
}