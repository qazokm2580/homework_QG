#include "../Headers/sort.h"
#include <windows.h>

int main()
{
	int chi=999;
	int n=100;
	sort_menu();
	return 0;
}

void switch_c(int arr[], int n){
	int chi;
	double t;
    printMenu();
	scanf("%d",&chi);
    switch(chi){
        case 1:{      	
        	t = timer(insertSort, arr, n);
        	printf("%f ms",t);
            system("pause");
            printArray(arr, n);
			break;
		}
		case 2:{
        	t = timer(MergeSort, arr, n);
            printf("%f ms", t);
            system("pause");
            printArray(arr, n);
			break;
		}
		case 3:{
			t = timer(QuickSort_Recursion, arr, 0);
            printf("%f ms", t);
            system("pause");
            printArray(arr, n);
			break;
		}
		case 4:{
        //	t = timer(MergeSort, arr, 0);
            printf("%f ms", t);
            system("pause");
            printArray(arr, n);
			break;
		}
		case 6:{
			t = timer(radixSort, arr, n);
			printf("%f ms", t);
            system("pause");
            printArray(arr, n);
			break;
		}
		default:{
			break;
		}
    }
}

//void RadixCountSort(int *arr, int n)
void printArray(int arr[],int n)
{
	//int nv = sizeof(arr) / sizeof(arr[0]);

    for ( int i = 0; i < n; i++)
    {
        if (i%10 == 0)
        {
        	printf("\n");
        }
        printf("%d\t", arr[i]);
	}
	printf("\n");
}

void sort_menu(){
	int s=999;
	double t=0;
	while(s!=0)
	{
	printf("1.10k个数据\n");
	printf("2.50k个数据\n");
	printf("3.200k个数据\n");
	printf("4.100个数据（循环）\n");
	printf("0.exit  输入其他均为1000个\n");
	scanf("%d",&s);
	switch (s)
    {
    	case 0:{
			break;
		}
        case 1:{
		int arr[10000]={0};
        int n=10000;
        generateRandomNumbers(arr,n);
        switch_c(arr,n);
            break;
        }
        case 2:{
			int arr[50000]={0};
        	int n=50000;
        	generateRandomNumbers(arr,n);
        	switch_c(arr,n);
            break;
        }
        case 3:{
			int arr[200000]={0};
        	int n=200000;
        	generateRandomNumbers(arr,n);
           	switch_c(arr,n);
            break;
        }
        case 4:{
        	int arr[100]={0};
        	int n=100;
        	for(int j=0; j<100000; j++)
        	{
        		generateRandomNumbers(arr,n);
           		t = timer(insertSort, arr, n);
			}
			break;
		}
        default:{
		int arr[1000]={0};
		int n=1000;
        	generateRandomNumbers(arr,n);
           	switch_c(arr, n);
        break;
    	}
    }
}}

void QuickSort_Recursion(int *a, int begin, int end)
{
	
	if (begin >= end)
	{
		return;
	}
	//一趟的实现
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		//右边开始行动   一定要加上等于，因为快速排序找的是一定比它小的值
		while (left < right && a[keyi] <= a[right])
		{
			right--;
		}
		//左边开始行动
		while (left < right &&   a[left] <= a[keyi])
		{
			left++;
		}
		swap(&a[left], &a[right]);
 
	}
	swap(&(a[keyi]), &(a[right]));
	keyi = right;
	//[begin,keyi-1] keyi [keyi+1,end]
	QuickSort_Recursion(a, begin, keyi - 1);
	QuickSort_Recursion(a, keyi+1, end);
}

void MergeArray(int *arr,int begin,int mid,int end){
	int *temp = (int *)malloc((end-begin+1) * sizeof(int));
	int i = begin;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    //将临时区域中排序后的元素，整合到原数组中
    for (i = 0; i < k; i++)
    {
        arr[begin + i] = temp[i];
    }

    free(temp);
}

void MergeSort(int *arr,int begin,int end){
	int mid = begin + (end - begin) / 2;
 
     if (begin >= end)
     {
         return;
     }
     
     MergeSort(arr, begin, mid);
     MergeSort(arr, mid + 1, end);
 
     MergeArray(arr, begin, mid, end);
}

void insertSort(int ar[], int len)
{
    int tmp = 0;
    for (int i = 1; i < len; i++)
    {
        tmp = ar[i];
        if (ar[i-1] > tmp)
        {
            int j = i-1;
            for (; j >= 0; j--)//从后向前找
            {
                if (ar[j] > tmp)//如果大于tmp则向后移动
                {
                    ar[j + 1] = ar[j];
                }
                else
                {
                    break;
                }
            }
            ar[j + 1] = tmp;

        }
    }

}

static int Get_Figure(int ar[], int len)//获取最大值的位数
{
    int max = ar[0];
    for (int i = 1; i < len; i++)
    {
        if (max < ar[i])
        {
            max = ar[i];
        }
    }
    int count = 0;
    while (max != 0)
    {
        count++;
        max /= 10;
    }
    return count;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // 从个位开始，对数组按照位数进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        radixCountSort(arr, n, exp);
    }
}

void radixCountSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // 统计每个数字出现的次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 将count[i]更新为arr中小于等于i的数字的个数
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 根据count数组将数据放到正确的位置
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将排序好的数据复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void generateRandomNumbers(int arr[], int n) 
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%10000; // 随机数的范围
    }
}

double timer(void (*sortFunction)(int[], int), int arr[], int n){
	double t;
	clock_t begin = clock();
	sortFunction(arr,n);
	clock_t diff =clock()-begin;
	t=(double)diff;
	return t;
}

int getMax(int arr[], int n) 
{ 
    int max = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
/*void generateTestData(int size, int max, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        int num = generateRandomNumber(min, max);
        fprintf(fp, "%d\n", arr);
    }

    fclose(fp);
}

void readDataFromFile(const char* filename, int arr[], int* size) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    *size = 0;
    while (fscanf(fp, "%d", &arr[*size]) != EOF) {
        (*size)++;
    }

    fclose(fp);
}
*/
