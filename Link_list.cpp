
#include <iostream>
#include <iomanip>
using namespace std;

typedef int  elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

class linkedList
{
public:
    linkedList();//构造函数
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert( int value );//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove( int pos, int& value );
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    LList *head;
    int len;
};

//请在此处补充所有成员函数的实现

linkedList::linkedList()
{
    head = (PList)malloc(sizeof(LList));
    len=0;
}
linkedList::~linkedList()
{

}
void linkedList::insert(int value)
{
    len++;
    node *p=head;
    while(true)
    {   
         if(p==nullptr)
        {
            node *tem=(PList)malloc(sizeof(LList));
            tem->data=value;
            tem->next=nullptr;
            p->next=tem;
            break;
            
        }
        // else
        // {
        //     p=p->next;
        // }
    }


}
bool linkedList::initiate()
{
    head= (PList)malloc(sizeof(LList)); 
    if(head!=NULL)  
    return true;
    else
    {
        return false;
    }
    
}
bool linkedList::isEmpty()
{
    if(head->next==NULL)
    return true;
    else
    {
        return false;
    }
    
}
bool linkedList::remove(int pos, int& value)
{
    if(head->next==NULL||pos==0)
    {
        cout<<"pos <= 0, failed"<<endl;
        return false;
    }
    else if(pos>len)
    {
        cout<<"pos > len, failed"<<endl;
        return false;
    }
    else
    {
       
       node *p=head;
       for(int i=0;i<pos-1;i++)
       {
           p=p->next;
       }
        node *tem=p->next;
        p->next=tem->next;
        value=tem->data;
        free(tem);
        len=len-1;
        return true;
    }
    

} 
int linkedList::Length()
{
   return len;
}

//成员函数print
void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    linkedList L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }
    system("pause");
    return 0;
}
