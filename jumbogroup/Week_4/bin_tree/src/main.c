#include <stdio.h>
#include <binary_sort_tree.h>

/*Status PreorderTraverse(BiTree T,Status(*visit)(TElemType e)){
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
*/
int main() {
    printf("Hello, World!\n");
    return 0;
}
