/**
 * 二分查找  有重复数字的有序数组中查找最左和最右的点
 *
 * 测试用例   1 2 3 3 3 4 5    target = 3
 *
 * 
 */

int get_first_target(int a[], int left, int right, int target){

	int mid = left + (right - left)/2;

	while(left<right){
		if (a[mid] >= target) 
			right = mid;
		else 
			left = mid+1; 
	}

	return mid;
}

int get_last_target(int a[], int left, int right, int target){

	int mid = left + (right - left)/2;

	while(left < right){
		if(a[mid] <= target)
			left = mid+1;
		else
			right = mid;
	}

	return mid;
}

int get_sum_of_target(int a[], int len, int target){

	if (len == 0)
		return 0;

	int left_index = right_index = 0;

	left_index = get_first_target(a,0,len,target);

	right_index = get_last_target(a,0,len,target);

	return (right_index - left_index);
}