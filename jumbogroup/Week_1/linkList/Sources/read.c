#include "linkedList.h"
#include<stdlib.h> 
#include<stdio.h> 
void printMenu();


int main(){
    int choice;
    int data;
    LinkedList L;


    do {
        printMenu();
        scanf("%d", &choice);
//        printf("\n***** ͼ�β˵� *****\n");
//        printf("1. ��ʼ������\n");
//        printf("2. ��ӽڵ�\n");
//        printf("3. ����ڵ�\n");
//        printf("4. ɾ���ڵ�\n");
//        printf("5. ��ѯ�ڵ�\n");
//        printf("6. ��ת����\n");
//        printf("7. �ж������Ƿ�ɻ�\n");
//        printf("8. ��ż����\n");
//        printf("9. ��ѯ�е�\n");
//        printf("10. ��ʾ��ǰ����\n");
//        printf("11. �˳�\n");
//        printf("��ѡ�����: ");

        switch (choice) {
            case 1:
                printf("��ʼ������\n");
                InitList(&L);
                break;
            case 2:
                printf("���һ���ڵ�,������ڵ��data:");
                scanf("%d",&data);
                getchar();
                LinkedList new = createNode(data);
                AddList(L,new);
                break;
            case 3:
                printf("����ڵ����\n����������������:\n");
                ShowList(L);
                printf("������׼�������λ��(���ĸ��ڵ��)��data �Ͳ���Ľڵ��data,��: 1 2\n������:");
                int position = 0;
                int inserted = 0;
                scanf("%d%d", &position, &inserted);
                LNode *inserted_node = createNode(inserted);
                InsertList(L, position, inserted_node);
                printf("������������������:\n");
                ShowList(L);
                break;
            case 4:
                printf("ִ��ɾ������\n����������������:\n");
                ShowList(L);
                printf("������Ҫɾ���Ľڵ�data:");
                scanf("%d",&data);
                getchar();
                DeleteList(L, data);
                printf("������������������:\n");
                ShowList(L);
                break;
            case 5:
                printf("��ѯ����\n");
                printf("������Ҫ���ҵĽڵ�����:");
                scanf("%d",&data);
                getchar();
                LNode *pNode = SearchList(L, data);
                if (pNode->data != 0){
                    printf("���ҵ���Ӧ�ڵ�\n");
                } else{
                    printf("δ�ҵ��˽ڵ�\n");
                }
                break;
            case 6:
                printf("��ת����\n��ѡ��ת����:1. ������//2. �ݹ鷨\n�������ѡ��:");
                scanf("%d",&data);
                getchar();
                if(data == 1){
                    ReverseList(&L);
                }else if(data == 2){
                    L->next = ReverseListByRecursion(L->next);
                }else printf("��Ч����\n");
                break;
            case 7:
                printf("�ж������Ƿ�ɻ�\n");
                Status status = IsLoopList(L);
                if(status == SUCCESS){
                    printf("��\n");
                } else printf("����\n");
                break;
//            case 8:
//                printf("��ż����\n");
//                ReverseEvenList(L);
//                break;
            case 9:
                printf("��ѯ�е�\n");
                LNode *midNode = FindMidNode(&L);
                printf("�е�����Ϊ:%d\n",midNode->data);
                break;
            case 10:
                ShowList(L);
                break;
            case 11:
                exit(0);
            default:
                printf("��Ч��ѡ������������\n");
        }
    } while (choice != 0);

    return 0;
}

void printMenu() {
    printf("\n***** ͼ�β˵� *****\n");
    printf("1. ��ʼ������\n");
    printf("2. ��ӽڵ�\n");
    printf("3. ����ڵ�\n");
    printf("4. ɾ���ڵ�\n");
    printf("5. ��ѯ�ڵ�\n");
    printf("6. ��ת����\n");
    printf("7. �ж������Ƿ�ɻ�\n");
//    printf("8. ��ż����\n");
    printf("9. ��ѯ�е�\n");
    printf("10. ��ʾ��ǰ����\n");
    printf("11. �˳�\n");
    printf("��ѡ�����: ");
}
