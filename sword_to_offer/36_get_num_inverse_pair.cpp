/**
 * 练习归并算法
 *
 * 先分解再归并   归并时求逆序数个数
 *
 * 比归并算法多一个辅助数组  需要通过辅助数组来记录有序的子数组
 *
 * 测试用例  6 4 7 5     结果为5
 */

int get_sum_inverse_pairs(int a[], int len){
	if (data == NULL || len == 0)
		return 0;

	int copy[len];
	memset(copy,0,sizeof(copy));

	for(int i=0; i<len; i++)
		copy[i] =a[i];

	int count = compute(a,copy,0,len-1);

	return count;
}

int compute(int a[], int copy[], int start, int end){
	if(start == end){
		copy[start] = a[start];
		return 0;
	}

	int mid = start + (end - start)/2;

	int left, right;

	left = compute(copy,data,start,mid);
	right = compute(copy,data,mid+1,end);

	int i = mid;
	int j = end;

	int index_copy = end;
	int count = 0;

	while(i>=start && j>=mid+1){
		if(data[i] > data[j]){
			copy[index_copy] = data[i];
			index_copy --;
			i--;
			count += j - mid; 
		}
		else{
			copy[index_copy] = data[j];
			index_copy --;
			j--;
		}
	}

	while(i>=start){
		copy[index_copy] = data[i];
		index_copy--;
		i--;
	}

	while(j>=mid+1){
		copy[index_copy] = data[j];
		index_copy--;
		j--;
	}

	return left+right+count;
}