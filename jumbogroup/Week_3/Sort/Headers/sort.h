
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define COLORSORT_SIZE 100

#define MAX_SIZE 1000

#define NUMBERS1_SIZE 10000
#define NUMBERS2_SIZE 50000
#define NUMBERS3_SIZE 200000

#define FORTIME 100
#define FORSIZE 100

#define X_SIZE 100

#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void printMenu(){
	printf("**1.request1:Insertion Sort\n");
	printf("**2.request2:Merge Sort\n");
	printf("**3.request3:Quick Sort\n");
	printf("**4.request4:Counting Sort\n");
	printf("**5.request5:Color Sort\n");
	printf("**6.request6:Radix Sort\n");
	printf("**0.exit\n");
}

void sort_menu();

/**
 *  @name        : 
 *  @description : 打印数组
 *  @param       : int指针a, int元素个数n
 *  @specific	 : 使用制表符使打印结果美观，每10个元素换行
 */
void printArray(int arr[],int n);

int getMax(int arr[], int n);

void switch_c(int arr[], int n);

void generateRandomNumbers(int arr[],int n);

/**
 *  @name        : 
 *  @description : 计时函数
 *  @param       : void执行函数，int指针a, int元素个数n, 返回操作时间t
 */
double timer(void (*sortFunction)(int[], int), int arr[], int n);

/**
 *  @name        : void swap(int* a, int *b)
 *  @description : 交换俩个值的位置
 *  @param       : int指针a, int指针b
 */
void swap(int* a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int a[],int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);

/**
 *  @name        : int pivoxChoose(int* array, int begin, int end)
 *  @description : 三值取中
 *  @param       : 数组指针array，数组起点begin，数组终点end
 */
int pivoxChoose(int* array, int begin, int end);

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);

/**
 *  @name        : int getDigit(int num, int digit)
 *  @description : 提取第几位数, 个位时digit是0
 *  @param       : 数字num, 要的位数digit
 */
int getDigit(int num, int digit);

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void radixCountSort(int *arr, int n, int exp);
void radixSort(int arr[], int n);
/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);

void generateTestData(int size, int max, const char* filename);
void readDataFromFile(const char* filename, int arr[], int* size);
/**
 *  @name        : Status kthDecimal(int* a, int begin, int end, int k, int* output)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组起始下标begin, 数组终止下标end, 要找的第几小数k, 作为返回的output
 */
//Status kthDecimal(int* a, int begin, int end, int k, int* output);


 /**
  *  @name        : Status pushStack(int* array, int* top, int input)
  *  @description : 入栈
  *  @param       : 数组指针array，栈顶top, 入栈数input
  */
//Status pushStack(int* array, int* top, int input);

/**
 *  @name        : Status popStack(int* array, int* top,int *output)
 *  @description : 出栈
 *  @param       : 数组指针array，栈顶top, 出栈数存贮的指针
 */
//Status popStack(int* array, int* top, int* output);

/**
 *  @name        : int* initStack(int length)
 *  @description : 初始化栈
 *  @param       : 数组长度length
 */
int* initStack(int length);

#endif // QUEUE_H_INCLUDED