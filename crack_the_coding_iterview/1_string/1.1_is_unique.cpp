/**
 * 通过增加辅助数组的方式来记录字符是否出现，或者出现的次数是字符串算法常见的题目
 * 
 * 考虑字符串的范围，此处是ASCII共256个字符
 * 如果限制为小写字母a-z则可以只用一个int即可存储
 *
 * 注意int数组和bool数组两种方式
 *
 * int数组可以通过槽位和偏移来实现，假定256个单bit的位，通过int被分为32*8的槽位
 * 有8个槽位，每个槽位有32个bit
 * 即可得: idx = num / 32;      shift = num % 32;
 *
 * 
 */

bool is_unique(char[] s, int len){
	if(s == null || len == 0)
		return false;

	bool used[256];

	memset(used,0,sizeof(used));

	int idx;
	for(int i=0; i<len; i++){
		idx = (int)s[i];
		if(!used[idx]){
			used[idx] = true;
		}else{
			return false;
		}
	}

	return true;

}


bool is_unique_new(char[] s, int len){
	if(s == null || len == 0)
		return false;

	int used[8];
	memset(used, 0, sizeof(used));

	int num, idx, shift;
	for(int i=0; i<len; i++){
		num = (int)s[i];
		idx = num / 32;
		shift = num % 32;

		if(used & (1 << shift))
			return false;
		else
			used |= (1 << shift);
	}

	return true;
}