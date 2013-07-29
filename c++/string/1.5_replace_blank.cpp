/**
 * 替换的主要原则： 
 * 1. 先计算替换后str的总长度： 空格个数*2('%20'的长度 - ' '的长度) + 原来的长度
 * 2. 从尾部开始用两个指针进行替换
 *
 * 记得给新串添加'\0'的标志
 *
 */

char [] replace_blank(char [] str, int len){

	if(str == NULL || len == 0)
		return NULL;

	int cnt;
	for(int i=0; i<len; i++)
		if(str[i] == ' ')
			cnt ++;

	int n_len = len + cnt*2;

	str[n_len] = '\0';  // 注意不能忘记
	
	int j = n_len - 1;
	for(int i=len-1;i>=0;i--){
		if(str[i] == ' '){
			str[j] = '0';
			str[j-1] = '2';
			str[j-2] = '%';
			j -= 3;
		}else{
			str[j] = str[i];
			j--;
		}

	}

	return str;
}