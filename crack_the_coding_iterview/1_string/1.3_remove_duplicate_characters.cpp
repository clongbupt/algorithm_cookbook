/**
 * 用一个char[256]的字符串存储ASCII的各个字符
 *
 * 此处用了一个p指针, 从头开始修改当前串, 但只修改已经访问过的
 * 这也是一种非常好的方式
 *
 */

char [] remove_duplicate_characters (char [] str, int len){
	if (str == null || len == 0)
		return NULL;

	bool used[256];
	memset(used,0,sizeof(used));

	int p = 0;
	int num;
	for(int i=0; i<len; i++){
		num = (int)str[i];
		if(!used[num]){
			used[num] = true;
			str[p] = str[i];
			p++;
		}
	}

	str[p] = '\0';

	return str;
}


/**
 * 移除重复的字符串, 字符串范围为a-z
 */
char [] remove_duplicate_characters_new(char [] str, int len){
	if (str == null || len == 0)
		return NULL;

	int check = 0;

	int p = 0;

	int value;
	for(int i=0; i<len; i++){
		value = str[i] - 'a';
		if((check & (1 << value)) ==0){
			check |= (1 << value);
			str[p] = str[i];
			p++;
		}
	}

	s[p] = '\0';

	return str;
}