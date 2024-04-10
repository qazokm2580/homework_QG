#include<iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char TElemType;
using namespace std;

Status PreorderTraverse(BiTree T,Status(*visit)(TElemType e)){
    if (T == NULL)  return 1;
//先序遍历
    visit(T->data);
    PreorderTraverse(T->lchild, visit);
    PreorderTraverse(T->rchild, visit);

    //中序遍历
    PreorderTraverse(T->lchild, visit);
    visit(T->data);
    PreorderTraverse(T->rchild, visit);

    //后序遍历
    PreorderTraverse(T->lchild, visit);
    PreorderTraverse(T->rchild, visit);
    visit(T->data);
}



int main(){
    cout<<"helloworld!"<<endl;
    return 0;
}