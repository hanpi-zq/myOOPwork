#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
struct node
{
   T  data;
   node * next;
};
template<class T>
class linkedList
{
    public:
        linkedList();
        virtual ~linkedList();
        void insert( T value );
        bool initiate();
        bool isEmpty();
        bool remove( int pos, T& value );
        void print();
        int Length();
private:
    node<T> *head;
    int len;

};
template<class T>
bool linkedList<T>::initiate()
{
    head= (node<T>*)malloc(sizeof(node<T>)); 
    head->next=NULL;
    if(head!=NULL)  
    return true;
    else
    {
        return false;
    }
}
template<class T>
linkedList<T>::linkedList()
{
    head= (node<T>*)malloc(sizeof(node<T>));
    len=0;
}
template<class T>
linkedList<T>::~linkedList()
{

}
template<class T>
void linkedList<T>::insert(T value)
{
    len++;
    node<T> *p=head;
    while(true)
    {   
         if(p->next==nullptr)
        {
            node<T>*tem= (node<T>*)malloc(sizeof(node<T>));
            tem->data=value;
            tem->next=nullptr;
            p->next=tem;
            break;
            
        }
        else
        {
            p=p->next;
        }
    }


}


template<class T>
bool  linkedList<T>::isEmpty()
{
    if(head->next==NULL)
    return true;
    else
    {
        return false;
    }
    
}
template<class T>
bool  linkedList<T>::remove(int pos, T& value)
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
       
       node<T> *p=head;
       for(int i=0;i<pos-1;i++)
       {
           p=p->next;
       }
        node<T> *tem=p->next;
        p->next=tem->next;
        value=tem->data;
        free(tem);
        len=len-1;
        return true;
    }
    

} 
template<class T>
int  linkedList<T>::Length()
{
   return len;
}

//成员函数print
template<class T>
void  linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    node<T>* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    linkedList<int> L1;
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

    return 0;
}
