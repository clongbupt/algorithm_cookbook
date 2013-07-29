/**
 * 如果一个给len, 则直接用两个指针做即可
 *
 * 如果不给len, 则自己计算出lenth,然后做
 *
 * 结果值可以是返回值为空，然后传指针的指针来修改源串；也可以是返回修改后的串
 *
 * strlen()  的结果是   "abcd"   4  下标为0,1,2,3  但是还有一个'\0'字符
 *
 * while(*p)访问时， 到'\0'字符时的情况
 */

char [] reverse_string (char [] str, int len){
	if (str == null || len == 0)
		return NULL;

	int i = 0;
	int j = len - 1;
	char tmp;
	while(i < j){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}

	return str;
}

void reverse_string (char ** str_ptr){
	if ( *str == null)
		return;

	char *right = *str;
	char *left = *str;
	while( *right)
		right++;
	right --;

	char tmp;
	while(left < right){
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right++;
	}

}