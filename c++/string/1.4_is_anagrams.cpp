/**
 * 判断是否变位词， 变位词是指组成两个单词的字符相同, 但位置不同的单词.
 *
 * 判断方法可以是对每个单词各个字符的个数进行判断
 */
char [] is_anagrams(char [] str1, char [] str2){
	if(str1 == NULL || str2 == NULL)
		return false;

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if(len1 != len2) 
		return false;

	int cnt[256];
	memset(cnt,0,sizeof(cnt));

	for(int i=0; i<len; i++){
		++cnt[str1[i]];
		--cnt[str2[i]];
	}

	for(int i=0; i<len; i++){
		if(c[i] != 0)
			return false;
	}

	return true;

}