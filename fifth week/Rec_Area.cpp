//1. 设计一个CRectangle类，其中包括CPoint类的两个对象成员，表示左上角和右下角的两个点。要求求解矩形的面积。
// 设计一个CRectangle类，其中包括CPoint类的两个对象成员，表示左上角和右下角的两个点。要求求解矩形的面积。
// 注意，每个类的构造函数、拷贝构造函数需要输出“*** is called”,具体的请根据输出进行分析。
#include <iostream>
using  namespace  std;
class CPoint
    {
		public:
		CPoint(int xx=0,int yy=0);
		CPoint(CPoint &p);
		int Getx(){return x;}
		int Gety(){return y;}
		private:
		int x,y;
    };
CPoint::CPoint(int xx,int yy)
{
	x=xx;
	y=yy;
	cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(CPoint &p)
{
	x=p.x;
	y=p.y;
	cout<<"CPoint copy contstructor is called."<<endl;
}
class CRectangle
	{
		public:
		CRectangle(int lenxx=0,int lenyy=0);
		CRectangle(int a,int b, int c,int d);
		CRectangle(CPoint xp1,CPoint xp2);
		CRectangle(CRectangle &S);
		int GetArea();
		private:
		CPoint p1, p2;					//p1为左上角的点，p2为右上角的点
		int lenx,leny;
	};
	 CRectangle::CRectangle(int lenxx,int lenyy)
	 {
	 	lenx=lenxx;
	 	leny=lenyy;
		cout<<"CRectangle default contstructor is called."<<endl;
	 }
CRectangle::CRectangle(CPoint xp1,CPoint xp2) :p1(xp1),p2(xp2)
	{
		lenx=p1.Getx()-p2.Getx();
		leny=p1.Gety()-p2.Gety();
		cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
	}
CRectangle::CRectangle(int a,int b, int c,int d):p1(a,b),p2(c,d)
{
	lenx=c-a;
	leny=d-b;
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle &S):p1(S.p1),p2(S.p2)
{
	lenx=p1.Getx()-p2.Getx();
	leny=p1.Gety()-p2.Gety();
	cout<<"CRectangle copy contstructor is called."<<endl;
}
int CRectangle::GetArea()
{
	return lenx*leny;
}
int  main()
{
    int  a=1,  b=1,  c=6,  d=11;
    cout<<"#  Define  p1  ######"<<endl;
    CPoint  p1;
    cout<<"#  Define  p2  ######"<<endl;
    CPoint  p2(10,20);
    cout<<"#  Define  rect1  ######"<<endl;
    CRectangle  rect1;
    cout<<"#  Define  rect2  ######"<<endl;
    CRectangle  rect2(p1,  p2);
    cout<<"#  Define  rect3  ######"<<endl;
    CRectangle  rect3(a,  b,  c,  d);
    cout<<"#  Define  rect4  ######"<<endl;
    CRectangle  rect4(rect2);
    cout<<"#  Calculate  area  ######"<<endl;
    cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl;
    cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl;
    cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl;
    cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl;
    system("pause");
    return  0;
}
