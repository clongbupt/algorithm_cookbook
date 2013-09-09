/**
 *
 * 判断字符串1可否通过字符串2的循环旋转, 只能使用substring
 * 
 * 通过判断s2是否是s1+s1的子字符串便可以搞定
 *
 * TODO 实现C语言的sub_string版本   C语言中有一个strstr的实现可以搞定
 *
 */
bool check_rotation(char s1[], char s2[]){
	if (s1 == NULL || s2 == NULL)
		return false;

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 != len2)
		return false;

	return sub_string(strcat(s1,s1), s2);
}

bool sub_string(char s1[], char s2[]){
	...
}