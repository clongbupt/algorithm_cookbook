#include "cstdio"

using namespace std;

int bsearch (int a[], int left, int right, int key){
	int mid;
	if(a[right] < key || a[left] > key)
		return -1;
	if(left == right ){
		if(a[left] == key)
			return left;
		else
			return -1;
	}
	while(left < right){
		mid = left + (right - left) / 2;
		if (a[mid] == key)  
			return mid;
		else if(a[mid]<key) 
			left = mid+1;
		else
			right = mid;
	}
	return -1;
}

int bsearch2 (int a[], int left, int right, int key){
	int mid;
	if(left < right){
		mid = left + (right - left) / 2;
		if(a[mid] == key) 
			return mid;
		else if (a[mid] > key)
			return bsearch2(a, left, mid, key);
		else
			return bsearch2(a, mid+1, right, key);
	}
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	int b[] = {1,2,3,4,5,6};
	int c[] = {1,1,1};
	printf("%d\n",bsearch2(a,0,4,3));
	printf("%d\n",bsearch2(a,0,4,1));
	printf("%d\n",bsearch2(a,0,5,5));   // 左闭右开区间
	printf("%d\n",bsearch2(b,0,5,3));
	printf("%d\n",bsearch2(c,0,3,1));
	return 0;
}