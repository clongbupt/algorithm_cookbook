#include "cstdio"
#include "cstring"

using namespace std;


/**
 * 快排双端法
 *
 * pivot取值，从右向左找到一个小于pivot的值，赋值为i位置， 从左向右找到一个大于pivot的值，赋值到j位置
 *
 * 直到i不小于j, 最后将a[i]赋值为pivot值，并返回i位置 
 *
 */
int partition(int a[], int left, int right){
	int pivot = a[left];
	int i = left;
	int j = right;

	while(i < j){
		while(pivot <= a[j] && i < j)  j--;
		a[i] = a[j];
		while(pivot >= a[i]&& i < j) i++;
		a[j] = a[i];
	}

	a[i] = pivot;
	return i;
}

void q_sort(int a[], int left, int right){
	int index;
	if (left < right){
		index = partition(a,left,right);
		q_sort(a,left,index-1);
		q_sort(a,index+1,right);
	}
}

void quick_sort(int a[], int len){
	if(a == NULL || len <= 0 )
		return;

	int left = 0;
	int right = len-1;

	q_sort(a, left,right);
}


int main(int argc, char const *argv[])
{
	int a[] = {2, 2, 1, 1};
	quick_sort(a,4);
	for(int i=0; i<4;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

/**
 *
 * 经典法
 *
 * 选择轴枢值的index，将该值移动到数组末尾
 * 
 * 定义一个small的下标值
 *
 * 从左向右选择比位于数组末尾的轴枢值小的值，++small，如果small下标不等于index，则对small和index的值进行交换
 *
 * 跳出循环后，++small，并将轴枢值同small下标值进行交换
 *
 */
// int partition2(int a[], int left, int right){

// 	int index = left;
// 	swap(a[index], a[right]);

// 	int small = left - 1;
// 	for(index=0; index<right; index++){
// 		if(data[index] < data[right])
// 		{
// 			++small;
// 			if(small != index)
// 				swap(data[index], data[small]);
// 		}
// 	}

// 	++small;
// 	swap(data[small], data[end]);

// 	return small;

// }

// /**
//  *
//  * 获得最小的k个数   通过partition方法找到k以及所有比k小的值，这样便可以获得最小的k个数
//  *
//  *
//  */
// int * get_least_k_number(int a[], int len, int k){
// 	if (a == NULL || len <= 0 || k <= 0)
// 		return;

// 	int output[k];
// 	memset(output,0,sizeof(output));

// 	int start = 0;
// 	int end = len - 1;

// 	int index = partition(a, start, end);

// 	while(index != k-1){
// 		if(index > (k-1))
// 		{
// 			end = index - 1;
// 			index = partition(a,start,end);
// 		}
// 		else{
// 			start = index + 1;
// 			index = partition(a,start,end);
// 		}
// 	}

// 	for(int i=0; i<k; i++)
// 		output[i] = a[i];

// 	return output;

// }