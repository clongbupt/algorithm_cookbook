/**
 * 二分查找 无相同元素的有序数组 非递归
 * 
 * @param  int*  data   输入数据   数组
 * @param  int   len    数组长度
 * @param  int   target 目标数字
 */
bool binary_search(int*data, int len, int target){
    if (data == null || len == 0 || target < data[0] || target > data[len-1])
        return false;
    int left = 0;
    int right = len;
    int mid;
    while (left < right){
        mid = left + (right - left)/2;
        if (data[mid] == target) return true;
        else if (data[mid] < target) left = mid+1;
        else right = mid;
    }
    return false;
}