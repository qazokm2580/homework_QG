#include "../Headers/LinkedList.h"
#include <iostream>
using namespace std;


 //尾插法创建单链表、链表长度为n;
void CreatLinkedList(LinkedList &L,int n)  
{
    L = (LinkedList)malloc(sizeof(LNode));  //初始化;
    L->next = NULL;
    L->data = 0;
    LinkedList Tail = L;    //尾指针;
    cout<<"Enter "<<n<<" number(s)"<<endl;
    for(int i = 0 ; i < n; i++)
    {
        LinkedList Temp = (LinkedList)malloc(sizeof(LNode));
        cin>>Temp->data;
        Tail->next = Temp;
        Tail = Temp;
        Temp = NULL;
        L->data++;  //计数;
    }
    Tail->next = NULL;
}
