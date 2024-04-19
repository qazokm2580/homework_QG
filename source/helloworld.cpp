#include<iostream>
#include<string>
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

int main() {
    int choice;
    printf("\n");
    printf("      MENU\n");
    printf("==================\n");
    printf(" 1. New Game\n");
    printf(" 2. Continue\n");
    printf(" 3. Options\n");
    printf(" 4. Credits\n");
    printf(" 5. Exit\n");
    printf("==================\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
 
    while (choice >= 1 && choice <= 5) {
        switch (choice) {
            case 1:
                printf("\nYou selected New Game.\n");
                // Code for New Game
                break;
            case 2:
                printf("\nYou selected Continue.\n");
                // Code for Continue
                break;
            case 3:
                printf("\nYou selected Options.\n");
                // Code for Options
                break;
            case 4:
                printf("\nYou selected Credits.\n");
                // Code for Credits
                break;
            case 5:
                printf("\nYou selected Exit.\n");
                // Code for Exit
                return 0;
        }
        printf("\nEnter choice: ");
        scanf("%d", &choice);
    }
 
    printf("\nInvalid choice!\n");
    return 1;
}